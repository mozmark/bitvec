#ifndef BITVEC_FFI_BITSLICE_H
#define BITVEC_FFI_BITSLICE_H

/*!
 * @file bitvec/bitslice.h
 *
 * @brief Bindings to the `BitSlice` type family functions.
 *
 * This file has the following sections:
 *
 * 1. Definitions of FFI types. These types are used in the signatures of the
 *    FFI function declarations in C, and definitions in Rust.
 *
 * 2. Definitions of C wrappers. These types are to be used in C as wrappers
 *    over the FFI types. The FFI types have no semantic information; the
 *    wrappers add this information.
 *
 * 3. Declarations of all the Rust FFI signatures. These signatures match the
 *    functions defined, and symbol-exported, in the Rust library's `ffi`
 *    module.
 */

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

//  This file is built to be a polyglot C and C++ header. When read as C++, it
//  must match the layout of `bitvec.hpp`.
#ifdef __cplusplus
namespace bitvec {
//  Ensure that all the types and functions laid out in this file have C-ABI
//  linkage and mangling specifications.
extern "C" {
#endif

// -----------------------------------------------------------------------------
// # 1. FFI Type Definitions
// -----------------------------------------------------------------------------

/**
 * @struct BitPtrImmut
 *
 * @brief Pointer to a slice of immutable bits.
 *
 * @note This structure mimics the `BitPtr<T>` on the Rust side. Its member
 * values are mangled, and cannot be meaningfully read by C.
 *
 * This handle should not be used directly; prefer the BitSlice$C$T variants
 * laid out below.
 */
struct BitPtrImmut {
#ifdef __cplusplus
//  If this is being used in C++, prevent direct external access to the fields.
protected:
#endif
	/// Mangled pointer to the slice region.
	const void * ptr;
	/// Mangled length of the slice region.
	size_t len;
};

/**
 * @struct BitPtrMut
 *
 * @brief Pointer to a slice of mutable bits.
 *
 * @note This structure mimics the `BitPtr<T>` on the Rust side. Its member
 * values are mangled, and cannot be meaningfully read by C.
 *
 * This handle should not be used directly; prefer the BitSlice$C$T variants
 * laid out below.
 */
struct BitPtrMut {
#ifdef __cplusplus
//  If this is being used in C++, prevent direct external access to the fields.
protected:
#endif
	/// Mangled pointer to the slice region.
	void * ptr;
	/// Mangled length of the slice region.
	size_t len;
};

/**
 * @brief Freezes the bits behind a handle.
 * @param self Pointer to mutable bits.
 * @return Pointer to those bits, now immutable.
 *
 * This function constrains the slice from changing its width.
 */
const struct BitPtrImmut * const rsbv_bitptr_freeze(
	const struct BitPtrMut * const self
) {
	return (const struct BitPtrImmut * const)(const void * const)self;
}

/**
 * @brief Freezes the bits behind a handle.
 * @param self Pointer to mutable bits.
 * @return Pointer to those bits, now immutable.
 *
 * This function does not constrain the slice from changing its width.
 */
struct BitPtrImmut * const rsbv_bitptr_freeze_mut(
	struct BitPtrMut * const self
) {
	return (struct BitPtrImmut * const)(void * const)self;
}

/**
 * @union BitPtr
 *
 * @brief Pointer to a slice of bits. The bits may be accessed mutably or
 * immutably.
 */
union BitPtr {
	/// Pointer to immutable bits.
	struct BitPtrImmut immut;
	/// Pointer to mutable bits.
	struct BitPtrMut mut;
};

// -----------------------------------------------------------------------------
// # 2. Wrapper Type Definitions
// -----------------------------------------------------------------------------

/**
 * @enum Tristate
 *
 * @brief C encoding of Rust `Option<bool>`.
 *
 * This enumeration is the return value for functions which intend to return a
 * `bool` but may fail to do so. Functions which intend to return `void` but may
 * fail return `bool` as a success signal.
 */
enum Tristate {
	/// The function failed to operate. Rust: `None`
	Error = -1,
	/// The function succeeded, and returned `false`. Rust: `Some(false)`.
	False = 0,
	/// The function succeeded, and returned `true`. Rust: `Some(true)`.
	True = 1,
};

/**
 * @struct BitSliceB08
 *
 * @brief Opaque handle to a slice of bits.
 *
 * The bits are in big-endian order, chunked in one-byte intervals.
 */
struct BitSliceB08 {
	/// Im/mutable pointer to the bits this handle governs.
	union BitPtr bp;
};

/**
 * @struct BitSliceL08
 *
 * @brief Opaque handle to a slice of bits.
 *
 * The bits are in little-endian order, chunked in one-byte intervals.
 */
struct BitSliceL08 {
	/// Im/mutable pointer to the bits this handle governs.
	union BitPtr bp;
};

/**
 * @struct BitSliceB16
 *
 * @brief Opaque handle to a slice of bits.
 *
 * The bits are in big-endian order, chunked in two-byte intervals.
 */
struct BitSliceB16 {
	/// Im/mutable pointer to the bits this handle governs.
	union BitPtr bp;
};

/**
 * @struct BitSliceL16
 *
 * @brief Opaque handle to a slice of bits.
 *
 * The bits are in little-endian order, chunked in two-byte intervals.
 */
struct BitSliceL16 {
	/// Im/mutable pointer to the bits this handle governs.
	union BitPtr bp;
};

/**
 * @struct BitSliceB32
 *
 * @brief Opaque handle to a slice of bits.
 *
 * The bits are in big-endian order, chunked in four-byte intervals.
 */
struct BitSliceB32 {
	/// Im/mutable pointer to the bits this handle governs.
	union BitPtr bp;
};

/**
 * @struct BitSliceL32
 *
 * @brief Opaque handle to a slice of bits.
 *
 * The bits are in little-endian order, chunked in four-byte intervals.
 */
struct BitSliceL32 {
	/// Im/mutable pointer to the bits this handle governs.
	union BitPtr bp;
};

/**
 * @struct BitSliceB64
 *
 * @brief Opaque handle to a slice of bits.
 *
 * The bits are in big-endian order, chunked in eight-byte intervals.
 */
struct BitSliceB64 {
	/// Im/mutable pointer to the bits this handle governs.
	union BitPtr bp;
};

/**
 * @struct BitSliceL64
 *
 * @brief Opaque handle to a slice of bits.
 *
 * The bits are in little-endian order, chunked in eight-byte intervals.
 */
struct BitSliceL64 {
	/// Im/mutable pointer to the bits this handle governs.
	union BitPtr bp;
};

/**
 * @brief Gets the `BitPtrImmut` from a handle.
 * @param rsbvhbs Binding name for any of the `struct BitSlice$C$T` variants.
 * @return The BitPtrImmut inner value.
 *
 * This macro permits correctly using a handle value in the functions that act
 * on it. C will not allow implicit pointer conversion from `Handle$C$T *` to
 * the desired `BitPtr$M *`; this macro performs the correct conversion.
 *
 * This takes bindings to values; a pointer-to-handle must be dereferenced in
 * the argument position.
 */
#define RSBV_BS_IMMUT(rsbvhbs) &(rsbvhbs.bp.immut)
/**
 * @brief Gets the `BitPtrMut` from a handle.
 * @param rsbvhbs Binding name for any of the `struct BitSlice$C$T` variants.
 * @return The BitPtrMut inner value.
 *
 * This macro permits correctly using a handle value in the functions that act
 * on it. C will not allow implicit pointer conversion from `Handle$C$T *` to
 * the desired `BitPtr$M *`; this macro performs the correct conversion.
 *
 * This takes bindings to values; a pointer-to-handle must be dereferenced in
 * the argument position.
 */
#define RSBV_BS_MUT(rsbvhbs) &(rsbvhbs.bp.mut)

// -----------------------------------------------------------------------------
// # 3. FFI Binding Declarations
// -----------------------------------------------------------------------------

//  ## 3.1 BitSlice::<C, T>::empty

/**
 * @brief Initializes a `BitSlice` handle to govern the empty slice.
 * @param[out] self Pointer to an uninitialized `BitSlice` handle. If this is
 * not `null`, then after this function returns, the pointed handle is
 * initialized to the empty slice.
 */
extern void bitvec_bs_b08_empty(struct BitPtrImmut *const self);

/**
 * @brief Initializes a `BitSlice` handle to govern the empty slice.
 * @param[out] self Pointer to an uninitialized `BitSlice` handle. If this is
 * not `null`, then after this function returns, the pointed handle is
 * initialized to the empty slice.
 */
extern void bitvec_bs_l08_empty(struct BitPtrImmut *const self);

/**
 * @brief Initializes a `BitSlice` handle to govern the empty slice.
 * @param[out] self Pointer to an uninitialized `BitSlice` handle. If this is
 * not `null`, then after this function returns, the pointed handle is
 * initialized to the empty slice.
 */
extern void bitvec_bs_b16_empty(struct BitPtrImmut *const self);

/**
 * @brief Initializes a `BitSlice` handle to govern the empty slice.
 * @param[out] self Pointer to an uninitialized `BitSlice` handle. If this is
 * not `null`, then after this function returns, the pointed handle is
 * initialized to the empty slice.
 */
extern void bitvec_bs_l16_empty(struct BitPtrImmut *const self);

/**
 * @brief Initializes a `BitSlice` handle to govern the empty slice.
 * @param[out] self Pointer to an uninitialized `BitSlice` handle. If this is
 * not `null`, then after this function returns, the pointed handle is
 * initialized to the empty slice.
 */
extern void bitvec_bs_b32_empty(struct BitPtrImmut *const self);

/**
 * @brief Initializes a `BitSlice` handle to govern the empty slice.
 * @param[out] self Pointer to an uninitialized `BitSlice` handle. If this is
 * not `null`, then after this function returns, the pointed handle is
 * initialized to the empty slice.
 */
extern void bitvec_bs_l32_empty(struct BitPtrImmut *const self);

/**
 * @brief Initializes a `BitSlice` handle to govern the empty slice.
 * @param[out] self Pointer to an uninitialized `BitSlice` handle. If this is
 * not `null`, then after this function returns, the pointed handle is
 * initialized to the empty slice.
 */
extern void bitvec_bs_b64_empty(struct BitPtrImmut *const self);

/**
 * @brief Initializes a `BitSlice` handle to govern the empty slice.
 * @param[out] self Pointer to an uninitialized `BitSlice` handle. If this is
 * not `null`, then after this function returns, the pointed handle is
 * initialized to the empty slice.
 */
extern void bitvec_bs_l64_empty(struct BitPtrImmut *const self);

/**
 * @brief Initializes a `BitSlice` handle to govern the empty slice.
 * @param[out] self Pointer to an uninitialized `BitSlice` handle. If this is
 * not `null`, then after this function returns, the pointed handle is
 * initialized to the empty slice.
 */
extern void bitvec_bs_b08_empty_mut(struct BitPtrMut *const self);

/**
 * @brief Initializes a `BitSlice` handle to govern the empty slice.
 * @param[out] self Pointer to an uninitialized `BitSlice` handle. If this is
 * not `null`, then after this function returns, the pointed handle is
 * initialized to the empty slice.
 */
extern void bitvec_bs_l08_empty_mut(struct BitPtrMut *const self);

/**
 * @brief Initializes a `BitSlice` handle to govern the empty slice.
 * @param[out] self Pointer to an uninitialized `BitSlice` handle. If this is
 * not `null`, then after this function returns, the pointed handle is
 * initialized to the empty slice.
 */
extern void bitvec_bs_b16_empty_mut(struct BitPtrMut *const self);

/**
 * @brief Initializes a `BitSlice` handle to govern the empty slice.
 * @param[out] self Pointer to an uninitialized `BitSlice` handle. If this is
 * not `null`, then after this function returns, the pointed handle is
 * initialized to the empty slice.
 */
extern void bitvec_bs_l16_empty_mut(struct BitPtrMut *const self);

/**
 * @brief Initializes a `BitSlice` handle to govern the empty slice.
 * @param[out] self Pointer to an uninitialized `BitSlice` handle. If this is
 * not `null`, then after this function returns, the pointed handle is
 * initialized to the empty slice.
 */
extern void bitvec_bs_b32_empty_mut(struct BitPtrMut *const self);

/**
 * @brief Initializes a `BitSlice` handle to govern the empty slice.
 * @param[out] self Pointer to an uninitialized `BitSlice` handle. If this is
 * not `null`, then after this function returns, the pointed handle is
 * initialized to the empty slice.
 */
extern void bitvec_bs_l32_empty_mut(struct BitPtrMut *const self);

/**
 * @brief Initializes a `BitSlice` handle to govern the empty slice.
 * @param[out] self Pointer to an uninitialized `BitSlice` handle. If this is
 * not `null`, then after this function returns, the pointed handle is
 * initialized to the empty slice.
 */
extern void bitvec_bs_b64_empty_mut(struct BitPtrMut *const self);

/**
 * @brief Initializes a `BitSlice` handle to govern the empty slice.
 * @param[out] self Pointer to an uninitialized `BitSlice` handle. If this is
 * not `null`, then after this function returns, the pointed handle is
 * initialized to the empty slice.
 */
extern void bitvec_bs_l64_empty_mut(struct BitPtrMut *const self);


/**
 * @brief Initializes a slice handle from a provided span pointer and element
 * count.
 * @param[out] self Pointer to an uninitialized slice handle over immutable
 * bits.
 * @param ptr Pointer to the first element in the span of memory that the handle
 * will govern.
 * @param len Length (in storage elements) of the span.
 * @return Success signal for handle initialization.
 * @retval `true` `self` and `ptr` were both non-`null`, and `*self` is now
 * initialized.
 * @retval `false` `self` or `ptr` were `null`, and `*self` is not initialized.
 */
extern bool bitvec_bs_b08_from_span(
	struct BitPtrImmut *const self,
	const uint8_t  *const ptr,
	const size_t len
);

/**
 * @brief Initializes a slice handle from a provided span pointer and element
 * count.
 * @param[out] self Pointer to an uninitialized slice handle over immutable
 * bits.
 * @param ptr Pointer to the first element in the span of memory that the handle
 * will govern.
 * @param len Length (in storage elements) of the span.
 * @return Success signal for handle initialization.
 * @retval `true` `self` and `ptr` were both non-`null`, and `*self` is now
 * initialized.
 * @retval `false` `self` or `ptr` were `null`, and `*self` is not initialized.
 */
extern bool bitvec_bs_l08_from_span(
	struct BitPtrImmut *const self,
	const uint8_t  *const ptr,
	const size_t len
);

/**
 * @brief Initializes a slice handle from a provided span pointer and element
 * count.
 * @param[out] self Pointer to an uninitialized slice handle over immutable
 * bits.
 * @param ptr Pointer to the first element in the span of memory that the handle
 * will govern.
 * @param len Length (in storage elements) of the span.
 * @return Success signal for handle initialization.
 * @retval `true` `self` and `ptr` were both non-`null`, and `*self` is now
 * initialized.
 * @retval `false` `self` or `ptr` were `null`, and `*self` is not initialized.
 */
extern bool bitvec_bs_b16_from_span(
	struct BitPtrImmut *const self,
	const uint16_t *const ptr,
	const size_t len
);

/**
 * @brief Initializes a slice handle from a provided span pointer and element
 * count.
 * @param[out] self Pointer to an uninitialized slice handle over immutable
 * bits.
 * @param ptr Pointer to the first element in the span of memory that the handle
 * will govern.
 * @param len Length (in storage elements) of the span.
 * @return Success signal for handle initialization.
 * @retval `true` `self` and `ptr` were both non-`null`, and `*self` is now
 * initialized.
 * @retval `false` `self` or `ptr` were `null`, and `*self` is not initialized.
 */
extern bool bitvec_bs_l16_from_span(
	struct BitPtrImmut *const self,
	const uint16_t *const ptr,
	const size_t len
);

/**
 * @brief Initializes a slice handle from a provided span pointer and element
 * count.
 * @param[out] self Pointer to an uninitialized slice handle over immutable
 * bits.
 * @param ptr Pointer to the first element in the span of memory that the handle
 * will govern.
 * @param len Length (in storage elements) of the span.
 * @return Success signal for handle initialization.
 * @retval `true` `self` and `ptr` were both non-`null`, and `*self` is now
 * initialized.
 * @retval `false` `self` or `ptr` were `null`, and `*self` is not initialized.
 */
extern bool bitvec_bs_b32_from_span(
	struct BitPtrImmut *const self,
	const uint32_t *const ptr,
	const size_t len
);

/**
 * @brief Initializes a slice handle from a provided span pointer and element
 * count.
 * @param[out] self Pointer to an uninitialized slice handle over immutable
 * bits.
 * @param ptr Pointer to the first element in the span of memory that the handle
 * will govern.
 * @param len Length (in storage elements) of the span.
 * @return Success signal for handle initialization.
 * @retval `true` `self` and `ptr` were both non-`null`, and `*self` is now
 * initialized.
 * @retval `false` `self` or `ptr` were `null`, and `*self` is not initialized.
 */
extern bool bitvec_bs_l32_from_span(
	struct BitPtrImmut *const self,
	const uint32_t *const ptr,
	const size_t len
);

/**
 * @brief Initializes a slice handle from a provided span pointer and element
 * count.
 * @param[out] self Pointer to an uninitialized slice handle over immutable
 * bits.
 * @param ptr Pointer to the first element in the span of memory that the handle
 * will govern.
 * @param len Length (in storage elements) of the span.
 * @return Success signal for handle initialization.
 * @retval `true` `self` and `ptr` were both non-`null`, and `*self` is now
 * initialized.
 * @retval `false` `self` or `ptr` were `null`, and `*self` is not initialized.
 */
extern bool bitvec_bs_b64_from_span(
	struct BitPtrImmut *const self,
	const uint64_t *const ptr,
	const size_t len
);

/**
 * @brief Initializes a slice handle from a provided span pointer and element
 * count.
 * @param[out] self Pointer to an uninitialized slice handle over immutable
 * bits.
 * @param ptr Pointer to the first element in the span of memory that the handle
 * will govern.
 * @param len Length (in storage elements) of the span.
 * @return Success signal for handle initialization.
 * @retval `true` `self` and `ptr` were both non-`null`, and `*self` is now
 * initialized.
 * @retval `false` `self` or `ptr` were `null`, and `*self` is not initialized.
 */
extern bool bitvec_bs_l64_from_span(
	struct BitPtrImmut *const self,
	const uint64_t *const ptr,
	const size_t len
);

/**
 * @brief Initializes a slice handle from a provided span pointer and element
 * count.
 * @param[out] self Pointer to an uninitialized slice handle over mutable bits.
 * @param ptr Pointer to the first element in the span of memory that the handle
 * will govern.
 * @param len Length (in storage elements) of the span.
 * @return Success signal for handle initialization.
 * @retval `true` `self` and `ptr` were both non-`null`, and `*self` is now
 * initialized.
 * @retval `false` `self` and `ptr` were both non-`null`, and `*self` is now
 * initialized.
 */
extern bool bitvec_bs_b08_from_span_mut(
	struct BitPtrMut *const self,
	uint8_t  *const ptr,
	const size_t len
);

/**
 * @brief Initializes a slice handle from a provided span pointer and element
 * count.
 * @param[out] self Pointer to an uninitialized slice handle over mutable bits.
 * @param ptr Pointer to the first element in the span of memory that the handle
 * will govern.
 * @param len Length (in storage elements) of the span.
 * @return Success signal for handle initialization.
 * @retval `true` `self` and `ptr` were both non-`null`, and `*self` is now
 * initialized.
 * @retval `false` `self` and `ptr` were both non-`null`, and `*self` is now
 * initialized.
 */
extern bool bitvec_bs_l08_from_span_mut(
	struct BitPtrMut *const self,
	uint8_t  *const ptr,
	const size_t len
);

/**
 * @brief Initializes a slice handle from a provided span pointer and element
 * count.
 * @param[out] self Pointer to an uninitialized slice handle over mutable bits.
 * @param ptr Pointer to the first element in the span of memory that the handle
 * will govern.
 * @param len Length (in storage elements) of the span.
 * @return Success signal for handle initialization.
 * @retval `true` `self` and `ptr` were both non-`null`, and `*self` is now
 * initialized.
 * @retval `false` `self` and `ptr` were both non-`null`, and `*self` is now
 * initialized.
 */
extern bool bitvec_bs_b16_from_span_mut(
	struct BitPtrMut *const self,
	uint16_t *const ptr,
	const size_t len
);

/**
 * @brief Initializes a slice handle from a provided span pointer and element
 * count.
 * @param[out] self Pointer to an uninitialized slice handle over mutable bits.
 * @param ptr Pointer to the first element in the span of memory that the handle
 * will govern.
 * @param len Length (in storage elements) of the span.
 * @return Success signal for handle initialization.
 * @retval `true` `self` and `ptr` were both non-`null`, and `*self` is now
 * initialized.
 * @retval `false` `self` and `ptr` were both non-`null`, and `*self` is now
 * initialized.
 */
extern bool bitvec_bs_l16_from_span_mut(
	struct BitPtrMut *const self,
	uint16_t *const ptr,
	const size_t len
);

/**
 * @brief Initializes a slice handle from a provided span pointer and element
 * count.
 * @param[out] self Pointer to an uninitialized slice handle over mutable bits.
 * @param ptr Pointer to the first element in the span of memory that the handle
 * will govern.
 * @param len Length (in storage elements) of the span.
 * @return Success signal for handle initialization.
 * @retval `true` `self` and `ptr` were both non-`null`, and `*self` is now
 * initialized.
 * @retval `false` `self` and `ptr` were both non-`null`, and `*self` is now
 * initialized.
 */
extern bool bitvec_bs_b32_from_span_mut(
	struct BitPtrMut *const self,
	uint32_t *const ptr,
	const size_t len
);

/**
 * @brief Initializes a slice handle from a provided span pointer and element
 * count.
 * @param[out] self Pointer to an uninitialized slice handle over mutable bits.
 * @param ptr Pointer to the first element in the span of memory that the handle
 * will govern.
 * @param len Length (in storage elements) of the span.
 * @return Success signal for handle initialization.
 * @retval `true` `self` and `ptr` were both non-`null`, and `*self` is now
 * initialized.
 * @retval `false` `self` and `ptr` were both non-`null`, and `*self` is now
 * initialized.
 */
extern bool bitvec_bs_l32_from_span_mut(
	struct BitPtrMut *const self,
	uint32_t *const ptr,
	const size_t len
);

/**
 * @brief Initializes a slice handle from a provided span pointer and element
 * count.
 * @param[out] self Pointer to an uninitialized slice handle over mutable bits.
 * @param ptr Pointer to the first element in the span of memory that the handle
 * will govern.
 * @param len Length (in storage elements) of the span.
 * @return Success signal for handle initialization.
 * @retval `true` `self` and `ptr` were both non-`null`, and `*self` is now
 * initialized.
 * @retval `false` `self` and `ptr` were both non-`null`, and `*self` is now
 * initialized.
 */
extern bool bitvec_bs_b64_from_span_mut(
	struct BitPtrMut *const self,
	uint64_t *const ptr,
	const size_t len
);

/**
 * @brief Initializes a slice handle from a provided span pointer and element
 * count.
 * @param[out] self Pointer to an uninitialized slice handle over mutable bits.
 * @param ptr Pointer to the first element in the span of memory that the handle
 * will govern.
 * @param len Length (in storage elements) of the span.
 * @return Success signal for handle initialization.
 * @retval `true` `self` and `ptr` were both non-`null`, and `*self` is now
 * initialized.
 * @retval `false` `self` and `ptr` were both non-`null`, and `*self` is now
 * initialized.
 */
extern bool bitvec_bs_l64_from_span_mut(
	struct BitPtrMut *const self,
	uint64_t *const ptr,
	const size_t len
);

/**
 * @brief Initializes a slice handle from provided span details.
 * @param[out] self Pointer to an uninitialized `BitSlice` handle. After this
 * function succeeds, the handle will be initialized according to the provided
 * span arguments.
 * @param ptr Pointer to the region of memory over which `*self` will govern
 * after initialization.
 * @param len Count in elements, not bytes, of the region to which `ptr` points.
 * @param head Index of the first live bit in the first element of the slice.
 * @param tail Index of the first dead bit in the last element of the slice.
 * @return Success signal of the handle initialization.
 * @retval `true` `self` and `ptr` were not `null` and `*self` is now
 * initialized.
 * @retval `false` `self` or `ptr` were `null`, or the arguments were invalid,
 * and `*self` is not initialized.
 *
 * If the arguments were invalid, then the program will abort, instead of
 * returning failure.
 */
extern bool bitvec_bs_b08_from_span_partial(
	struct BitPtrImmut *const self,
	const uint8_t  *const ptr,
	const size_t len,
	const uint8_t head,
	const uint8_t tail
);

/**
 * @brief Initializes a slice handle from provided span details.
 * @param[out] self Pointer to an uninitialized `BitSlice` handle. After this
 * function succeeds, the handle will be initialized according to the provided
 * span arguments.
 * @param ptr Pointer to the region of memory over which `*self` will govern
 * after initialization.
 * @param len Count in elements, not bytes, of the region to which `ptr` points.
 * @param head Index of the first live bit in the first element of the slice.
 * @param tail Index of the first dead bit in the last element of the slice.
 * @return Success signal of the handle initialization.
 * @retval `true` `self` and `ptr` were not `null` and `*self` is now
 * initialized.
 * @retval `false` `self` or `ptr` were `null`, or the arguments were invalid,
 * and `*self` is not initialized.
 *
 * If the arguments were invalid, then the program will abort, instead of
 * returning failure.
 */
extern bool bitvec_bs_l08_from_span_partial(
	struct BitPtrImmut *const self,
	const uint8_t  *const ptr,
	const size_t len,
	const uint8_t head,
	const uint8_t tail
);

/**
 * @brief Initializes a slice handle from provided span details.
 * @param[out] self Pointer to an uninitialized `BitSlice` handle. After this
 * function succeeds, the handle will be initialized according to the provided
 * span arguments.
 * @param ptr Pointer to the region of memory over which `*self` will govern
 * after initialization.
 * @param len Count in elements, not bytes, of the region to which `ptr` points.
 * @param head Index of the first live bit in the first element of the slice.
 * @param tail Index of the first dead bit in the last element of the slice.
 * @return Success signal of the handle initialization.
 * @retval `true` `self` and `ptr` were not `null` and `*self` is now
 * initialized.
 * @retval `false` `self` or `ptr` were `null`, or the arguments were invalid,
 * and `*self` is not initialized.
 *
 * If the arguments were invalid, then the program will abort, instead of
 * returning failure.
 */
extern bool bitvec_bs_b16_from_span_partial(
	struct BitPtrImmut *const self,
	const uint16_t *const ptr,
	const size_t len,
	const uint8_t head,
	const uint8_t tail
);

/**
 * @brief Initializes a slice handle from provided span details.
 * @param[out] self Pointer to an uninitialized `BitSlice` handle. After this
 * function succeeds, the handle will be initialized according to the provided
 * span arguments.
 * @param ptr Pointer to the region of memory over which `*self` will govern
 * after initialization.
 * @param len Count in elements, not bytes, of the region to which `ptr` points.
 * @param head Index of the first live bit in the first element of the slice.
 * @param tail Index of the first dead bit in the last element of the slice.
 * @return Success signal of the handle initialization.
 * @retval `true` `self` and `ptr` were not `null` and `*self` is now
 * initialized.
 * @retval `false` `self` or `ptr` were `null`, or the arguments were invalid,
 * and `*self` is not initialized.
 *
 * If the arguments were invalid, then the program will abort, instead of
 * returning failure.
 */
extern bool bitvec_bs_l16_from_span_partial(
	struct BitPtrImmut *const self,
	const uint16_t *const ptr,
	const size_t len,
	const uint8_t head,
	const uint8_t tail
);

/**
 * @brief Initializes a slice handle from provided span details.
 * @param[out] self Pointer to an uninitialized `BitSlice` handle. After this
 * function succeeds, the handle will be initialized according to the provided
 * span arguments.
 * @param ptr Pointer to the region of memory over which `*self` will govern
 * after initialization.
 * @param len Count in elements, not bytes, of the region to which `ptr` points.
 * @param head Index of the first live bit in the first element of the slice.
 * @param tail Index of the first dead bit in the last element of the slice.
 * @return Success signal of the handle initialization.
 * @retval `true` `self` and `ptr` were not `null` and `*self` is now
 * initialized.
 * @retval `false` `self` or `ptr` were `null`, or the arguments were invalid,
 * and `*self` is not initialized.
 *
 * If the arguments were invalid, then the program will abort, instead of
 * returning failure.
 */
extern bool bitvec_bs_b32_from_span_partial(
	struct BitPtrImmut *const self,
	const uint32_t *const ptr,
	const size_t len,
	const uint8_t head,
	const uint8_t tail
);

/**
 * @brief Initializes a slice handle from provided span details.
 * @param[out] self Pointer to an uninitialized `BitSlice` handle. After this
 * function succeeds, the handle will be initialized according to the provided
 * span arguments.
 * @param ptr Pointer to the region of memory over which `*self` will govern
 * after initialization.
 * @param len Count in elements, not bytes, of the region to which `ptr` points.
 * @param head Index of the first live bit in the first element of the slice.
 * @param tail Index of the first dead bit in the last element of the slice.
 * @return Success signal of the handle initialization.
 * @retval `true` `self` and `ptr` were not `null` and `*self` is now
 * initialized.
 * @retval `false` `self` or `ptr` were `null`, or the arguments were invalid,
 * and `*self` is not initialized.
 *
 * If the arguments were invalid, then the program will abort, instead of
 * returning failure.
 */
extern bool bitvec_bs_l32_from_span_partial(
	struct BitPtrImmut *const self,
	const uint32_t *const ptr,
	const size_t len,
	const uint8_t head,
	const uint8_t tail
);

/**
 * @brief Initializes a slice handle from provided span details.
 * @param[out] self Pointer to an uninitialized `BitSlice` handle. After this
 * function succeeds, the handle will be initialized according to the provided
 * span arguments.
 * @param ptr Pointer to the region of memory over which `*self` will govern
 * after initialization.
 * @param len Count in elements, not bytes, of the region to which `ptr` points.
 * @param head Index of the first live bit in the first element of the slice.
 * @param tail Index of the first dead bit in the last element of the slice.
 * @return Success signal of the handle initialization.
 * @retval `true` `self` and `ptr` were not `null` and `*self` is now
 * initialized.
 * @retval `false` `self` or `ptr` were `null`, or the arguments were invalid,
 * and `*self` is not initialized.
 *
 * If the arguments were invalid, then the program will abort, instead of
 * returning failure.
 */
extern bool bitvec_bs_b64_from_span_partial(
	struct BitPtrImmut *const self,
	const uint64_t *const ptr,
	const size_t len,
	const uint8_t head,
	const uint8_t tail
);

/**
 * @brief Initializes a slice handle from provided span details.
 * @param[out] self Pointer to an uninitialized `BitSlice` handle. After this
 * function succeeds, the handle will be initialized according to the provided
 * span arguments.
 * @param ptr Pointer to the region of memory over which `*self` will govern
 * after initialization.
 * @param len Count in elements, not bytes, of the region to which `ptr` points.
 * @param head Index of the first live bit in the first element of the slice.
 * @param tail Index of the first dead bit in the last element of the slice.
 * @return Success signal of the handle initialization.
 * @retval `true` `self` and `ptr` were not `null` and `*self` is now
 * initialized.
 * @retval `false` `self` or `ptr` were `null`, or the arguments were invalid,
 * and `*self` is not initialized.
 *
 * If the arguments were invalid, then the program will abort, instead of
 * returning failure.
 */
extern bool bitvec_bs_l64_from_span_partial(
	struct BitPtrImmut *const self,
	const uint64_t *const ptr,
	const size_t len,
	const uint8_t head,
	const uint8_t tail
);

/**
 * @brief Initializes a slice handle from provided span details.
 * @param[out] self Pointer to an uninitialized `BitSlice` handle. After this
 * function succeeds, the handle will be initialized according to the provided
 * span arguments.
 * @param ptr Pointer to the region of memory over which `*self` will govern
 * after initialization.
 * @param len Count in elements, not bytes, of the region to which `ptr` points.
 * @param head Index of the first live bit in the first element of the slice.
 * @param tail Index of the first dead bit in the last element of the slice.
 * @return Success signal of the handle initialization.
 * @retval `true` `self` and `ptr` were not `null` and `*self` is now
 * initialized.
 * @retval `false` `self` or `ptr` were `null`, or the arguments were invalid,
 * and `*self` is not initialized.
 *
 * If the arguments were invalid, then the program will abort, instead of
 * returning failure.
 */
extern bool bitvec_bs_b08_from_span_partial_mut(
	struct BitPtrMut *const self,
	uint8_t  *const ptr,
	const size_t len,
	const uint8_t head,
	const uint8_t tail
);

/**
 * @brief Initializes a slice handle from provided span details.
 * @param[out] self Pointer to an uninitialized `BitSlice` handle. After this
 * function succeeds, the handle will be initialized according to the provided
 * span arguments.
 * @param ptr Pointer to the region of memory over which `*self` will govern
 * after initialization.
 * @param len Count in elements, not bytes, of the region to which `ptr` points.
 * @param head Index of the first live bit in the first element of the slice.
 * @param tail Index of the first dead bit in the last element of the slice.
 * @return Success signal of the handle initialization.
 * @retval `true` `self` and `ptr` were not `null` and `*self` is now
 * initialized.
 * @retval `false` `self` or `ptr` were `null`, or the arguments were invalid,
 * and `*self` is not initialized.
 *
 * If the arguments were invalid, then the program will abort, instead of
 * returning failure.
 */
extern bool bitvec_bs_l08_from_span_partial_mut(
	struct BitPtrMut *const self,
	uint8_t  *const ptr,
	const size_t len,
	const uint8_t head,
	const uint8_t tail
);

/**
 * @brief Initializes a slice handle from provided span details.
 * @param[out] self Pointer to an uninitialized `BitSlice` handle. After this
 * function succeeds, the handle will be initialized according to the provided
 * span arguments.
 * @param ptr Pointer to the region of memory over which `*self` will govern
 * after initialization.
 * @param len Count in elements, not bytes, of the region to which `ptr` points.
 * @param head Index of the first live bit in the first element of the slice.
 * @param tail Index of the first dead bit in the last element of the slice.
 * @return Success signal of the handle initialization.
 * @retval `true` `self` and `ptr` were not `null` and `*self` is now
 * initialized.
 * @retval `false` `self` or `ptr` were `null`, or the arguments were invalid,
 * and `*self` is not initialized.
 *
 * If the arguments were invalid, then the program will abort, instead of
 * returning failure.
 */
extern bool bitvec_bs_b16_from_span_partial_mut(
	struct BitPtrMut *const self,
	uint16_t *const ptr,
	const size_t len,
	const uint8_t head,
	const uint8_t tail
);

/**
 * @brief Initializes a slice handle from provided span details.
 * @param[out] self Pointer to an uninitialized `BitSlice` handle. After this
 * function succeeds, the handle will be initialized according to the provided
 * span arguments.
 * @param ptr Pointer to the region of memory over which `*self` will govern
 * after initialization.
 * @param len Count in elements, not bytes, of the region to which `ptr` points.
 * @param head Index of the first live bit in the first element of the slice.
 * @param tail Index of the first dead bit in the last element of the slice.
 * @return Success signal of the handle initialization.
 * @retval `true` `self` and `ptr` were not `null` and `*self` is now
 * initialized.
 * @retval `false` `self` or `ptr` were `null`, or the arguments were invalid,
 * and `*self` is not initialized.
 *
 * If the arguments were invalid, then the program will abort, instead of
 * returning failure.
 */
extern bool bitvec_bs_l16_from_span_partial_mut(
	struct BitPtrMut *const self,
	uint16_t *const ptr,
	const size_t len,
	const uint8_t head,
	const uint8_t tail
);

/**
 * @brief Initializes a slice handle from provided span details.
 * @param[out] self Pointer to an uninitialized `BitSlice` handle. After this
 * function succeeds, the handle will be initialized according to the provided
 * span arguments.
 * @param ptr Pointer to the region of memory over which `*self` will govern
 * after initialization.
 * @param len Count in elements, not bytes, of the region to which `ptr` points.
 * @param head Index of the first live bit in the first element of the slice.
 * @param tail Index of the first dead bit in the last element of the slice.
 * @return Success signal of the handle initialization.
 * @retval `true` `self` and `ptr` were not `null` and `*self` is now
 * initialized.
 * @retval `false` `self` or `ptr` were `null`, or the arguments were invalid,
 * and `*self` is not initialized.
 *
 * If the arguments were invalid, then the program will abort, instead of
 * returning failure.
 */
extern bool bitvec_bs_b32_from_span_partial_mut(
	struct BitPtrMut *const self,
	uint32_t *const ptr,
	const size_t len,
	const uint8_t head,
	const uint8_t tail
);

/**
 * @brief Initializes a slice handle from provided span details.
 * @param[out] self Pointer to an uninitialized `BitSlice` handle. After this
 * function succeeds, the handle will be initialized according to the provided
 * span arguments.
 * @param ptr Pointer to the region of memory over which `*self` will govern
 * after initialization.
 * @param len Count in elements, not bytes, of the region to which `ptr` points.
 * @param head Index of the first live bit in the first element of the slice.
 * @param tail Index of the first dead bit in the last element of the slice.
 * @return Success signal of the handle initialization.
 * @retval `true` `self` and `ptr` were not `null` and `*self` is now
 * initialized.
 * @retval `false` `self` or `ptr` were `null`, or the arguments were invalid,
 * and `*self` is not initialized.
 *
 * If the arguments were invalid, then the program will abort, instead of
 * returning failure.
 */
extern bool bitvec_bs_l32_from_span_partial_mut(
	struct BitPtrMut *const self,
	uint32_t *const ptr,
	const size_t len,
	const uint8_t head,
	const uint8_t tail
);

/**
 * @brief Initializes a slice handle from provided span details.
 * @param[out] self Pointer to an uninitialized `BitSlice` handle. After this
 * function succeeds, the handle will be initialized according to the provided
 * span arguments.
 * @param ptr Pointer to the region of memory over which `*self` will govern
 * after initialization.
 * @param len Count in elements, not bytes, of the region to which `ptr` points.
 * @param head Index of the first live bit in the first element of the slice.
 * @param tail Index of the first dead bit in the last element of the slice.
 * @return Success signal of the handle initialization.
 * @retval `true` `self` and `ptr` were not `null` and `*self` is now
 * initialized.
 * @retval `false` `self` or `ptr` were `null`, or the arguments were invalid,
 * and `*self` is not initialized.
 *
 * If the arguments were invalid, then the program will abort, instead of
 * returning failure.
 */
extern bool bitvec_bs_b64_from_span_partial_mut(
	struct BitPtrMut *const self,
	uint64_t *const ptr,
	const size_t len,
	const uint8_t head,
	const uint8_t tail
);

/**
 * @brief Initializes a slice handle from provided span details.
 * @param[out] self Pointer to an uninitialized `BitSlice` handle. After this
 * function succeeds, the handle will be initialized according to the provided
 * span arguments.
 * @param ptr Pointer to the region of memory over which `*self` will govern
 * after initialization.
 * @param len Count in elements, not bytes, of the region to which `ptr` points.
 * @param head Index of the first live bit in the first element of the slice.
 * @param tail Index of the first dead bit in the last element of the slice.
 * @return Success signal of the handle initialization.
 * @retval `true` `self` and `ptr` were not `null` and `*self` is now
 * initialized.
 * @retval `false` `self` or `ptr` were `null`, or the arguments were invalid,
 * and `*self` is not initialized.
 *
 * If the arguments were invalid, then the program will abort, instead of
 * returning failure.
 */
extern bool bitvec_bs_l64_from_span_partial_mut(
	struct BitPtrMut *const self,
	uint64_t *const ptr,
	const size_t len,
	const uint8_t head,
	const uint8_t tail
);

/**
 * @brief Gets the length of the bit slice that a handle governs.
 * @param[in] self Pointer to a `const` handle of const bits.
 * @return The length of the bit slice governed by `self`.
 */
extern size_t bitvec_bs_b08_len(const struct BitPtrImmut *const self);

/**
 * @brief Gets the length of the bit slice that a handle governs.
 * @param[in] self Pointer to a `const` handle of const bits.
 * @return The length of the bit slice governed by `self`.
 */
extern size_t bitvec_bs_l08_len(const struct BitPtrImmut *const self);

/**
 * @brief Gets the length of the bit slice that a handle governs.
 * @param[in] self Pointer to a `const` handle of const bits.
 * @return The length of the bit slice governed by `self`.
 */
extern size_t bitvec_bs_b16_len(const struct BitPtrImmut *const self);

/**
 * @brief Gets the length of the bit slice that a handle governs.
 * @param[in] self Pointer to a `const` handle of const bits.
 * @return The length of the bit slice governed by `self`.
 */
extern size_t bitvec_bs_l16_len(const struct BitPtrImmut *const self);

/**
 * @brief Gets the length of the bit slice that a handle governs.
 * @param[in] self Pointer to a `const` handle of const bits.
 * @return The length of the bit slice governed by `self`.
 */
extern size_t bitvec_bs_b32_len(const struct BitPtrImmut *const self);

/**
 * @brief Gets the length of the bit slice that a handle governs.
 * @param[in] self Pointer to a `const` handle of const bits.
 * @return The length of the bit slice governed by `self`.
 */
extern size_t bitvec_bs_l32_len(const struct BitPtrImmut *const self);

/**
 * @brief Gets the length of the bit slice that a handle governs.
 * @param[in] self Pointer to a `const` handle of const bits.
 * @return The length of the bit slice governed by `self`.
 */
extern size_t bitvec_bs_b64_len(const struct BitPtrImmut *const self);

/**
 * @brief Gets the length of the bit slice that a handle governs.
 * @param[in] self Pointer to a `const` handle of const bits.
 * @return The length of the bit slice governed by `self`.
 */
extern size_t bitvec_bs_l64_len(const struct BitPtrImmut *const self);

/**
 * @brief Tests if a handle governs an empty bit slice.
 * @param[in] self Pointer to a `const` handle of const bits.
 * @return Tristate boolean.
 * @retval `False` The bit slice is not empty.
 * @retval `True` The bit slice is empty.
 * @retval `Error` `self` is `null`.
 */
extern enum Tristate bitvec_bs_b08_is_empty(
	const struct BitPtrImmut *const self
);

/**
 * @brief Tests if a handle governs an empty bit slice.
 * @param[in] self Pointer to a `const` handle of const bits.
 * @return Tristate boolean.
 * @retval `False` The bit slice is not empty.
 * @retval `True` The bit slice is empty.
 * @retval `Error` `self` is `null`.
 */
extern enum Tristate bitvec_bs_l08_is_empty(
	const struct BitPtrImmut *const self
);

/**
 * @brief Tests if a handle governs an empty bit slice.
 * @param[in] self Pointer to a `const` handle of const bits.
 * @return Tristate boolean.
 * @retval `False` The bit slice is not empty.
 * @retval `True` The bit slice is empty.
 * @retval `Error` `self` is `null`.
 */
extern enum Tristate bitvec_bs_b16_is_empty(
	const struct BitPtrImmut *const self
);

/**
 * @brief Tests if a handle governs an empty bit slice.
 * @param[in] self Pointer to a `const` handle of const bits.
 * @return Tristate boolean.
 * @retval `False` The bit slice is not empty.
 * @retval `True` The bit slice is empty.
 * @retval `Error` `self` is `null`.
 */
extern enum Tristate bitvec_bs_l16_is_empty(
	const struct BitPtrImmut *const self
);

/**
 * @brief Tests if a handle governs an empty bit slice.
 * @param[in] self Pointer to a `const` handle of const bits.
 * @return Tristate boolean.
 * @retval `False` The bit slice is not empty.
 * @retval `True` The bit slice is empty.
 * @retval `Error` `self` is `null`.
 */
extern enum Tristate bitvec_bs_b32_is_empty(
	const struct BitPtrImmut *const self
);

/**
 * @brief Tests if a handle governs an empty bit slice.
 * @param[in] self Pointer to a `const` handle of const bits.
 * @return Tristate boolean.
 * @retval `False` The bit slice is not empty.
 * @retval `True` The bit slice is empty.
 * @retval `Error` `self` is `null`.
 */
extern enum Tristate bitvec_bs_l32_is_empty(
	const struct BitPtrImmut *const self
);

/**
 * @brief Tests if a handle governs an empty bit slice.
 * @param[in] self Pointer to a `const` handle of const bits.
 * @return Tristate boolean.
 * @retval `False` The bit slice is not empty.
 * @retval `True` The bit slice is empty.
 * @retval `Error` `self` is `null`.
 */
extern enum Tristate bitvec_bs_b64_is_empty(
	const struct BitPtrImmut *const self
);

/**
 * @brief Tests if a handle governs an empty bit slice.
 * @param[in] self Pointer to a `const` handle of const bits.
 * @return Tristate boolean.
 * @retval `False` The bit slice is not empty.
 * @retval `True` The bit slice is empty.
 * @retval `Error` `self` is `null`.
 */
extern enum Tristate bitvec_bs_l64_is_empty(
	const struct BitPtrImmut *const self
);

/**
 * @brief Gets the first bit in the bit slice governed by a handle.
 * @param[in] self Pointer to a `const` handle of const bits.
 * @return Tristate boolean.
 * @retval `False` The first bit in the slice is `0`.
 * @retval `True` The first bit in the slice is `1`.
 * @retval `Error` `self` is `null`, or the bit slice is empty.
 */
extern enum Tristate bitvec_bs_b08_first(
	const struct BitPtrImmut *const self
);

/**
 * @brief Gets the first bit in the bit slice governed by a handle.
 * @param[in] self Pointer to a `const` handle of const bits.
 * @return Tristate boolean.
 * @retval `False` The first bit in the slice is `0`.
 * @retval `True` The first bit in the slice is `1`.
 * @retval `Error` `self` is `null`, or the bit slice is empty.
 */
extern enum Tristate bitvec_bs_l08_first(
	const struct BitPtrImmut *const self
);

/**
 * @brief Gets the first bit in the bit slice governed by a handle.
 * @param[in] self Pointer to a `const` handle of const bits.
 * @return Tristate boolean.
 * @retval `False` The first bit in the slice is `0`.
 * @retval `True` The first bit in the slice is `1`.
 * @retval `Error` `self` is `null`, or the bit slice is empty.
 */
extern enum Tristate bitvec_bs_b16_first(
	const struct BitPtrImmut *const self
);

/**
 * @brief Gets the first bit in the bit slice governed by a handle.
 * @param[in] self Pointer to a `const` handle of const bits.
 * @return Tristate boolean.
 * @retval `False` The first bit in the slice is `0`.
 * @retval `True` The first bit in the slice is `1`.
 * @retval `Error` `self` is `null`, or the bit slice is empty.
 */
extern enum Tristate bitvec_bs_l16_first(
	const struct BitPtrImmut *const self
);

/**
 * @brief Gets the first bit in the bit slice governed by a handle.
 * @param[in] self Pointer to a `const` handle of const bits.
 * @return Tristate boolean.
 * @retval `False` The first bit in the slice is `0`.
 * @retval `True` The first bit in the slice is `1`.
 * @retval `Error` `self` is `null`, or the bit slice is empty.
 */
extern enum Tristate bitvec_bs_b32_first(
	const struct BitPtrImmut *const self
);

/**
 * @brief Gets the first bit in the bit slice governed by a handle.
 * @param[in] self Pointer to a `const` handle of const bits.
 * @return Tristate boolean.
 * @retval `False` The first bit in the slice is `0`.
 * @retval `True` The first bit in the slice is `1`.
 * @retval `Error` `self` is `null`, or the bit slice is empty.
 */
extern enum Tristate bitvec_bs_l32_first(
	const struct BitPtrImmut *const self
);

/**
 * @brief Gets the first bit in the bit slice governed by a handle.
 * @param[in] self Pointer to a `const` handle of const bits.
 * @return Tristate boolean.
 * @retval `False` The first bit in the slice is `0`.
 * @retval `True` The first bit in the slice is `1`.
 * @retval `Error` `self` is `null`, or the bit slice is empty.
 */
extern enum Tristate bitvec_bs_b64_first(
	const struct BitPtrImmut *const self
);

/**
 * @brief Gets the first bit in the bit slice governed by a handle.
 * @param[in] self Pointer to a `const` handle of const bits.
 * @return Tristate boolean.
 * @retval `False` The first bit in the slice is `0`.
 * @retval `True` The first bit in the slice is `1`.
 * @retval `Error` `self` is `null`, or the bit slice is empty.
 */
extern enum Tristate bitvec_bs_l64_first(
	const struct BitPtrImmut *const self
);

/**
 * @brief Splits the bit slice governed by the handle after the first bit.
 * @param[in,out] self Pointer to a mutable handle of const bits.
 * @return Tristate boolean.
 * @retval `False` The first bit in the slice was `0`.
 * @retval `True` The first bit in the slice was `1`.
 * @retval `Error` `self` is `null`, or the bit slice is empty.
 *
 * @note This function modifies the handle such that after the call, the first
 * bit is no longer included in the slice it governs. This may cause the handle
 * to which `self` points to become empty.
 */
extern enum Tristate bitvec_bs_b08_split_first(
	struct BitPtrImmut *const self
);

/**
 * @brief Splits the bit slice governed by the handle after the first bit.
 * @param[in,out] self Pointer to a mutable handle of const bits.
 * @return Tristate boolean.
 * @retval `False` The first bit in the slice was `0`.
 * @retval `True` The first bit in the slice was `1`.
 * @retval `Error` `self` is `null`, or the bit slice is empty.
 *
 * @note This function modifies the handle such that after the call, the first
 * bit is no longer included in the slice it governs. This may cause the handle
 * to which `self` points to become empty.
 */
extern enum Tristate bitvec_bs_l08_split_first(
	struct BitPtrImmut *const self
);

/**
 * @brief Splits the bit slice governed by the handle after the first bit.
 * @param[in,out] self Pointer to a mutable handle of const bits.
 * @return Tristate boolean.
 * @retval `False` The first bit in the slice was `0`.
 * @retval `True` The first bit in the slice was `1`.
 * @retval `Error` `self` is `null`, or the bit slice is empty.
 *
 * @note This function modifies the handle such that after the call, the first
 * bit is no longer included in the slice it governs. This may cause the handle
 * to which `self` points to become empty.
 */
extern enum Tristate bitvec_bs_b16_split_first(
	struct BitPtrImmut *const self
);

/**
 * @brief Splits the bit slice governed by the handle after the first bit.
 * @param[in,out] self Pointer to a mutable handle of const bits.
 * @return Tristate boolean.
 * @retval `False` The first bit in the slice was `0`.
 * @retval `True` The first bit in the slice was `1`.
 * @retval `Error` `self` is `null`, or the bit slice is empty.
 *
 * @note This function modifies the handle such that after the call, the first
 * bit is no longer included in the slice it governs. This may cause the handle
 * to which `self` points to become empty.
 */
extern enum Tristate bitvec_bs_l16_split_first(
	struct BitPtrImmut *const self
);

/**
 * @brief Splits the bit slice governed by the handle after the first bit.
 * @param[in,out] self Pointer to a mutable handle of const bits.
 * @return Tristate boolean.
 * @retval `False` The first bit in the slice was `0`.
 * @retval `True` The first bit in the slice was `1`.
 * @retval `Error` `self` is `null`, or the bit slice is empty.
 *
 * @note This function modifies the handle such that after the call, the first
 * bit is no longer included in the slice it governs. This may cause the handle
 * to which `self` points to become empty.
 */
extern enum Tristate bitvec_bs_b32_split_first(
	struct BitPtrImmut *const self
);

/**
 * @brief Splits the bit slice governed by the handle after the first bit.
 * @param[in,out] self Pointer to a mutable handle of const bits.
 * @return Tristate boolean.
 * @retval `False` The first bit in the slice was `0`.
 * @retval `True` The first bit in the slice was `1`.
 * @retval `Error` `self` is `null`, or the bit slice is empty.
 *
 * @note This function modifies the handle such that after the call, the first
 * bit is no longer included in the slice it governs. This may cause the handle
 * to which `self` points to become empty.
 */
extern enum Tristate bitvec_bs_l32_split_first(
	struct BitPtrImmut *const self
);

/**
 * @brief Splits the bit slice governed by the handle after the first bit.
 * @param[in,out] self Pointer to a mutable handle of const bits.
 * @return Tristate boolean.
 * @retval `False` The first bit in the slice was `0`.
 * @retval `True` The first bit in the slice was `1`.
 * @retval `Error` `self` is `null`, or the bit slice is empty.
 *
 * @note This function modifies the handle such that after the call, the first
 * bit is no longer included in the slice it governs. This may cause the handle
 * to which `self` points to become empty.
 */
extern enum Tristate bitvec_bs_b64_split_first(
	struct BitPtrImmut *const self
);

/**
 * @brief Splits the bit slice governed by the handle after the first bit.
 * @param[in,out] self Pointer to a mutable handle of const bits.
 * @return Tristate boolean.
 * @retval `False` The first bit in the slice was `0`.
 * @retval `True` The first bit in the slice was `1`.
 * @retval `Error` `self` is `null`, or the bit slice is empty.
 *
 * @note This function modifies the handle such that after the call, the first
 * bit is no longer included in the slice it governs. This may cause the handle
 * to which `self` points to become empty.
 */
extern enum Tristate bitvec_bs_l64_split_first(
	struct BitPtrImmut *const self
);

/**
 * @brief Splits the bit slice governed by the handle after the first bit.
 * @param[in,out] self Pointer to a mutable handle of mutable bits.
 * @return Tristate boolean.
 * @retval `False` The first bit in the slice was `0`.
 * @retval `True` The first bit in the slice was `1`.
 * @retval `Error` `self` is `null`, or the bit slice is empty.
 *
 * @note This function modifies the handle such that after the call, the first
 * bit is no longer included in the slice it governs. This may cause the handle
 * to which `self` points to become empty.
 */
extern enum Tristate bitvec_bs_b08_split_first_mut(
	struct BitPtrMut *const self
);

/**
 * @brief Splits the bit slice governed by the handle after the first bit.
 * @param[in,out] self Pointer to a mutable handle of mutable bits.
 * @return Tristate boolean.
 * @retval `False` The first bit in the slice was `0`.
 * @retval `True` The first bit in the slice was `1`.
 * @retval `Error` `self` is `null`, or the bit slice is empty.
 *
 * @note This function modifies the handle such that after the call, the first
 * bit is no longer included in the slice it governs. This may cause the handle
 * to which `self` points to become empty.
 */
extern enum Tristate bitvec_bs_l08_split_first_mut(
	struct BitPtrMut *const self
);

/**
 * @brief Splits the bit slice governed by the handle after the first bit.
 * @param[in,out] self Pointer to a mutable handle of mutable bits.
 * @return Tristate boolean.
 * @retval `False` The first bit in the slice was `0`.
 * @retval `True` The first bit in the slice was `1`.
 * @retval `Error` `self` is `null`, or the bit slice is empty.
 *
 * @note This function modifies the handle such that after the call, the first
 * bit is no longer included in the slice it governs. This may cause the handle
 * to which `self` points to become empty.
 */
extern enum Tristate bitvec_bs_b16_split_first_mut(
	struct BitPtrMut *const self
);

/**
 * @brief Splits the bit slice governed by the handle after the first bit.
 * @param[in,out] self Pointer to a mutable handle of mutable bits.
 * @return Tristate boolean.
 * @retval `False` The first bit in the slice was `0`.
 * @retval `True` The first bit in the slice was `1`.
 * @retval `Error` `self` is `null`, or the bit slice is empty.
 *
 * @note This function modifies the handle such that after the call, the first
 * bit is no longer included in the slice it governs. This may cause the handle
 * to which `self` points to become empty.
 */
extern enum Tristate bitvec_bs_l16_split_first_mut(
	struct BitPtrMut *const self
);

/**
 * @brief Splits the bit slice governed by the handle after the first bit.
 * @param[in,out] self Pointer to a mutable handle of mutable bits.
 * @return Tristate boolean.
 * @retval `False` The first bit in the slice was `0`.
 * @retval `True` The first bit in the slice was `1`.
 * @retval `Error` `self` is `null`, or the bit slice is empty.
 *
 * @note This function modifies the handle such that after the call, the first
 * bit is no longer included in the slice it governs. This may cause the handle
 * to which `self` points to become empty.
 */
extern enum Tristate bitvec_bs_b32_split_first_mut(
	struct BitPtrMut *const self
);

/**
 * @brief Splits the bit slice governed by the handle after the first bit.
 * @param[in,out] self Pointer to a mutable handle of mutable bits.
 * @return Tristate boolean.
 * @retval `False` The first bit in the slice was `0`.
 * @retval `True` The first bit in the slice was `1`.
 * @retval `Error` `self` is `null`, or the bit slice is empty.
 *
 * @note This function modifies the handle such that after the call, the first
 * bit is no longer included in the slice it governs. This may cause the handle
 * to which `self` points to become empty.
 */
extern enum Tristate bitvec_bs_l32_split_first_mut(
	struct BitPtrMut *const self
);

/**
 * @brief Splits the bit slice governed by the handle after the first bit.
 * @param[in,out] self Pointer to a mutable handle of mutable bits.
 * @return Tristate boolean.
 * @retval `False` The first bit in the slice was `0`.
 * @retval `True` The first bit in the slice was `1`.
 * @retval `Error` `self` is `null`, or the bit slice is empty.
 *
 * @note This function modifies the handle such that after the call, the first
 * bit is no longer included in the slice it governs. This may cause the handle
 * to which `self` points to become empty.
 */
extern enum Tristate bitvec_bs_b64_split_first_mut(
	struct BitPtrMut *const self
);

/**
 * @brief Splits the bit slice governed by the handle after the first bit.
 * @param[in,out] self Pointer to a mutable handle of mutable bits.
 * @return Tristate boolean.
 * @retval `False` The first bit in the slice was `0`.
 * @retval `True` The first bit in the slice was `1`.
 * @retval `Error` `self` is `null`, or the bit slice is empty.
 *
 * @note This function modifies the handle such that after the call, the first
 * bit is no longer included in the slice it governs. This may cause the handle
 * to which `self` points to become empty.
 */
extern enum Tristate bitvec_bs_l64_split_first_mut(
	struct BitPtrMut *const self
);

/**
 * @brief Splits the bit slice governed by the handle before the last bit.
 * @param[in,out] self Pointer to a mutable handle of const bits.
 * @return Tristate boolean.
 * @retval `False` The last bit in the slice was `0`.
 * @retval `True` The last bit in the slice was `1`.
 * @retval `Error` `self` is `null`, or the bit slice is empty.
 *
 * @note This function modifies the handle such that after the call, the last
 * bit is no longer included in the slice it governs. This may cause the handle
 * to which `self` points to become empty.
 */
extern enum Tristate bitvec_bs_b08_split_last(
	struct BitPtrImmut *const self
);

/**
 * @brief Splits the bit slice governed by the handle before the last bit.
 * @param[in,out] self Pointer to a mutable handle of const bits.
 * @return Tristate boolean.
 * @retval `False` The last bit in the slice was `0`.
 * @retval `True` The last bit in the slice was `1`.
 * @retval `Error` `self` is `null`, or the bit slice is empty.
 *
 * @note This function modifies the handle such that after the call, the last
 * bit is no longer included in the slice it governs. This may cause the handle
 * to which `self` points to become empty.
 */
extern enum Tristate bitvec_bs_l08_split_last(
	struct BitPtrImmut *const self
);

/**
 * @brief Splits the bit slice governed by the handle before the last bit.
 * @param[in,out] self Pointer to a mutable handle of const bits.
 * @return Tristate boolean.
 * @retval `False` The last bit in the slice was `0`.
 * @retval `True` The last bit in the slice was `1`.
 * @retval `Error` `self` is `null`, or the bit slice is empty.
 *
 * @note This function modifies the handle such that after the call, the last
 * bit is no longer included in the slice it governs. This may cause the handle
 * to which `self` points to become empty.
 */
extern enum Tristate bitvec_bs_b16_split_last(
	struct BitPtrImmut *const self
);

/**
 * @brief Splits the bit slice governed by the handle before the last bit.
 * @param[in,out] self Pointer to a mutable handle of const bits.
 * @return Tristate boolean.
 * @retval `False` The last bit in the slice was `0`.
 * @retval `True` The last bit in the slice was `1`.
 * @retval `Error` `self` is `null`, or the bit slice is empty.
 *
 * @note This function modifies the handle such that after the call, the last
 * bit is no longer included in the slice it governs. This may cause the handle
 * to which `self` points to become empty.
 */
extern enum Tristate bitvec_bs_l16_split_last(
	struct BitPtrImmut *const self
);

/**
 * @brief Splits the bit slice governed by the handle before the last bit.
 * @param[in,out] self Pointer to a mutable handle of const bits.
 * @return Tristate boolean.
 * @retval `False` The last bit in the slice was `0`.
 * @retval `True` The last bit in the slice was `1`.
 * @retval `Error` `self` is `null`, or the bit slice is empty.
 *
 * @note This function modifies the handle such that after the call, the last
 * bit is no longer included in the slice it governs. This may cause the handle
 * to which `self` points to become empty.
 */
extern enum Tristate bitvec_bs_b32_split_last(
	struct BitPtrImmut *const self
);

/**
 * @brief Splits the bit slice governed by the handle before the last bit.
 * @param[in,out] self Pointer to a mutable handle of const bits.
 * @return Tristate boolean.
 * @retval `False` The last bit in the slice was `0`.
 * @retval `True` The last bit in the slice was `1`.
 * @retval `Error` `self` is `null`, or the bit slice is empty.
 *
 * @note This function modifies the handle such that after the call, the last
 * bit is no longer included in the slice it governs. This may cause the handle
 * to which `self` points to become empty.
 */
extern enum Tristate bitvec_bs_l32_split_last(
	struct BitPtrImmut *const self
);

/**
 * @brief Splits the bit slice governed by the handle before the last bit.
 * @param[in,out] self Pointer to a mutable handle of const bits.
 * @return Tristate boolean.
 * @retval `False` The last bit in the slice was `0`.
 * @retval `True` The last bit in the slice was `1`.
 * @retval `Error` `self` is `null`, or the bit slice is empty.
 *
 * @note This function modifies the handle such that after the call, the last
 * bit is no longer included in the slice it governs. This may cause the handle
 * to which `self` points to become empty.
 */
extern enum Tristate bitvec_bs_b64_split_last(
	struct BitPtrImmut *const self
);

/**
 * @brief Splits the bit slice governed by the handle before the last bit.
 * @param[in,out] self Pointer to a mutable handle of const bits.
 * @return Tristate boolean.
 * @retval `False` The last bit in the slice was `0`.
 * @retval `True` The last bit in the slice was `1`.
 * @retval `Error` `self` is `null`, or the bit slice is empty.
 *
 * @note This function modifies the handle such that after the call, the last
 * bit is no longer included in the slice it governs. This may cause the handle
 * to which `self` points to become empty.
 */
extern enum Tristate bitvec_bs_l64_split_last(
	struct BitPtrImmut *const self
);

/**
 * @brief Splits the bit slice governed by the handle before the last bit.
 * @param[in,out] self Pointer to a mutable handle of mutable bits.
 * @return Tristate boolean.
 * @retval `False` The last bit in the slice was `0`.
 * @retval `True` The last bit in the slice was `1`.
 * @retval `Error` `self` is `null`, or the bit slice is empty.
 *
 * @note This function modifies the handle such that ofter the call, the last
 * bit is no longer included in the slice it governs. This may cause the handle
 * to which `self` points to become empty.
 */
extern enum Tristate bitvec_bs_b08_split_last_mut(
	struct BitPtrMut *const self
);

/**
 * @brief Splits the bit slice governed by the handle before the last bit.
 * @param[in,out] self Pointer to a mutable handle of mutable bits.
 * @return Tristate boolean.
 * @retval `False` The last bit in the slice was `0`.
 * @retval `True` The last bit in the slice was `1`.
 * @retval `Error` `self` is `null`, or the bit slice is empty.
 *
 * @note This function modifies the handle such that ofter the call, the last
 * bit is no longer included in the slice it governs. This may cause the handle
 * to which `self` points to become empty.
 */
extern enum Tristate bitvec_bs_l08_split_last_mut(
	struct BitPtrMut *const self
);

/**
 * @brief Splits the bit slice governed by the handle before the last bit.
 * @param[in,out] self Pointer to a mutable handle of mutable bits.
 * @return Tristate boolean.
 * @retval `False` The last bit in the slice was `0`.
 * @retval `True` The last bit in the slice was `1`.
 * @retval `Error` `self` is `null`, or the bit slice is empty.
 *
 * @note This function modifies the handle such that ofter the call, the last
 * bit is no longer included in the slice it governs. This may cause the handle
 * to which `self` points to become empty.
 */
extern enum Tristate bitvec_bs_b16_split_last_mut(
	struct BitPtrMut *const self
);

/**
 * @brief Splits the bit slice governed by the handle before the last bit.
 * @param[in,out] self Pointer to a mutable handle of mutable bits.
 * @return Tristate boolean.
 * @retval `False` The last bit in the slice was `0`.
 * @retval `True` The last bit in the slice was `1`.
 * @retval `Error` `self` is `null`, or the bit slice is empty.
 *
 * @note This function modifies the handle such that ofter the call, the last
 * bit is no longer included in the slice it governs. This may cause the handle
 * to which `self` points to become empty.
 */
extern enum Tristate bitvec_bs_l16_split_last_mut(
	struct BitPtrMut *const self
);

/**
 * @brief Splits the bit slice governed by the handle before the last bit.
 * @param[in,out] self Pointer to a mutable handle of mutable bits.
 * @return Tristate boolean.
 * @retval `False` The last bit in the slice was `0`.
 * @retval `True` The last bit in the slice was `1`.
 * @retval `Error` `self` is `null`, or the bit slice is empty.
 *
 * @note This function modifies the handle such that ofter the call, the last
 * bit is no longer included in the slice it governs. This may cause the handle
 * to which `self` points to become empty.
 */
extern enum Tristate bitvec_bs_b32_split_last_mut(
	struct BitPtrMut *const self
);

/**
 * @brief Splits the bit slice governed by the handle before the last bit.
 * @param[in,out] self Pointer to a mutable handle of mutable bits.
 * @return Tristate boolean.
 * @retval `False` The last bit in the slice was `0`.
 * @retval `True` The last bit in the slice was `1`.
 * @retval `Error` `self` is `null`, or the bit slice is empty.
 *
 * @note This function modifies the handle such that ofter the call, the last
 * bit is no longer included in the slice it governs. This may cause the handle
 * to which `self` points to become empty.
 */
extern enum Tristate bitvec_bs_l32_split_last_mut(
	struct BitPtrMut *const self
);

/**
 * @brief Splits the bit slice governed by the handle before the last bit.
 * @param[in,out] self Pointer to a mutable handle of mutable bits.
 * @return Tristate boolean.
 * @retval `False` The last bit in the slice was `0`.
 * @retval `True` The last bit in the slice was `1`.
 * @retval `Error` `self` is `null`, or the bit slice is empty.
 *
 * @note This function modifies the handle such that ofter the call, the last
 * bit is no longer included in the slice it governs. This may cause the handle
 * to which `self` points to become empty.
 */
extern enum Tristate bitvec_bs_b64_split_last_mut(
	struct BitPtrMut *const self
);

/**
 * @brief Splits the bit slice governed by the handle before the last bit.
 * @param[in,out] self Pointer to a mutable handle of mutable bits.
 * @return Tristate boolean.
 * @retval `False` The last bit in the slice was `0`.
 * @retval `True` The last bit in the slice was `1`.
 * @retval `Error` `self` is `null`, or the bit slice is empty.
 *
 * @note This function modifies the handle such that ofter the call, the last
 * bit is no longer included in the slice it governs. This may cause the handle
 * to which `self` points to become empty.
 */
extern enum Tristate bitvec_bs_l64_split_last_mut(
	struct BitPtrMut *const self
);

/**
 * @brief Gets the last bit in the bit slice governed by a handle.
 * @param[in] self Pointer to a `const` handle of const bits.
 * @return Tristate boolean.
 * @retval `False` The last bit in the slice is `0`.
 * @retval `True` The last bit in the slice is `1`.
 * @retval `Error` `self` is `null`, or the slice is empty.
 */
extern enum Tristate bitvec_bs_b08_last(
	const struct BitPtrImmut *const self
);

/**
 * @brief Gets the last bit in the bit slice governed by a handle.
 * @param[in] self Pointer to a `const` handle of const bits.
 * @return Tristate boolean.
 * @retval `False` The last bit in the slice is `0`.
 * @retval `True` The last bit in the slice is `1`.
 * @retval `Error` `self` is `null`, or the slice is empty.
 */
extern enum Tristate bitvec_bs_l08_last(
	const struct BitPtrImmut *const self
);

/**
 * @brief Gets the last bit in the bit slice governed by a handle.
 * @param[in] self Pointer to a `const` handle of const bits.
 * @return Tristate boolean.
 * @retval `False` The last bit in the slice is `0`.
 * @retval `True` The last bit in the slice is `1`.
 * @retval `Error` `self` is `null`, or the slice is empty.
 */
extern enum Tristate bitvec_bs_b16_last(
	const struct BitPtrImmut *const self
);

/**
 * @brief Gets the last bit in the bit slice governed by a handle.
 * @param[in] self Pointer to a `const` handle of const bits.
 * @return Tristate boolean.
 * @retval `False` The last bit in the slice is `0`.
 * @retval `True` The last bit in the slice is `1`.
 * @retval `Error` `self` is `null`, or the slice is empty.
 */
extern enum Tristate bitvec_bs_l16_last(
	const struct BitPtrImmut *const self
);

/**
 * @brief Gets the last bit in the bit slice governed by a handle.
 * @param[in] self Pointer to a `const` handle of const bits.
 * @return Tristate boolean.
 * @retval `False` The last bit in the slice is `0`.
 * @retval `True` The last bit in the slice is `1`.
 * @retval `Error` `self` is `null`, or the slice is empty.
 */
extern enum Tristate bitvec_bs_b32_last(
	const struct BitPtrImmut *const self
);

/**
 * @brief Gets the last bit in the bit slice governed by a handle.
 * @param[in] self Pointer to a `const` handle of const bits.
 * @return Tristate boolean.
 * @retval `False` The last bit in the slice is `0`.
 * @retval `True` The last bit in the slice is `1`.
 * @retval `Error` `self` is `null`, or the slice is empty.
 */
extern enum Tristate bitvec_bs_l32_last(
	const struct BitPtrImmut *const self
);

/**
 * @brief Gets the last bit in the bit slice governed by a handle.
 * @param[in] self Pointer to a `const` handle of const bits.
 * @return Tristate boolean.
 * @retval `False` The last bit in the slice is `0`.
 * @retval `True` The last bit in the slice is `1`.
 * @retval `Error` `self` is `null`, or the slice is empty.
 */
extern enum Tristate bitvec_bs_b64_last(
	const struct BitPtrImmut *const self
);

/**
 * @brief Gets the last bit in the bit slice governed by a handle.
 * @param[in] self Pointer to a `const` handle of const bits.
 * @return Tristate boolean.
 * @retval `False` The last bit in the slice is `0`.
 * @retval `True` The last bit in the slice is `1`.
 * @retval `Error` `self` is `null`, or the slice is empty.
 */
extern enum Tristate bitvec_bs_l64_last(
	const struct BitPtrImmut *const self
);

/**
 * @brief Gets the value of the bit at the specified index.
 * @param[in] self Pointer to a `const` handle of const bits.
 * @param index The index to look up in the bit slice.
 * @return Tristate boolean.
 * @retval `False` The bit at the requested index is `0`.
 * @retval `True` The bit at the requested index is `1`.
 * @retval `Error` `self` is `null`, or the requested index is not contained in
 * the bit slice.
 */
extern enum Tristate bitvec_bs_b08_get(
	const struct BitPtrImmut *const self,
	const size_t index
);

/**
 * @brief Gets the value of the bit at the specified index.
 * @param[in] self Pointer to a `const` handle of const bits.
 * @param index The index to look up in the bit slice.
 * @return Tristate boolean.
 * @retval `False` The bit at the requested index is `0`.
 * @retval `True` The bit at the requested index is `1`.
 * @retval `Error` `self` is `null`, or the requested index is not contained in
 * the bit slice.
 */
extern enum Tristate bitvec_bs_l08_get(
	const struct BitPtrImmut *const self,
	const size_t index
);

/**
 * @brief Gets the value of the bit at the specified index.
 * @param[in] self Pointer to a `const` handle of const bits.
 * @param index The index to look up in the bit slice.
 * @return Tristate boolean.
 * @retval `False` The bit at the requested index is `0`.
 * @retval `True` The bit at the requested index is `1`.
 * @retval `Error` `self` is `null`, or the requested index is not contained in
 * the bit slice.
 */
extern enum Tristate bitvec_bs_b16_get(
	const struct BitPtrImmut *const self,
	const size_t index
);

/**
 * @brief Gets the value of the bit at the specified index.
 * @param[in] self Pointer to a `const` handle of const bits.
 * @param index The index to look up in the bit slice.
 * @return Tristate boolean.
 * @retval `False` The bit at the requested index is `0`.
 * @retval `True` The bit at the requested index is `1`.
 * @retval `Error` `self` is `null`, or the requested index is not contained in
 * the bit slice.
 */
extern enum Tristate bitvec_bs_l16_get(
	const struct BitPtrImmut *const self,
	const size_t index
);

/**
 * @brief Gets the value of the bit at the specified index.
 * @param[in] self Pointer to a `const` handle of const bits.
 * @param index The index to look up in the bit slice.
 * @return Tristate boolean.
 * @retval `False` The bit at the requested index is `0`.
 * @retval `True` The bit at the requested index is `1`.
 * @retval `Error` `self` is `null`, or the requested index is not contained in
 * the bit slice.
 */
extern enum Tristate bitvec_bs_b32_get(
	const struct BitPtrImmut *const self,
	const size_t index
);

/**
 * @brief Gets the value of the bit at the specified index.
 * @param[in] self Pointer to a `const` handle of const bits.
 * @param index The index to look up in the bit slice.
 * @return Tristate boolean.
 * @retval `False` The bit at the requested index is `0`.
 * @retval `True` The bit at the requested index is `1`.
 * @retval `Error` `self` is `null`, or the requested index is not contained in
 * the bit slice.
 */
extern enum Tristate bitvec_bs_l32_get(
	const struct BitPtrImmut *const self,
	const size_t index
);

/**
 * @brief Gets the value of the bit at the specified index.
 * @param[in] self Pointer to a `const` handle of const bits.
 * @param index The index to look up in the bit slice.
 * @return Tristate boolean.
 * @retval `False` The bit at the requested index is `0`.
 * @retval `True` The bit at the requested index is `1`.
 * @retval `Error` `self` is `null`, or the requested index is not contained in
 * the bit slice.
 */
extern enum Tristate bitvec_bs_b64_get(
	const struct BitPtrImmut *const self,
	const size_t index
);

/**
 * @brief Gets the value of the bit at the specified index.
 * @param[in] self Pointer to a `const` handle of const bits.
 * @param index The index to look up in the bit slice.
 * @return Tristate boolean.
 * @retval `False` The bit at the requested index is `0`.
 * @retval `True` The bit at the requested index is `1`.
 * @retval `Error` `self` is `null`, or the requested index is not contained in
 * the bit slice.
 */
extern enum Tristate bitvec_bs_l64_get(
	const struct BitPtrImmut *const self,
	const size_t index
);

/**
 * @brief Sets a bit in the slice at the given index to the given value.
 * @param[in] self Pointer to a `const` handle of mutable bits.
 * @param index The index of the bit in the slice to set.
 * @param value The value to set the requested bit.
 *
 * @note If `index` is outside the bounds of the bit slice governed by `*self`,
 * then self function does nothing.
 */
extern void bitvec_bs_b08_set(
	const struct BitPtrMut *const self,
	const size_t index,
	const bool value
);

/**
 * @brief Sets a bit in the slice at the given index to the given value.
 * @param[in] self Pointer to a `const` handle of mutable bits.
 * @param index The index of the bit in the slice to set.
 * @param value The value to set the requested bit.
 *
 * @note If `index` is outside the bounds of the bit slice governed by `*self`,
 * then self function does nothing.
 */
extern void bitvec_bs_l08_set(
	const struct BitPtrMut *const self,
	const size_t index,
	const bool value
);

/**
 * @brief Sets a bit in the slice at the given index to the given value.
 * @param[in] self Pointer to a `const` handle of mutable bits.
 * @param index The index of the bit in the slice to set.
 * @param value The value to set the requested bit.
 *
 * @note If `index` is outside the bounds of the bit slice governed by `*self`,
 * then self function does nothing.
 */
extern void bitvec_bs_b16_set(
	const struct BitPtrMut *const self,
	const size_t index,
	const bool value
);

/**
 * @brief Sets a bit in the slice at the given index to the given value.
 * @param[in] self Pointer to a `const` handle of mutable bits.
 * @param index The index of the bit in the slice to set.
 * @param value The value to set the requested bit.
 *
 * @note If `index` is outside the bounds of the bit slice governed by `*self`,
 * then self function does nothing.
 */
extern void bitvec_bs_l16_set(
	const struct BitPtrMut *const self,
	const size_t index,
	const bool value
);

/**
 * @brief Sets a bit in the slice at the given index to the given value.
 * @param[in] self Pointer to a `const` handle of mutable bits.
 * @param index The index of the bit in the slice to set.
 * @param value The value to set the requested bit.
 *
 * @note If `index` is outside the bounds of the bit slice governed by `*self`,
 * then self function does nothing.
 */
extern void bitvec_bs_b32_set(
	const struct BitPtrMut *const self,
	const size_t index,
	const bool value
);

/**
 * @brief Sets a bit in the slice at the given index to the given value.
 * @param[in] self Pointer to a `const` handle of mutable bits.
 * @param index The index of the bit in the slice to set.
 * @param value The value to set the requested bit.
 *
 * @note If `index` is outside the bounds of the bit slice governed by `*self`,
 * then self function does nothing.
 */
extern void bitvec_bs_l32_set(
	const struct BitPtrMut *const self,
	const size_t index,
	const bool value
);

/**
 * @brief Sets a bit in the slice at the given index to the given value.
 * @param[in] self Pointer to a `const` handle of mutable bits.
 * @param index The index of the bit in the slice to set.
 * @param value The value to set the requested bit.
 *
 * @note If `index` is outside the bounds of the bit slice governed by `*self`,
 * then self function does nothing.
 */
extern void bitvec_bs_b64_set(
	const struct BitPtrMut *const self,
	const size_t index,
	const bool value
);

/**
 * @brief Sets a bit in the slice at the given index to the given value.
 * @param[in] self Pointer to a `const` handle of mutable bits.
 * @param index The index of the bit in the slice to set.
 * @param value The value to set the requested bit.
 *
 * @note If `index` is outside the bounds of the bit slice governed by `*self`,
 * then self function does nothing.
 */
extern void bitvec_bs_l64_set(
	const struct BitPtrMut *const self,
	const size_t index,
	const bool value
);

/**
 * @brief Gets a pointer to the first byte underlying the bit slice governed by
 * a handle.
 * @param[in] self Pointer to a `const` handle of const bits.
 * @return A pointer to the first storage element underlying the bit slice.
 */
extern const uint8_t  *const bitvec_bs_b08_as_ptr(
	const struct BitPtrImmut *const self
);

/**
 * @brief Gets a pointer to the first byte underlying the bit slice governed by
 * a handle.
 * @param[in] self Pointer to a `const` handle of const bits.
 * @return A pointer to the first storage element underlying the bit slice.
 */
extern const uint8_t  *const bitvec_bs_l08_as_ptr(
	const struct BitPtrImmut *const self
);

/**
 * @brief Gets a pointer to the first two bytes underlying the bit slice
 * governed by a handle.
 * @param[in] self Pointer to a `const` handle of const bits.
 * @return A pointer to the first storage element underlying the bit slice.
 */
extern const uint16_t *const bitvec_bs_b16_as_ptr(
	const struct BitPtrImmut *const self
);

/**
 * @brief Gets a pointer to the first two bytes underlying the bit slice
 * governed by a handle.
 * @param[in] self Pointer to a `const` handle of const bits.
 * @return A pointer to the first storage element underlying the bit slice.
 */
extern const uint16_t *const bitvec_bs_l16_as_ptr(
	const struct BitPtrImmut *const self
);

/**
 * @brief Gets a pointer to the first four bytes underlying the bit slice
 * governed by a handle.
 * @param[in] self Pointer to a `const` handle of const bits.
 * @return A pointer to the first storage element underlying the bit slice.
 */
extern const uint32_t *const bitvec_bs_b32_as_ptr(
	const struct BitPtrImmut *const self
);

/**
 * @brief Gets a pointer to the first four bytes underlying the bit slice
 * governed by a handle.
 * @param[in] self Pointer to a `const` handle of const bits.
 * @return A pointer to the first storage element underlying the bit slice.
 */
extern const uint32_t *const bitvec_bs_l32_as_ptr(
	const struct BitPtrImmut *const self
);

/**
 * @brief Gets a pointer to the first eight bytes underlying the bit slice
 * governed by a handle.
 * @param[in] self Pointer to a `const` handle of const bits.
 * @return A pointer to the first storage element underlying the bit slice.
 */
extern const uint64_t *const bitvec_bs_b64_as_ptr(
	const struct BitPtrImmut *const self
);

/**
 * @brief Gets a pointer to the first eight bytes underlying the bit slice
 * governed by a handle.
 * @param[in] self Pointer to a `const` handle of const bits.
 * @return A pointer to the first storage element underlying the bit slice.
 */
extern const uint64_t *const bitvec_bs_l64_as_ptr(
	const struct BitPtrImmut *const self
);

/**
 * @brief Gets a pointer to the first byte underlying the bit slice governed by
 * a handle.
 * @param[in] self Pointer to a `const` handle of mutable bits.
 * @return A pointer to the first storage element underlying the bit slice.
 */
extern       uint8_t  *const bitvec_bs_b08_as_mut_ptr(
	const struct BitPtrMut *const self
);

/**
 * @brief Gets a pointer to the first byte underlying the bit slice governed by
 * a handle.
 * @param[in] self Pointer to a `const` handle of mutable bits.
 * @return A pointer to the first storage element underlying the bit slice.
 */
extern       uint8_t  *const bitvec_bs_l08_as_mut_ptr(
	const struct BitPtrMut *const self
);

/**
 * @brief Gets a pointer to the first two bytes underlying the bit slice
 * governed by a handle.
 * @param[in] self Pointer to a `const` handle of mutable bits.
 * @return A pointer to the first storage element underlying the bit slice.
 */
extern       uint16_t *const bitvec_bs_b16_as_mut_ptr(
	const struct BitPtrMut *const self
);

/**
 * @brief Gets a pointer to the first two bytes underlying the bit slice
 * governed by a handle.
 * @param[in] self Pointer to a `const` handle of mutable bits.
 * @return A pointer to the first storage element underlying the bit slice.
 */
extern       uint16_t *const bitvec_bs_l16_as_mut_ptr(
	const struct BitPtrMut *const self
);

/**
 * @brief Gets a pointer to the first four bytes underlying the bit slice
 * governed by a handle.
 * @param[in] self Pointer to a `const` handle of mutable bits.
 * @return A pointer to the first storage element underlying the bit slice.
 */
extern       uint32_t *const bitvec_bs_b32_as_mut_ptr(
	const struct BitPtrMut *const self
);

/**
 * @brief Gets a pointer to the first four bytes underlying the bit slice
 * governed by a handle.
 * @param[in] self Pointer to a `const` handle of mutable bits.
 * @return A pointer to the first storage element underlying the bit slice.
 */
extern       uint32_t *const bitvec_bs_l32_as_mut_ptr(
	const struct BitPtrMut *const self
);

/**
 * @brief Gets a pointer to the first eight bytes underlying the bit slice
 * governed by a handle.
 * @param[in] self Pointer to a `const` handle of mutable bits.
 * @return A pointer to the first storage element underlying the bit slice.
 */
extern       uint64_t *const bitvec_bs_b64_as_mut_ptr(
	const struct BitPtrMut *const self
);

/**
 * @brief Gets a pointer to the first eight bytes underlying the bit slice
 * governed by a handle.
 * @param[in] self Pointer to a `const` handle of mutable bits.
 * @return A pointer to the first storage element underlying the bit slice.
 */
extern       uint64_t *const bitvec_bs_l64_as_mut_ptr(
	const struct BitPtrMut *const self
);

/**
 * @brief Swaps the bit values at two indices in a bit slice.
 * @param[in] self Pointer to a `const` handle of mutable bits.
 * @param a The first index in the slice to be swapped.
 * @param b The second index in the slice to be swapped.
 *
 * @note If `self` is `null`, or if either `a` or `b` are out of bounds of the
 * bit slice governed by `*self`, then self function does nothing.
 */
extern void bitvec_bs_b08_swap(
	const struct BitPtrMut *const self,
	const size_t a,
	const size_t b
);

/**
 * @brief Swaps the bit values at two indices in a bit slice.
 * @param[in] self Pointer to a `const` handle of mutable bits.
 * @param a The first index in the slice to be swapped.
 * @param b The second index in the slice to be swapped.
 *
 * @note If `self` is `null`, or if either `a` or `b` are out of bounds of the
 * bit slice governed by `*self`, then self function does nothing.
 */
extern void bitvec_bs_l08_swap(
	const struct BitPtrMut *const self,
	const size_t a,
	const size_t b
);

/**
 * @brief Swaps the bit values at two indices in a bit slice.
 * @param[in] self Pointer to a `const` handle of mutable bits.
 * @param a The first index in the slice to be swapped.
 * @param b The second index in the slice to be swapped.
 *
 * @note If `self` is `null`, or if either `a` or `b` are out of bounds of the
 * bit slice governed by `*self`, then self function does nothing.
 */
extern void bitvec_bs_b16_swap(
	const struct BitPtrMut *const self,
	const size_t a,
	const size_t b
);

/**
 * @brief Swaps the bit values at two indices in a bit slice.
 * @param[in] self Pointer to a `const` handle of mutable bits.
 * @param a The first index in the slice to be swapped.
 * @param b The second index in the slice to be swapped.
 *
 * @note If `self` is `null`, or if either `a` or `b` are out of bounds of the
 * bit slice governed by `*self`, then self function does nothing.
 */
extern void bitvec_bs_l16_swap(
	const struct BitPtrMut *const self,
	const size_t a,
	const size_t b
);

/**
 * @brief Swaps the bit values at two indices in a bit slice.
 * @param[in] self Pointer to a `const` handle of mutable bits.
 * @param a The first index in the slice to be swapped.
 * @param b The second index in the slice to be swapped.
 *
 * @note If `self` is `null`, or if either `a` or `b` are out of bounds of the
 * bit slice governed by `*self`, then self function does nothing.
 */
extern void bitvec_bs_b32_swap(
	const struct BitPtrMut *const self,
	const size_t a,
	const size_t b
);

/**
 * @brief Swaps the bit values at two indices in a bit slice.
 * @param[in] self Pointer to a `const` handle of mutable bits.
 * @param a The first index in the slice to be swapped.
 * @param b The second index in the slice to be swapped.
 *
 * @note If `self` is `null`, or if either `a` or `b` are out of bounds of the
 * bit slice governed by `*self`, then self function does nothing.
 */
extern void bitvec_bs_l32_swap(
	const struct BitPtrMut *const self,
	const size_t a,
	const size_t b
);

/**
 * @brief Swaps the bit values at two indices in a bit slice.
 * @param[in] self Pointer to a `const` handle of mutable bits.
 * @param a The first index in the slice to be swapped.
 * @param b The second index in the slice to be swapped.
 *
 * @note If `self` is `null`, or if either `a` or `b` are out of bounds of the
 * bit slice governed by `*self`, then self function does nothing.
 */
extern void bitvec_bs_b64_swap(
	const struct BitPtrMut *const self,
	const size_t a,
	const size_t b
);

/**
 * @brief Swaps the bit values at two indices in a bit slice.
 * @param[in] self Pointer to a `const` handle of mutable bits.
 * @param a The first index in the slice to be swapped.
 * @param b The second index in the slice to be swapped.
 *
 * @note If `self` is `null`, or if either `a` or `b` are out of bounds of the
 * bit slice governed by `*self`, then self function does nothing.
 */
extern void bitvec_bs_l64_swap(
	const struct BitPtrMut *const self,
	const size_t a,
	const size_t b
);

/**
 * @brief Reverses the bits in the slice governed by a handle.
 * @param[in] self Pointer to a `const` handle over mutable bits.
 */
extern void bitvec_bs_b08_reverse(const struct BitPtrMut *const self);

/**
 * @brief Reverses the bits in the slice governed by a handle.
 * @param[in] self Pointer to a `const` handle over mutable bits.
 */
extern void bitvec_bs_l08_reverse(const struct BitPtrMut *const self);

/**
 * @brief Reverses the bits in the slice governed by a handle.
 * @param[in] self Pointer to a `const` handle over mutable bits.
 */
extern void bitvec_bs_b16_reverse(const struct BitPtrMut *const self);

/**
 * @brief Reverses the bits in the slice governed by a handle.
 * @param[in] self Pointer to a `const` handle over mutable bits.
 */
extern void bitvec_bs_l16_reverse(const struct BitPtrMut *const self);

/**
 * @brief Reverses the bits in the slice governed by a handle.
 * @param[in] self Pointer to a `const` handle over mutable bits.
 */
extern void bitvec_bs_b32_reverse(const struct BitPtrMut *const self);

/**
 * @brief Reverses the bits in the slice governed by a handle.
 * @param[in] self Pointer to a `const` handle over mutable bits.
 */
extern void bitvec_bs_l32_reverse(const struct BitPtrMut *const self);

/**
 * @brief Reverses the bits in the slice governed by a handle.
 * @param[in] self Pointer to a `const` handle over mutable bits.
 */
extern void bitvec_bs_b64_reverse(const struct BitPtrMut *const self);

/**
 * @brief Reverses the bits in the slice governed by a handle.
 * @param[in] self Pointer to a `const` handle over mutable bits.
 */
extern void bitvec_bs_l64_reverse(const struct BitPtrMut *const self);

/**
 * @brief Splits the slice governed by a handle into two non-overlapping slices
 * each with their own handle.
 * @param[in,out] self Pointer to a handle over const bits. After the function
 * returns, self handle will govern a slice that ends at `mid`.
 * @param[out] other Pointer to an *uninitialized* handle. After the function
 * returns, self handle will govern the remainder of the original slice from
 * `mid` onward.
 * @param mid The index at which to split the slice.
 * @return Whether the split was successful, and `*other` is initialized.
 * @retval `true` `mid` was in bounds of the original slice, so `*self` now
 * governs from `.. mid` and `*other` governs from `mid ..`.
 * @retval `false` `self` or `other` was `null`, or `mid` was out of bounds. No
 * split occurred, `*self` is not modified, and `*other` is uninitialized.
 *
 * @note `mid` may be in the full range `0 ..= len`. If it is `0`, then `*self`
 * will become the empty slice, and if it is `len`, then `*other` will become
 * the empty slice.
 */
extern bool bitvec_bs_b08_split_at(
	struct BitPtrImmut *const self,
	struct BitPtrImmut *const other,
	const size_t mid
);

/**
 * @brief Splits the slice governed by a handle into two non-overlapping slices
 * each with their own handle.
 * @param[in,out] self Pointer to a handle over const bits. After the function
 * returns, self handle will govern a slice that ends at `mid`.
 * @param[out] other Pointer to an *uninitialized* handle. After the function
 * returns, self handle will govern the remainder of the original slice from
 * `mid` onward.
 * @param mid The index at which to split the slice.
 * @return Whether the split was successful, and `*other` is initialized.
 * @retval `true` `mid` was in bounds of the original slice, so `*self` now
 * governs from `.. mid` and `*other` governs from `mid ..`.
 * @retval `false` `self` or `other` was `null`, or `mid` was out of bounds. No
 * split occurred, `*self` is not modified, and `*other` is uninitialized.
 *
 * @note `mid` may be in the full range `0 ..= len`. If it is `0`, then `*self`
 * will become the empty slice, and if it is `len`, then `*other` will become
 * the empty slice.
 */
extern bool bitvec_bs_l08_split_at(
	struct BitPtrImmut *const self,
	struct BitPtrImmut *const other,
	const size_t mid
);

/**
 * @brief Splits the slice governed by a handle into two non-overlapping slices
 * each with their own handle.
 * @param[in,out] self Pointer to a handle over const bits. After the function
 * returns, self handle will govern a slice that ends at `mid`.
 * @param[out] other Pointer to an *uninitialized* handle. After the function
 * returns, self handle will govern the remainder of the original slice from
 * `mid` onward.
 * @param mid The index at which to split the slice.
 * @return Whether the split was successful, and `*other` is initialized.
 * @retval `true` `mid` was in bounds of the original slice, so `*self` now
 * governs from `.. mid` and `*other` governs from `mid ..`.
 * @retval `false` `self` or `other` was `null`, or `mid` was out of bounds. No
 * split occurred, `*self` is not modified, and `*other` is uninitialized.
 *
 * @note `mid` may be in the full range `0 ..= len`. If it is `0`, then `*self`
 * will become the empty slice, and if it is `len`, then `*other` will become
 * the empty slice.
 */
extern bool bitvec_bs_b16_split_at(
	struct BitPtrImmut *const self,
	struct BitPtrImmut *const other,
	const size_t mid
);

/**
 * @brief Splits the slice governed by a handle into two non-overlapping slices
 * each with their own handle.
 * @param[in,out] self Pointer to a handle over const bits. After the function
 * returns, self handle will govern a slice that ends at `mid`.
 * @param[out] other Pointer to an *uninitialized* handle. After the function
 * returns, self handle will govern the remainder of the original slice from
 * `mid` onward.
 * @param mid The index at which to split the slice.
 * @return Whether the split was successful, and `*other` is initialized.
 * @retval `true` `mid` was in bounds of the original slice, so `*self` now
 * governs from `.. mid` and `*other` governs from `mid ..`.
 * @retval `false` `self` or `other` was `null`, or `mid` was out of bounds. No
 * split occurred, `*self` is not modified, and `*other` is uninitialized.
 *
 * @note `mid` may be in the full range `0 ..= len`. If it is `0`, then `*self`
 * will become the empty slice, and if it is `len`, then `*other` will become
 * the empty slice.
 */
extern bool bitvec_bs_l16_split_at(
	struct BitPtrImmut *const self,
	struct BitPtrImmut *const other,
	const size_t mid
);

/**
 * @brief Splits the slice governed by a handle into two non-overlapping slices
 * each with their own handle.
 * @param[in,out] self Pointer to a handle over const bits. After the function
 * returns, self handle will govern a slice that ends at `mid`.
 * @param[out] other Pointer to an *uninitialized* handle. After the function
 * returns, self handle will govern the remainder of the original slice from
 * `mid` onward.
 * @param mid The index at which to split the slice.
 * @return Whether the split was successful, and `*other` is initialized.
 * @retval `true` `mid` was in bounds of the original slice, so `*self` now
 * governs from `.. mid` and `*other` governs from `mid ..`.
 * @retval `false` `self` or `other` was `null`, or `mid` was out of bounds. No
 * split occurred, `*self` is not modified, and `*other` is uninitialized.
 *
 * @note `mid` may be in the full range `0 ..= len`. If it is `0`, then `*self`
 * will become the empty slice, and if it is `len`, then `*other` will become
 * the empty slice.
 */
extern bool bitvec_bs_b32_split_at(
	struct BitPtrImmut *const self,
	struct BitPtrImmut *const other,
	const size_t mid
);

/**
 * @brief Splits the slice governed by a handle into two non-overlapping slices
 * each with their own handle.
 * @param[in,out] self Pointer to a handle over const bits. After the function
 * returns, self handle will govern a slice that ends at `mid`.
 * @param[out] other Pointer to an *uninitialized* handle. After the function
 * returns, self handle will govern the remainder of the original slice from
 * `mid` onward.
 * @param mid The index at which to split the slice.
 * @return Whether the split was successful, and `*other` is initialized.
 * @retval `true` `mid` was in bounds of the original slice, so `*self` now
 * governs from `.. mid` and `*other` governs from `mid ..`.
 * @retval `false` `self` or `other` was `null`, or `mid` was out of bounds. No
 * split occurred, `*self` is not modified, and `*other` is uninitialized.
 *
 * @note `mid` may be in the full range `0 ..= len`. If it is `0`, then `*self`
 * will become the empty slice, and if it is `len`, then `*other` will become
 * the empty slice.
 */
extern bool bitvec_bs_l32_split_at(
	struct BitPtrImmut *const self,
	struct BitPtrImmut *const other,
	const size_t mid
);

/**
 * @brief Splits the slice governed by a handle into two non-overlapping slices
 * each with their own handle.
 * @param[in,out] self Pointer to a handle over const bits. After the function
 * returns, self handle will govern a slice that ends at `mid`.
 * @param[out] other Pointer to an *uninitialized* handle. After the function
 * returns, self handle will govern the remainder of the original slice from
 * `mid` onward.
 * @param mid The index at which to split the slice.
 * @return Whether the split was successful, and `*other` is initialized.
 * @retval `true` `mid` was in bounds of the original slice, so `*self` now
 * governs from `.. mid` and `*other` governs from `mid ..`.
 * @retval `false` `self` or `other` was `null`, or `mid` was out of bounds. No
 * split occurred, `*self` is not modified, and `*other` is uninitialized.
 *
 * @note `mid` may be in the full range `0 ..= len`. If it is `0`, then `*self`
 * will become the empty slice, and if it is `len`, then `*other` will become
 * the empty slice.
 */
extern bool bitvec_bs_b64_split_at(
	struct BitPtrImmut *const self,
	struct BitPtrImmut *const other,
	const size_t mid
);

/**
 * @brief Splits the slice governed by a handle into two non-overlapping slices
 * each with their own handle.
 * @param[in,out] self Pointer to a handle over const bits. After the function
 * returns, self handle will govern a slice that ends at `mid`.
 * @param[out] other Pointer to an *uninitialized* handle. After the function
 * returns, self handle will govern the remainder of the original slice from
 * `mid` onward.
 * @param mid The index at which to split the slice.
 * @return Whether the split was successful, and `*other` is initialized.
 * @retval `true` `mid` was in bounds of the original slice, so `*self` now
 * governs from `.. mid` and `*other` governs from `mid ..`.
 * @retval `false` `self` or `other` was `null`, or `mid` was out of bounds. No
 * split occurred, `*self` is not modified, and `*other` is uninitialized.
 *
 * @note `mid` may be in the full range `0 ..= len`. If it is `0`, then `*self`
 * will become the empty slice, and if it is `len`, then `*other` will become
 * the empty slice.
 */
extern bool bitvec_bs_l64_split_at(
	struct BitPtrImmut *const self,
	struct BitPtrImmut *const other,
	const size_t mid
);

/**
 * @brief Splits the slice governed by a handle into two non-overlapping slices
 * each with their own handle.
 * @param[in,out] self Pointer to a handle over mutable bits. After the function
 * returns, self handle will govern a slice that ends at `mid`.
 * @param[out] other Pointer to an *uninitialized* handle. After the function
 * returns, self handle will govern the remainder of the original slice from
 * `mid` onward.
 * @param mid The index at which to split the slice.
 * @return Whether the split was successful, and `*other` is initialized.
 * @retval `true` `mid` was in bounds of the original slice, so `*self` now
 * governs from `.. mid` and `*other` governs from `mid ..`.
 * @retval `false` `self` or `other` was `null`, or `mid` was out of bounds. No
 * split occurred, `*self` is not modified, and `*other` is uninitialized.
 *
 * @note `mid` may be in the full range `0 ..= len`. If it is `0`, then `*self`
 * will become the empty slice, and if it is `len`, then `*other` will become
 * the empty slice.
 */
extern bool bitvec_bs_b08_split_at_mut(
	struct BitPtrMut *const self,
	struct BitPtrMut *const other,
	const size_t mid
);

/**
 * @brief Splits the slice governed by a handle into two non-overlapping slices
 * each with their own handle.
 * @param[in,out] self Pointer to a handle over mutable bits. After the function
 * returns, self handle will govern a slice that ends at `mid`.
 * @param[out] other Pointer to an *uninitialized* handle. After the function
 * returns, self handle will govern the remainder of the original slice from
 * `mid` onward.
 * @param mid The index at which to split the slice.
 * @return Whether the split was successful, and `*other` is initialized.
 * @retval `true` `mid` was in bounds of the original slice, so `*self` now
 * governs from `.. mid` and `*other` governs from `mid ..`.
 * @retval `false` `self` or `other` was `null`, or `mid` was out of bounds. No
 * split occurred, `*self` is not modified, and `*other` is uninitialized.
 *
 * @note `mid` may be in the full range `0 ..= len`. If it is `0`, then `*self`
 * will become the empty slice, and if it is `len`, then `*other` will become
 * the empty slice.
 */
extern bool bitvec_bs_l08_split_at_mut(
	struct BitPtrMut *const self,
	struct BitPtrMut *const other,
	const size_t mid
);

/**
 * @brief Splits the slice governed by a handle into two non-overlapping slices
 * each with their own handle.
 * @param[in,out] self Pointer to a handle over mutable bits. After the function
 * returns, self handle will govern a slice that ends at `mid`.
 * @param[out] other Pointer to an *uninitialized* handle. After the function
 * returns, self handle will govern the remainder of the original slice from
 * `mid` onward.
 * @param mid The index at which to split the slice.
 * @return Whether the split was successful, and `*other` is initialized.
 * @retval `true` `mid` was in bounds of the original slice, so `*self` now
 * governs from `.. mid` and `*other` governs from `mid ..`.
 * @retval `false` `self` or `other` was `null`, or `mid` was out of bounds. No
 * split occurred, `*self` is not modified, and `*other` is uninitialized.
 *
 * @note `mid` may be in the full range `0 ..= len`. If it is `0`, then `*self`
 * will become the empty slice, and if it is `len`, then `*other` will become
 * the empty slice.
 */
extern bool bitvec_bs_b16_split_at_mut(
	struct BitPtrMut *const self,
	struct BitPtrMut *const other,
	const size_t mid
);

/**
 * @brief Splits the slice governed by a handle into two non-overlapping slices
 * each with their own handle.
 * @param[in,out] self Pointer to a handle over mutable bits. After the function
 * returns, self handle will govern a slice that ends at `mid`.
 * @param[out] other Pointer to an *uninitialized* handle. After the function
 * returns, self handle will govern the remainder of the original slice from
 * `mid` onward.
 * @param mid The index at which to split the slice.
 * @return Whether the split was successful, and `*other` is initialized.
 * @retval `true` `mid` was in bounds of the original slice, so `*self` now
 * governs from `.. mid` and `*other` governs from `mid ..`.
 * @retval `false` `self` or `other` was `null`, or `mid` was out of bounds. No
 * split occurred, `*self` is not modified, and `*other` is uninitialized.
 *
 * @note `mid` may be in the full range `0 ..= len`. If it is `0`, then `*self`
 * will become the empty slice, and if it is `len`, then `*other` will become
 * the empty slice.
 */
extern bool bitvec_bs_l16_split_at_mut(
	struct BitPtrMut *const self,
	struct BitPtrMut *const other,
	const size_t mid
);

/**
 * @brief Splits the slice governed by a handle into two non-overlapping slices
 * each with their own handle.
 * @param[in,out] self Pointer to a handle over mutable bits. After the function
 * returns, self handle will govern a slice that ends at `mid`.
 * @param[out] other Pointer to an *uninitialized* handle. After the function
 * returns, self handle will govern the remainder of the original slice from
 * `mid` onward.
 * @param mid The index at which to split the slice.
 * @return Whether the split was successful, and `*other` is initialized.
 * @retval `true` `mid` was in bounds of the original slice, so `*self` now
 * governs from `.. mid` and `*other` governs from `mid ..`.
 * @retval `false` `self` or `other` was `null`, or `mid` was out of bounds. No
 * split occurred, `*self` is not modified, and `*other` is uninitialized.
 *
 * @note `mid` may be in the full range `0 ..= len`. If it is `0`, then `*self`
 * will become the empty slice, and if it is `len`, then `*other` will become
 * the empty slice.
 */
extern bool bitvec_bs_b32_split_at_mut(
	struct BitPtrMut *const self,
	struct BitPtrMut *const other,
	const size_t mid
);

/**
 * @brief Splits the slice governed by a handle into two non-overlapping slices
 * each with their own handle.
 * @param[in,out] self Pointer to a handle over mutable bits. After the function
 * returns, self handle will govern a slice that ends at `mid`.
 * @param[out] other Pointer to an *uninitialized* handle. After the function
 * returns, self handle will govern the remainder of the original slice from
 * `mid` onward.
 * @param mid The index at which to split the slice.
 * @return Whether the split was successful, and `*other` is initialized.
 * @retval `true` `mid` was in bounds of the original slice, so `*self` now
 * governs from `.. mid` and `*other` governs from `mid ..`.
 * @retval `false` `self` or `other` was `null`, or `mid` was out of bounds. No
 * split occurred, `*self` is not modified, and `*other` is uninitialized.
 *
 * @note `mid` may be in the full range `0 ..= len`. If it is `0`, then `*self`
 * will become the empty slice, and if it is `len`, then `*other` will become
 * the empty slice.
 */
extern bool bitvec_bs_l32_split_at_mut(
	struct BitPtrMut *const self,
	struct BitPtrMut *const other,
	const size_t mid
);

/**
 * @brief Splits the slice governed by a handle into two non-overlapping slices
 * each with their own handle.
 * @param[in,out] self Pointer to a handle over mutable bits. After the function
 * returns, self handle will govern a slice that ends at `mid`.
 * @param[out] other Pointer to an *uninitialized* handle. After the function
 * returns, self handle will govern the remainder of the original slice from
 * `mid` onward.
 * @param mid The index at which to split the slice.
 * @return Whether the split was successful, and `*other` is initialized.
 * @retval `true` `mid` was in bounds of the original slice, so `*self` now
 * governs from `.. mid` and `*other` governs from `mid ..`.
 * @retval `false` `self` or `other` was `null`, or `mid` was out of bounds. No
 * split occurred, `*self` is not modified, and `*other` is uninitialized.
 *
 * @note `mid` may be in the full range `0 ..= len`. If it is `0`, then `*self`
 * will become the empty slice, and if it is `len`, then `*other` will become
 * the empty slice.
 */
extern bool bitvec_bs_b64_split_at_mut(
	struct BitPtrMut *const self,
	struct BitPtrMut *const other,
	const size_t mid
);

/**
 * @brief Splits the slice governed by a handle into two non-overlapping slices
 * each with their own handle.
 * @param[in,out] self Pointer to a handle over mutable bits. After the function
 * returns, self handle will govern a slice that ends at `mid`.
 * @param[out] other Pointer to an *uninitialized* handle. After the function
 * returns, self handle will govern the remainder of the original slice from
 * `mid` onward.
 * @param mid The index at which to split the slice.
 * @return Whether the split was successful, and `*other` is initialized.
 * @retval `true` `mid` was in bounds of the original slice, so `*self` now
 * governs from `.. mid` and `*other` governs from `mid ..`.
 * @retval `false` `self` or `other` was `null`, or `mid` was out of bounds. No
 * split occurred, `*self` is not modified, and `*other` is uninitialized.
 *
 * @note `mid` may be in the full range `0 ..= len`. If it is `0`, then `*self`
 * will become the empty slice, and if it is `len`, then `*other` will become
 * the empty slice.
 */
extern bool bitvec_bs_l64_split_at_mut(
	struct BitPtrMut *const self,
	struct BitPtrMut *const other,
	const size_t mid
);

/**
 * @brief Rotates the bits in the slice governed by a handle towards the front
 * by some amount.
 * @param[in] self Pointer to a `const` handle over mutable bits.
 * @param by The amount by which to rotate the bits in the slice. If self
 * exceeds the length of the slice governed by `*self`, then self function does
 * nothing.
 *
 * After self function returns, each value in the bit slice has moved `by`
 * indices towards the front, wrapping if need be.
 */
extern void bitvec_bs_b08_rotate_left(
	const struct BitPtrMut *const self,
	const size_t by
);

/**
 * @brief Rotates the bits in the slice governed by a handle towards the front
 * by some amount.
 * @param[in] self Pointer to a `const` handle over mutable bits.
 * @param by The amount by which to rotate the bits in the slice. If self
 * exceeds the length of the slice governed by `*self`, then self function does
 * nothing.
 *
 * After self function returns, each value in the bit slice has moved `by`
 * indices towards the front, wrapping if need be.
 */
extern void bitvec_bs_l08_rotate_left(
	const struct BitPtrMut *const self,
	const size_t by
);

/**
 * @brief Rotates the bits in the slice governed by a handle towards the front
 * by some amount.
 * @param[in] self Pointer to a `const` handle over mutable bits.
 * @param by The amount by which to rotate the bits in the slice. If self
 * exceeds the length of the slice governed by `*self`, then self function does
 * nothing.
 *
 * After self function returns, each value in the bit slice has moved `by`
 * indices towards the front, wrapping if need be.
 */
extern void bitvec_bs_b16_rotate_left(
	const struct BitPtrMut *const self,
	const size_t by
);

/**
 * @brief Rotates the bits in the slice governed by a handle towards the front
 * by some amount.
 * @param[in] self Pointer to a `const` handle over mutable bits.
 * @param by The amount by which to rotate the bits in the slice. If self
 * exceeds the length of the slice governed by `*self`, then self function does
 * nothing.
 *
 * After self function returns, each value in the bit slice has moved `by`
 * indices towards the front, wrapping if need be.
 */
extern void bitvec_bs_l16_rotate_left(
	const struct BitPtrMut *const self,
	const size_t by
);

/**
 * @brief Rotates the bits in the slice governed by a handle towards the front
 * by some amount.
 * @param[in] self Pointer to a `const` handle over mutable bits.
 * @param by The amount by which to rotate the bits in the slice. If self
 * exceeds the length of the slice governed by `*self`, then self function does
 * nothing.
 *
 * After self function returns, each value in the bit slice has moved `by`
 * indices towards the front, wrapping if need be.
 */
extern void bitvec_bs_b32_rotate_left(
	const struct BitPtrMut *const self,
	const size_t by
);

/**
 * @brief Rotates the bits in the slice governed by a handle towards the front
 * by some amount.
 * @param[in] self Pointer to a `const` handle over mutable bits.
 * @param by The amount by which to rotate the bits in the slice. If self
 * exceeds the length of the slice governed by `*self`, then self function does
 * nothing.
 *
 * After self function returns, each value in the bit slice has moved `by`
 * indices towards the front, wrapping if need be.
 */
extern void bitvec_bs_l32_rotate_left(
	const struct BitPtrMut *const self,
	const size_t by
);

/**
 * @brief Rotates the bits in the slice governed by a handle towards the front
 * by some amount.
 * @param[in] self Pointer to a `const` handle over mutable bits.
 * @param by The amount by which to rotate the bits in the slice. If self
 * exceeds the length of the slice governed by `*self`, then self function does
 * nothing.
 *
 * After self function returns, each value in the bit slice has moved `by`
 * indices towards the front, wrapping if need be.
 */
extern void bitvec_bs_b64_rotate_left(
	const struct BitPtrMut *const self,
	const size_t by
);

/**
 * @brief Rotates the bits in the slice governed by a handle towards the front
 * by some amount.
 * @param[in] self Pointer to a `const` handle over mutable bits.
 * @param by The amount by which to rotate the bits in the slice. If self
 * exceeds the length of the slice governed by `*self`, then self function does
 * nothing.
 *
 * After self function returns, each value in the bit slice has moved `by`
 * indices towards the front, wrapping if need be.
 */
extern void bitvec_bs_l64_rotate_left(
	const struct BitPtrMut *const self,
	const size_t by
);

/**
 * @brief Rotates the bits in the slice governed by a handle towards the back by
 * some amount.
 * @param[in] self Pointer to a `const` handle over mutable bits.
 * @param by The amount by which to rotate the bits in the slice. If self
 * exceeds the length of the slice governed by `*self`, then self function does
 * nothing.
 *
 * After self function returns, each value in the bit slice has moved `by`
 * indices towards the back, wrapping if need be.
 */
extern void bitvec_bs_b08_rotate_right(
	const struct BitPtrMut *const self,
	const size_t by
);

/**
 * @brief Rotates the bits in the slice governed by a handle towards the back by
 * some amount.
 * @param[in] self Pointer to a `const` handle over mutable bits.
 * @param by The amount by which to rotate the bits in the slice. If self
 * exceeds the length of the slice governed by `*self`, then self function does
 * nothing.
 *
 * After self function returns, each value in the bit slice has moved `by`
 * indices towards the back, wrapping if need be.
 */
extern void bitvec_bs_l08_rotate_right(
	const struct BitPtrMut *const self,
	const size_t by
);

/**
 * @brief Rotates the bits in the slice governed by a handle towards the back by
 * some amount.
 * @param[in] self Pointer to a `const` handle over mutable bits.
 * @param by The amount by which to rotate the bits in the slice. If self
 * exceeds the length of the slice governed by `*self`, then self function does
 * nothing.
 *
 * After self function returns, each value in the bit slice has moved `by`
 * indices towards the back, wrapping if need be.
 */
extern void bitvec_bs_b16_rotate_right(
	const struct BitPtrMut *const self,
	const size_t by
);

/**
 * @brief Rotates the bits in the slice governed by a handle towards the back by
 * some amount.
 * @param[in] self Pointer to a `const` handle over mutable bits.
 * @param by The amount by which to rotate the bits in the slice. If self
 * exceeds the length of the slice governed by `*self`, then self function does
 * nothing.
 *
 * After self function returns, each value in the bit slice has moved `by`
 * indices towards the back, wrapping if need be.
 */
extern void bitvec_bs_l16_rotate_right(
	const struct BitPtrMut *const self,
	const size_t by
);

/**
 * @brief Rotates the bits in the slice governed by a handle towards the back by
 * some amount.
 * @param[in] self Pointer to a `const` handle over mutable bits.
 * @param by The amount by which to rotate the bits in the slice. If self
 * exceeds the length of the slice governed by `*self`, then self function does
 * nothing.
 *
 * After self function returns, each value in the bit slice has moved `by`
 * indices towards the back, wrapping if need be.
 */
extern void bitvec_bs_b32_rotate_right(
	const struct BitPtrMut *const self,
	const size_t by
);

/**
 * @brief Rotates the bits in the slice governed by a handle towards the back by
 * some amount.
 * @param[in] self Pointer to a `const` handle over mutable bits.
 * @param by The amount by which to rotate the bits in the slice. If self
 * exceeds the length of the slice governed by `*self`, then self function does
 * nothing.
 *
 * After self function returns, each value in the bit slice has moved `by`
 * indices towards the back, wrapping if need be.
 */
extern void bitvec_bs_l32_rotate_right(
	const struct BitPtrMut *const self,
	const size_t by
);

/**
 * @brief Rotates the bits in the slice governed by a handle towards the back by
 * some amount.
 * @param[in] self Pointer to a `const` handle over mutable bits.
 * @param by The amount by which to rotate the bits in the slice. If self
 * exceeds the length of the slice governed by `*self`, then self function does
 * nothing.
 *
 * After self function returns, each value in the bit slice has moved `by`
 * indices towards the back, wrapping if need be.
 */
extern void bitvec_bs_b64_rotate_right(
	const struct BitPtrMut *const self,
	const size_t by
);

/**
 * @brief Rotates the bits in the slice governed by a handle towards the back by
 * some amount.
 * @param[in] self Pointer to a `const` handle over mutable bits.
 * @param by The amount by which to rotate the bits in the slice. If self
 * exceeds the length of the slice governed by `*self`, then self function does
 * nothing.
 *
 * After self function returns, each value in the bit slice has moved `by`
 * indices towards the back, wrapping if need be.
 */
extern void bitvec_bs_l64_rotate_right(
	const struct BitPtrMut *const self,
	const size_t by
);

/**
 * @brief Tests if all bits in the slice governed by a handle are set to `1`.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return Tristate boolean.
 * @retval `False` At least one bit in the slice is `0`.
 * @retval `True` All bits in the slice are `1`.
 * @retval `Error` `self` is `null`.
 */
extern enum Tristate bitvec_bs_b08_all(const struct BitPtrImmut *const self);

/**
 * @brief Tests if all bits in the slice governed by a handle are set to `1`.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return Tristate boolean.
 * @retval `False` At least one bit in the slice is `0`.
 * @retval `True` All bits in the slice are `1`.
 * @retval `Error` `self` is `null`.
 */
extern enum Tristate bitvec_bs_l08_all(const struct BitPtrImmut *const self);

/**
 * @brief Tests if all bits in the slice governed by a handle are set to `1`.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return Tristate boolean.
 * @retval `False` At least one bit in the slice is `0`.
 * @retval `True` All bits in the slice are `1`.
 * @retval `Error` `self` is `null`.
 */
extern enum Tristate bitvec_bs_b16_all(const struct BitPtrImmut *const self);

/**
 * @brief Tests if all bits in the slice governed by a handle are set to `1`.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return Tristate boolean.
 * @retval `False` At least one bit in the slice is `0`.
 * @retval `True` All bits in the slice are `1`.
 * @retval `Error` `self` is `null`.
 */
extern enum Tristate bitvec_bs_l16_all(const struct BitPtrImmut *const self);

/**
 * @brief Tests if all bits in the slice governed by a handle are set to `1`.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return Tristate boolean.
 * @retval `False` At least one bit in the slice is `0`.
 * @retval `True` All bits in the slice are `1`.
 * @retval `Error` `self` is `null`.
 */
extern enum Tristate bitvec_bs_b32_all(const struct BitPtrImmut *const self);

/**
 * @brief Tests if all bits in the slice governed by a handle are set to `1`.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return Tristate boolean.
 * @retval `False` At least one bit in the slice is `0`.
 * @retval `True` All bits in the slice are `1`.
 * @retval `Error` `self` is `null`.
 */
extern enum Tristate bitvec_bs_l32_all(const struct BitPtrImmut *const self);

/**
 * @brief Tests if all bits in the slice governed by a handle are set to `1`.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return Tristate boolean.
 * @retval `False` At least one bit in the slice is `0`.
 * @retval `True` All bits in the slice are `1`.
 * @retval `Error` `self` is `null`.
 */
extern enum Tristate bitvec_bs_b64_all(const struct BitPtrImmut *const self);

/**
 * @brief Tests if all bits in the slice governed by a handle are set to `1`.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return Tristate boolean.
 * @retval `False` At least one bit in the slice is `0`.
 * @retval `True` All bits in the slice are `1`.
 * @retval `Error` `self` is `null`.
 */
extern enum Tristate bitvec_bs_l64_all(const struct BitPtrImmut *const self);

/**
 * @brief Tests if any bit in the slice governed by a handle is set to `1`.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return Tristate boolean.
 * @retval `False` No bit in the slice is `1`.
 * @retval `True` At least one bit in the slice is `1`.
 * @retval `Error` `self` is `null`.
 */
extern enum Tristate bitvec_bs_b08_any(const struct BitPtrImmut *const self);

/**
 * @brief Tests if any bit in the slice governed by a handle is set to `1`.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return Tristate boolean.
 * @retval `False` No bit in the slice is `1`.
 * @retval `True` At least one bit in the slice is `1`.
 * @retval `Error` `self` is `null`.
 */
extern enum Tristate bitvec_bs_l08_any(const struct BitPtrImmut *const self);

/**
 * @brief Tests if any bit in the slice governed by a handle is set to `1`.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return Tristate boolean.
 * @retval `False` No bit in the slice is `1`.
 * @retval `True` At least one bit in the slice is `1`.
 * @retval `Error` `self` is `null`.
 */
extern enum Tristate bitvec_bs_b16_any(const struct BitPtrImmut *const self);

/**
 * @brief Tests if any bit in the slice governed by a handle is set to `1`.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return Tristate boolean.
 * @retval `False` No bit in the slice is `1`.
 * @retval `True` At least one bit in the slice is `1`.
 * @retval `Error` `self` is `null`.
 */
extern enum Tristate bitvec_bs_l16_any(const struct BitPtrImmut *const self);

/**
 * @brief Tests if any bit in the slice governed by a handle is set to `1`.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return Tristate boolean.
 * @retval `False` No bit in the slice is `1`.
 * @retval `True` At least one bit in the slice is `1`.
 * @retval `Error` `self` is `null`.
 */
extern enum Tristate bitvec_bs_b32_any(const struct BitPtrImmut *const self);

/**
 * @brief Tests if any bit in the slice governed by a handle is set to `1`.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return Tristate boolean.
 * @retval `False` No bit in the slice is `1`.
 * @retval `True` At least one bit in the slice is `1`.
 * @retval `Error` `self` is `null`.
 */
extern enum Tristate bitvec_bs_l32_any(const struct BitPtrImmut *const self);

/**
 * @brief Tests if any bit in the slice governed by a handle is set to `1`.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return Tristate boolean.
 * @retval `False` No bit in the slice is `1`.
 * @retval `True` At least one bit in the slice is `1`.
 * @retval `Error` `self` is `null`.
 */
extern enum Tristate bitvec_bs_b64_any(const struct BitPtrImmut *const self);

/**
 * @brief Tests if any bit in the slice governed by a handle is set to `1`.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return Tristate boolean.
 * @retval `False` No bit in the slice is `1`.
 * @retval `True` At least one bit in the slice is `1`.
 * @retval `Error` `self` is `null`.
 */
extern enum Tristate bitvec_bs_l64_any(const struct BitPtrImmut *const self);

/**
 * @brief Tests if any bit in the slice governed by a handle is set to `0`.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return Tristate boolean.
 * @retval `False` No bit in the slice is `0`.
 * @retval `True` At least one bit in the slice is `0`.
 * @retval `Error` `self` is `null`.
 */
extern enum Tristate bitvec_bs_b08_not_all(
	const struct BitPtrImmut *const self
);

/**
 * @brief Tests if any bit in the slice governed by a handle is set to `0`.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return Tristate boolean.
 * @retval `False` No bit in the slice is `0`.
 * @retval `True` At least one bit in the slice is `0`.
 * @retval `Error` `self` is `null`.
 */
extern enum Tristate bitvec_bs_l08_not_all(
	const struct BitPtrImmut *const self
);

/**
 * @brief Tests if any bit in the slice governed by a handle is set to `0`.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return Tristate boolean.
 * @retval `False` No bit in the slice is `0`.
 * @retval `True` At least one bit in the slice is `0`.
 * @retval `Error` `self` is `null`.
 */
extern enum Tristate bitvec_bs_b16_not_all(
	const struct BitPtrImmut *const self
);

/**
 * @brief Tests if any bit in the slice governed by a handle is set to `0`.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return Tristate boolean.
 * @retval `False` No bit in the slice is `0`.
 * @retval `True` At least one bit in the slice is `0`.
 * @retval `Error` `self` is `null`.
 */
extern enum Tristate bitvec_bs_l16_not_all(
	const struct BitPtrImmut *const self
);

/**
 * @brief Tests if any bit in the slice governed by a handle is set to `0`.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return Tristate boolean.
 * @retval `False` No bit in the slice is `0`.
 * @retval `True` At least one bit in the slice is `0`.
 * @retval `Error` `self` is `null`.
 */
extern enum Tristate bitvec_bs_b32_not_all(
	const struct BitPtrImmut *const self
);

/**
 * @brief Tests if any bit in the slice governed by a handle is set to `0`.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return Tristate boolean.
 * @retval `False` No bit in the slice is `0`.
 * @retval `True` At least one bit in the slice is `0`.
 * @retval `Error` `self` is `null`.
 */
extern enum Tristate bitvec_bs_l32_not_all(
	const struct BitPtrImmut *const self
);

/**
 * @brief Tests if any bit in the slice governed by a handle is set to `0`.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return Tristate boolean.
 * @retval `False` No bit in the slice is `0`.
 * @retval `True` At least one bit in the slice is `0`.
 * @retval `Error` `self` is `null`.
 */
extern enum Tristate bitvec_bs_b64_not_all(
	const struct BitPtrImmut *const self
);

/**
 * @brief Tests if any bit in the slice governed by a handle is set to `0`.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return Tristate boolean.
 * @retval `False` No bit in the slice is `0`.
 * @retval `True` At least one bit in the slice is `0`.
 * @retval `Error` `self` is `null`.
 */
extern enum Tristate bitvec_bs_l64_not_all(
	const struct BitPtrImmut *const self
);

/**
 * @brief Tests if all bits in the slice governed by a handle are set to `0`.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return Tristate boolean.
 * @retval `False` At least one bit in the slice is `1`.
 * @retval `True` All bits in the slice are `0`.
 * @retval `Error` `self` is `null`.
 */
extern enum Tristate bitvec_bs_b08_not_any(
	const struct BitPtrImmut *const self
);

/**
 * @brief Tests if all bits in the slice governed by a handle are set to `0`.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return Tristate boolean.
 * @retval `False` At least one bit in the slice is `1`.
 * @retval `True` All bits in the slice are `0`.
 * @retval `Error` `self` is `null`.
 */
extern enum Tristate bitvec_bs_l08_not_any(
	const struct BitPtrImmut *const self
);

/**
 * @brief Tests if all bits in the slice governed by a handle are set to `0`.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return Tristate boolean.
 * @retval `False` At least one bit in the slice is `1`.
 * @retval `True` All bits in the slice are `0`.
 * @retval `Error` `self` is `null`.
 */
extern enum Tristate bitvec_bs_b16_not_any(
	const struct BitPtrImmut *const self
);

/**
 * @brief Tests if all bits in the slice governed by a handle are set to `0`.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return Tristate boolean.
 * @retval `False` At least one bit in the slice is `1`.
 * @retval `True` All bits in the slice are `0`.
 * @retval `Error` `self` is `null`.
 */
extern enum Tristate bitvec_bs_l16_not_any(
	const struct BitPtrImmut *const self
);

/**
 * @brief Tests if all bits in the slice governed by a handle are set to `0`.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return Tristate boolean.
 * @retval `False` At least one bit in the slice is `1`.
 * @retval `True` All bits in the slice are `0`.
 * @retval `Error` `self` is `null`.
 */
extern enum Tristate bitvec_bs_b32_not_any(
	const struct BitPtrImmut *const self
);

/**
 * @brief Tests if all bits in the slice governed by a handle are set to `0`.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return Tristate boolean.
 * @retval `False` At least one bit in the slice is `1`.
 * @retval `True` All bits in the slice are `0`.
 * @retval `Error` `self` is `null`.
 */
extern enum Tristate bitvec_bs_l32_not_any(
	const struct BitPtrImmut *const self
);

/**
 * @brief Tests if all bits in the slice governed by a handle are set to `0`.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return Tristate boolean.
 * @retval `False` At least one bit in the slice is `1`.
 * @retval `True` All bits in the slice are `0`.
 * @retval `Error` `self` is `null`.
 */
extern enum Tristate bitvec_bs_b64_not_any(
	const struct BitPtrImmut *const self
);

/**
 * @brief Tests if all bits in the slice governed by a handle are set to `0`.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return Tristate boolean.
 * @retval `False` At least one bit in the slice is `1`.
 * @retval `True` All bits in the slice are `0`.
 * @retval `Error` `self` is `null`.
 */
extern enum Tristate bitvec_bs_l64_not_any(
	const struct BitPtrImmut *const self
);

/**
 * @brief Tests if the slice governed by a handle as some `0` bits and some `1`
 * bits.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return Tristate boolean.
 * @retval `False` The slice is homogenous; either all bits are `0` or all bits
 * are `1`.
 * @retval `True` The slice is heterogenous; some bits are `0` and some bits are
 * `1`.
 * @retval `Error` `self` is `null`.
 */
extern enum Tristate bitvec_bs_b08_some(
	const struct BitPtrImmut *const self
);

/**
 * @brief Tests if the slice governed by a handle as some `0` bits and some `1`
 * bits.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return Tristate boolean.
 * @retval `False` The slice is homogenous; either all bits are `0` or all bits
 * are `1`.
 * @retval `True` The slice is heterogenous; some bits are `0` and some bits are
 * `1`.
 * @retval `Error` `self` is `null`.
 */
extern enum Tristate bitvec_bs_l08_some(
	const struct BitPtrImmut *const self
);

/**
 * @brief Tests if the slice governed by a handle as some `0` bits and some `1`
 * bits.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return Tristate boolean.
 * @retval `False` The slice is homogenous; either all bits are `0` or all bits
 * are `1`.
 * @retval `True` The slice is heterogenous; some bits are `0` and some bits are
 * `1`.
 * @retval `Error` `self` is `null`.
 */
extern enum Tristate bitvec_bs_b16_some(
	const struct BitPtrImmut *const self
);

/**
 * @brief Tests if the slice governed by a handle as some `0` bits and some `1`
 * bits.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return Tristate boolean.
 * @retval `False` The slice is homogenous; either all bits are `0` or all bits
 * are `1`.
 * @retval `True` The slice is heterogenous; some bits are `0` and some bits are
 * `1`.
 * @retval `Error` `self` is `null`.
 */
extern enum Tristate bitvec_bs_l16_some(
	const struct BitPtrImmut *const self
);

/**
 * @brief Tests if the slice governed by a handle as some `0` bits and some `1`
 * bits.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return Tristate boolean.
 * @retval `False` The slice is homogenous; either all bits are `0` or all bits
 * are `1`.
 * @retval `True` The slice is heterogenous; some bits are `0` and some bits are
 * `1`.
 * @retval `Error` `self` is `null`.
 */
extern enum Tristate bitvec_bs_b32_some(
	const struct BitPtrImmut *const self
);

/**
 * @brief Tests if the slice governed by a handle as some `0` bits and some `1`
 * bits.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return Tristate boolean.
 * @retval `False` The slice is homogenous; either all bits are `0` or all bits
 * are `1`.
 * @retval `True` The slice is heterogenous; some bits are `0` and some bits are
 * `1`.
 * @retval `Error` `self` is `null`.
 */
extern enum Tristate bitvec_bs_l32_some(
	const struct BitPtrImmut *const self
);

/**
 * @brief Tests if the slice governed by a handle as some `0` bits and some `1`
 * bits.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return Tristate boolean.
 * @retval `False` The slice is homogenous; either all bits are `0` or all bits
 * are `1`.
 * @retval `True` The slice is heterogenous; some bits are `0` and some bits are
 * `1`.
 * @retval `Error` `self` is `null`.
 */
extern enum Tristate bitvec_bs_b64_some(
	const struct BitPtrImmut *const self
);

/**
 * @brief Tests if the slice governed by a handle as some `0` bits and some `1`
 * bits.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return Tristate boolean.
 * @retval `False` The slice is homogenous; either all bits are `0` or all bits
 * are `1`.
 * @retval `True` The slice is heterogenous; some bits are `0` and some bits are
 * `1`.
 * @retval `Error` `self` is `null`.
 */
extern enum Tristate bitvec_bs_l64_some(
	const struct BitPtrImmut *const self
);

/**
 * @brief Counts how many bits in the slice governed by a handle are `1`.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return The number of bits in the slice that are set to `1`.
 */
extern size_t bitvec_bs_b08_count_ones(const struct BitPtrImmut *const self);

/**
 * @brief Counts how many bits in the slice governed by a handle are `1`.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return The number of bits in the slice that are set to `1`.
 */
extern size_t bitvec_bs_l08_count_ones(const struct BitPtrImmut *const self);

/**
 * @brief Counts how many bits in the slice governed by a handle are `1`.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return The number of bits in the slice that are set to `1`.
 */
extern size_t bitvec_bs_b16_count_ones(const struct BitPtrImmut *const self);

/**
 * @brief Counts how many bits in the slice governed by a handle are `1`.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return The number of bits in the slice that are set to `1`.
 */
extern size_t bitvec_bs_l16_count_ones(const struct BitPtrImmut *const self);

/**
 * @brief Counts how many bits in the slice governed by a handle are `1`.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return The number of bits in the slice that are set to `1`.
 */
extern size_t bitvec_bs_b32_count_ones(const struct BitPtrImmut *const self);

/**
 * @brief Counts how many bits in the slice governed by a handle are `1`.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return The number of bits in the slice that are set to `1`.
 */
extern size_t bitvec_bs_l32_count_ones(const struct BitPtrImmut *const self);

/**
 * @brief Counts how many bits in the slice governed by a handle are `1`.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return The number of bits in the slice that are set to `1`.
 */
extern size_t bitvec_bs_b64_count_ones(const struct BitPtrImmut *const self);

/**
 * @brief Counts how many bits in the slice governed by a handle are `1`.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return The number of bits in the slice that are set to `1`.
 */
extern size_t bitvec_bs_l64_count_ones(const struct BitPtrImmut *const self);

/**
 * @brief Counts how many bits in the slice governed by a handle are `0`.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return The number of bits in the slice that are set to `0`.
 */
extern size_t bitvec_bs_b08_count_zeros(
	const struct BitPtrImmut *const self
);

/**
 * @brief Counts how many bits in the slice governed by a handle are `0`.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return The number of bits in the slice that are set to `0`.
 */
extern size_t bitvec_bs_l08_count_zeros(
	const struct BitPtrImmut *const self
);

/**
 * @brief Counts how many bits in the slice governed by a handle are `0`.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return The number of bits in the slice that are set to `0`.
 */
extern size_t bitvec_bs_b16_count_zeros(
	const struct BitPtrImmut *const self
);

/**
 * @brief Counts how many bits in the slice governed by a handle are `0`.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return The number of bits in the slice that are set to `0`.
 */
extern size_t bitvec_bs_l16_count_zeros(
	const struct BitPtrImmut *const self
);

/**
 * @brief Counts how many bits in the slice governed by a handle are `0`.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return The number of bits in the slice that are set to `0`.
 */
extern size_t bitvec_bs_b32_count_zeros(
	const struct BitPtrImmut *const self
);

/**
 * @brief Counts how many bits in the slice governed by a handle are `0`.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return The number of bits in the slice that are set to `0`.
 */
extern size_t bitvec_bs_l32_count_zeros(
	const struct BitPtrImmut *const self
);

/**
 * @brief Counts how many bits in the slice governed by a handle are `0`.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return The number of bits in the slice that are set to `0`.
 */
extern size_t bitvec_bs_b64_count_zeros(
	const struct BitPtrImmut *const self
);

/**
 * @brief Counts how many bits in the slice governed by a handle are `0`.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @return The number of bits in the slice that are set to `0`.
 */
extern size_t bitvec_bs_l64_count_zeros(
	const struct BitPtrImmut *const self
);

/**
 * @brief Sets all bits in the slice governed by a handle to a given value.
 * @param[in] self Pointer to a `const` handle over mutable bits.
 * @param value The new bit value to which all bits in the slice will be set.
 */
extern void bitvec_bs_b08_set_all(
	const struct BitPtrMut *const self,
	const bool value
);

/**
 * @brief Sets all bits in the slice governed by a handle to a given value.
 * @param[in] self Pointer to a `const` handle over mutable bits.
 * @param value The new bit value to which all bits in the slice will be set.
 */
extern void bitvec_bs_l08_set_all(
	const struct BitPtrMut *const self,
	const bool value
);

/**
 * @brief Sets all bits in the slice governed by a handle to a given value.
 * @param[in] self Pointer to a `const` handle over mutable bits.
 * @param value The new bit value to which all bits in the slice will be set.
 */
extern void bitvec_bs_b16_set_all(
	const struct BitPtrMut *const self,
	const bool value
);

/**
 * @brief Sets all bits in the slice governed by a handle to a given value.
 * @param[in] self Pointer to a `const` handle over mutable bits.
 * @param value The new bit value to which all bits in the slice will be set.
 */
extern void bitvec_bs_l16_set_all(
	const struct BitPtrMut *const self,
	const bool value
);

/**
 * @brief Sets all bits in the slice governed by a handle to a given value.
 * @param[in] self Pointer to a `const` handle over mutable bits.
 * @param value The new bit value to which all bits in the slice will be set.
 */
extern void bitvec_bs_b32_set_all(
	const struct BitPtrMut *const self,
	const bool value
);

/**
 * @brief Sets all bits in the slice governed by a handle to a given value.
 * @param[in] self Pointer to a `const` handle over mutable bits.
 * @param value The new bit value to which all bits in the slice will be set.
 */
extern void bitvec_bs_l32_set_all(
	const struct BitPtrMut *const self,
	const bool value
);

/**
 * @brief Sets all bits in the slice governed by a handle to a given value.
 * @param[in] self Pointer to a `const` handle over mutable bits.
 * @param value The new bit value to which all bits in the slice will be set.
 */
extern void bitvec_bs_b64_set_all(
	const struct BitPtrMut *const self,
	const bool value
);

/**
 * @brief Sets all bits in the slice governed by a handle to a given value.
 * @param[in] self Pointer to a `const` handle over mutable bits.
 * @param value The new bit value to which all bits in the slice will be set.
 */
extern void bitvec_bs_l64_set_all(
	const struct BitPtrMut *const self,
	const bool value
);

/**
 * @brief Runs a function for each bit index in the slice governed by a handle.
 * @param[in] self Pointer to a `const` handle over mutable bits.
 * @param func A function which receives the index and value of each bit in the
 * slice, and produces a new value to which the current bit will be set. This
 * function is run on every bit in the slice, sequentially, from `0` to `len`.
 */
extern void bitvec_bs_b08_for_each(
	const struct BitPtrMut *const self,
	bool (*const func)(const size_t index, const bool value)
);

/**
 * @brief Runs a function for each bit index in the slice governed by a handle.
 * @param[in] self Pointer to a `const` handle over mutable bits.
 * @param func A function which receives the index and value of each bit in the
 * slice, and produces a new value to which the current bit will be set. This
 * function is run on every bit in the slice, sequentially, from `0` to `len`.
 */
extern void bitvec_bs_l08_for_each(
	const struct BitPtrMut *const self,
	bool (*const func)(const size_t index, const bool value)
);

/**
 * @brief Runs a function for each bit index in the slice governed by a handle.
 * @param[in] self Pointer to a `const` handle over mutable bits.
 * @param func A function which receives the index and value of each bit in the
 * slice, and produces a new value to which the current bit will be set. This
 * function is run on every bit in the slice, sequentially, from `0` to `len`.
 */
extern void bitvec_bs_b16_for_each(
	const struct BitPtrMut *const self,
	bool (*const func)(const size_t index, const bool value)
);

/**
 * @brief Runs a function for each bit index in the slice governed by a handle.
 * @param[in] self Pointer to a `const` handle over mutable bits.
 * @param func A function which receives the index and value of each bit in the
 * slice, and produces a new value to which the current bit will be set. This
 * function is run on every bit in the slice, sequentially, from `0` to `len`.
 */
extern void bitvec_bs_l16_for_each(
	const struct BitPtrMut *const self,
	bool (*const func)(const size_t index, const bool value)
);

/**
 * @brief Runs a function for each bit index in the slice governed by a handle.
 * @param[in] self Pointer to a `const` handle over mutable bits.
 * @param func A function which receives the index and value of each bit in the
 * slice, and produces a new value to which the current bit will be set. This
 * function is run on every bit in the slice, sequentially, from `0` to `len`.
 */
extern void bitvec_bs_b32_for_each(
	const struct BitPtrMut *const self,
	bool (*const func)(const size_t index, const bool value)
);

/**
 * @brief Runs a function for each bit index in the slice governed by a handle.
 * @param[in] self Pointer to a `const` handle over mutable bits.
 * @param func A function which receives the index and value of each bit in the
 * slice, and produces a new value to which the current bit will be set. This
 * function is run on every bit in the slice, sequentially, from `0` to `len`.
 */
extern void bitvec_bs_l32_for_each(
	const struct BitPtrMut *const self,
	bool (*const func)(const size_t index, const bool value)
);

/**
 * @brief Runs a function for each bit index in the slice governed by a handle.
 * @param[in] self Pointer to a `const` handle over mutable bits.
 * @param func A function which receives the index and value of each bit in the
 * slice, and produces a new value to which the current bit will be set. This
 * function is run on every bit in the slice, sequentially, from `0` to `len`.
 */
extern void bitvec_bs_b64_for_each(
	const struct BitPtrMut *const self,
	bool (*const func)(const size_t index, const bool value)
);

/**
 * @brief Runs a function for each bit index in the slice governed by a handle.
 * @param[in] self Pointer to a `const` handle over mutable bits.
 * @param func A function which receives the index and value of each bit in the
 * slice, and produces a new value to which the current bit will be set. This
 * function is run on every bit in the slice, sequentially, from `0` to `len`.
 */
extern void bitvec_bs_l64_for_each(
	const struct BitPtrMut *const self,
	bool (*const func)(const size_t index, const bool value)
);

/**
 * @brief Gets a pointer/length pair to the storage elements underlying a slice.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @param[out] len Pointer through which the length (in storage elements) of the
 * slice will be written.
 * @return A pointer to the first storage element in the slice.
 */
extern const uint8_t  *const bitvec_bs_b08_as_slice(
	const struct BitPtrImmut *const self,
	size_t *const len
);

/**
 * @brief Gets a pointer/length pair to the storage elements underlying a slice.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @param[out] len Pointer through which the length (in storage elements) of the
 * slice will be written.
 * @return A pointer to the first storage element in the slice.
 */
extern const uint8_t  *const bitvec_bs_l08_as_slice(
	const struct BitPtrImmut *const self,
	size_t *const len
);

/**
 * @brief Gets a pointer/length pair to the storage elements underlying a slice.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @param[out] len Pointer through which the length (in storage elements) of the
 * slice will be written.
 * @return A pointer to the first storage element in the slice.
 */
extern const uint16_t *const bitvec_bs_b16_as_slice(
	const struct BitPtrImmut *const self,
	size_t *const len
);

/**
 * @brief Gets a pointer/length pair to the storage elements underlying a slice.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @param[out] len Pointer through which the length (in storage elements) of the
 * slice will be written.
 * @return A pointer to the first storage element in the slice.
 */
extern const uint16_t *const bitvec_bs_l16_as_slice(
	const struct BitPtrImmut *const self,
	size_t *const len
);

/**
 * @brief Gets a pointer/length pair to the storage elements underlying a slice.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @param[out] len Pointer through which the length (in storage elements) of the
 * slice will be written.
 * @return A pointer to the first storage element in the slice.
 */
extern const uint32_t *const bitvec_bs_b32_as_slice(
	const struct BitPtrImmut *const self,
	size_t *const len
);

/**
 * @brief Gets a pointer/length pair to the storage elements underlying a slice.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @param[out] len Pointer through which the length (in storage elements) of the
 * slice will be written.
 * @return A pointer to the first storage element in the slice.
 */
extern const uint32_t *const bitvec_bs_l32_as_slice(
	const struct BitPtrImmut *const self,
	size_t *const len
);

/**
 * @brief Gets a pointer/length pair to the storage elements underlying a slice.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @param[out] len Pointer through which the length (in storage elements) of the
 * slice will be written.
 * @return A pointer to the first storage element in the slice.
 */
extern const uint64_t *const bitvec_bs_b64_as_slice(
	const struct BitPtrImmut *const self,
	size_t *const len
);

/**
 * @brief Gets a pointer/length pair to the storage elements underlying a slice.
 * @param[in] self Pointer to a `const` handle over const bits.
 * @param[out] len Pointer through which the length (in storage elements) of the
 * slice will be written.
 * @return A pointer to the first storage element in the slice.
 */
extern const uint64_t *const bitvec_bs_l64_as_slice(
	const struct BitPtrImmut *const self,
	size_t *const len
);

/**
 * @brief Gets a write pointer/length pair to the storage elements underlying a
 * bit slice.
 * @param[in] self Pointer to a `const` handle over mutable bits.
 * @param[out] len Pointer through which the length (in storage elements) of the
 * slice will be written.
 * @return A write pointer to the first storage element in the slice.
 */
extern       uint8_t  *const bitvec_bs_b08_as_mut_slice(
	const struct BitPtrMut *const self,
	size_t *const len
);

/**
 * @brief Gets a write pointer/length pair to the storage elements underlying a
 * bit slice.
 * @param[in] self Pointer to a `const` handle over mutable bits.
 * @param[out] len Pointer through which the length (in storage elements) of the
 * slice will be written.
 * @return A write pointer to the first storage element in the slice.
 */
extern       uint8_t  *const bitvec_bs_l08_as_mut_slice(
	const struct BitPtrMut *const self,
	size_t *const len
);

/**
 * @brief Gets a write pointer/length pair to the storage elements underlying a
 * bit slice.
 * @param[in] self Pointer to a `const` handle over mutable bits.
 * @param[out] len Pointer through which the length (in storage elements) of the
 * slice will be written.
 * @return A write pointer to the first storage element in the slice.
 */
extern       uint16_t *const bitvec_bs_b16_as_mut_slice(
	const struct BitPtrMut *const self,
	size_t *const len
);

/**
 * @brief Gets a write pointer/length pair to the storage elements underlying a
 * bit slice.
 * @param[in] self Pointer to a `const` handle over mutable bits.
 * @param[out] len Pointer through which the length (in storage elements) of the
 * slice will be written.
 * @return A write pointer to the first storage element in the slice.
 */
extern       uint16_t *const bitvec_bs_l16_as_mut_slice(
	const struct BitPtrMut *const self,
	size_t *const len
);

/**
 * @brief Gets a write pointer/length pair to the storage elements underlying a
 * bit slice.
 * @param[in] self Pointer to a `const` handle over mutable bits.
 * @param[out] len Pointer through which the length (in storage elements) of the
 * slice will be written.
 * @return A write pointer to the first storage element in the slice.
 */
extern       uint32_t *const bitvec_bs_b32_as_mut_slice(
	const struct BitPtrMut *const self,
	size_t *const len
);

/**
 * @brief Gets a write pointer/length pair to the storage elements underlying a
 * bit slice.
 * @param[in] self Pointer to a `const` handle over mutable bits.
 * @param[out] len Pointer through which the length (in storage elements) of the
 * slice will be written.
 * @return A write pointer to the first storage element in the slice.
 */
extern       uint32_t *const bitvec_bs_l32_as_mut_slice(
	const struct BitPtrMut *const self,
	size_t *const len
);

/**
 * @brief Gets a write pointer/length pair to the storage elements underlying a
 * bit slice.
 * @param[in] self Pointer to a `const` handle over mutable bits.
 * @param[out] len Pointer through which the length (in storage elements) of the
 * slice will be written.
 * @return A write pointer to the first storage element in the slice.
 */
extern       uint64_t *const bitvec_bs_b64_as_mut_slice(
	const struct BitPtrMut *const self,
	size_t *const len
);

/**
 * @brief Gets a write pointer/length pair to the storage elements underlying a
 * bit slice.
 * @param[in] self Pointer to a `const` handle over mutable bits.
 * @param[out] len Pointer through which the length (in storage elements) of the
 * slice will be written.
 * @return A write pointer to the first storage element in the slice.
 */
extern       uint64_t *const bitvec_bs_l64_as_mut_slice(
	const struct BitPtrMut *const self,
	size_t *const len
);

#ifdef __cplusplus
} // extern "C"
}; // namespace bitvec
#endif

#endif//BITVEC_FFI_BITSLICE_H
