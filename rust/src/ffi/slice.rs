/*! FFI Entry for `BitSlice<C, T>`.

# Levels of Pointer Indirection

`BitSlice<_, _>` is an unsized type that describes a region of memory. It can
never be held directly. It must always be held by either a reference or pointer
handle. These are always two words wide, and are a concretely holdable
structure.

References have lifetimes, which cannot be communicated across the FFI boundary.

`*const BitSlice<_, _>` is equivalent to `&BitSlice<_, _>`: it is a two-word
handle with (mangled) pointer and length fields.

`*const *const BitSlice<_, _>` is a pointer to a `&BitSlice<_, _>`. It is one
word in size.

In order to avoid large-value annoyances in the FFI ABI boundary, values larger
than a CPU word will always be passed by pointer. Since the `*const BitSlice`
handle is two words, it will always be passed by two layers of pointer.

# Levels of Mutability

`*const *mut BitSlice<_, _>` is a pointer to an *immutable* handle – the region
of memory cannot have its boundaries changed – of *mutable* data – the bits in
the region can have their values changed.

`*mut *const BitSlice<_, _>` is a pointer to a *mutable* handle – the region of
memory can have its boundaries changed – of *immutable* data – the bits in the
region cannot be set to different values.
!*/

use super::{
	Tristate,
};
use crate::{
	BigEndian,
	BitPtr,
	BitSlice,
	LittleEndian,
};
use core::ptr;

/** Initializes a slice handle to be the empty slice.

# Parameters

- `this: *mut *const BitSlice<LittleEndian, u64>`: Pointer to an *uninitialized*
  handle.

# Modifies

The handle to which `this` points will be modified to be a handle over the empty
slice.

# Safety

If `this` is `null`, then the function will return without doing any
initialization.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b08_empty(this: *mut *const BitSlice<BigEndian, u8>) {
	nullck!(this);
	ptr::write(this, BitSlice::empty());
}
/** Initializes a slice handle to be the empty slice.

# Parameters

- `this: *mut *const BitSlice<LittleEndian, u64>`: Pointer to an *uninitialized*
  handle.

# Modifies

The handle to which `this` points will be modified to be a handle over the empty
slice.

# Safety

If `this` is `null`, then the function will return without doing any
initialization.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l08_empty(this: *mut *const BitSlice<LittleEndian, u8>) {
	nullck!(this);
	ptr::write(this, BitSlice::empty());
}
/** Initializes a slice handle to be the empty slice.

# Parameters

- `this: *mut *const BitSlice<LittleEndian, u64>`: Pointer to an *uninitialized*
  handle.

# Modifies

The handle to which `this` points will be modified to be a handle over the empty
slice.

# Safety

If `this` is `null`, then the function will return without doing any
initialization.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b16_empty(this: *mut *const BitSlice<BigEndian, u16>) {
	nullck!(this);
	ptr::write(this, BitSlice::empty());
}
/** Initializes a slice handle to be the empty slice.

# Parameters

- `this: *mut *const BitSlice<LittleEndian, u64>`: Pointer to an *uninitialized*
  handle.

# Modifies

The handle to which `this` points will be modified to be a handle over the empty
slice.

# Safety

If `this` is `null`, then the function will return without doing any
initialization.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l16_empty(this: *mut *const BitSlice<LittleEndian, u16>) {
	nullck!(this);
	ptr::write(this, BitSlice::empty());
}
/** Initializes a slice handle to be the empty slice.

# Parameters

- `this: *mut *const BitSlice<LittleEndian, u64>`: Pointer to an *uninitialized*
  handle.

# Modifies

The handle to which `this` points will be modified to be a handle over the empty
slice.

# Safety

If `this` is `null`, then the function will return without doing any
initialization.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b32_empty(this: *mut *const BitSlice<BigEndian, u32>) {
	nullck!(this);
	ptr::write(this, BitSlice::empty());
}
/** Initializes a slice handle to be the empty slice.

# Parameters

- `this: *mut *const BitSlice<LittleEndian, u64>`: Pointer to an *uninitialized*
  handle.

# Modifies

The handle to which `this` points will be modified to be a handle over the empty
slice.

# Safety

If `this` is `null`, then the function will return without doing any
initialization.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l32_empty(this: *mut *const BitSlice<LittleEndian, u32>) {
	nullck!(this);
	ptr::write(this, BitSlice::empty());
}
/** Initializes a slice handle to be the empty slice.

# Parameters

- `this: *mut *const BitSlice<LittleEndian, u64>`: Pointer to an *uninitialized*
  handle.

# Modifies

The handle to which `this` points will be modified to be a handle over the empty
slice.

# Safety

If `this` is `null`, then the function will return without doing any
initialization.
**/
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b64_empty(this: *mut *const BitSlice<BigEndian, u64>) {
	nullck!(this);
	ptr::write(this, BitSlice::empty());
}
/** Initializes a slice handle to be the empty slice.

# Parameters

- `this: *mut *const BitSlice<LittleEndian, u64>`: Pointer to an *uninitialized*
  handle.

# Modifies

The handle to which `this` points will be modified to be a handle over the empty
slice.

# Safety

If `this` is `null`, then the function will return without doing any
initialization.
**/
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l64_empty(this: *mut *const BitSlice<LittleEndian, u64>) {
	nullck!(this);
	ptr::write(this, BitSlice::empty());
}

/** Initializes a slice handle to be the empty slice.

This function behaves identically to the corresponding `empty`; the only
difference is in the mutability of the span behind the handle.

# Parameters

- `this: *mut *mut BitSlice<LittleEndian, u64>`: Pointer to an *uninitialized*
  handle.

# Modifies

The handle to which `this` points will be modified to be a handle over the empty
slice.

# Safety

If `this` is `null`, then the function will return without doing any
initialization.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b08_empty_mut(this: *mut *mut BitSlice<BigEndian, u8>) {
	nullck!(this);
	ptr::write(this, BitSlice::empty_mut());
}
/** Initializes a slice handle to be the empty slice.

This function behaves identically to the corresponding `empty`; the only
difference is in the mutability of the span behind the handle.

# Parameters

- `this: *mut *mut BitSlice<LittleEndian, u64>`: Pointer to an *uninitialized*
  handle.

# Modifies

The handle to which `this` points will be modified to be a handle over the empty
slice.

# Safety

If `this` is `null`, then the function will return without doing any
initialization.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l08_empty_mut(this: *mut *mut BitSlice<LittleEndian, u8>) {
	nullck!(this);
	ptr::write(this, BitSlice::empty_mut());
}
/** Initializes a slice handle to be the empty slice.

This function behaves identically to the corresponding `empty`; the only
difference is in the mutability of the span behind the handle.

# Parameters

- `this: *mut *mut BitSlice<LittleEndian, u64>`: Pointer to an *uninitialized*
  handle.

# Modifies

The handle to which `this` points will be modified to be a handle over the empty
slice.

# Safety

If `this` is `null`, then the function will return without doing any
initialization.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b16_empty_mut(this: *mut *mut BitSlice<BigEndian, u16>) {
	nullck!(this);
	ptr::write(this, BitSlice::empty_mut());
}
/** Initializes a slice handle to be the empty slice.

This function behaves identically to the corresponding `empty`; the only
difference is in the mutability of the span behind the handle.

# Parameters

- `this: *mut *mut BitSlice<LittleEndian, u64>`: Pointer to an *uninitialized*
  handle.

# Modifies

The handle to which `this` points will be modified to be a handle over the empty
slice.

# Safety

If `this` is `null`, then the function will return without doing any
initialization.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l16_empty_mut(this: *mut *mut BitSlice<LittleEndian, u16>) {
	nullck!(this);
	ptr::write(this, BitSlice::empty_mut());
}
/** Initializes a slice handle to be the empty slice.

This function behaves identically to the corresponding `empty`; the only
difference is in the mutability of the span behind the handle.

# Parameters

- `this: *mut *mut BitSlice<LittleEndian, u64>`: Pointer to an *uninitialized*
  handle.

# Modifies

The handle to which `this` points will be modified to be a handle over the empty
slice.

# Safety

If `this` is `null`, then the function will return without doing any
initialization.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b32_empty_mut(this: *mut *mut BitSlice<BigEndian, u32>) {
	nullck!(this);
	ptr::write(this, BitSlice::empty_mut());
}
/** Initializes a slice handle to be the empty slice.

This function behaves identically to the corresponding `empty`; the only
difference is in the mutability of the span behind the handle.

# Parameters

- `this: *mut *mut BitSlice<LittleEndian, u64>`: Pointer to an *uninitialized*
  handle.

# Modifies

The handle to which `this` points will be modified to be a handle over the empty
slice.

# Safety

If `this` is `null`, then the function will return without doing any
initialization.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l32_empty_mut(this: *mut *mut BitSlice<LittleEndian, u32>) {
	nullck!(this);
	ptr::write(this, BitSlice::empty_mut());
}
/** Initializes a slice handle to be the empty slice.

This function behaves identically to the corresponding `empty`; the only
difference is in the mutability of the span behind the handle.

# Parameters

- `this: *mut *mut BitSlice<LittleEndian, u64>`: Pointer to an *uninitialized*
  handle.

# Modifies

The handle to which `this` points will be modified to be a handle over the empty
slice.

# Safety

If `this` is `null`, then the function will return without doing any
initialization.
**/
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b64_empty_mut(this: *mut *mut BitSlice<BigEndian, u64>) {
	nullck!(this);
	ptr::write(this, BitSlice::empty_mut());
}
/** Initializes a slice handle to be the empty slice.

This function behaves identically to the corresponding `empty`; the only
difference is in the mutability of the span behind the handle.

# Parameters

- `this: *mut *mut BitSlice<LittleEndian, u64>`: Pointer to an *uninitialized*
  handle.

# Modifies

The handle to which `this` points will be modified to be a handle over the empty
slice.

# Safety

If `this` is `null`, then the function will return without doing any
initialization.
**/
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l64_empty_mut(this: *mut *mut BitSlice<LittleEndian, u64>) {
	nullck!(this);
	ptr::write(this, BitSlice::empty_mut());
}

/** Initializes a slice handle from a provided span pointer and element count.

# Parameters

- `this: *mut *const BitSlice<BigEndian, u8>`: Write-pointer to an
  *uninitialized* `BitSlice` handle. After this function succeeds, the handle
  will be initialized according to the provided span arguments.
- `ptr: *const u8`: Pointer to the region of memory over which `*this` will
  govern after initialization.
- `len: usize`: Count of `u8` elements in the region to which `ptr` points.

# Returns

`bool` of `true` if `*this` is initialized or `false` if initialization
failed. Failure reasons are not communicated across the FFI boundary.

# Panics

The internal function called to initialize `*this` *may* panic if its
arguments are invalid. As of Rust `1.24`, FFI boundary functions no longer
include automatic `catch_unwind` guards which abort. Use of the FFI boundary
functions *requires* compiling with `panic = abort`.

# Safety

If this function is called with either `this` or `ptr` as `null`, it will
return `false` before dereferencing. If this is called with invalid
arguments, it will panic. This function does not catch any unwinding, so
panics **must** cause abort rather than allow an unwind across the FFI
boundary.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b08_from_span(
	this: *mut *const BitSlice<BigEndian, u8>,
	ptr: *const u8,
	len: usize,
) -> bool {
	bitvec_bs_b08_from_span_partial(this, ptr, len, 0, 8)
}
/** Initializes a slice handle from a provided span pointer and element count.

# Parameters

- `this: *mut *const BitSlice<LittleEndian, u8>`: Write-pointer to an
  *uninitialized* `BitSlice` handle. After this function succeeds, the handle
  will be initialized according to the provided span arguments.
- `ptr: *const u8`: Pointer to the region of memory over which `*this` will
  govern after initialization.
- `len: usize`: Count of `u8` elements in the region to which `ptr` points.

# Returns

`bool` of `true` if `*this` is initialized or `false` if initialization
failed. Failure reasons are not communicated across the FFI boundary.

# Panics

The internal function called to initialize `*this` *may* panic if its
arguments are invalid. As of Rust `1.24`, FFI boundary functions no longer
include automatic `catch_unwind` guards which abort. Use of the FFI boundary
functions *requires* compiling with `panic = abort`.

# Safety

If this function is called with either `this` or `ptr` as `null`, it will
return `false` before dereferencing. If this is called with invalid
arguments, it will panic. This function does not catch any unwinding, so
panics **must** cause abort rather than allow an unwind across the FFI
boundary.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l08_from_span(
	this: *mut *const BitSlice<LittleEndian, u8>,
	ptr: *const u8,
	len: usize,
) -> bool {
	bitvec_bs_l08_from_span_partial(this, ptr, len, 0, 8)
}
/** Initializes a slice handle from a provided span pointer and element count.

# Parameters

- `this: *mut *const BitSlice<BigEndian, u16>`: Write-pointer to an
  *uninitialized* `BitSlice` handle. After this function succeeds, the handle
  will be initialized according to the provided span arguments.
- `ptr: *const u`16: Pointer to the region of memory over which `*this` will
  govern after initialization.
- `len: usize`: Count of `u16` *elements* (not bytes) in the region to which
`ptr` points.

# Returns

`bool` of `true` if `*this` is initialized or `false` if initialization
failed. Failure reasons are not communicated across the FFI boundary.

# Panics

The internal function called to initialize `*this` *may* panic if its
arguments are invalid. As of Rust `1.24`, FFI boundary functions no longer
include automatic `catch_unwind` guards which abort. Use of the FFI boundary
functions *requires* compiling with `panic = abort`.

# Safety

If this function is called with either `this` or `ptr` as `null`, it will
return `false` before dereferencing. If this is called with invalid
arguments, it will panic. This function does not catch any unwinding, so
panics **must** cause abort rather than allow unwinding to cross the FFI
boundary.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b16_from_span(
	this: *mut *const BitSlice<BigEndian, u16>,
	ptr: *const u16,
	len: usize,
) -> bool {
	bitvec_bs_b16_from_span_partial(this, ptr, len, 0, 16)
}
/** Initializes a slice handle from a provided span pointer and element count.

# Parameters

- `this: *mut *const BitSlice<LittleEndian, u16>`: Write-pointer to an
  *uninitialized* `BitSlice` handle. After this function succeeds, the handle
  will be initialized according to the provided span arguments.
- `ptr: *const u`16: Pointer to the region of memory over which `*this` will
  govern after initialization.
- `len: usize`: Count of `u16` *elements* (not bytes) in the region to which
`ptr` points.

# Returns

`bool` of `true` if `*this` is initialized or `false` if initialization
failed. Failure reasons are not communicated across the FFI boundary.

# Panics

The internal function called to initialize `*this` *may* panic if its
arguments are invalid. As of Rust `1.24`, FFI boundary functions no longer
include automatic `catch_unwind` guards which abort. Use of the FFI boundary
functions *requires* compiling with `panic = abort`.

# Safety

If this function is called with either `this` or `ptr` as `null`, it will
return `false` before dereferencing. If this is called with invalid
arguments, it will panic. This function does not catch any unwinding, so
panics **must** cause abort rather than allow unwinding to cross the FFI
boundary.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l16_from_span(
	this: *mut *const BitSlice<LittleEndian, u16>,
	ptr: *const u16,
	len: usize,
) -> bool {
	bitvec_bs_l16_from_span_partial(this, ptr, len, 0, 16)
}
/** Initializes a slice handle from a provided span pointer and element count.

# Parameters

- `this: *mut *const BitSlice<BigEndian, u32>`: Write-pointer to an
  *uninitialized* `BitSlice` handle. After this function succeeds, the handle
  will be initialized according to the provided span arguments.
- `ptr: *const u32`: Pointer to the region of memory over which `*this` will
  govern after initialization.
- `len: usize`: Count of `u32` *elements* (not bytes) in the region to which
`ptr` points.

# Returns

`bool` of `true` if `*this` is initialized or `false` if initialization
failed. Failure reasons are not communicated across the FFI boundary.

# Panics

The internal function called to initialize `*this` *may* panic if its
arguments are invalid. As of Rust `1.24`, FFI boundary functions no longer
include automatic `catch_unwind` guards which abort. Use of the FFI boundary
functions *requires* compiling with `panic = abort`.

# Safety

If this function is called with either `this` or `ptr` as `null`, it will
return `false` before dereferencing. If this is called with invalid
arguments, it will panic. This function does not catch any unwinding, so
panics **must** cause abort rather than allow unwinding to cross the FFI
boundary.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b32_from_span(
	this: *mut *const BitSlice<BigEndian, u32>,
	ptr: *const u32,
	len: usize,
) -> bool {
	bitvec_bs_b32_from_span_partial(this, ptr, len, 0, 32)
}
/** Initializes a slice handle from a provided span pointer and element count.

# Parameters

- `this: *mut *const BitSlice<LittleEndian, u32>`: Write-pointer to an
  *uninitialized* `BitSlice` handle. After this function succeeds, the handle
  will be initialized according to the provided span arguments.
- `ptr: *const u32`: Pointer to the region of memory over which `*this` will
  govern after initialization.
- `len: usize`: Count of `u32` *elements* (not bytes) in the region to which
`ptr` points.

# Returns

`bool` of `true` if `*this` is initialized or `false` if initialization
failed. Failure reasons are not communicated across the FFI boundary.

# Panics

The internal function called to initialize `*this` *may* panic if its
arguments are invalid. As of Rust `1.24`, FFI boundary functions no longer
include automatic `catch_unwind` guards which abort. Use of the FFI boundary
functions *requires* compiling with `panic = abort`.

# Safety

If this function is called with either `this` or `ptr` as `null`, it will
return `false` before dereferencing. If this is called with invalid
arguments, it will panic. This function does not catch any unwinding, so
panics **must** cause abort rather than allow unwinding to cross the FFI
boundary.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l32_from_span(
	this: *mut *const BitSlice<LittleEndian, u32>,
	ptr: *const u32,
	len: usize,
) -> bool {
	bitvec_bs_l32_from_span_partial(this, ptr, len, 0, 32)
}
/** Initializes a slice handle from a provided span pointer and element count.

# Parameters

- `this: *mut *const BitSlice<BigEndian, u64>`: Write-pointer to an
  *uninitialized* `BitSlice` handle. After this function succeeds, the handle
  will be initialized according to the provided span arguments.
- `ptr: *const u64`: Pointer to the region of memory over which `*this` will
  govern after initialization.
- `len: usize`: Count of `u64` *elements* (not bytes) in the region to which
`ptr` points.

# Returns

`bool` of `true` if `*this` is initialized or `false` if initialization
failed. Failure reasons are not communicated across the FFI boundary.

# Panics

The internal function called to initialize `*this` *may* panic if its
arguments are invalid. As of Rust `1.24`, FFI boundary functions no longer
include automatic `catch_unwind` guards which abort. Use of the FFI boundary
functions *requires* compiling with `panic = abort`.

# Safety

If this function is called with either `this` or `ptr` as `null`, it will
return `false` before dereferencing. If this is called with invalid
arguments, it will panic. This function does not catch any unwinding, so
panics **must** cause abort rather than allow unwinding to cross the FFI
boundary.
**/
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b64_from_span(
	this: *mut *const BitSlice<BigEndian, u64>,
	ptr: *const u64,
	len: usize,
) -> bool {
	bitvec_bs_b64_from_span_partial(this, ptr, len, 0, 64)
}
/** Initializes a slice handle from a provided span pointer and element count.

# Parameters

- `this: *mut *const BitSlice<LittleEndian, u64>`: Write-pointer to an
  *uninitialized* `BitSlice` handle. After this function succeeds, the handle
  will be initialized according to the provided span arguments.
- `ptr: *const u64`: Pointer to the region of memory over which `*this` will
  govern after initialization.
- `len: usize`: Count of `u64` *elements* (not bytes) in the region to which
`ptr` points.

# Returns

`bool` of `true` if `*this` is initialized or `false` if initialization
failed. Failure reasons are not communicated across the FFI boundary.

# Panics

The internal function called to initialize `*this` *may* panic if its
arguments are invalid. As of Rust `1.24`, FFI boundary functions no longer
include automatic `catch_unwind` guards which abort. Use of the FFI boundary
functions *requires* compiling with `panic = abort`.

# Safety

If this function is called with either `this` or `ptr` as `null`, it will
return `false` before dereferencing. If this is called with invalid
arguments, it will panic. This function does not catch any unwinding, so
panics **must** cause abort rather than allow unwinding to cross the FFI
boundary.
**/
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l64_from_span(
	this: *mut *const BitSlice<LittleEndian, u64>,
	ptr: *const u64,
	len: usize,
) -> bool {
	bitvec_bs_l64_from_span_partial(this, ptr, len, 0, 64)
}

