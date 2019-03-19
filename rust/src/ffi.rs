/*! C API External Entry Points

This module defines C-API `extern` functions suitable for other languages to
call. Each child module replicates the API of its corresponding Rust module,
with monomorphized functions.

The C API requires that all stack handles are passed by *reference*, because of
requirements in C++ about passing templated structures through FFI even when
their size is fully known. As such, the Rust FFI boundary always takes pointers
to the type for manipulating the type itself. The memory governed by the type is
always managed by Rust (for the owning types) or the foreign caller (for
`BitSlice`).

# PANIC SAFETY

Note that use of this module *requires* compiling with `panic = abort`. The main
Rust library liberally employs runtime assertions which panic on violation. When
this module is enabled, you **must** compile with `panic = abort` to prevent any
unwinding from occuring which may cross the FFI boundary.

The unwinding guard, `std::panic::catch_unwind`, is only available in `std`, and
not in `core`. As such, it cannot be used in this library as an FFI guard.

Users of source distributions must set `panic = abort` in their project. There
are three ways to do this:

1. Modify the `Cargo.toml` of this library or one closer to the project root:

```toml
# Cargo.toml

[profile.release]
panic = "abort"
```

2. Set `RUSTFLAGS=${RUSTFLAGS},-Cpanic=abort` in the environment.

3. Set a `.cargo/config` file in the project root or higher with the setting:

```toml
# .cargo/config

[build]
panic = "abort"
```

Precompiled distributions are available in both panic behaviors, and will be
marked as `panic=unwind` or `panic=abort` as appropriate.

The repository ships a VSCode snippets definition file that allows the rapid
construction of monomorphized FFI definitions in Rust, C, and C++.
!*/

use super::{
	BitIdx,
	Bits,
	Cursor,
	bits::BitPos,
};
use core::sync::atomic::{
	AtomicBool,
	Ordering,
};

/** Checks a pointer or a sequence of pointers against `null`.
 *
 * If any of the pointers are `null`, then the expansion site returns.
 *
 * # Parameters
 *
 * - `$ptr : expr`: A pointer expression to check if it `is_null()`.
 * - `$( , $ptrs : expr )*`: A sequence of additional pointers to check if any
 *   of them are `null`, and return if so.
 * - `$( => $retval : expr )?`: An expression to return. If this is not present,
 *   then the expansion returns `()`.
 *
 * # Expansion
 *
 * ```rust,ignore
 * if $ptr.is_null() [ || $ptrs.is_null() ]* {
 *   return $retval? ;
 * }
 * ```
 *
 * # Safety
 *
 * This macro *must* be called at the entry of each FFI boundary function, to
 * check every pointer which will be dereferenced by the receiving function.
 */
macro_rules! nullck {
	( $ptr:expr $( , $ptrs:expr )* $( => $retval:expr )? ) => {
		if $ptr.is_null() $( || $ptrs.is_null() )* { return $( $retval )?; }
	};
}

/// Tristate boolean value for reporting `true`, `false`, or failure.
///
/// This is used to flatly encode `Option<bool>`, since C has no concept of it.
#[repr(C)]
#[derive(Clone, Copy, Debug, Eq, PartialEq, PartialOrd, Ord)]
pub enum Tristate {
	/// The operation has failed in a manner that cannot be communicated across
	/// the FFI boundary.
	Error = -1,
	/// The operation has succeeded, and returned `bool::false`.
	False = 0,
	/// The operation has succeeded, and returned `bool::true`.
	True = 1,
}

impl From<bool> for Tristate {
	fn from(bit: bool) -> Self {
		if bit { Tristate::True }
		else { Tristate::False }
	}
}

impl From<Option<bool>> for Tristate {
	fn from(opt: Option<bool>) -> Self {
		opt.map(Tristate::from).unwrap_or(Tristate::Error)
	}
}

/// Wrapper for a client-provided cursor function.
pub struct FfiCursor {
	/// A function which implements a total map of `u8 -> u8`.
	at: fn(u8) -> u8,
}

/// Global instance of the foreign cursor.
static mut FFI_CURSOR: Option<FfiCursor> = None;
/// Use flag for the cursor
static FFI_CURSOR_FLAG: AtomicBool = AtomicBool::new(false);

impl Cursor for FfiCursor {
	const TYPENAME: &'static str = "FFI_CURSOR";

	fn at<T: Bits>(idx: BitIdx) -> BitPos {
		assert!(
			*idx < T::SIZE,
			"FFI CURSOR FAILURE: Index out of range: {} overflows {}",
			*idx,
			T::SIZE,
		);
		unsafe {
			while FFI_CURSOR_FLAG.compare_and_swap(false, true, Ordering::SeqCst) {}
			let out = if let Some(ref fc) = FFI_CURSOR {
				(fc.at)(idx.into()).into()
			}
			else {
				BitPos::from(*idx)
			};
			FFI_CURSOR_FLAG.store(false, Ordering::SeqCst);
			out
		}
	}
}

/// Set the global foreign cursor to a provided map function.
///
/// # Params
///
/// - `func: Option<fn(u8) -> u8>`: Address of a function to use for the cursor.
///   This function must be total and unique for all values in `u8`.
///
/// # Locks
///
/// Spinlocks if `FFI_CURSOR_FLAG` was `true` on entry, until it becomes
/// `false`. Sets it to `true` before modifying `FFI_CURSOR` and sets it back to
/// `false` afterward.
#[no_mangle]
pub unsafe extern "C" fn bitvec_set_ffi_cursor(func: Option<fn(u8) -> u8>) {
	while FFI_CURSOR_FLAG.compare_and_swap(false, true, Ordering::SeqCst) {}
	FFI_CURSOR = func.map(|func| FfiCursor { at: func });
	FFI_CURSOR_FLAG.store(false, Ordering::SeqCst);
}

pub mod boxed;
pub mod slice;
pub mod vec;