/** Initializes a slice handle from a provided span pointer and element count.

# Parameters

- `this: *mut *const BitSlice<BigEndian, u8>`: Write-pointer to an
  *uninitialized* `BitSlice` handle. After this function succeeds, the handle
  will be initialized according to the provided span arguments.
- `ptr: *const u8`: Pointer to the region of memory over which `*this` will
  govern after initialization.
- `len: usize`: Count of `u8` elements in the region to which `ptr` points.

# Returns

`bool` of `true` if `*this` is initialized or `false` if initialization
failed. Failure reasons are not communicated across the FFI boundary.

# Panics

The internal function called to initialize `*this` *may* panic if its
arguments are invalid. As of Rust `1.24`, FFI boundary functions no longer
include automatic `catch_unwind` guards which abort. Use of the FFI boundary
functions *requires* compiling with `panic = abort`.

# Safety

If this function is called with either `this` or `ptr` as `null`, it will
return `false` before dereferencing. If this is called with invalid
arguments, it will panic. This function does not catch any unwinding, so
panics **must** cause abort rather than allow an unwind across the FFI
boundary.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b08_from_span_mut(
	this: *mut *mut BitSlice<BigEndian, u8>,
	ptr: *mut u8,
	len: usize,
) -> bool {
	bitvec_bs_b08_from_span_partial_mut(this, ptr, len, 0, 8)
}
/** Initializes a slice handle from a provided span pointer and element count.

# Parameters

- `this: *mut *const BitSlice<LittleEndian, u8>`: Write-pointer to an
  *uninitialized* `BitSlice` handle. After this function succeeds, the handle
  will be initialized according to the provided span arguments.
- `ptr: *const u8`: Pointer to the region of memory over which `*this` will
  govern after initialization.
- `len: usize`: Count of `u8` elements in the region to which `ptr` points.

# Returns

`bool` of `true` if `*this` is initialized or `false` if initialization
failed. Failure reasons are not communicated across the FFI boundary.

# Panics

The internal function called to initialize `*this` *may* panic if its
arguments are invalid. As of Rust `1.24`, FFI boundary functions no longer
include automatic `catch_unwind` guards which abort. Use of the FFI boundary
functions *requires* compiling with `panic = abort`.

# Safety

If this function is called with either `this` or `ptr` as `null`, it will
return `false` before dereferencing. If this is called with invalid
arguments, it will panic. This function does not catch any unwinding, so
panics **must** cause abort rather than allow an unwind across the FFI
boundary.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l08_from_span_mut(
	this: *mut *mut BitSlice<LittleEndian, u8>,
	ptr: *mut u8,
	len: usize,
) -> bool {
	bitvec_bs_l08_from_span_partial_mut(this, ptr, len, 0, 8)
}
/** Initializes a slice handle from a provided span pointer and element count.

# Parameters

- `this: *mut *const BitSlice<BigEndian, u16>`: Write-pointer to an
  *uninitialized* `BitSlice` handle. After this function succeeds, the handle
  will be initialized according to the provided span arguments.
- `ptr: *const u`16: Pointer to the region of memory over which `*this` will
  govern after initialization.
- `len: usize`: Count of `u16` *elements* (not bytes) in the region to which
`ptr` points.

# Returns

`bool` of `true` if `*this` is initialized or `false` if initialization
failed. Failure reasons are not communicated across the FFI boundary.

# Panics

The internal function called to initialize `*this` *may* panic if its
arguments are invalid. As of Rust `1.24`, FFI boundary functions no longer
include automatic `catch_unwind` guards which abort. Use of the FFI boundary
functions *requires* compiling with `panic = abort`.

# Safety

If this function is called with either `this` or `ptr` as `null`, it will
return `false` before dereferencing. If this is called with invalid
arguments, it will panic. This function does not catch any unwinding, so
panics **must** cause abort rather than allow unwinding to cross the FFI
boundary.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b16_from_span_mut(
	this: *mut *mut BitSlice<BigEndian, u16>,
	ptr: *mut u16,
	len: usize,
) -> bool {
	bitvec_bs_b16_from_span_partial_mut(this, ptr, len, 0, 16)
}
/** Initializes a slice handle from a provided span pointer and element count.

# Parameters

- `this: *mut *const BitSlice<LittleEndian, u16>`: Write-pointer to an
  *uninitialized* `BitSlice` handle. After this function succeeds, the handle
  will be initialized according to the provided span arguments.
- `ptr: *const u`16: Pointer to the region of memory over which `*this` will
  govern after initialization.
- `len: usize`: Count of `u16` *elements* (not bytes) in the region to which
`ptr` points.

# Returns

`bool` of `true` if `*this` is initialized or `false` if initialization
failed. Failure reasons are not communicated across the FFI boundary.

# Panics

The internal function called to initialize `*this` *may* panic if its
arguments are invalid. As of Rust `1.24`, FFI boundary functions no longer
include automatic `catch_unwind` guards which abort. Use of the FFI boundary
functions *requires* compiling with `panic = abort`.

# Safety

If this function is called with either `this` or `ptr` as `null`, it will
return `false` before dereferencing. If this is called with invalid
arguments, it will panic. This function does not catch any unwinding, so
panics **must** cause abort rather than allow unwinding to cross the FFI
boundary.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l16_from_span_mut(
	this: *mut *mut BitSlice<LittleEndian, u16>,
	ptr: *mut u16,
	len: usize,
) -> bool {
	bitvec_bs_l16_from_span_partial_mut(this, ptr, len, 0, 16)
}
/** Initializes a slice handle from a provided span pointer and element count.

# Parameters

- `this: *mut *const BitSlice<BigEndian, u32>`: Write-pointer to an
  *uninitialized* `BitSlice` handle. After this function succeeds, the handle
  will be initialized according to the provided span arguments.
- `ptr: *const u32`: Pointer to the region of memory over which `*this` will
  govern after initialization.
- `len: usize`: Count of `u32` *elements* (not bytes) in the region to which
`ptr` points.

# Returns

`bool` of `true` if `*this` is initialized or `false` if initialization
failed. Failure reasons are not communicated across the FFI boundary.

# Panics

The internal function called to initialize `*this` *may* panic if its
arguments are invalid. As of Rust `1.24`, FFI boundary functions no longer
include automatic `catch_unwind` guards which abort. Use of the FFI boundary
functions *requires* compiling with `panic = abort`.

# Safety

If this function is called with either `this` or `ptr` as `null`, it will
return `false` before dereferencing. If this is called with invalid
arguments, it will panic. This function does not catch any unwinding, so
panics **must** cause abort rather than allow unwinding to cross the FFI
boundary.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b32_from_span_mut(
	this: *mut *mut BitSlice<BigEndian, u32>,
	ptr: *mut u32,
	len: usize,
) -> bool {
	bitvec_bs_b32_from_span_partial_mut(this, ptr, len, 0, 32)
}
/** Initializes a slice handle from a provided span pointer and element count.

# Parameters

- `this: *mut *const BitSlice<LittleEndian, u32>`: Write-pointer to an
  *uninitialized* `BitSlice` handle. After this function succeeds, the handle
  will be initialized according to the provided span arguments.
- `ptr: *const u32`: Pointer to the region of memory over which `*this` will
  govern after initialization.
- `len: usize`: Count of `u32` *elements* (not bytes) in the region to which
`ptr` points.

# Returns

`bool` of `true` if `*this` is initialized or `false` if initialization
failed. Failure reasons are not communicated across the FFI boundary.

# Panics

The internal function called to initialize `*this` *may* panic if its
arguments are invalid. As of Rust `1.24`, FFI boundary functions no longer
include automatic `catch_unwind` guards which abort. Use of the FFI boundary
functions *requires* compiling with `panic = abort`.

# Safety

If this function is called with either `this` or `ptr` as `null`, it will
return `false` before dereferencing. If this is called with invalid
arguments, it will panic. This function does not catch any unwinding, so
panics **must** cause abort rather than allow unwinding to cross the FFI
boundary.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l32_from_span_mut(
	this: *mut *mut BitSlice<LittleEndian, u32>,
	ptr: *mut u32,
	len: usize,
) -> bool {
	bitvec_bs_l32_from_span_partial_mut(this, ptr, len, 0, 32)
}
/** Initializes a slice handle from a provided span pointer and element count.

# Parameters

- `this: *mut *const BitSlice<BigEndian, u64>`: Write-pointer to an
  *uninitialized* `BitSlice` handle. After this function succeeds, the handle
  will be initialized according to the provided span arguments.
- `ptr: *const u64`: Pointer to the region of memory over which `*this` will
  govern after initialization.
- `len: usize`: Count of `u64` *elements* (not bytes) in the region to which
`ptr` points.

# Returns

`bool` of `true` if `*this` is initialized or `false` if initialization
failed. Failure reasons are not communicated across the FFI boundary.

# Panics

The internal function called to initialize `*this` *may* panic if its
arguments are invalid. As of Rust `1.24`, FFI boundary functions no longer
include automatic `catch_unwind` guards which abort. Use of the FFI boundary
functions *requires* compiling with `panic = abort`.

# Safety

If this function is called with either `this` or `ptr` as `null`, it will
return `false` before dereferencing. If this is called with invalid
arguments, it will panic. This function does not catch any unwinding, so
panics **must** cause abort rather than allow unwinding to cross the FFI
boundary.
**/
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b64_from_span_mut(
	this: *mut *mut BitSlice<BigEndian, u64>,
	ptr: *mut u64,
	len: usize,
) -> bool {
	bitvec_bs_b64_from_span_partial_mut(this, ptr, len, 0, 64)
}
/** Initializes a slice handle from a provided span pointer and element count.

# Parameters

- `this: *mut *const BitSlice<LittleEndian, u64>`: Write-pointer to an
  *uninitialized* `BitSlice` handle. After this function succeeds, the handle
  will be initialized according to the provided span arguments.
- `ptr: *const u64`: Pointer to the region of memory over which `*this` will
  govern after initialization.
- `len: usize`: Count of `u64` *elements* (not bytes) in the region to which
`ptr` points.

# Returns

`bool` of `true` if `*this` is initialized or `false` if initialization
failed. Failure reasons are not communicated across the FFI boundary.

# Panics

The internal function called to initialize `*this` *may* panic if its
arguments are invalid. As of Rust `1.24`, FFI boundary functions no longer
include automatic `catch_unwind` guards which abort. Use of the FFI boundary
functions *requires* compiling with `panic = abort`.

# Safety

If this function is called with either `this` or `ptr` as `null`, it will
return `false` before dereferencing. If this is called with invalid
arguments, it will panic. This function does not catch any unwinding, so
panics **must** cause abort rather than allow unwinding to cross the FFI
boundary.
**/
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l64_from_span_mut(
	this: *mut *mut BitSlice<LittleEndian, u64>,
	ptr: *mut u64,
	len: usize,
) -> bool {
	bitvec_bs_l64_from_span_partial_mut(this, ptr, len, 0, 64)
}

/** Initializes a slice handle from provided span details.

# Parameters

- `this: *mut *const BitSlice<BigEndian, u8>`: Write-pointer to an
  *uninitialized* `BitSlice` handle. After this function succeeds, the handle
  will be initialized according to the provided span arguments.
- `ptr: *const u8`: Pointer to the region of memory over which `*this` will
  govern after initialization.
- `len: usize`: Count of `u8` *elements* in the region to which `ptr` points.
- `head: u8`: Index of the first live bit in the first element of the slice.
- `tail: u8`: Indef of the first dead bit in the last element of the slice.

# Returns

`bool` of `true` if `*this` is initialized or `false` if initialization failed.
Failure reasons are not communicated across the FFI boundary.

# Panics

The internal function called to initialize `*this` *may* panic if its arguments
are invalid. As of Rust `1.24`, FFI boundary functions no longer include
automatic `catch_unwind` guards which abort. Use of the FFI boundary functions
*requires* compiling with `panic = abort`.

# Safety

If this function is called with either `this` or `ptr` as `null`, it will return
`false` before dereferencing. If this is called with invalid arguments, it will
panic. this function does not catch any unwinding, so panics **must** cause
abort rather than allow unwinding to cross the FFI boundary.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b08_from_span_partial(
	this: *mut *const BitSlice<BigEndian, u8>,
	ptr: *const u8,
	len: usize,
	head: u8,
	tail: u8,
) -> bool {
	nullck!(this, ptr => false);
	let bitslice: &BitSlice<_, _> = BitPtr::new(ptr, len, head, tail).into();
	ptr::write(this, bitslice);
	true
}
/** Initializes a slice handle from provided span details.

# Parameters

- `this: *mut *const BitSlice<LittleEndian, u8>`: Write-pointer to an
  *uninitialized* `BitSlice` handle. After this function succeeds, the handle
  will be initialized according to the provided span arguments.
- `ptr: *const u8`: Pointer to the region of memory over which `*this` will
  govern after initialization.
- `len: usize`: Count of `u8` *elements* in the region to which `ptr` points.
- `head: u8`: Index of the first live bit in the first element of the slice.
- `tail: u8`: Indef of the first dead bit in the last element of the slice.

# Returns

`bool` of `true` if `*this` is initialized or `false` if initialization failed.
Failure reasons are not communicated across the FFI boundary.

# Panics

The internal function called to initialize `*this` *may* panic if its arguments
are invalid. As of Rust `1.24`, FFI boundary functions no longer include
automatic `catch_unwind` guards which abort. Use of the FFI boundary functions
*requires* compiling with `panic = abort`.

# Safety

If this function is called with either `this` or `ptr` as `null`, it will return
`false` before dereferencing. If this is called with invalid arguments, it will
panic. this function does not catch any unwinding, so panics **must** cause
abort rather than allow unwinding to cross the FFI boundary.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l08_from_span_partial(
	this: *mut *const BitSlice<LittleEndian, u8>,
	ptr: *const u8,
	len: usize,
	head: u8,
	tail: u8,
) -> bool {
	nullck!(this, ptr => false);
	let bitslice: &BitSlice<_, _> = BitPtr::new(ptr, len, head, tail).into();
	ptr::write(this, bitslice);
	true
}
/** Initializes a slice handle from provided span details.

# Parameters

- `this: *mut *const BitSlice<BigEndian, u16>`: Write-pointer to an
  *uninitialized* `BitSlice` handle. After this function succeeds, the handle
  will be initialized according to the provided span arguments.
- `ptr: *const u16`: Pointer to the region of memory over which `*this` will
  govern after initialization.
- `len: usize`: Count of `u16` *elements* (not bytes) in the region to which
  `ptr` points.
- `head: u8`: Index of the first live bit in the first element of the slice.
- `tail: u8`: Indef of the first dead bit in the last element of the slice.

# Returns

`bool` of `true` if `*this` is initialized or `false` if initialization failed.
Failure reasons are not communicated across the FFI boundary.

# Panics

The internal function called to initialize `*this` *may* panic if its arguments
are invalid. As of Rust `1.24`, FFI boundary functions no longer include
automatic `catch_unwind` guards which abort. Use of the FFI boundary functions
*requires* compiling with `panic = abort`.

# Safety

If this function is called with either `this` or `ptr` as `null`, it will return
`false` before dereferencing. If this is called with invalid arguments, it will
panic. this function does not catch any unwinding, so panics **must** cause
abort rather than allow unwinding to cross the FFI boundary.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b16_from_span_partial(
	this: *mut *const BitSlice<BigEndian, u16>,
	ptr: *const u16,
	len: usize,
	head: u8,
	tail: u8,
) -> bool {
	nullck!(this, ptr => false);
	let bitslice: &BitSlice<_, _> = BitPtr::new(ptr, len, head, tail).into();
	ptr::write(this, bitslice);
	true
}
/** Initializes a slice handle from provided span details.

# Parameters

- `this: *mut *const BitSlice<LittleEndian, u16>`: Write-pointer to an
  *uninitialized* `BitSlice` handle. After this function succeeds, the handle
  will be initialized according to the provided span arguments.
- `ptr: *const u16`: Pointer to the region of memory over which `*this` will
  govern after initialization.
- `len: usize`: Count of `u16` *elements* (not bytes) in the region to which
  `ptr` points.
- `head: u8`: Index of the first live bit in the first element of the slice.
- `tail: u8`: Indef of the first dead bit in the last element of the slice.

# Returns

`bool` of `true` if `*this` is initialized or `false` if initialization failed.
Failure reasons are not communicated across the FFI boundary.

# Panics

The internal function called to initialize `*this` *may* panic if its arguments
are invalid. As of Rust `1.24`, FFI boundary functions no longer include
automatic `catch_unwind` guards which abort. Use of the FFI boundary functions
*requires* compiling with `panic = abort`.

# Safety

If this function is called with either `this` or `ptr` as `null`, it will return
`false` before dereferencing. If this is called with invalid arguments, it will
panic. this function does not catch any unwinding, so panics **must** cause
abort rather than allow unwinding to cross the FFI boundary.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l16_from_span_partial(
	this: *mut *const BitSlice<LittleEndian, u16>,
	ptr: *const u16,
	len: usize,
	head: u8,
	tail: u8,
) -> bool {
	nullck!(this, ptr => false);
	let bitslice: &BitSlice<_, _> = BitPtr::new(ptr, len, head, tail).into();
	ptr::write(this, bitslice);
	true
}
/** Initializes a slice handle from provided span details.

# Parameters

- `this: *mut *const BitSlice<BigEndian, u32>`: Write-pointer to an
  *uninitialized* `BitSlice` handle. After this function succeeds, the handle
  will be initialized according to the provided span arguments.
- `ptr: *const u32`: Pointer to the region of memory over which `*this` will
  govern after initialization.
- `len: usize`: Count of `u32` *elements* (not bytes) in the region to which
  `ptr` points.
- `head: u8`: Index of the first live bit in the first element of the slice.
- `tail: u8`: Indef of the first dead bit in the last element of the slice.

# Returns

`bool` of `true` if `*this` is initialized or `false` if initialization failed.
Failure reasons are not communicated across the FFI boundary.

# Panics

The internal function called to initialize `*this` *may* panic if its arguments
are invalid. As of Rust `1.24`, FFI boundary functions no longer include
automatic `catch_unwind` guards which abort. Use of the FFI boundary functions
*requires* compiling with `panic = abort`.

# Safety

If this function is called with either `this` or `ptr` as `null`, it will return
`false` before dereferencing. If this is called with invalid arguments, it will
panic. this function does not catch any unwinding, so panics **must** cause
abort rather than allow unwinding to cross the FFI boundary.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b32_from_span_partial(
	this: *mut *const BitSlice<BigEndian, u32>,
	ptr: *const u32,
	len: usize,
	head: u8,
	tail: u8,
) -> bool {
	nullck!(this, ptr => false);
	let bitslice: &BitSlice<_, _> = BitPtr::new(ptr, len, head, tail).into();
	ptr::write(this, bitslice);
	true
}
/** Initializes a slice handle from provided span details.

# Parameters

- `this: *mut *const BitSlice<LittleEndian, u32>`: Write-pointer to an
  *uninitialized* `BitSlice` handle. After this function succeeds, the handle
  will be initialized according to the provided span arguments.
- `ptr: *const u32`: Pointer to the region of memory over which `*this` will
  govern after initialization.
- `len: usize`: Count of `u32` *elements* (not bytes) in the region to which
  `ptr` points.
- `head: u8`: Index of the first live bit in the first element of the slice.
- `tail: u8`: Indef of the first dead bit in the last element of the slice.

# Returns

`bool` of `true` if `*this` is initialized or `false` if initialization failed.
Failure reasons are not communicated across the FFI boundary.

# Panics

The internal function called to initialize `*this` *may* panic if its arguments
are invalid. As of Rust `1.24`, FFI boundary functions no longer include
automatic `catch_unwind` guards which abort. Use of the FFI boundary functions
*requires* compiling with `panic = abort`.

# Safety

If this function is called with either `this` or `ptr` as `null`, it will return
`false` before dereferencing. If this is called with invalid arguments, it will
panic. this function does not catch any unwinding, so panics **must** cause
abort rather than allow unwinding to cross the FFI boundary.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l32_from_span_partial(
	this: *mut *const BitSlice<LittleEndian, u32>,
	ptr: *const u32,
	len: usize,
	head: u8,
	tail: u8,
) -> bool {
	nullck!(this, ptr => false);
	let bitslice: &BitSlice<_, _> = BitPtr::new(ptr, len, head, tail).into();
	ptr::write(this, bitslice);
	true
}
/** Initializes a slice handle from provided span details.

# Parameters

- `this: *mut *const BitSlice<BigEndian, u64>`: Write-pointer to an
  *uninitialized* `BitSlice` handle. After this function succeeds, the handle
  will be initialized according to the provided span arguments.
- `ptr: *const u64`: Pointer to the region of memory over which `*this` will
  govern after initialization.
- `len: usize`: Count of `u64` *elements* (not bytes) in the region to which
  `ptr` points.
- `head: u8`: Index of the first live bit in the first element of the slice.
- `tail: u8`: Indef of the first dead bit in the last element of the slice.

# Returns

`bool` of `true` if `*this` is initialized or `false` if initialization failed.
Failure reasons are not communicated across the FFI boundary.

# Panics

The internal function called to initialize `*this` *may* panic if its arguments
are invalid. As of Rust `1.24`, FFI boundary functions no longer include
automatic `catch_unwind` guards which abort. Use of the FFI boundary functions
*requires* compiling with `panic = abort`.

# Safety

If this function is called with either `this` or `ptr` as `null`, it will return
`false` before dereferencing. If this is called with invalid arguments, it will
panic. this function does not catch any unwinding, so panics **must** cause
abort rather than allow unwinding to cross the FFI boundary.
**/
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b64_from_span_partial(
	this: *mut *const BitSlice<BigEndian, u64>,
	ptr: *const u64,
	len: usize,
	head: u8,
	tail: u8,
) -> bool {
	nullck!(this, ptr => false);
	let bitslice: &BitSlice<_, _> = BitPtr::new(ptr, len, head, tail).into();
	ptr::write(this, bitslice);
	true
}
/** Initializes a slice handle from provided span details.

# Parameters

- `this: *mut *const BitSlice<LittleEndian, u64>`: Write-pointer to an
  *uninitialized* `BitSlice` handle. After this function succeeds, the handle
  will be initialized according to the provided span arguments.
- `ptr: *const u64`: Pointer to the region of memory over which `*this` will
  govern after initialization.
- `len: usize`: Count of `u64` *elements* (not bytes) in the region to which
  `ptr` points.
- `head: u8`: Index of the first live bit in the first element of the slice.
- `tail: u8`: Indef of the first dead bit in the last element of the slice.

# Returns

`bool` of `true` if `*this` is initialized or `false` if initialization failed.
Failure reasons are not communicated across the FFI boundary.

# Panics

The internal function called to initialize `*this` *may* panic if its arguments
are invalid. As of Rust `1.24`, FFI boundary functions no longer include
automatic `catch_unwind` guards which abort. Use of the FFI boundary functions
*requires* compiling with `panic = abort`.

# Safety

If this function is called with either `this` or `ptr` as `null`, it will return
`false` before dereferencing. If this is called with invalid arguments, it will
panic. this function does not catch any unwinding, so panics **must** cause
abort rather than allow unwinding to cross the FFI boundary.
**/
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l64_from_span_partial(
	this: *mut *const BitSlice<LittleEndian, u64>,
	ptr: *const u64,
	len: usize,
	head: u8,
	tail: u8,
) -> bool {
	nullck!(this, ptr => false);
	let bitslice: &BitSlice<_, _> = BitPtr::new(ptr, len, head, tail).into();
	ptr::write(this, bitslice);
	true
}
/** Initializes a slice handle from provided span details.

# Parameters

- `this: *mut *const BitSlice<BigEndian, u8>`: Write-pointer to an
  *uninitialized* `BitSlice` handle. After this function succeeds, the handle
  will be initialized according to the provided span arguments.
- `ptr: *const u8`: Pointer to the region of memory over which `*this` will
  govern after initialization.
- `len: usize`: Count of `u8` *elements* in the region to which `ptr` points.
- `head: u8`: Index of the first live bit in the first element of the slice.
- `tail: u8`: Indef of the first dead bit in the last element of the slice.

# Returns

`bool` of `true` if `*this` is initialized or `false` if initialization failed.
Failure reasons are not communicated across the FFI boundary.

# Panics

The internal function called to initialize `*this` *may* panic if its arguments
are invalid. As of Rust `1.24`, FFI boundary functions no longer include
automatic `catch_unwind` guards which abort. Use of the FFI boundary functions
*requires* compiling with `panic = abort`.

# Safety

If this function is called with either `this` or `ptr` as `null`, it will return
`false` before dereferencing. If this is called with invalid arguments, it will
panic. this function does not catch any unwinding, so panics **must** cause
abort rather than allow unwinding to cross the FFI boundary.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b08_from_span_partial_mut(
	this: *mut *mut BitSlice<BigEndian, u8>,
	ptr: *mut u8,
	len: usize,
	head: u8,
	tail: u8,
) -> bool {
	nullck!(this, ptr => false);
	let bitslice: &mut BitSlice<_, _> = BitPtr::new(ptr, len, head, tail).into();
	ptr::write(this, bitslice);
	true
}
/** Initializes a slice handle from provided span details.

# Parameters

- `this: *mut *const BitSlice<LittleEndian, u8>`: Write-pointer to an
  *uninitialized* `BitSlice` handle. After this function succeeds, the handle
  will be initialized according to the provided span arguments.
- `ptr: *const u8`: Pointer to the region of memory over which `*this` will
  govern after initialization.
- `len: usize`: Count of `u8` *elements* in the region to which `ptr` points.
- `head: u8`: Index of the first live bit in the first element of the slice.
- `tail: u8`: Indef of the first dead bit in the last element of the slice.

# Returns

`bool` of `true` if `*this` is initialized or `false` if initialization failed.
Failure reasons are not communicated across the FFI boundary.

# Panics

The internal function called to initialize `*this` *may* panic if its arguments
are invalid. As of Rust `1.24`, FFI boundary functions no longer include
automatic `catch_unwind` guards which abort. Use of the FFI boundary functions
*requires* compiling with `panic = abort`.

# Safety

If this function is called with either `this` or `ptr` as `null`, it will return
`false` before dereferencing. If this is called with invalid arguments, it will
panic. this function does not catch any unwinding, so panics **must** cause
abort rather than allow unwinding to cross the FFI boundary.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l08_from_span_partial_mut(
	this: *mut *mut BitSlice<LittleEndian, u8>,
	ptr: *mut u8,
	len: usize,
	head: u8,
	tail: u8,
) -> bool {
	nullck!(this, ptr => false);
	let bitslice: &mut BitSlice<_, _> = BitPtr::new(ptr, len, head, tail).into();
	ptr::write(this, bitslice);
	true
}
/** Initializes a slice handle from provided span details.

# Parameters

- `this: *mut *const BitSlice<BigEndian, u16>`: Write-pointer to an
  *uninitialized* `BitSlice` handle. After this function succeeds, the handle
  will be initialized according to the provided span arguments.
- `ptr: *const u16`: Pointer to the region of memory over which `*this` will
  govern after initialization.
- `len: usize`: Count of `u16` *elements* (not bytes) in the region to which
  `ptr` points.
- `head: u8`: Index of the first live bit in the first element of the slice.
- `tail: u8`: Indef of the first dead bit in the last element of the slice.

# Returns

`bool` of `true` if `*this` is initialized or `false` if initialization failed.
Failure reasons are not communicated across the FFI boundary.

# Panics

The internal function called to initialize `*this` *may* panic if its arguments
are invalid. As of Rust `1.24`, FFI boundary functions no longer include
automatic `catch_unwind` guards which abort. Use of the FFI boundary functions
*requires* compiling with `panic = abort`.

# Safety

If this function is called with either `this` or `ptr` as `null`, it will return
`false` before dereferencing. If this is called with invalid arguments, it will
panic. this function does not catch any unwinding, so panics **must** cause
abort rather than allow unwinding to cross the FFI boundary.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b16_from_span_partial_mut(
	this: *mut *mut BitSlice<BigEndian, u16>,
	ptr: *mut u16,
	len: usize,
	head: u8,
	tail: u8,
) -> bool {
	nullck!(this, ptr => false);
	let bitslice: &mut BitSlice<_, _> = BitPtr::new(ptr, len, head, tail).into();
	ptr::write(this, bitslice);
	true
}
/** Initializes a slice handle from provided span details.

# Parameters

- `this: *mut *const BitSlice<LittleEndian, u16>`: Write-pointer to an
  *uninitialized* `BitSlice` handle. After this function succeeds, the handle
  will be initialized according to the provided span arguments.
- `ptr: *const u16`: Pointer to the region of memory over which `*this` will
  govern after initialization.
- `len: usize`: Count of `u16` *elements* (not bytes) in the region to which
  `ptr` points.
- `head: u8`: Index of the first live bit in the first element of the slice.
- `tail: u8`: Indef of the first dead bit in the last element of the slice.

# Returns

`bool` of `true` if `*this` is initialized or `false` if initialization failed.
Failure reasons are not communicated across the FFI boundary.

# Panics

The internal function called to initialize `*this` *may* panic if its arguments
are invalid. As of Rust `1.24`, FFI boundary functions no longer include
automatic `catch_unwind` guards which abort. Use of the FFI boundary functions
*requires* compiling with `panic = abort`.

# Safety

If this function is called with either `this` or `ptr` as `null`, it will return
`false` before dereferencing. If this is called with invalid arguments, it will
panic. this function does not catch any unwinding, so panics **must** cause
abort rather than allow unwinding to cross the FFI boundary.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l16_from_span_partial_mut(
	this: *mut *mut BitSlice<LittleEndian, u16>,
	ptr: *mut u16,
	len: usize,
	head: u8,
	tail: u8,
) -> bool {
	nullck!(this, ptr => false);
	let bitslice: &mut BitSlice<_, _> = BitPtr::new(ptr, len, head, tail).into();
	ptr::write(this, bitslice);
	true
}
/** Initializes a slice handle from provided span details.

# Parameters

- `this: *mut *const BitSlice<BigEndian, u32>`: Write-pointer to an
  *uninitialized* `BitSlice` handle. After this function succeeds, the handle
  will be initialized according to the provided span arguments.
- `ptr: *const u32`: Pointer to the region of memory over which `*this` will
  govern after initialization.
- `len: usize`: Count of `u32` *elements* (not bytes) in the region to which
  `ptr` points.
- `head: u8`: Index of the first live bit in the first element of the slice.
- `tail: u8`: Indef of the first dead bit in the last element of the slice.

# Returns

`bool` of `true` if `*this` is initialized or `false` if initialization failed.
Failure reasons are not communicated across the FFI boundary.

# Panics

The internal function called to initialize `*this` *may* panic if its arguments
are invalid. As of Rust `1.24`, FFI boundary functions no longer include
automatic `catch_unwind` guards which abort. Use of the FFI boundary functions
*requires* compiling with `panic = abort`.

# Safety

If this function is called with either `this` or `ptr` as `null`, it will return
`false` before dereferencing. If this is called with invalid arguments, it will
panic. this function does not catch any unwinding, so panics **must** cause
abort rather than allow unwinding to cross the FFI boundary.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b32_from_span_partial_mut(
	this: *mut *mut BitSlice<BigEndian, u32>,
	ptr: *mut u32,
	len: usize,
	head: u8,
	tail: u8,
) -> bool {
	nullck!(this, ptr => false);
	let bitslice: &mut BitSlice<_, _> = BitPtr::new(ptr, len, head, tail).into();
	ptr::write(this, bitslice);
	true
}
/** Initializes a slice handle from provided span details.

# Parameters

- `this: *mut *const BitSlice<LittleEndian, u32>`: Write-pointer to an
  *uninitialized* `BitSlice` handle. After this function succeeds, the handle
  will be initialized according to the provided span arguments.
- `ptr: *const u32`: Pointer to the region of memory over which `*this` will
  govern after initialization.
- `len: usize`: Count of `u32` *elements* (not bytes) in the region to which
  `ptr` points.
- `head: u8`: Index of the first live bit in the first element of the slice.
- `tail: u8`: Indef of the first dead bit in the last element of the slice.

# Returns

`bool` of `true` if `*this` is initialized or `false` if initialization failed.
Failure reasons are not communicated across the FFI boundary.

# Panics

The internal function called to initialize `*this` *may* panic if its arguments
are invalid. As of Rust `1.24`, FFI boundary functions no longer include
automatic `catch_unwind` guards which abort. Use of the FFI boundary functions
*requires* compiling with `panic = abort`.

# Safety

If this function is called with either `this` or `ptr` as `null`, it will return
`false` before dereferencing. If this is called with invalid arguments, it will
panic. this function does not catch any unwinding, so panics **must** cause
abort rather than allow unwinding to cross the FFI boundary.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l32_from_span_partial_mut(
	this: *mut *mut BitSlice<LittleEndian, u32>,
	ptr: *mut u32,
	len: usize,
	head: u8,
	tail: u8,
) -> bool {
	nullck!(this, ptr => false);
	let bitslice: &mut BitSlice<_, _> = BitPtr::new(ptr, len, head, tail).into();
	ptr::write(this, bitslice);
	true
}
/** Initializes a slice handle from provided span details.

# Parameters

- `this: *mut *const BitSlice<BigEndian, u64>`: Write-pointer to an
  *uninitialized* `BitSlice` handle. After this function succeeds, the handle
  will be initialized according to the provided span arguments.
- `ptr: *const u64`: Pointer to the region of memory over which `*this` will
  govern after initialization.
- `len: usize`: Count of `u64` *elements* (not bytes) in the region to which
  `ptr` points.
- `head: u8`: Index of the first live bit in the first element of the slice.
- `tail: u8`: Indef of the first dead bit in the last element of the slice.

# Returns

`bool` of `true` if `*this` is initialized or `false` if initialization failed.
Failure reasons are not communicated across the FFI boundary.

# Panics

The internal function called to initialize `*this` *may* panic if its arguments
are invalid. As of Rust `1.24`, FFI boundary functions no longer include
automatic `catch_unwind` guards which abort. Use of the FFI boundary functions
*requires* compiling with `panic = abort`.

# Safety

If this function is called with either `this` or `ptr` as `null`, it will return
`false` before dereferencing. If this is called with invalid arguments, it will
panic. this function does not catch any unwinding, so panics **must** cause
abort rather than allow unwinding to cross the FFI boundary.
**/
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b64_from_span_partial_mut(
	this: *mut *mut BitSlice<BigEndian, u64>,
	ptr: *mut u64,
	len: usize,
	head: u8,
	tail: u8,
) -> bool {
	nullck!(this, ptr => false);
	let bitslice: &mut BitSlice<_, _> = BitPtr::new(ptr, len, head, tail).into();
	ptr::write(this, bitslice);
	true
}
/** Initializes a slice handle from provided span details.

# Parameters

- `this: *mut *const BitSlice<LittleEndian, u64>`: Write-pointer to an
  *uninitialized* `BitSlice` handle. After this function succeeds, the handle
  will be initialized according to the provided span arguments.
- `ptr: *const u64`: Pointer to the region of memory over which `*this` will
  govern after initialization.
- `len: usize`: Count of `u64` *elements* (not bytes) in the region to which
  `ptr` points.
- `head: u8`: Index of the first live bit in the first element of the slice.
- `tail: u8`: Indef of the first dead bit in the last element of the slice.

# Returns

`bool` of `true` if `*this` is initialized or `false` if initialization failed.
Failure reasons are not communicated across the FFI boundary.

# Panics

The internal function called to initialize `*this` *may* panic if its arguments
are invalid. As of Rust `1.24`, FFI boundary functions no longer include
automatic `catch_unwind` guards which abort. Use of the FFI boundary functions
*requires* compiling with `panic = abort`.

# Safety

If this function is called with either `this` or `ptr` as `null`, it will return
`false` before dereferencing. If this is called with invalid arguments, it will
panic. this function does not catch any unwinding, so panics **must** cause
abort rather than allow unwinding to cross the FFI boundary.
**/
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l64_from_span_partial_mut(
	this: *mut *mut BitSlice<LittleEndian, u64>,
	ptr: *mut u64,
	len: usize,
	head: u8,
	tail: u8,
) -> bool {
	nullck!(this, ptr => false);
	let bitslice: &mut BitSlice<_, _> = BitPtr::new(ptr, len, head, tail).into();
	ptr::write(this, bitslice);
	true
}

/** Computes the length, in bits, of a bit slice behind a handle.

# Parameters

- `this: *const *const BitSlice<BigEndian, u8>`: Const-pointer to a `BitSlice`
  handle of immutable bits.

# Returns

The number of bits contained in the slice.

# Safety

If `this` is `null`, then this early-returns `0`.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b08_len(
	this: *const *const BitSlice<BigEndian, u8>,
) -> usize {
	nullck!(this => 0);
	(&**this).len()
}
/** Computes the length, in bits, of a bit slice behind a handle.

# Parameters

- `this: *const *const BitSlice<LittleEndian, u8>`: Const-pointer to a
  `BitSlice` handle of immutable bits.

# Returns

The number of bits contained in the slice.

# Safety

If `this` is `null`, then this early-returns `0`.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l08_len(
	this: *const *const BitSlice<LittleEndian, u8>,
) -> usize {
	nullck!(this => 0);
	(&**this).len()
}
/** Computes the length, in bits, of a bit slice behind a handle.

# Parameters

- `this: *const *const BitSlice<BigEndian, u16>`: Const-pointer to a `BitSlice`
  handle of immutable bits.

# Returns

The number of bits contained in the slice.

# Safety

If `this` is `null`, then this early-returns `0`.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b16_len(
	this: *const *const BitSlice<BigEndian, u16>,
) -> usize {
	nullck!(this => 0);
	(&**this).len()
}
/** Computes the length, in bits, of a bit slice behind a handle.

# Parameters

- `this: *const *const BitSlice<LittleEndian, u16>`: Const-pointer to a
  `BitSlice` handle of immutable bits.

# Returns

The number of bits contained in the slice.

# Safety

If `this` is `null`, then this early-returns `0`.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l16_len(
	this: *const *const BitSlice<LittleEndian, u16>,
) -> usize {
	nullck!(this => 0);
	(&**this).len()
}
/** Computes the length, in bits, of a bit slice behind a handle.

# Parameters

- `this: *const *const BitSlice<BigEndian, u32>`: Const-pointer to a `BitSlice`
  handle of immutable bits.

# Returns

The number of bits contained in the slice.

# Safety

If `this` is `null`, then this early-returns `0`.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b32_len(
	this: *const *const BitSlice<BigEndian, u32>,
) -> usize {
	nullck!(this => 0);
	(&**this).len()
}
/** Computes the length, in bits, of a bit slice behind a handle.

# Parameters

- `this: *const *const BitSlice<LittleEndian, u32>`: Const-pointer to a
  `BitSlice` handle of immutable bits.

# Returns

The number of bits contained in the slice.

# Safety

If `this` is `null`, then this early-returns `0`.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l32_len(
	this: *const *const BitSlice<LittleEndian, u32>,
) -> usize {
	nullck!(this => 0);
	(&**this).len()
}
/** Computes the length, in bits, of a bit slice behind a handle.

# Parameters

- `this: *const *const BitSlice<BigEndian, u64>`: Const-pointer to a `BitSlice`
  handle of immutable bits.

# Returns

The number of bits contained in the slice.

# Safety

If `this` is `null`, then this early-returns `0`.
**/
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b64_len(
	this: *const *const BitSlice<BigEndian, u64>,
) -> usize {
	nullck!(this => 0);
	(&**this).len()
}
/** Computes the length, in bits, of a bit slice behind a handle.

# Parameters

- `this: *const *const BitSlice<LittleEndian, u64>`: Const-pointer to a
  `BitSlice` handle of immutable bits.

# Returns

The number of bits contained in the slice.

# Safety

If `this` is `null`, then this early-returns `0`.
**/
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l64_len(
	this: *const *const BitSlice<LittleEndian, u64>,
) -> usize {
	nullck!(this => 0);
	(&**this).len()
}

/** Tests if a `BitSlice` handle is empty.

# Parameters

- `this: *const *const BitSlice<BigEndian, u8>`: Const-pointer to a `BitSlice`
  handle of immutable bits.

# Returns

A `Tristate` boolean of whether `this` is valid, and `*this` is empty.

# Safety

If `this` is `null`, then this early-returns `Tristate::Error`.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b08_is_empty(
	this: *const *const BitSlice<BigEndian, u8>,
) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).is_empty().into()
}
/** Tests if a `BitSlice` handle is empty.

# Parameters

- `this: *const *const BitSlice<LittleEndian, u8>`: Const-pointer to a
  `BitSlice` handle of immutable bits.

# Returns

A `Tristate` boolean of whether `this` is valid, and `*this` is empty.

# Safety

If `this` is `null`, then this early-returns `Tristate::Error`.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l08_is_empty(
	this: *const *const BitSlice<LittleEndian, u8>,
) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).is_empty().into()
}
/** Tests if a `BitSlice` handle is empty.

# Parameters

- `this: *const *const BitSlice<BigEndian, u16>`: Const-pointer to a `BitSlice`
  handle of immutable bits.

# Returns

A `Tristate` boolean of whether `this` is valid, and `*this` is empty.

# Safety

If `this` is `null`, then this early-returns `Tristate::Error`.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b16_is_empty(
	this: *const *const BitSlice<BigEndian, u16>,
) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).is_empty().into()
}
/** Tests if a `BitSlice` handle is empty.

# Parameters

- `this: *const *const BitSlice<LittleEndian, u16>`: Const-pointer to a
  `BitSlice` handle of immutable bits.

# Returns

A `Tristate` boolean of whether `this` is valid, and `*this` is empty.

# Safety

If `this` is `null`, then this early-returns `Tristate::Error`.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l16_is_empty(
	this: *const *const BitSlice<LittleEndian, u16>,
) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).is_empty().into()
}
/** Tests if a `BitSlice` handle is empty.

# Parameters

- `this: *const *const BitSlice<BigEndian, u32>`: Const-pointer to a `BitSlice`
  handle of immutable bits.

# Returns

A `Tristate` boolean of whether `this` is valid, and `*this` is empty.

# Safety

If `this` is `null`, then this early-returns `Tristate::Error`.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b32_is_empty(
	this: *const *const BitSlice<BigEndian, u32>,
) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).is_empty().into()
}
/** Tests if a `BitSlice` handle is empty.

# Parameters

- `this: *const *const BitSlice<LittleEndian, u32>`: Const-pointer to a
  `BitSlice` handle of immutable bits.

# Returns

A `Tristate` boolean of whether `this` is valid, and `*this` is empty.

# Safety

If `this` is `null`, then this early-returns `Tristate::Error`.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l32_is_empty(
	this: *const *const BitSlice<LittleEndian, u32>,
) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).is_empty().into()
}
/** Tests if a `BitSlice` handle is empty.

# Parameters

- `this: *const *const BitSlice<BigEndian, u64>`: Const-pointer to a `BitSlice`
  handle of immutable bits.

# Returns

A `Tristate` boolean of whether `this` is valid, and `*this` is empty.

# Safety

If `this` is `null`, then this early-returns `Tristate::Error`.
**/
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b64_is_empty(
	this: *const *const BitSlice<BigEndian, u64>,
) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).is_empty().into()
}
/** Tests if a `BitSlice` handle is empty.

# Parameters

- `this: *const *const BitSlice<LittleEndian, u64>`: Const-pointer to a
  `BitSlice` handle of immutable bits.

# Returns

A `Tristate` boolean of whether `this` is valid, and `*this` is empty.

# Safety

If `this` is `null`, then this early-returns `Tristate::Error`.
**/
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l64_is_empty(
	this: *const *const BitSlice<LittleEndian, u64>,
) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).is_empty().into()
}

/** Attempts to get the first bit in a `BitSlice`.

# Parameters

- `this: *const *const BitSlice<BigEndian, u8>`: Const-pointer to a `BitSlice`
  handle of immutable bits.

# Returns

A `Tristate` boolean of whether `this` is valid, and what the first bit in
`**this` is. `Tristate::Error` can be returned when `this` is `null` *or*
when `*this` is empty.

# Safety

If `this` is `null`, this function early-returns `Tristate::Error`.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b08_first(
	this: *const *const BitSlice<BigEndian, u8>,
) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).first().into()
}
/** Attempts to get the first bit in a `BitSlice`.

# Parameters

- `this: *const *const BitSlice<LittleEndian, u8>`: Const-pointer to a
  `BitSlice` handle of immutable bits.

# Returns

A `Tristate` boolean of whether `this` is valid, and what the first bit in
`**this` is. `Tristate::Error` can be returned when `this` is `null` *or*
when `*this` is empty.

# Safety

If `this` is `null`, this function early-returns `Tristate::Error`.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l08_first(
	this: *const *const BitSlice<LittleEndian, u8>,
) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).first().into()
}
/** Attempts to get the first bit in a `BitSlice`.

# Parameters

- `this: *const *const BitSlice<BigEndian, u16>`: Const-pointer to a `BitSlice`
  handle of immutable bits.

# Returns

A `Tristate` boolean of whether `this` is valid, and what the first bit in
`**this` is. `Tristate::Error` can be returned when `this` is `null` *or*
when `*this` is empty.

# Safety

If `this` is `null`, this function early-returns `Tristate::Error`.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b16_first(
	this: *const *const BitSlice<BigEndian, u16>,
) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).first().into()
}
/** Attempts to get the first bit in a `BitSlice`.

# Parameters

- `this: *const *const BitSlice<LittleEndian, u16>`: Const-pointer to a
  `BitSlice` handle of immutable bits.

# Returns

A `Tristate` boolean of whether `this` is valid, and what the first bit in
`**this` is. `Tristate::Error` can be returned when `this` is `null` *or*
when `*this` is empty.

# Safety

If `this` is `null`, this function early-returns `Tristate::Error`.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l16_first(
	this: *const *const BitSlice<LittleEndian, u16>,
) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).first().into()
}
/** Attempts to get the first bit in a `BitSlice`.

# Parameters

- `this: *const *const BitSlice<BigEndian, u32>`: Const-pointer to a `BitSlice`
  handle of immutable bits.

# Returns

A `Tristate` boolean of whether `this` is valid, and what the first bit in
`**this` is. `Tristate::Error` can be returned when `this` is `null` *or*
when `*this` is empty.

# Safety

If `this` is `null`, this function early-returns `Tristate::Error`.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b32_first(
	this: *const *const BitSlice<BigEndian, u32>,
) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).first().into()
}
/** Attempts to get the first bit in a `BitSlice`.

# Parameters

- `this: *const *const BitSlice<LittleEndian, u32>`: Const-pointer to a
  `BitSlice` handle of immutable bits.

# Returns

A `Tristate` boolean of whether `this` is valid, and what the first bit in
`**this` is. `Tristate::Error` can be returned when `this` is `null` *or*
when `*this` is empty.

# Safety

If `this` is `null`, this function early-returns `Tristate::Error`.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l32_first(
	this: *const *const BitSlice<LittleEndian, u32>,
) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).first().into()
}
/** Attempts to get the first bit in a `BitSlice`.

# Parameters

- `this: *const *const BitSlice<BigEndian, u64>`: Const-pointer to a `BitSlice`
  handle of immutable bits.

# Returns

A `Tristate` boolean of whether `this` is valid, and what the first bit in
`**this` is. `Tristate::Error` can be returned when `this` is `null` *or*
when `*this` is empty.

# Safety

If `this` is `null`, this function early-returns `Tristate::Error`.
**/
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b64_first(
	this: *const *const BitSlice<BigEndian, u64>,
) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).first().into()
}
/** Attempts to get the first bit in a `BitSlice`.

# Parameters

- `this: *const *const BitSlice<LittleEndian, u64>`: Const-pointer to a
  `BitSlice` handle of immutable bits.

# Returns

A `Tristate` boolean of whether `this` is valid, and what the first bit in
`**this` is. `Tristate::Error` can be returned when `this` is `null` *or*
when `*this` is empty.

# Safety

If `this` is `null`, this function early-returns `Tristate::Error`.
**/
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l64_first(
	this: *const *const BitSlice<LittleEndian, u64>,
) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).first().into()
}

/** Attempts to split a `BitSlice` after its first bit.

# Parameters

- `this: *mut *const BitSlice<BigEndian, u8>`: Pointer to a mutable `BitSlice`
  handle of immutable bits.

# Returns

A `Tristate` boolean of whether `this` is valid, `*this` is not-empty, and
the first bit in `**this`.

# Modifies

If the split successfully occured, then the handle to which `this` points is
modified in the caller’s scope. If `*this` is empty, then the split does not
occur.

# Safety

If `this` is `null`, then this function early-returns `Tristate::Error`.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b08_split_first(
	this: *mut *const BitSlice<BigEndian, u8>,
) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).split_first().map(|(bit, slice)| {
		*this = slice;
		bit
	}).into()
}
/** Attempts to split a `BitSlice` after its first bit.

# Parameters

- `this: *mut *const BitSlice<LittleEndian, u8>`: Pointer to a mutable
  `BitSlice` handle of immutable bits.

# Returns

A `Tristate` boolean of whether `this` is valid, `*this` is not-empty, and
the first bit in `**this`.

# Modifies

If the split successfully occured, then the handle to which `this` points is
modified in the caller’s scope. If `*this` is empty, then the split does not
occur.

# Safety

If `this` is `null`, then this function early-returns `Tristate::Error`.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l08_split_first(
	this: *mut *const BitSlice<LittleEndian, u8>,
) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).split_first().map(|(bit, slice)| {
		*this = slice;
		bit
	}).into()
}
/** Attempts to split a `BitSlice` after its first bit.

# Parameters

- `this: *mut *const BitSlice<BigEndian, u16>`: Pointer to a mutable `BitSlice`
  handle of immutable bits.

# Returns

A `Tristate` boolean of whether `this` is valid, `*this` is not-empty, and
the first bit in `**this`.

# Modifies

If the split successfully occured, then the handle to which `this` points is
modified in the caller’s scope. If `*this` is empty, then the split does not
occur.

# Safety

If `this` is `null`, then this function early-returns `Tristate::Error`.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b16_split_first(
	this: *mut *const BitSlice<BigEndian, u16>,
) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).split_first().map(|(bit, slice)| {
		*this = slice;
		bit
	}).into()
}
/** Attempts to split a `BitSlice` after its first bit.

# Parameters

- `this: *mut *const BitSlice<LittleEndian, u16>`: Pointer to a mutable
  `BitSlice` handle of immutable bits.

# Returns

A `Tristate` boolean of whether `this` is valid, `*this` is not-empty, and
the first bit in `**this`.

# Modifies

If the split successfully occured, then the handle to which `this` points is
modified in the caller’s scope. If `*this` is empty, then the split does not
occur.

# Safety

If `this` is `null`, then this function early-returns `Tristate::Error`.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l16_split_first(
	this: *mut *const BitSlice<LittleEndian, u16>,
) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).split_first().map(|(bit, slice)| {
		*this = slice;
		bit
	}).into()
}
/** Attempts to split a `BitSlice` after its first bit.

# Parameters

- `this: *mut *const BitSlice<BigEndian, u32>`: Pointer to a mutable `BitSlice`
  handle of immutable bits.

# Returns

A `Tristate` boolean of whether `this` is valid, `*this` is not-empty, and
the first bit in `**this`.

# Modifies

If the split successfully occured, then the handle to which `this` points is
modified in the caller’s scope. If `*this` is empty, then the split does not
occur.

# Safety

If `this` is `null`, then this function early-returns `Tristate::Error`.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b32_split_first(
	this: *mut *const BitSlice<BigEndian, u32>,
) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).split_first().map(|(bit, slice)| {
		*this = slice;
		bit
	}).into()
}
/** Attempts to split a `BitSlice` after its first bit.

# Parameters

- `this: *mut *const BitSlice<LittleEndian, u32>`: Pointer to a mutable
  `BitSlice` handle of immutable bits.

# Returns

A `Tristate` boolean of whether `this` is valid, `*this` is not-empty, and
the first bit in `**this`.

# Modifies

If the split successfully occured, then the handle to which `this` points is
modified in the caller’s scope. If `*this` is empty, then the split does not
occur.

# Safety

If `this` is `null`, then this function early-returns `Tristate::Error`.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l32_split_first(
	this: *mut *const BitSlice<LittleEndian, u32>,
) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).split_first().map(|(bit, slice)| {
		*this = slice;
		bit
	}).into()
}
/** Attempts to split a `BitSlice` after its first bit.

# Parameters

- `this: *mut *const BitSlice<BigEndian, 64u>`: Pointer to a mutable `BitSlice`
  handle of immutable bits.

# Returns

A `Tristate` boolean of whether `this` is valid, `*this` is not-empty, and
the first bit in `**this`.

# Modifies

If the split successfully occured, then the handle to which `this` points is
modified in the caller’s scope. If `*this` is empty, then the split does not
occur.

# Safety

If `this` is `null`, then this function early-returns `Tristate::Error`.
**/
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b64_split_first(
	this: *mut *const BitSlice<BigEndian, u64>,
) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).split_first().map(|(bit, slice)| {
		*this = slice;
		bit
	}).into()
}
/** Attempts to split a `BitSlice` after its first bit.

# Parameters

- `this: *mut *const BitSlice<LittleEndian, u64n >`: Pointer to a mutable
  `BitSlice` handle of immutable bits.

# Returns

A `Tristate` boolean of whether `this` is valid, `*this` is not-empty, and
the first bit in `**this`.

# Modifies

If the split successfully occured, then the handle to which `this` points is
modified in the caller’s scope. If `*this` is empty, then the split does not
occur.

# Safety

If `this` is `null`, then this function early-returns `Tristate::Error`.
**/
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l64_split_first(
	this: *mut *const BitSlice<LittleEndian, u64>,
) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).split_first().map(|(bit, slice)| {
		*this = slice;
		bit
	}).into()
}

/** Attempts to split a mutable `BitSlice` after the first bit.

# Parameters

- `this: *mut *mut BitSlice<BigEndian, u8>`: Pointer to a mutable `BitSlice`
  handle of mutable bits.

# Returns

A `Tristate` boolean of whether the split succeeded and what the first bit
in the slice was. If `*this` is empty, then this returns `Tristate::Error`.

# Modifies

If the split succeeded, then the handle to which `this` points is modified to no
longer include the first bit. If `*this` is empty, then it is *not* modified.

# Safety

If `this` is `null`, then this function early-returns `Tristate::Error`.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b08_split_first_mut(
	this: *mut *mut BitSlice<BigEndian, u8>,
) -> Tristate {
	nullck!(this => Tristate::Error);
	(&mut **this).split_first_mut().map(|(bit, slice)| {
		*this = slice;
		bit
	}).into()
}
/** Attempts to split a mutable `BitSlice` after the first bit.

# Parameters

- `this: *mut *mut BitSlice<LittleEndian, u8>`: Pointer to a mutable
  `BitSlice` handle of mutable bits.

# Returns

A `Tristate` boolean of whether the split succeeded and what the first bit
in the slice was. If `*this` is empty, then this returns `Tristate::Error`.

# Modifies

If the split succeeded, then the handle to which `this` points is modified to no
longer include the first bit. If `*this` is empty, then it is *not* modified.

# Safety

If `this` is `null`, then this function early-returns `Tristate::Error`.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l08_split_first_mut(
	this: *mut *mut BitSlice<LittleEndian, u8>,
) -> Tristate {
	nullck!(this => Tristate::Error);
	(&mut **this).split_first_mut().map(|(bit, slice)| {
		*this = slice;
		bit
	}).into()
}
/** Attempts to split a mutable `BitSlice` after the first bit.

# Parameters

- `this: *mut *mut BitSlice<BigEndian, u16>`: Pointer to a mutable `BitSlice`
  handle of mutable bits.

# Returns

A `Tristate` boolean of whether the split succeeded and what the first bit
in the slice was. If `*this` is empty, then this returns `Tristate::Error`.

# Modifies

If the split succeeded, then the handle to which `this` points is modified to no
longer include the first bit. If `*this` is empty, then it is *not* modified.

# Safety

If `this` is `null`, then this function early-returns `Tristate::Error`.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b16_split_first_mut(
	this: *mut *mut BitSlice<BigEndian, u16>,
) -> Tristate {
	nullck!(this => Tristate::Error);
	(&mut **this).split_first_mut().map(|(bit, slice)| {
		*this = slice;
		bit
	}).into()
}
/** Attempts to split a mutable `BitSlice` after the first bit.

# Parameters

- `this: *mut *mut BitSlice<LittleEndian, u16>`: Pointer to a mutable
  `BitSlice` handle of mutable bits.

# Returns

A `Tristate` boolean of whether the split succeeded and what the first bit
in the slice was. If `*this` is empty, then this returns `Tristate::Error`.

# Modifies

If the split succeeded, then the handle to which `this` points is modified to no
longer include the first bit. If `*this` is empty, then it is *not* modified.

# Safety

If `this` is `null`, then this function early-returns `Tristate::Error`.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l16_split_first_mut(
	this: *mut *mut BitSlice<LittleEndian, u16>,
) -> Tristate {
	nullck!(this => Tristate::Error);
	(&mut **this).split_first_mut().map(|(bit, slice)| {
		*this = slice;
		bit
	}).into()
}
/** Attempts to split a mutable `BitSlice` after the first bit.

# Parameters

- `this: *mut *mut BitSlice<BigEndian, u32>`: Pointer to a mutable `BitSlice`
  handle of mutable bits.

# Returns

A `Tristate` boolean of whether the split succeeded and what the first bit
in the slice was. If `*this` is empty, then this returns `Tristate::Error`.

# Modifies

If the split succeeded, then the handle to which `this` points is modified to no
longer include the first bit. If `*this` is empty, then it is *not* modified.

# Safety

If `this` is `null`, then this function early-returns `Tristate::Error`.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b32_split_first_mut(
	this: *mut *mut BitSlice<BigEndian, u32>,
) -> Tristate {
	nullck!(this => Tristate::Error);
	(&mut **this).split_first_mut().map(|(bit, slice)| {
		*this = slice;
		bit
	}).into()
}
/** Attempts to split a mutable `BitSlice` after the first bit.

# Parameters

- `this: *mut *mut BitSlice<LittleEndian, u32>`: Pointer to a mutable
  `BitSlice` handle of mutable bits.

# Returns

A `Tristate` boolean of whether the split succeeded and what the first bit
in the slice was. If `*this` is empty, then this returns `Tristate::Error`.

# Modifies

If the split succeeded, then the handle to which `this` points is modified to no
longer include the first bit. If `*this` is empty, then it is *not* modified.

# Safety

If `this` is `null`, then this function early-returns `Tristate::Error`.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l32_split_first_mut(
	this: *mut *mut BitSlice<LittleEndian, u32>,
) -> Tristate {
	nullck!(this => Tristate::Error);
	(&mut **this).split_first_mut().map(|(bit, slice)| {
		*this = slice;
		bit
	}).into()
}
/** Attempts to split a mutable `BitSlice` after the first bit.

# Parameters

- `this: *mut *mut BitSlice<BigEndian, u64>`: Pointer to a mutable `BitSlice`
  handle of mutable bits.

# Returns

A `Tristate` boolean of whether the split succeeded and what the first bit
in the slice was. If `*this` is empty, then this returns `Tristate::Error`.

# Modifies

If the split succeeded, then the handle to which `this` points is modified to no
longer include the first bit. If `*this` is empty, then it is *not* modified.

# Safety

If `this` is `null`, then this function early-returns `Tristate::Error`.
**/
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b64_split_first_mut(
	this: *mut *mut BitSlice<BigEndian, u64>,
) -> Tristate {
	nullck!(this => Tristate::Error);
	(&mut **this).split_first_mut().map(|(bit, slice)| {
		*this = slice;
		bit
	}).into()
}
/** Attempts to split a mutable `BitSlice` after the first bit.

# Parameters

- `this: *mut *mut BitSlice<LittleEndian, u64>`: Pointer to a mutable
  `BitSlice` handle of mutable bits.

# Returns

A `Tristate` boolean of whether the split succeeded and what the first bit
in the slice was. If `*this` is empty, then this returns `Tristate::Error`.

# Modifies

If the split succeeded, then the handle to which `this` points is modified to no
longer include the first bit. If `*this` is empty, then it is *not* modified.

# Safety

If `this` is `null`, then this function early-returns `Tristate::Error`.
**/
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l64_split_first_mut(
	this: *mut *mut BitSlice<LittleEndian, u64>,
) -> Tristate {
	nullck!(this => Tristate::Error);
	(&mut **this).split_first_mut().map(|(bit, slice)| {
		*this = slice;
		bit
	}).into()
}

/** Attempts to split a `BitSlice` before its last bit.

# Parameters

- `this: *mut *const BitSlice<BigEndian, u8>`: Pointer to a mutable `BitSlice`
  handle of mutable bits.

# Returns

A `Tristate` boolean of whether the split succeeded and what the last bit in the
slice was. If `*this` is empty, then this returns `Tristate::Error`.

# Modifies

If the split succeeded, then the handle to which `this` points is modified to no
longer include the last bit. If `*this` is empty, then it is *not* modified.

# Safety

If `this` is `null`, then this function early-returns `Tristate::Error`.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b08_split_last(
	this: *mut *const BitSlice<BigEndian, u8>,
) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).split_last().map(|(bit, slice)| {
		*this = slice;
		bit
	}).into()
}
/** Attempts to split a `BitSlice` before its last bit.

# Parameters

- `this: *mut *const BitSlice<LittleEndian, u8>`: Pointer to a mutable
  `BitSlice` handle of mutable bits.

# Returns

A `Tristate` boolean of whether the split succeeded and what the last bit in the
slice was. If `*this` is empty, then this returns `Tristate::Error`.

# Modifies

If the split succeeded, then the handle to which `this` points is modified to no
longer include the last bit. If `*this` is empty, then it is *not* modified.

# Safety

If `this` is `null`, then this function early-returns `Tristate::Error`.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l08_split_last(
	this: *mut *const BitSlice<LittleEndian, u8>,
) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).split_last().map(|(bit, slice)| {
		*this = slice;
		bit
	}).into()
}
/** Attempts to split a `BitSlice` before its last bit.

# Parameters

- `this: *mut *const BitSlice<BigEndian, u16>`: Pointer to a mutable `BitSlice`
  handle of mutable bits.

# Returns

A `Tristate` boolean of whether the split succeeded and what the last bit in the
slice was. If `*this` is empty, then this returns `Tristate::Error`.

# Modifies

If the split succeeded, then the handle to which `this` points is modified to no
longer include the last bit. If `*this` is empty, then it is *not* modified.

# Safety

If `this` is `null`, then this function early-returns `Tristate::Error`.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b16_split_last(
	this: *mut *const BitSlice<BigEndian, u16>,
) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).split_last().map(|(bit, slice)| {
		*this = slice;
		bit
	}).into()
}
/** Attempts to split a `BitSlice` before its last bit.

# Parameters

- `this: *mut *const BitSlice<LittleEndian, u16>`: Pointer to a mutable
  `BitSlice` handle of mutable bits.

# Returns

A `Tristate` boolean of whether the split succeeded and what the last bit in the
slice was. If `*this` is empty, then this returns `Tristate::Error`.

# Modifies

If the split succeeded, then the handle to which `this` points is modified to no
longer include the last bit. If `*this` is empty, then it is *not* modified.

# Safety

If `this` is `null`, then this function early-returns `Tristate::Error`.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l16_split_last(
	this: *mut *const BitSlice<LittleEndian, u16>,
) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).split_last().map(|(bit, slice)| {
		*this = slice;
		bit
	}).into()
}
/** Attempts to split a `BitSlice` before its last bit.

# Parameters

- `this: *mut *const BitSlice<BigEndian, u32>`: Pointer to a mutable `BitSlice`
  handle of mutable bits.

# Returns

A `Tristate` boolean of whether the split succeeded and what the last bit in the
slice was. If `*this` is empty, then this returns `Tristate::Error`.

# Modifies

If the split succeeded, then the handle to which `this` points is modified to no
longer include the last bit. If `*this` is empty, then it is *not* modified.

# Safety

If `this` is `null`, then this function early-returns `Tristate::Error`.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b32_split_last(
	this: *mut *const BitSlice<BigEndian, u32>,
) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).split_last().map(|(bit, slice)| {
		*this = slice;
		bit
	}).into()
}
/** Attempts to split a `BitSlice` before its last bit.

# Parameters

- `this: *mut *const BitSlice<LittleEndian, u32>`: Pointer to a mutable
  `BitSlice` handle of mutable bits.

# Returns

A `Tristate` boolean of whether the split succeeded and what the last bit in the
slice was. If `*this` is empty, then this returns `Tristate::Error`.

# Modifies

If the split succeeded, then the handle to which `this` points is modified to no
longer include the last bit. If `*this` is empty, then it is *not* modified.

# Safety

If `this` is `null`, then this function early-returns `Tristate::Error`.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l32_split_last(
	this: *mut *const BitSlice<LittleEndian, u32>,
) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).split_last().map(|(bit, slice)| {
		*this = slice;
		bit
	}).into()
}
/** Attempts to split a `BitSlice` before its last bit.

# Parameters

- `this: *mut *const BitSlice<BigEndian, u64>`: Pointer to a mutable `BitSlice`
  handle of mutable bits.

# Returns

A `Tristate` boolean of whether the split succeeded and what the last bit in the
slice was. If `*this` is empty, then this returns `Tristate::Error`.

# Modifies

If the split succeeded, then the handle to which `this` points is modified to no
longer include the last bit. If `*this` is empty, then it is *not* modified.

# Safety

If `this` is `null`, then this function early-returns `Tristate::Error`.
**/
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b64_split_last(
	this: *mut *const BitSlice<BigEndian, u64>,
) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).split_last().map(|(bit, slice)| {
		*this = slice;
		bit
	}).into()
}
/** Attempts to split a `BitSlice` before its last bit.

# Parameters

- `this: *mut *const BitSlice<LittleEndian, u64>`: Pointer to a mutable
  `BitSlice` handle of mutable bits.

# Returns

A `Tristate` boolean of whether the split succeeded and what the last bit in the
slice was. If `*this` is empty, then this returns `Tristate::Error`.

# Modifies

If the split succeeded, then the handle to which `this` points is modified to no
longer include the last bit. If `*this` is empty, then it is *not* modified.

# Safety

If `this` is `null`, then this function early-returns `Tristate::Error`.
**/
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l64_split_last(
	this: *mut *const BitSlice<LittleEndian, u64>,
) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).split_last().map(|(bit, slice)| {
		*this = slice;
		bit
	}).into()
}

/** Attempts to split a mutable `BitSlice` before its last bit.

# Parameters

- `this: *mut *mut BitSlice<BigEndian, u8>`: Pointer to a mutable `BitSlice`
  handle of mutable bits.

# Returns

A `Tristate` boolean of whether the split succeeded and what the last bit in the
slice was.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b08_split_last_mut(
	this: *mut *mut BitSlice<BigEndian, u8>,
) -> Tristate {
	nullck!(this => Tristate::Error);
	(&mut **this).split_last_mut().map(|(bit, slice)| {
		*this = slice;
		bit
	}).into()
}
/** Attempts to split a mutable `BitSlice` before its last bit.

# Parameters

- `this: *mut *mut BitSlice<LittleEndian, u8>`: Pointer to a mutable `BitSlice`
  handle of mutable bits.

# Returns

A `Tristate` boolean of whether the split succeeded and what the last bit in the
slice was.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l08_split_last_mut(
	this: *mut *mut BitSlice<LittleEndian, u8>,
) -> Tristate {
	nullck!(this => Tristate::Error);
	(&mut **this).split_last_mut().map(|(bit, slice)| {
		*this = slice;
		bit
	}).into()
}
/** Attempts to split a mutable `BitSlice` before its last bit.

# Parameters

- `this: *mut *mut BitSlice<BigEndian, u16>`: Pointer to a mutable `BitSlice`
  handle of mutable bits.

# Returns

A `Tristate` boolean of whether the split succeeded and what the last bit in the
slice was.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b16_split_last_mut(
	this: *mut *mut BitSlice<BigEndian, u16>,
) -> Tristate {
	nullck!(this => Tristate::Error);
	(&mut **this).split_last_mut().map(|(bit, slice)| {
		*this = slice;
		bit
	}).into()
}
/** Attempts to split a mutable `BitSlice` before its last bit.

# Parameters

- `this: *mut *mut BitSlice<LittleEndian, u16>`: Pointer to a mutable `BitSlice`
  handle of mutable bits.

# Returns

A `Tristate` boolean of whether the split succeeded and what the last bit in the
slice was.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l16_split_last_mut(
	this: *mut *mut BitSlice<LittleEndian, u16>,
) -> Tristate {
	nullck!(this => Tristate::Error);
	(&mut **this).split_last_mut().map(|(bit, slice)| {
		*this = slice;
		bit
	}).into()
}
/** Attempts to split a mutable `BitSlice` before its last bit.

# Parameters

- `this: *mut *mut BitSlice<BigEndian, u32>`: Pointer to a mutable `BitSlice`
  handle of mutable bits.

# Returns

A `Tristate` boolean of whether the split succeeded and what the last bit in the
slice was.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b32_split_last_mut(
	this: *mut *mut BitSlice<BigEndian, u32>,
) -> Tristate {
	nullck!(this => Tristate::Error);
	(&mut **this).split_last_mut().map(|(bit, slice)| {
		*this = slice;
		bit
	}).into()
}
/** Attempts to split a mutable `BitSlice` before its last bit.

# Parameters

- `this: *mut *mut BitSlice<LittleEndian, u32>`: Pointer to a mutable `BitSlice`
  handle of mutable bits.

# Returns

A `Tristate` boolean of whether the split succeeded and what the last bit in the
slice was.
**/
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l32_split_last_mut(
	this: *mut *mut BitSlice<LittleEndian, u32>,
) -> Tristate {
	nullck!(this => Tristate::Error);
	(&mut **this).split_last_mut().map(|(bit, slice)| {
		*this = slice;
		bit
	}).into()
}
/** Attempts to split a mutable `BitSlice` before its last bit.

# Parameters

- `this: *mut *mut BitSlice<BigEndian, u64>`: Pointer to a mutable `BitSlice`
  handle of mutable bits.

# Returns

A `Tristate` boolean of whether the split succeeded and what the last bit in the
slice was.
**/
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b64_split_last_mut(
	this: *mut *mut BitSlice<BigEndian, u64>,
) -> Tristate {
	nullck!(this => Tristate::Error);
	(&mut **this).split_last_mut().map(|(bit, slice)| {
		*this = slice;
		bit
	}).into()
}
/** Attempts to split a mutable `BitSlice` before its last bit.

# Parameters

- `this: *mut *mut BitSlice<LittleEndian, u64>`: Pointer to a mutable `BitSlice`
  handle of mutable bits.

# Returns

A `Tristate` boolean of whether the split succeeded and what the last bit in the
slice was.
**/
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l64_split_last_mut(
	this: *mut *mut BitSlice<LittleEndian, u64>,
) -> Tristate {
	nullck!(this => Tristate::Error);
	(&mut **this).split_last_mut().map(|(bit, slice)| {
		*this = slice;
		bit
	}).into()
}

#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b08_last(this: *const *const BitSlice<BigEndian, u8>) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).last().into()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l08_last(this: *const *const BitSlice<LittleEndian, u8>) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).last().into()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b16_last(this: *const *const BitSlice<BigEndian, u16>) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).last().into()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l16_last(this: *const *const BitSlice<LittleEndian, u16>) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).last().into()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b32_last(this: *const *const BitSlice<BigEndian, u32>) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).last().into()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l32_last(this: *const *const BitSlice<LittleEndian, u32>) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).last().into()
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b64_last(this: *const *const BitSlice<BigEndian, u64>) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).last().into()
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l64_last(this: *const *const BitSlice<LittleEndian, u64>) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).last().into()
}

#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b08_get(this: *const *const BitSlice<BigEndian, u8>, index: usize) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).get(index).into()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l08_get(this: *const *const BitSlice<LittleEndian, u8>, index: usize) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).get(index).into()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b16_get(this: *const *const BitSlice<BigEndian, u16>, index: usize) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).get(index).into()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l16_get(this: *const *const BitSlice<LittleEndian, u16>, index: usize) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).get(index).into()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b32_get(this: *const *const BitSlice<BigEndian, u32>, index: usize) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).get(index).into()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l32_get(this: *const *const BitSlice<LittleEndian, u32>, index: usize) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).get(index).into()
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b64_get(this: *const *const BitSlice<BigEndian, u64>, index: usize) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).get(index).into()
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l64_get(this: *const *const BitSlice<LittleEndian, u64>, index: usize) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).get(index).into()
}

#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b08_set(this: *const *mut BitSlice<BigEndian, u8>, index: usize, value: bool) {
	nullck!(this);
	if index >= (&**this).len() { return; }
	(&mut **this).set(index, value);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l08_set(this: *const *mut BitSlice<LittleEndian, u8>, index: usize, value: bool) {
	nullck!(this);
	if index >= (&**this).len() { return; }
	(&mut **this).set(index, value);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b16_set(this: *const *mut BitSlice<BigEndian, u16>, index: usize, value: bool) {
	nullck!(this);
	if index >= (&**this).len() { return; }
	(&mut **this).set(index, value);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l16_set(this: *const *mut BitSlice<LittleEndian, u16>, index: usize, value: bool) {
	nullck!(this);
	if index >= (&**this).len() { return; }
	(&mut **this).set(index, value);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b32_set(this: *const *mut BitSlice<BigEndian, u32>, index: usize, value: bool) {
	nullck!(this);
	if index >= (&**this).len() { return; }
	(&mut **this).set(index, value);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l32_set(this: *const *mut BitSlice<LittleEndian, u32>, index: usize, value: bool) {
	nullck!(this);
	if index >= (&**this).len() { return; }
	(&mut **this).set(index, value);
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b64_set(this: *const *mut BitSlice<BigEndian, u64>, index: usize, value: bool) {
	nullck!(this);
	if index >= (&**this).len() { return; }
	(&mut **this).set(index, value);
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l64_set(this: *const *mut BitSlice<LittleEndian, u64>, index: usize, value: bool) {
	nullck!(this);
	if index >= (&**this).len() { return; }
	(&mut **this).set(index, value);
}

#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b08_as_ptr(this: *const *const BitSlice<BigEndian, u8>) -> *const u8 {
	nullck!(this => ptr::null());
	(&**this).as_ptr()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l08_as_ptr(this: *const *const BitSlice<LittleEndian, u8>) -> *const u8 {
	nullck!(this => ptr::null());
	(&**this).as_ptr()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b16_as_ptr(this: *const *const BitSlice<BigEndian, u16>) -> *const u16 {
	nullck!(this => ptr::null());
	(&**this).as_ptr()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l16_as_ptr(this: *const *const BitSlice<LittleEndian, u16>) -> *const u16 {
	nullck!(this => ptr::null());
	(&**this).as_ptr()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b32_as_ptr(this: *const *const BitSlice<BigEndian, u32>) -> *const u32 {
	nullck!(this => ptr::null());
	(&**this).as_ptr()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l32_as_ptr(this: *const *const BitSlice<LittleEndian, u32>) -> *const u32 {
	nullck!(this => ptr::null());
	(&**this).as_ptr()
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b64_as_ptr(this: *const *const BitSlice<BigEndian, u64>) -> *const u64 {
	nullck!(this => ptr::null());
	(&**this).as_ptr()
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l64_as_ptr(this: *const *const BitSlice<LittleEndian, u64>) -> *const u64 {
	nullck!(this => ptr::null());
	(&**this).as_ptr()
}

#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b08_as_mut_ptr(this: *const *mut BitSlice<BigEndian, u8>) -> *mut u8 {
	nullck!(this => ptr::null_mut());
	(&mut **this).as_mut_ptr()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l08_as_mut_ptr(this: *const *mut BitSlice<LittleEndian, u8>) -> *mut u8 {
	nullck!(this => ptr::null_mut());
	(&mut **this).as_mut_ptr()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b16_as_mut_ptr(this: *const *mut BitSlice<BigEndian, u16>) -> *mut u16 {
	nullck!(this => ptr::null_mut());
	(&mut **this).as_mut_ptr()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l16_as_mut_ptr(this: *const *mut BitSlice<LittleEndian, u16>) -> *mut u16 {
	nullck!(this => ptr::null_mut());
	(&mut **this).as_mut_ptr()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b32_as_mut_ptr(this: *const *mut BitSlice<BigEndian, u32>) -> *mut u32 {
	nullck!(this => ptr::null_mut());
	(&mut **this).as_mut_ptr()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l32_as_mut_ptr(this: *const *mut BitSlice<LittleEndian, u32>) -> *mut u32 {
	nullck!(this => ptr::null_mut());
	(&mut **this).as_mut_ptr()
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b64_as_mut_ptr(this: *const *mut BitSlice<BigEndian, u64>) -> *mut u64 {
	nullck!(this => ptr::null_mut());
	(&mut **this).as_mut_ptr()
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l64_as_mut_ptr(this: *const *mut BitSlice<LittleEndian, u64>) -> *mut u64 {
	nullck!(this => ptr::null_mut());
	(&mut **this).as_mut_ptr()
}

#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b08_swap(this: *const *mut BitSlice<BigEndian, u8>, a: usize, b: usize) {
	nullck!(this);
	if a >= (&**this).len() || b >= (&**this).len() { return; }
	(&mut **this).swap(a, b);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l08_swap(this: *const *mut BitSlice<LittleEndian, u8>, a: usize, b: usize) {
	nullck!(this);
	if a >= (&**this).len() || b >= (&**this).len() { return; }
	(&mut **this).swap(a, b);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b16_swap(this: *const *mut BitSlice<BigEndian, u16>, a: usize, b: usize) {
	nullck!(this);
	if a >= (&**this).len() || b >= (&**this).len() { return; }
	(&mut **this).swap(a, b);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l16_swap(this: *const *mut BitSlice<LittleEndian, u16>, a: usize, b: usize) {
	nullck!(this);
	if a >= (&**this).len() || b >= (&**this).len() { return; }
	(&mut **this).swap(a, b);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b32_swap(this: *const *mut BitSlice<BigEndian, u32>, a: usize, b: usize) {
	nullck!(this);
	if a >= (&**this).len() || b >= (&**this).len() { return; }
	(&mut **this).swap(a, b);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l32_swap(this: *const *mut BitSlice<LittleEndian, u32>, a: usize, b: usize) {
	nullck!(this);
	if a >= (&**this).len() || b >= (&**this).len() { return; }
	(&mut **this).swap(a, b);
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b64_swap(this: *const *mut BitSlice<BigEndian, u64>, a: usize, b: usize) {
	nullck!(this);
	if a >= (&**this).len() || b >= (&**this).len() { return; }
	(&mut **this).swap(a, b);
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l64_swap(this: *const *mut BitSlice<LittleEndian, u64>, a: usize, b: usize) {
	nullck!(this);
	if a >= (&**this).len() || b >= (&**this).len() { return; }
	(&mut **this).swap(a, b);
}

#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b08_reverse(this: *const *mut BitSlice<BigEndian, u8>) {
	nullck!(this);
	(&mut **this).reverse();
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l08_reverse(this: *const *mut BitSlice<LittleEndian, u8>) {
	nullck!(this);
	(&mut **this).reverse();
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b16_reverse(this: *const *mut BitSlice<BigEndian, u16>) {
	nullck!(this);
	(&mut **this).reverse();
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l16_reverse(this: *const *mut BitSlice<LittleEndian, u16>) {
	nullck!(this);
	(&mut **this).reverse();
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b32_reverse(this: *const *mut BitSlice<BigEndian, u32>) {
	nullck!(this);
	(&mut **this).reverse();
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l32_reverse(this: *const *mut BitSlice<LittleEndian, u32>) {
	nullck!(this);
	(&mut **this).reverse();
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b64_reverse(this: *const *mut BitSlice<BigEndian, u64>) {
	nullck!(this);
	(&mut **this).reverse();
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l64_reverse(this: *const *mut BitSlice<LittleEndian, u64>) {
	nullck!(this);
	(&mut **this).reverse();
}

#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b08_split_at(
	this: *mut *const BitSlice<BigEndian, u8>,
	other: *mut *const BitSlice<BigEndian, u8>,
	mid: usize,
) -> bool {
	nullck!(this, other => false);
	if mid > (&**this).len() { return false; }
	let (l, r) = (&**this).split_at(mid);
	*this = l;
	ptr::write(other, r);
	true
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l08_split_at(
	this: *mut *const BitSlice<LittleEndian, u8>,
	other: *mut *const BitSlice<LittleEndian, u8>,
	mid: usize,
) -> bool {
	nullck!(this, other => false);
	if mid > (&**this).len() { return false; }
	let (l, r) = (&**this).split_at(mid);
	*this = l;
	ptr::write(other, r);
	true
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b16_split_at(
	this: *mut *const BitSlice<BigEndian, u16>,
	other: *mut *const BitSlice<BigEndian, u16>,
	mid: usize,
) -> bool {
	nullck!(this, other => false);
	if mid > (&**this).len() { return false; }
	let (l, r) = (&**this).split_at(mid);
	*this = l;
	ptr::write(other, r);
	true
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l16_split_at(
	this: *mut *const BitSlice<LittleEndian, u16>,
	other: *mut *const BitSlice<LittleEndian, u16>,
	mid: usize,
) -> bool {
	nullck!(this, other => false);
	if mid > (&**this).len() { return false; }
	let (l, r) = (&**this).split_at(mid);
	*this = l;
	ptr::write(other, r);
	true
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b32_split_at(
	this: *mut *const BitSlice<BigEndian, u32>,
	other: *mut *const BitSlice<BigEndian, u32>,
	mid: usize,
) -> bool {
	nullck!(this, other => false);
	if mid > (&**this).len() { return false; }
	let (l, r) = (&**this).split_at(mid);
	*this = l;
	ptr::write(other, r);
	true
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l32_split_at(
	this: *mut *const BitSlice<LittleEndian, u32>,
	other: *mut *const BitSlice<LittleEndian, u32>,
	mid: usize,
) -> bool {
	nullck!(this, other => false);
	if mid > (&**this).len() { return false; }
	let (l, r) = (&**this).split_at(mid);
	*this = l;
	ptr::write(other, r);
	true
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b64_split_at(
	this: *mut *const BitSlice<BigEndian, u64>,
	other: *mut *const BitSlice<BigEndian, u64>,
	mid: usize,
) -> bool {
	nullck!(this, other => false);
	if mid > (&**this).len() { return false; }
	let (l, r) = (&**this).split_at(mid);
	*this = l;
	ptr::write(other, r);
	true
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l64_split_at(
	this: *mut *const BitSlice<LittleEndian, u64>,
	other: *mut *const BitSlice<LittleEndian, u64>,
	mid: usize,
) -> bool {
	nullck!(this, other => false);
	if mid > (&**this).len() { return false; }
	let (l, r) = (&**this).split_at(mid);
	*this = l;
	ptr::write(other, r);
	true
}

#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b08_split_at_mut(
	this: *mut *mut BitSlice<BigEndian, u8>,
	other: *mut *mut BitSlice<BigEndian, u8>,
	mid: usize,
) -> bool {
	nullck!(this, other => false);
	if mid > (&**this).len() { return false; }
	let (l, r) = (&mut **this).split_at_mut(mid);
	*this = l;
	ptr::write(other, r);
	true
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l08_split_at_mut(
	this: *mut *mut BitSlice<LittleEndian, u8>,
	other: *mut *mut BitSlice<LittleEndian, u8>,
	mid: usize,
) -> bool {
	nullck!(this, other => false);
	if mid > (&**this).len() { return false; }
	let (l, r) = (&mut **this).split_at_mut(mid);
	*this = l;
	ptr::write(other, r);
	true
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b16_split_at_mut(
	this: *mut *mut BitSlice<BigEndian, u16>,
	other: *mut *mut BitSlice<BigEndian, u16>,
	mid: usize,
) -> bool {
	nullck!(this, other => false);
	if mid > (&**this).len() { return false; }
	let (l, r) = (&mut **this).split_at_mut(mid);
	*this = l;
	ptr::write(other, r);
	true
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l16_split_at_mut(
	this: *mut *mut BitSlice<LittleEndian, u16>,
	other: *mut *mut BitSlice<LittleEndian, u16>,
	mid: usize,
) -> bool {
	nullck!(this, other => false);
	if mid > (&**this).len() { return false; }
	let (l, r) = (&mut **this).split_at_mut(mid);
	*this = l;
	ptr::write(other, r);
	true
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b32_split_at_mut(
	this: *mut *mut BitSlice<BigEndian, u32>,
	other: *mut *mut BitSlice<BigEndian, u32>,
	mid: usize,
) -> bool {
	nullck!(this, other => false);
	if mid > (&**this).len() { return false; }
	let (l, r) = (&mut **this).split_at_mut(mid);
	*this = l;
	ptr::write(other, r);
	true
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l32_split_at_mut(
	this: *mut *mut BitSlice<LittleEndian, u32>,
	other: *mut *mut BitSlice<LittleEndian, u32>,
	mid: usize,
) -> bool {
	nullck!(this, other => false);
	if mid > (&**this).len() { return false; }
	let (l, r) = (&mut **this).split_at_mut(mid);
	*this = l;
	ptr::write(other, r);
	true
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b64_split_at_mut(
	this: *mut *mut BitSlice<BigEndian, u64>,
	other: *mut *mut BitSlice<BigEndian, u64>,
	mid: usize,
) -> bool {
	nullck!(this, other => false);
	if mid > (&**this).len() { return false; }
	let (l, r) = (&mut **this).split_at_mut(mid);
	*this = l;
	ptr::write(other, r);
	true
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l64_split_at_mut(
	this: *mut *mut BitSlice<LittleEndian, u64>,
	other: *mut *mut BitSlice<LittleEndian, u64>,
	mid: usize,
) -> bool {
	nullck!(this, other => false);
	if mid > (&**this).len() { return false; }
	let (l, r) = (&mut **this).split_at_mut(mid);
	*this = l;
	ptr::write(other, r);
	true
}

#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b08_rotate_left(this: *const *mut BitSlice<BigEndian, u8>, by: usize) {
	nullck!(this);
	if by > (&**this).len() { return; }
	(&mut **this).rotate_left(by);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l08_rotate_left(this: *const *mut BitSlice<LittleEndian, u8>, by: usize) {
	nullck!(this);
	if by > (&**this).len() { return; }
	(&mut **this).rotate_left(by);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b16_rotate_left(this: *const *mut BitSlice<BigEndian, u16>, by: usize) {
	nullck!(this);
	if by > (&**this).len() { return; }
	(&mut **this).rotate_left(by);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l16_rotate_left(this: *const *mut BitSlice<LittleEndian, u16>, by: usize) {
	nullck!(this);
	if by > (&**this).len() { return; }
	(&mut **this).rotate_left(by);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b32_rotate_left(this: *const *mut BitSlice<BigEndian, u32>, by: usize) {
	nullck!(this);
	if by > (&**this).len() { return; }
	(&mut **this).rotate_left(by);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l32_rotate_left(this: *const *mut BitSlice<LittleEndian, u32>, by: usize) {
	nullck!(this);
	if by > (&**this).len() { return; }
	(&mut **this).rotate_left(by);
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b64_rotate_left(this: *const *mut BitSlice<BigEndian, u64>, by: usize) {
	nullck!(this);
	if by > (&**this).len() { return; }
	(&mut **this).rotate_left(by);
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l64_rotate_left(this: *const *mut BitSlice<LittleEndian, u64>, by: usize) {
	nullck!(this);
	if by > (&**this).len() { return; }
	(&mut **this).rotate_left(by);
}

#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b08_rotate_right(this: *const *mut BitSlice<BigEndian, u8>, by: usize) {
	nullck!(this);
	if by > (&**this).len() { return; }
	(&mut **this).rotate_right(by);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l08_rotate_right(this: *const *mut BitSlice<LittleEndian, u8>, by: usize) {
	nullck!(this);
	if by > (&**this).len() { return; }
	(&mut **this).rotate_right(by);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b16_rotate_right(this: *const *mut BitSlice<BigEndian, u16>, by: usize) {
	nullck!(this);
	if by > (&**this).len() { return; }
	(&mut **this).rotate_right(by);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l16_rotate_right(this: *const *mut BitSlice<LittleEndian, u16>, by: usize) {
	nullck!(this);
	if by > (&**this).len() { return; }
	(&mut **this).rotate_right(by);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b32_rotate_right(this: *const *mut BitSlice<BigEndian, u32>, by: usize) {
	nullck!(this);
	if by > (&**this).len() { return; }
	(&mut **this).rotate_right(by);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l32_rotate_right(this: *const *mut BitSlice<LittleEndian, u32>, by: usize) {
	nullck!(this);
	if by > (&**this).len() { return; }
	(&mut **this).rotate_right(by);
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b64_rotate_right(this: *const *mut BitSlice<BigEndian, u64>, by: usize) {
	nullck!(this);
	if by > (&**this).len() { return; }
	(&mut **this).rotate_right(by);
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l64_rotate_right(this: *const *mut BitSlice<LittleEndian, u64>, by: usize) {
	nullck!(this);
	if by > (&**this).len() { return; }
	(&mut **this).rotate_right(by);
}

#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b08_all(this: *const *const BitSlice<BigEndian, u8>) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).all().into()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l08_all(this: *const *const BitSlice<LittleEndian, u8>) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).all().into()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b16_all(this: *const *const BitSlice<BigEndian, u16>) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).all().into()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l16_all(this: *const *const BitSlice<LittleEndian, u16>) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).all().into()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b32_all(this: *const *const BitSlice<BigEndian, u32>) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).all().into()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l32_all(this: *const *const BitSlice<LittleEndian, u32>) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).all().into()
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b64_all(this: *const *const BitSlice<BigEndian, u64>) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).all().into()
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l64_all(this: *const *const BitSlice<LittleEndian, u64>) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).all().into()
}

#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b08_any(this: *const *const BitSlice<BigEndian, u8>) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).any().into()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l08_any(this: *const *const BitSlice<LittleEndian, u8>) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).any().into()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b16_any(this: *const *const BitSlice<BigEndian, u16>) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).any().into()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l16_any(this: *const *const BitSlice<LittleEndian, u16>) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).any().into()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b32_any(this: *const *const BitSlice<BigEndian, u32>) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).any().into()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l32_any(this: *const *const BitSlice<LittleEndian, u32>) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).any().into()
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b64_any(this: *const *const BitSlice<BigEndian, u64>) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).any().into()
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l64_any(this: *const *const BitSlice<LittleEndian, u64>) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).any().into()
}

#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b08_not_all(this: *const *const BitSlice<BigEndian, u8>) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).not_all().into()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l08_not_all(this: *const *const BitSlice<LittleEndian, u8>) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).not_all().into()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b16_not_all(this: *const *const BitSlice<BigEndian, u16>) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).not_all().into()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l16_not_all(this: *const *const BitSlice<LittleEndian, u16>) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).not_all().into()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b32_not_all(this: *const *const BitSlice<BigEndian, u32>) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).not_all().into()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l32_not_all(this: *const *const BitSlice<LittleEndian, u32>) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).not_all().into()
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b64_not_all(this: *const *const BitSlice<BigEndian, u64>) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).not_all().into()
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l64_not_all(this: *const *const BitSlice<LittleEndian, u64>) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).not_all().into()
}

#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b08_not_any(this: *const *const BitSlice<BigEndian, u8>) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).not_any().into()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l08_not_any(this: *const *const BitSlice<LittleEndian, u8>) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).not_any().into()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b16_not_any(this: *const *const BitSlice<BigEndian, u16>) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).not_any().into()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l16_not_any(this: *const *const BitSlice<LittleEndian, u16>) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).not_any().into()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b32_not_any(this: *const *const BitSlice<BigEndian, u32>) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).not_any().into()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l32_not_any(this: *const *const BitSlice<LittleEndian, u32>) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).not_any().into()
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b64_not_any(this: *const *const BitSlice<BigEndian, u64>) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).not_any().into()
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l64_not_any(this: *const *const BitSlice<LittleEndian, u64>) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).not_any().into()
}

#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b08_some(this: *const *const BitSlice<BigEndian, u8>) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).some().into()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l08_some(this: *const *const BitSlice<LittleEndian, u8>) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).some().into()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b16_some(this: *const *const BitSlice<BigEndian, u16>) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).some().into()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l16_some(this: *const *const BitSlice<LittleEndian, u16>) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).some().into()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b32_some(this: *const *const BitSlice<BigEndian, u32>) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).some().into()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l32_some(this: *const *const BitSlice<LittleEndian, u32>) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).some().into()
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b64_some(this: *const *const BitSlice<BigEndian, u64>) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).some().into()
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l64_some(this: *const *const BitSlice<LittleEndian, u64>) -> Tristate {
	nullck!(this => Tristate::Error);
	(&**this).some().into()
}

#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b08_count_ones(this: *const *const BitSlice<BigEndian, u8>) -> usize {
	nullck!(this => 0);
	(&**this).count_ones()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l08_count_ones(this: *const *const BitSlice<LittleEndian, u8>) -> usize {
	nullck!(this => 0);
	(&**this).count_ones()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b16_count_ones(this: *const *const BitSlice<BigEndian, u16>) -> usize {
	nullck!(this => 0);
	(&**this).count_ones()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l16_count_ones(this: *const *const BitSlice<LittleEndian, u16>) -> usize {
	nullck!(this => 0);
	(&**this).count_ones()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b32_count_ones(this: *const *const BitSlice<BigEndian, u32>) -> usize {
	nullck!(this => 0);
	(&**this).count_ones()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l32_count_ones(this: *const *const BitSlice<LittleEndian, u32>) -> usize {
	nullck!(this => 0);
	(&**this).count_ones()
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b64_count_ones(this: *const *const BitSlice<BigEndian, u64>) -> usize {
	nullck!(this => 0);
	(&**this).count_ones()
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l64_count_ones(this: *const *const BitSlice<LittleEndian, u64>) -> usize {
	nullck!(this => 0);
	(&**this).count_ones()
}

#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b08_count_zeros(this: *const *const BitSlice<BigEndian, u8>) -> usize {
	nullck!(this => 0);
	(&**this).count_zeros()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l08_count_zeros(this: *const *const BitSlice<LittleEndian, u8>) -> usize {
	nullck!(this => 0);
	(&**this).count_zeros()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b16_count_zeros(this: *const *const BitSlice<BigEndian, u16>) -> usize {
	nullck!(this => 0);
	(&**this).count_zeros()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l16_count_zeros(this: *const *const BitSlice<LittleEndian, u16>) -> usize {
	nullck!(this => 0);
	(&**this).count_zeros()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b32_count_zeros(this: *const *const BitSlice<BigEndian, u32>) -> usize {
	nullck!(this => 0);
	(&**this).count_zeros()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l32_count_zeros(this: *const *const BitSlice<LittleEndian, u32>) -> usize {
	nullck!(this => 0);
	(&**this).count_zeros()
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b64_count_zeros(this: *const *const BitSlice<BigEndian, u64>) -> usize {
	nullck!(this => 0);
	(&**this).count_zeros()
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l64_count_zeros(this: *const *const BitSlice<LittleEndian, u64>) -> usize {
	nullck!(this => 0);
	(&**this).count_zeros()
}

#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b08_set_all(this: *const *mut BitSlice<BigEndian, u8>, value: bool) {
	nullck!(this);
	(&mut **this).set_all(value);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l08_set_all(this: *const *mut BitSlice<LittleEndian, u8>, value: bool) {
	nullck!(this);
	(&mut **this).set_all(value);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b16_set_all(this: *const *mut BitSlice<BigEndian, u16>, value: bool) {
	nullck!(this);
	(&mut **this).set_all(value);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l16_set_all(this: *const *mut BitSlice<LittleEndian, u16>, value: bool) {
	nullck!(this);
	(&mut **this).set_all(value);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b32_set_all(this: *const *mut BitSlice<BigEndian, u32>, value: bool) {
	nullck!(this);
	(&mut **this).set_all(value);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l32_set_all(this: *const *mut BitSlice<LittleEndian, u32>, value: bool) {
	nullck!(this);
	(&mut **this).set_all(value);
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b64_set_all(this: *const *mut BitSlice<BigEndian, u64>, value: bool) {
	nullck!(this);
	(&mut **this).set_all(value);
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l64_set_all(this: *const *mut BitSlice<LittleEndian, u64>, value: bool) {
	nullck!(this);
	(&mut **this).set_all(value);
}

#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b08_for_each(this: *const *mut BitSlice<BigEndian, u8>, func: fn(usize, bool) -> bool) {
	nullck!(this);
	(&mut **this).for_each(func)
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l08_for_each(this: *const *mut BitSlice<LittleEndian, u8>, func: fn(usize, bool) -> bool) {
	nullck!(this);
	(&mut **this).for_each(func)
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b16_for_each(this: *const *mut BitSlice<BigEndian, u16>, func: fn(usize, bool) -> bool) {
	nullck!(this);
	(&mut **this).for_each(func)
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l16_for_each(this: *const *mut BitSlice<LittleEndian, u16>, func: fn(usize, bool) -> bool) {
	nullck!(this);
	(&mut **this).for_each(func)
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b32_for_each(this: *const *mut BitSlice<BigEndian, u32>, func: fn(usize, bool) -> bool) {
	nullck!(this);
	(&mut **this).for_each(func)
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l32_for_each(this: *const *mut BitSlice<LittleEndian, u32>, func: fn(usize, bool) -> bool) {
	nullck!(this);
	(&mut **this).for_each(func)
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b64_for_each(this: *const *mut BitSlice<BigEndian, u64>, func: fn(usize, bool) -> bool) {
	nullck!(this);
	(&mut **this).for_each(func)
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l64_for_each(this: *const *mut BitSlice<LittleEndian, u64>, func: fn(usize, bool) -> bool) {
	nullck!(this);
	(&mut **this).for_each(func)
}

#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b08_as_slice(this: *const *const BitSlice<BigEndian, u8>, len: *mut usize) -> *const u8 {
	nullck!(this => ptr::null());
	let slice = (&**this).as_slice();
	*len = slice.len();
	slice.as_ptr()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l08_as_slice(this: *const *const BitSlice<LittleEndian, u8>, len: *mut usize) -> *const u8 {
	nullck!(this => ptr::null());
	let slice = (&**this).as_slice();
	*len = slice.len();
	slice.as_ptr()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b16_as_slice(this: *const *const BitSlice<BigEndian, u16>, len: *mut usize) -> *const u16 {
	nullck!(this => ptr::null());
	let slice = (&**this).as_slice();
	*len = slice.len();
	slice.as_ptr()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l16_as_slice(this: *const *const BitSlice<LittleEndian, u16>, len: *mut usize) -> *const u16 {
	nullck!(this => ptr::null());
	let slice = (&**this).as_slice();
	*len = slice.len();
	slice.as_ptr()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b32_as_slice(this: *const *const BitSlice<BigEndian, u32>, len: *mut usize) -> *const u32 {
	nullck!(this => ptr::null());
	let slice = (&**this).as_slice();
	*len = slice.len();
	slice.as_ptr()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l32_as_slice(this: *const *const BitSlice<LittleEndian, u32>, len: *mut usize) -> *const u32 {
	nullck!(this => ptr::null());
	let slice = (&**this).as_slice();
	*len = slice.len();
	slice.as_ptr()
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b64_as_slice(this: *const *const BitSlice<BigEndian, u64>, len: *mut usize) -> *const u64 {
	nullck!(this => ptr::null());
	let slice = (&**this).as_slice();
	*len = slice.len();
	slice.as_ptr()
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l64_as_slice(this: *const *const BitSlice<LittleEndian, u64>, len: *mut usize) -> *const u64 {
	nullck!(this => ptr::null());
	let slice = (&**this).as_slice();
	*len = slice.len();
	slice.as_ptr()
}

#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b08_as_mut_slice(this: *const *mut BitSlice<BigEndian, u8>, len: *mut usize) -> *mut u8 {
	nullck!(this => ptr::null_mut());
	let slice = (&mut **this).as_mut_slice();
	*len = slice.len();
	slice.as_mut_ptr()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l08_as_mut_slice(this: *const *mut BitSlice<LittleEndian, u8>, len: *mut usize) -> *mut u8 {
	nullck!(this => ptr::null_mut());
	let slice = (&mut **this).as_mut_slice();
	*len = slice.len();
	slice.as_mut_ptr()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b16_as_mut_slice(this: *const *mut BitSlice<BigEndian, u16>, len: *mut usize) -> *mut u16 {
	nullck!(this => ptr::null_mut());
	let slice = (&mut **this).as_mut_slice();
	*len = slice.len();
	slice.as_mut_ptr()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l16_as_mut_slice(this: *const *mut BitSlice<LittleEndian, u16>, len: *mut usize) -> *mut u16 {
	nullck!(this => ptr::null_mut());
	let slice = (&mut **this).as_mut_slice();
	*len = slice.len();
	slice.as_mut_ptr()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b32_as_mut_slice(this: *const *mut BitSlice<BigEndian, u32>, len: *mut usize) -> *mut u32 {
	nullck!(this => ptr::null_mut());
	let slice = (&mut **this).as_mut_slice();
	*len = slice.len();
	slice.as_mut_ptr()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l32_as_mut_slice(this: *const *mut BitSlice<LittleEndian, u32>, len: *mut usize) -> *mut u32 {
	nullck!(this => ptr::null_mut());
	let slice = (&mut **this).as_mut_slice();
	*len = slice.len();
	slice.as_mut_ptr()
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_b64_as_mut_slice(this: *const *mut BitSlice<BigEndian, u64>, len: *mut usize) -> *mut u64 {
	nullck!(this => ptr::null_mut());
	let slice = (&mut **this).as_mut_slice();
	*len = slice.len();
	slice.as_mut_ptr()
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bs_l64_as_mut_slice(this: *const *mut BitSlice<LittleEndian, u64>, len: *mut usize) -> *mut u64 {
	nullck!(this => ptr::null_mut());
	let slice = (&mut **this).as_mut_slice();
	*len = slice.len();
	slice.as_mut_ptr()
}
