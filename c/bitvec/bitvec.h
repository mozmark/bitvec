#ifndef BITVEC_FFI_BITVEC_H
#define BITVEC_FFI_BITVEC_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "bitslice.h"

#ifdef __cplusplus
namespace bitvec {
extern "C" {
#endif

struct BitVec {
	union BitPtr bp;
	size_t capacity;
};

/**
 * @struct BitVecB08
 *
 * @brief Stack handle for an owned, managed, bit vector.
 *
 * The bits are in big-endian order, chunked in one-byte intervals.
 */
struct BitVecB08 {
	/// Inner untyped vec handle.
	struct BitVec bv;
};

/**
 * @struct BitVecL08
 *
 * @brief Stack handle for an owned, managed, bit vector.
 *
 * The bits are in little-endian order, chunked in one-byte intervals.
 */
struct BitVecL08 {
	/// Inner untyped vec handle.
	struct BitVec bv;
};

/**
 * @struct BitVecB16
 *
 * @brief Stack handle for an owned, managed, bit vector.
 *
 * The bits are in big-endian order, chunked in two-byte intervals.
 */
struct BitVecB16 {
	/// Inner untyped vec handle.
	struct BitVec bv;
};

/**
 * @struct BitVecL16
 *
 * @brief Stack handle for an owned, managed, bit vector.
 *
 * The bits are in little-endian order, chunked in two-byte intervals.
 */
struct BitVecL16 {
	/// Inner untyped vec handle.
	struct BitVec bv;
};

/**
 * @struct BitVecB32
 *
 * @brief Stack handle for an owned, managed, bit vector.
 *
 * The bits are in big-endian order, chunked in four-byte intervals.
 */
struct BitVecB32 {
	/// Inner untyped vec handle.
	struct BitVec bv;
};

/**
 * @struct BitVecL32
 *
 * @brief Stack handle for an owned, managed, bit vector.
 *
 * The bits are in little-endian order, chunked in four-byte intervals.
 */
struct BitVecL32 {
	/// Inner untyped vec handle.
	struct BitVec bv;
};

/**
 * @struct BitVecB64
 *
 * @brief Stack handle for an owned, managed, bit vector.
 *
 * The bits are in big-endian order, chunked in eight-byte intervals.
 */
struct BitVecB64 {
	/// Inner untyped vec handle.
	struct BitVec bv;
};

/**
 * @struct BitVecL64
 *
 * @brief Stack handle for an owned, managed, bit vector.
 *
 * The bits are in little-endian order, chunked in eight-byte intervals.
 */
struct BitVecL64 {
	/// Inner untyped vec handle.
	struct BitVec bv;
};

/**
 * @brief Permits passing a well-typed BitVec handle to a type-erased function.
 *
 * @param rsbvbv The name of an instance of any of the `BitVec$C$T` handle
 * variant types.
 *
 * @return The address of the interior type-erased `struct BitVec` for the
 * handle.
 */
#define RSBV_BV(rsbvbv) &(rsbvbv.bv)

/**
 * @brief Permits passing a well-typed BitVec handle to a type-erased *slice*
 * function, that can only inspect the data.
 *
 * @param rsbvbv The name of an instance of any of the `BitVec$C$T` handle
 * variant types.
 *
 * @return The address of the interior type-erased `struct BitPtrImmut` for the
 * handle.
 */
#define RSBV_BV_IMMUT(rsbvbv) &(rsbvbv.bv.bp.immut)

/**
 * @brief Permits passing a well-typed BitVec handle to a type-erased *slice*
 * function, that is able to mutate the data.
 *
 * @param rsbvbv The name of an instance of any of the `BitVec$C$T` handle
 * variant types.
 *
 * @return The address of the interior type-erased `struct BitPtrMut` for the
 * handle.
 */
#define RSBV_BV_MUT(rsbvbv) &(rsbvbv.bv.bp.mut)

/**
 * @brief Initializes a new `BitVec` handle.
 * @param[out] self Pointer to an *uninitialized* stack slot for a `BitVec`.
 */
extern void bitvec_bv_b08_new(struct BitVec *const self);

/**
 * @brief Initializes a new `BitVec` handle.
 * @param[out] self Pointer to an *uninitialized* stack slot for a `BitVec`.
 */
extern void bitvec_bv_l08_new(struct BitVec *const self);

/**
 * @brief Initializes a new `BitVec` handle.
 * @param[out] self Pointer to an *uninitialized* stack slot for a `BitVec`.
 */
extern void bitvec_bv_b16_new(struct BitVec *const self);

/**
 * @brief Initializes a new `BitVec` handle.
 * @param[out] self Pointer to an *uninitialized* stack slot for a `BitVec`.
 */
extern void bitvec_bv_l16_new(struct BitVec *const self);

/**
 * @brief Initializes a new `BitVec` handle.
 * @param[out] self Pointer to an *uninitialized* stack slot for a `BitVec`.
 */
extern void bitvec_bv_b32_new(struct BitVec *const self);

/**
 * @brief Initializes a new `BitVec` handle.
 * @param[out] self Pointer to an *uninitialized* stack slot for a `BitVec`.
 */
extern void bitvec_bv_l32_new(struct BitVec *const self);

/**
 * @brief Initializes a new `BitVec` handle.
 * @param[out] self Pointer to an *uninitialized* stack slot for a `BitVec`.
 */
extern void bitvec_bv_b64_new(struct BitVec *const self);

/**
 * @brief Initializes a new `BitVec` handle.
 * @param[out] self Pointer to an *uninitialized* stack slot for a `BitVec`.
 */
extern void bitvec_bv_l64_new(struct BitVec *const self);

/**
 * @brief Initializes a new `BitVec` handle with the specified allocation size.
 * @param[out] self Pointer to an *uninitialized* stack slot for a `BitVec`.
 * @param capacity The capacity, in storage elements, for the new `BitVec` to
 * allocate.
 */
extern void bitvec_bv_b08_with_capacity(
	struct BitVec *const self,
	const size_t capacity
);

/**
 * @brief Initializes a new `BitVec` handle with the specified allocation size.
 * @param[out] self Pointer to an *uninitialized* stack slot for a `BitVec`.
 * @param capacity The capacity, in storage elements, for the new `BitVec` to
 * allocate.
 */
extern void bitvec_bv_l08_with_capacity(
	struct BitVec *const self,
	const size_t capacity
);

/**
 * @brief Initializes a new `BitVec` handle with the specified allocation size.
 * @param[out] self Pointer to an *uninitialized* stack slot for a `BitVec`.
 * @param capacity The capacity, in storage elements, for the new `BitVec` to
 * allocate.
 */
extern void bitvec_bv_b16_with_capacity(
	struct BitVec *const self,
	const size_t capacity
);

/**
 * @brief Initializes a new `BitVec` handle with the specified allocation size.
 * @param[out] self Pointer to an *uninitialized* stack slot for a `BitVec`.
 * @param capacity The capacity, in storage elements, for the new `BitVec` to
 * allocate.
 */
extern void bitvec_bv_l16_with_capacity(
	struct BitVec *const self,
	const size_t capacity
);

/**
 * @brief Initializes a new `BitVec` handle with the specified allocation size.
 * @param[out] self Pointer to an *uninitialized* stack slot for a `BitVec`.
 * @param capacity The capacity, in storage elements, for the new `BitVec` to
 * allocate.
 */
extern void bitvec_bv_b32_with_capacity(
	struct BitVec *const self,
	const size_t capacity
);

/**
 * @brief Initializes a new `BitVec` handle with the specified allocation size.
 * @param[out] self Pointer to an *uninitialized* stack slot for a `BitVec`.
 * @param capacity The capacity, in storage elements, for the new `BitVec` to
 * allocate.
 */
extern void bitvec_bv_l32_with_capacity(
	struct BitVec *const self,
	const size_t capacity
);

/**
 * @brief Initializes a new `BitVec` handle with the specified allocation size.
 * @param[out] self Pointer to an *uninitialized* stack slot for a `BitVec`.
 * @param capacity The capacity, in storage elements, for the new `BitVec` to
 * allocate.
 */
extern void bitvec_bv_b64_with_capacity(
	struct BitVec *const self,
	const size_t capacity
);

/**
 * @brief Initializes a new `BitVec` handle with the specified allocation size.
 * @param[out] self Pointer to an *uninitialized* stack slot for a `BitVec`.
 * @param capacity The capacity, in storage elements, for the new `BitVec` to
 * allocate.
 */
extern void bitvec_bv_l64_with_capacity(
	struct BitVec *const self,
	const size_t capacity
);

/**
 * @brief Gets the allocation capacity of a `BitVec` handle.
 * @param[in] self Pointer to a `const` handle.
 * @return The number of storage elements allocated in the handle domain.
 */
extern size_t bitvec_bv_b08_capacity(const struct BitVec *const self);

/**
 * @brief Gets the allocation capacity of a `BitVec` handle.
 * @param[in] self Pointer to a `const` handle.
 * @return The number of storage elements allocated in the handle domain.
 */
extern size_t bitvec_bv_l08_capacity(const struct BitVec *const self);

/**
 * @brief Gets the allocation capacity of a `BitVec` handle.
 * @param[in] self Pointer to a `const` handle.
 * @return The number of storage elements allocated in the handle domain.
 */
extern size_t bitvec_bv_b16_capacity(const struct BitVec *const self);

/**
 * @brief Gets the allocation capacity of a `BitVec` handle.
 * @param[in] self Pointer to a `const` handle.
 * @return The number of storage elements allocated in the handle domain.
 */
extern size_t bitvec_bv_l16_capacity(const struct BitVec *const self);

/**
 * @brief Gets the allocation capacity of a `BitVec` handle.
 * @param[in] self Pointer to a `const` handle.
 * @return The number of storage elements allocated in the handle domain.
 */
extern size_t bitvec_bv_b32_capacity(const struct BitVec *const self);

/**
 * @brief Gets the allocation capacity of a `BitVec` handle.
 * @param[in] self Pointer to a `const` handle.
 * @return The number of storage elements allocated in the handle domain.
 */
extern size_t bitvec_bv_l32_capacity(const struct BitVec *const self);

/**
 * @brief Gets the allocation capacity of a `BitVec` handle.
 * @param[in] self Pointer to a `const` handle.
 * @return The number of storage elements allocated in the handle domain.
 */
extern size_t bitvec_bv_b64_capacity(const struct BitVec *const self);

/**
 * @brief Gets the allocation capacity of a `BitVec` handle.
 * @param[in] self Pointer to a `const` handle.
 * @return The number of storage elements allocated in the handle domain.
 */
extern size_t bitvec_bv_l64_capacity(const struct BitVec *const self);

/**
 * @brief Allocates space for more storage elements in a `BitVec` handle.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param additional The number of extra storage elements to allocate.
 */
extern void bitvec_bv_b08_reserve(
	struct BitVec *const self,
	const size_t additional
);

/**
 * @brief Allocates space for more storage elements in a `BitVec` handle.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param additional The number of extra storage elements to allocate.
 */
extern void bitvec_bv_l08_reserve(
	struct BitVec *const self,
	const size_t additional
);

/**
 * @brief Allocates space for more storage elements in a `BitVec` handle.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param additional The number of extra storage elements to allocate.
 */
extern void bitvec_bv_b16_reserve(
	struct BitVec *const self,
	const size_t additional
);

/**
 * @brief Allocates space for more storage elements in a `BitVec` handle.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param additional The number of extra storage elements to allocate.
 */
extern void bitvec_bv_l16_reserve(
	struct BitVec *const self,
	const size_t additional
);

/**
 * @brief Allocates space for more storage elements in a `BitVec` handle.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param additional The number of extra storage elements to allocate.
 */
extern void bitvec_bv_b32_reserve(
	struct BitVec *const self,
	const size_t additional
);

/**
 * @brief Allocates space for more storage elements in a `BitVec` handle.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param additional The number of extra storage elements to allocate.
 */
extern void bitvec_bv_l32_reserve(
	struct BitVec *const self,
	const size_t additional
);

/**
 * @brief Allocates space for more storage elements in a `BitVec` handle.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param additional The number of extra storage elements to allocate.
 */
extern void bitvec_bv_b64_reserve(
	struct BitVec *const self,
	const size_t additional
);

/**
 * @brief Allocates space for more storage elements in a `BitVec` handle.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param additional The number of extra storage elements to allocate.
 */
extern void bitvec_bv_l64_reserve(
	struct BitVec *const self,
	const size_t additional
);

/**
 * @brief Shrinks the allocated capacity of a `BitVec` to fit its live storage.
 * @param[in] self Pointer to a `BitVec` handle.
 */
extern void bitvec_bv_b08_shrink_to_fit(struct BitVec *const self);

/**
 * @brief Shrinks the allocated capacity of a `BitVec` to fit its live storage.
 * @param[in] self Pointer to a `BitVec` handle.
 */
extern void bitvec_bv_l08_shrink_to_fit(struct BitVec *const self);

/**
 * @brief Shrinks the allocated capacity of a `BitVec` to fit its live storage.
 * @param[in] self Pointer to a `BitVec` handle.
 */
extern void bitvec_bv_b16_shrink_to_fit(struct BitVec *const self);

/**
 * @brief Shrinks the allocated capacity of a `BitVec` to fit its live storage.
 * @param[in] self Pointer to a `BitVec` handle.
 */
extern void bitvec_bv_l16_shrink_to_fit(struct BitVec *const self);

/**
 * @brief Shrinks the allocated capacity of a `BitVec` to fit its live storage.
 * @param[in] self Pointer to a `BitVec` handle.
 */
extern void bitvec_bv_b32_shrink_to_fit(struct BitVec *const self);

/**
 * @brief Shrinks the allocated capacity of a `BitVec` to fit its live storage.
 * @param[in] self Pointer to a `BitVec` handle.
 */
extern void bitvec_bv_l32_shrink_to_fit(struct BitVec *const self);

/**
 * @brief Shrinks the allocated capacity of a `BitVec` to fit its live storage.
 * @param[in] self Pointer to a `BitVec` handle.
 */
extern void bitvec_bv_b64_shrink_to_fit(struct BitVec *const self);

/**
 * @brief Shrinks the allocated capacity of a `BitVec` to fit its live storage.
 * @param[in] self Pointer to a `BitVec` handle.
 */
extern void bitvec_bv_l64_shrink_to_fit(struct BitVec *const self);

/**
 * @brief Truncates the `BitVec` at the given bit length.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param len The length, in bits, of the `BitVec` domain after truncation.
 */
extern void bitvec_bv_b08_truncate(
	struct BitVec *const self,
	const size_t len
);

/**
 * @brief Truncates the `BitVec` at the given bit length.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param len The length, in bits, of the `BitVec` domain after truncation.
 */
extern void bitvec_bv_l08_truncate(
	struct BitVec *const self,
	const size_t len
);

/**
 * @brief Truncates the `BitVec` at the given bit length.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param len The length, in bits, of the `BitVec` domain after truncation.
 */
extern void bitvec_bv_b16_truncate(
	struct BitVec *const self,
	const size_t len
);

/**
 * @brief Truncates the `BitVec` at the given bit length.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param len The length, in bits, of the `BitVec` domain after truncation.
 */
extern void bitvec_bv_l16_truncate(
	struct BitVec *const self,
	const size_t len
);

/**
 * @brief Truncates the `BitVec` at the given bit length.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param len The length, in bits, of the `BitVec` domain after truncation.
 */
extern void bitvec_bv_b32_truncate(
	struct BitVec *const self,
	const size_t len
);

/**
 * @brief Truncates the `BitVec` at the given bit length.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param len The length, in bits, of the `BitVec` domain after truncation.
 */
extern void bitvec_bv_l32_truncate(
	struct BitVec *const self,
	const size_t len
);

/**
 * @brief Truncates the `BitVec` at the given bit length.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param len The length, in bits, of the `BitVec` domain after truncation.
 */
extern void bitvec_bv_b64_truncate(
	struct BitVec *const self,
	const size_t len
);

/**
 * @brief Truncates the `BitVec` at the given bit length.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param len The length, in bits, of the `BitVec` domain after truncation.
 */
extern void bitvec_bv_l64_truncate(
	struct BitVec *const self,
	const size_t len
);

/**
 * @brief Gets a `BitSlice` handle to const bits from a `BitVec`.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param[out] slice Pointer to an *uninitialized* `HBitSlice` handle.
 */
extern void bitvec_bv_b08_as_bitslice(
	const struct BitVec *const self,
	struct BitPtrImmut *const slice
);

/**
 * @brief Gets a `BitSlice` handle to const bits from a `BitVec`.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param[out] slice Pointer to an *uninitialized* `HBitSlice` handle.
 */
extern void bitvec_bv_l08_as_bitslice(
	const struct BitVec *const self,
	struct BitPtrImmut *const slice
);

/**
 * @brief Gets a `BitSlice` handle to const bits from a `BitVec`.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param[out] slice Pointer to an *uninitialized* `HBitSlice` handle.
 */
extern void bitvec_bv_b16_as_bitslice(
	const struct BitVec *const self,
	struct BitPtrImmut *const slice
);

/**
 * @brief Gets a `BitSlice` handle to const bits from a `BitVec`.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param[out] slice Pointer to an *uninitialized* `HBitSlice` handle.
 */
extern void bitvec_bv_l16_as_bitslice(
	const struct BitVec *const self,
	struct BitPtrImmut *const slice
);

/**
 * @brief Gets a `BitSlice` handle to const bits from a `BitVec`.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param[out] slice Pointer to an *uninitialized* `HBitSlice` handle.
 */
extern void bitvec_bv_b32_as_bitslice(
	const struct BitVec *const self,
	struct BitPtrImmut *const slice
);

/**
 * @brief Gets a `BitSlice` handle to const bits from a `BitVec`.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param[out] slice Pointer to an *uninitialized* `HBitSlice` handle.
 */
extern void bitvec_bv_l32_as_bitslice(
	const struct BitVec *const self,
	struct BitPtrImmut *const slice
);

/**
 * @brief Gets a `BitSlice` handle to const bits from a `BitVec`.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param[out] slice Pointer to an *uninitialized* `HBitSlice` handle.
 */
extern void bitvec_bv_b64_as_bitslice(
	const struct BitVec *const self,
	struct BitPtrImmut *const slice
);

/**
 * @brief Gets a `BitSlice` handle to const bits from a `BitVec`.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param[out] slice Pointer to an *uninitialized* `HBitSlice` handle.
 */
extern void bitvec_bv_l64_as_bitslice(
	const struct BitVec *const self,
	struct BitPtrImmut *const slice
);

/**
 * @brief Gets a `BitSlice` handle to mutable bits from a `BitVec`.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param[out] slice Pointer to an *uninitialized* `HBitSlice` handle.
 */
extern void bitvec_bv_b08_as_mut_bitslice(
	struct BitVec *const self,
	struct BitPtrMut *const slice
);

/**
 * @brief Gets a `BitSlice` handle to mutable bits from a `BitVec`.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param[out] slice Pointer to an *uninitialized* `HBitSlice` handle.
 */
extern void bitvec_bv_l08_as_mut_bitslice(
	struct BitVec *const self,
	struct BitPtrMut *const slice
);

/**
 * @brief Gets a `BitSlice` handle to mutable bits from a `BitVec`.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param[out] slice Pointer to an *uninitialized* `HBitSlice` handle.
 */
extern void bitvec_bv_b16_as_mut_bitslice(
	struct BitVec *const self,
	struct BitPtrMut *const slice
);

/**
 * @brief Gets a `BitSlice` handle to mutable bits from a `BitVec`.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param[out] slice Pointer to an *uninitialized* `HBitSlice` handle.
 */
extern void bitvec_bv_l16_as_mut_bitslice(
	struct BitVec *const self,
	struct BitPtrMut *const slice
);

/**
 * @brief Gets a `BitSlice` handle to mutable bits from a `BitVec`.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param[out] slice Pointer to an *uninitialized* `HBitSlice` handle.
 */
extern void bitvec_bv_b32_as_mut_bitslice(
	struct BitVec *const self,
	struct BitPtrMut *const slice
);

/**
 * @brief Gets a `BitSlice` handle to mutable bits from a `BitVec`.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param[out] slice Pointer to an *uninitialized* `HBitSlice` handle.
 */
extern void bitvec_bv_l32_as_mut_bitslice(
	struct BitVec *const self,
	struct BitPtrMut *const slice
);

/**
 * @brief Gets a `BitSlice` handle to mutable bits from a `BitVec`.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param[out] slice Pointer to an *uninitialized* `HBitSlice` handle.
 */
extern void bitvec_bv_b64_as_mut_bitslice(
	struct BitVec *const self,
	struct BitPtrMut *const slice
);

/**
 * @brief Gets a `BitSlice` handle to mutable bits from a `BitVec`.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param[out] slice Pointer to an *uninitialized* `HBitSlice` handle.
 */
extern void bitvec_bv_l64_as_mut_bitslice(
	struct BitVec *const self,
	struct BitPtrMut *const slice
);

/**
 * @brief Removes a bit from a bit vector, and returns it.
 *
 * The removed bit is replaced by the last bit in the vector, rather than
 * shunting all following bits down.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param index The index of the bit to remove and replace by the end.
 * @return The bit at the specified index.
 * @retval `False` The requested bit was `0`.
 * @retval `True` The requested bit was `1`.
 * @retval `Error` `self` is `null`, or `index` is out of range.
 */
extern enum Tristate bitvec_bv_b08_swap_remove(
	struct BitVec *const self,
	const size_t index
);

/**
 * @brief Removes a bit from a bit vector, and returns it.
 *
 * The removed bit is replaced by the last bit in the vector, rather than
 * shunting all following bits down.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param index The index of the bit to remove and replace by the end.
 * @return The bit at the specified index.
 * @retval `False` The requested bit was `0`.
 * @retval `True` The requested bit was `1`.
 * @retval `Error` `self` is `null`, or `index` is out of range.
 */
extern enum Tristate bitvec_bv_l08_swap_remove(
	struct BitVec *const self,
	const size_t index
);

/**
 * @brief Removes a bit from a bit vector, and returns it.
 *
 * The removed bit is replaced by the last bit in the vector, rather than
 * shunting all following bits down.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param index The index of the bit to remove and replace by the end.
 * @return The bit at the specified index.
 * @retval `False` The requested bit was `0`.
 * @retval `True` The requested bit was `1`.
 * @retval `Error` `self` is `null`, or `index` is out of range.
 */
extern enum Tristate bitvec_bv_b16_swap_remove(
	struct BitVec *const self,
	const size_t index
);

/**
 * @brief Removes a bit from a bit vector, and returns it.
 *
 * The removed bit is replaced by the last bit in the vector, rather than
 * shunting all following bits down.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param index The index of the bit to remove and replace by the end.
 * @return The bit at the specified index.
 * @retval `False` The requested bit was `0`.
 * @retval `True` The requested bit was `1`.
 * @retval `Error` `self` is `null`, or `index` is out of range.
 */
extern enum Tristate bitvec_bv_l16_swap_remove(
	struct BitVec *const self,
	const size_t index
);

/**
 * @brief Removes a bit from a bit vector, and returns it.
 *
 * The removed bit is replaced by the last bit in the vector, rather than
 * shunting all following bits down.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param index The index of the bit to remove and replace by the end.
 * @return The bit at the specified index.
 * @retval `False` The requested bit was `0`.
 * @retval `True` The requested bit was `1`.
 * @retval `Error` `self` is `null`, or `index` is out of range.
 */
extern enum Tristate bitvec_bv_b32_swap_remove(
	struct BitVec *const self,
	const size_t index
);

/**
 * @brief Removes a bit from a bit vector, and returns it.
 *
 * The removed bit is replaced by the last bit in the vector, rather than
 * shunting all following bits down.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param index The index of the bit to remove and replace by the end.
 * @return The bit at the specified index.
 * @retval `False` The requested bit was `0`.
 * @retval `True` The requested bit was `1`.
 * @retval `Error` `self` is `null`, or `index` is out of range.
 */
extern enum Tristate bitvec_bv_l32_swap_remove(
	struct BitVec *const self,
	const size_t index
);

/**
 * @brief Removes a bit from a bit vector, and returns it.
 *
 * The removed bit is replaced by the last bit in the vector, rather than
 * shunting all following bits down.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param index The index of the bit to remove and replace by the end.
 * @return The bit at the specified index.
 * @retval `False` The requested bit was `0`.
 * @retval `True` The requested bit was `1`.
 * @retval `Error` `self` is `null`, or `index` is out of range.
 */
extern enum Tristate bitvec_bv_b64_swap_remove(
	struct BitVec *const self,
	const size_t index
);

/**
 * @brief Removes a bit from a bit vector, and returns it.
 *
 * The removed bit is replaced by the last bit in the vector, rather than
 * shunting all following bits down.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param index The index of the bit to remove and replace by the end.
 * @return The bit at the specified index.
 * @retval `False` The requested bit was `0`.
 * @retval `True` The requested bit was `1`.
 * @retval `Error` `self` is `null`, or `index` is out of range.
 */
extern enum Tristate bitvec_bv_l64_swap_remove(
	struct BitVec *const self,
	const size_t index
);

/**
 * @brief Inserts a bit at the specified index.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param index The index at which to insert the new bit.
 * @param value The value of the inserted bit.
 *
 * Any bits to the right of `index` are shifted up by one.
 */
extern void bitvec_bv_b08_insert(
	struct BitVec *const self,
	const size_t index,
	const bool value
);

/**
 * @brief Inserts a bit at the specified index.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param index The index at which to insert the new bit.
 * @param value The value of the inserted bit.
 *
 * Any bits to the right of `index` are shifted up by one.
 */
extern void bitvec_bv_l08_insert(
	struct BitVec *const self,
	const size_t index,
	const bool value
);

/**
 * @brief Inserts a bit at the specified index.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param index The index at which to insert the new bit.
 * @param value The value of the inserted bit.
 *
 * Any bits to the right of `index` are shifted up by one.
 */
extern void bitvec_bv_b16_insert(
	struct BitVec *const self,
	const size_t index,
	const bool value
);

/**
 * @brief Inserts a bit at the specified index.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param index The index at which to insert the new bit.
 * @param value The value of the inserted bit.
 *
 * Any bits to the right of `index` are shifted up by one.
 */
extern void bitvec_bv_l16_insert(
	struct BitVec *const self,
	const size_t index,
	const bool value
);

/**
 * @brief Inserts a bit at the specified index.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param index The index at which to insert the new bit.
 * @param value The value of the inserted bit.
 *
 * Any bits to the right of `index` are shifted up by one.
 */
extern void bitvec_bv_b32_insert(
	struct BitVec *const self,
	const size_t index,
	const bool value
);

/**
 * @brief Inserts a bit at the specified index.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param index The index at which to insert the new bit.
 * @param value The value of the inserted bit.
 *
 * Any bits to the right of `index` are shifted up by one.
 */
extern void bitvec_bv_l32_insert(
	struct BitVec *const self,
	const size_t index,
	const bool value
);

/**
 * @brief Inserts a bit at the specified index.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param index The index at which to insert the new bit.
 * @param value The value of the inserted bit.
 *
 * Any bits to the right of `index` are shifted up by one.
 */
extern void bitvec_bv_b64_insert(
	struct BitVec *const self,
	const size_t index,
	const bool value
);

/**
 * @brief Inserts a bit at the specified index.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param index The index at which to insert the new bit.
 * @param value The value of the inserted bit.
 *
 * Any bits to the right of `index` are shifted up by one.
 */
extern void bitvec_bv_l64_insert(
	struct BitVec *const self,
	const size_t index,
	const bool value
);

/**
 * @brief Removes a bit from the specified index.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param index The index from which to remove the new bit.
 * @return The bit at the specified index, as a tristate boolean.
 * @retval `False` The bit was `0`.
 * @retval `True` The bit was `1`.
 * @retval `Error` `self` was `null`, or `index` was out of bounds.
 */
extern bool bitvec_bv_b08_remove(
	struct BitVec *const self,
	const size_t index
);

/**
 * @brief Removes a bit from the specified index.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param index The index from which to remove the new bit.
 * @return The bit at the specified index, as a tristate boolean.
 * @retval `False` The bit was `0`.
 * @retval `True` The bit was `1`.
 * @retval `Error` `self` was `null`, or `index` was out of bounds.
 */
extern bool bitvec_bv_l08_remove(
	struct BitVec *const self,
	const size_t index
);

/**
 * @brief Removes a bit from the specified index.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param index The index from which to remove the new bit.
 * @return The bit at the specified index, as a tristate boolean.
 * @retval `False` The bit was `0`.
 * @retval `True` The bit was `1`.
 * @retval `Error` `self` was `null`, or `index` was out of bounds.
 */
extern bool bitvec_bv_b16_remove(
	struct BitVec *const self,
	const size_t index
);

/**
 * @brief Removes a bit from the specified index.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param index The index from which to remove the new bit.
 * @return The bit at the specified index, as a tristate boolean.
 * @retval `False` The bit was `0`.
 * @retval `True` The bit was `1`.
 * @retval `Error` `self` was `null`, or `index` was out of bounds.
 */
extern bool bitvec_bv_l16_remove(
	struct BitVec *const self,
	const size_t index
);

/**
 * @brief Removes a bit from the specified index.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param index The index from which to remove the new bit.
 * @return The bit at the specified index, as a tristate boolean.
 * @retval `False` The bit was `0`.
 * @retval `True` The bit was `1`.
 * @retval `Error` `self` was `null`, or `index` was out of bounds.
 */
extern bool bitvec_bv_b32_remove(
	struct BitVec *const self,
	const size_t index
);

/**
 * @brief Removes a bit from the specified index.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param index The index from which to remove the new bit.
 * @return The bit at the specified index, as a tristate boolean.
 * @retval `False` The bit was `0`.
 * @retval `True` The bit was `1`.
 * @retval `Error` `self` was `null`, or `index` was out of bounds.
 */
extern bool bitvec_bv_l32_remove(
	struct BitVec *const self,
	const size_t index
);

/**
 * @brief Removes a bit from the specified index.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param index The index from which to remove the new bit.
 * @return The bit at the specified index, as a tristate boolean.
 * @retval `False` The bit was `0`.
 * @retval `True` The bit was `1`.
 * @retval `Error` `self` was `null`, or `index` was out of bounds.
 */
extern bool bitvec_bv_b64_remove(
	struct BitVec *const self,
	const size_t index
);

/**
 * @brief Removes a bit from the specified index.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param index The index from which to remove the new bit.
 * @return The bit at the specified index, as a tristate boolean.
 * @retval `False` The bit was `0`.
 * @retval `True` The bit was `1`.
 * @retval `Error` `self` was `null`, or `index` was out of bounds.
 */
extern bool bitvec_bv_l64_remove(
	struct BitVec *const self,
	const size_t index
);

/**
 * @brief Retains only the bits in a `BitVec` that satisfy a test.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param func Function which tests each bit to determine if it is retained.
 */
extern void bitvec_bv_b08_retain(
	struct BitVec *const self,
	bool (*func)(bool value)
);

/**
 * @brief Retains only the bits in a `BitVec` that satisfy a test.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param func Function which tests each bit to determine if it is retained.
 */
extern void bitvec_bv_l08_retain(
	struct BitVec *const self,
	bool (*func)(bool value)
);

/**
 * @brief Retains only the bits in a `BitVec` that satisfy a test.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param func Function which tests each bit to determine if it is retained.
 */
extern void bitvec_bv_b16_retain(
	struct BitVec *const self,
	bool (*func)(bool value)
);

/**
 * @brief Retains only the bits in a `BitVec` that satisfy a test.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param func Function which tests each bit to determine if it is retained.
 */
extern void bitvec_bv_l16_retain(
	struct BitVec *const self,
	bool (*func)(bool value)
);

/**
 * @brief Retains only the bits in a `BitVec` that satisfy a test.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param func Function which tests each bit to determine if it is retained.
 */
extern void bitvec_bv_b32_retain(
	struct BitVec *const self,
	bool (*func)(bool value)
);

/**
 * @brief Retains only the bits in a `BitVec` that satisfy a test.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param func Function which tests each bit to determine if it is retained.
 */
extern void bitvec_bv_l32_retain(
	struct BitVec *const self,
	bool (*func)(bool value)
);

/**
 * @brief Retains only the bits in a `BitVec` that satisfy a test.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param func Function which tests each bit to determine if it is retained.
 */
extern void bitvec_bv_b64_retain(
	struct BitVec *const self,
	bool (*func)(bool value)
);

/**
 * @brief Retains only the bits in a `BitVec` that satisfy a test.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param func Function which tests each bit to determine if it is retained.
 */
extern void bitvec_bv_l64_retain(
	struct BitVec *const self,
	bool (*func)(bool value)
);

/**
 * @brief Appends a bit to the back of a bit vector.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param value The bit to append.
 */
extern void bitvec_bv_b08_push(struct BitVec *const self, const bool value);

/**
 * @brief Appends a bit to the back of a bit vector.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param value The bit to append.
 */
extern void bitvec_bv_l08_push(struct BitVec *const self, const bool value);

/**
 * @brief Appends a bit to the back of a bit vector.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param value The bit to append.
 */
extern void bitvec_bv_b16_push(struct BitVec *const self, const bool value);

/**
 * @brief Appends a bit to the back of a bit vector.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param value The bit to append.
 */
extern void bitvec_bv_l16_push(struct BitVec *const self, const bool value);

/**
 * @brief Appends a bit to the back of a bit vector.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param value The bit to append.
 */
extern void bitvec_bv_b32_push(struct BitVec *const self, const bool value);

/**
 * @brief Appends a bit to the back of a bit vector.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param value The bit to append.
 */
extern void bitvec_bv_l32_push(struct BitVec *const self, const bool value);

/**
 * @brief Appends a bit to the back of a bit vector.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param value The bit to append.
 */
extern void bitvec_bv_b64_push(struct BitVec *const self, const bool value);

/**
 * @brief Appends a bit to the back of a bit vector.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param value The bit to append.
 */
extern void bitvec_bv_l64_push(struct BitVec *const self, const bool value);

/**
 * @brief Removes the last bit from a bit vector.
 * @param[in] self Pointer to a `BitVec` handle.
 * @return Tristate boolean ofthe last bit in the vector.
 * @retval `False` The last bit was `0`.
 * @retval `True` The last bit was `1`.
 * @retval `Error` `self` is `null`, or `*self` is empty.
 */
extern enum Tristate bitvec_bv_b08_pop(struct BitVec *const self);

/**
 * @brief Removes the last bit from a bit vector.
 * @param[in] self Pointer to a `BitVec` handle.
 * @return Tristate boolean ofthe last bit in the vector.
 * @retval `False` The last bit was `0`.
 * @retval `True` The last bit was `1`.
 * @retval `Error` `self` is `null`, or `*self` is empty.
 */
extern enum Tristate bitvec_bv_l08_pop(struct BitVec *const self);

/**
 * @brief Removes the last bit from a bit vector.
 * @param[in] self Pointer to a `BitVec` handle.
 * @return Tristate boolean ofthe last bit in the vector.
 * @retval `False` The last bit was `0`.
 * @retval `True` The last bit was `1`.
 * @retval `Error` `self` is `null`, or `*self` is empty.
 */
extern enum Tristate bitvec_bv_b16_pop(struct BitVec *const self);

/**
 * @brief Removes the last bit from a bit vector.
 * @param[in] self Pointer to a `BitVec` handle.
 * @return Tristate boolean ofthe last bit in the vector.
 * @retval `False` The last bit was `0`.
 * @retval `True` The last bit was `1`.
 * @retval `Error` `self` is `null`, or `*self` is empty.
 */
extern enum Tristate bitvec_bv_l16_pop(struct BitVec *const self);

/**
 * @brief Removes the last bit from a bit vector.
 * @param[in] self Pointer to a `BitVec` handle.
 * @return Tristate boolean ofthe last bit in the vector.
 * @retval `False` The last bit was `0`.
 * @retval `True` The last bit was `1`.
 * @retval `Error` `self` is `null`, or `*self` is empty.
 */
extern enum Tristate bitvec_bv_b32_pop(struct BitVec *const self);

/**
 * @brief Removes the last bit from a bit vector.
 * @param[in] self Pointer to a `BitVec` handle.
 * @return Tristate boolean ofthe last bit in the vector.
 * @retval `False` The last bit was `0`.
 * @retval `True` The last bit was `1`.
 * @retval `Error` `self` is `null`, or `*self` is empty.
 */
extern enum Tristate bitvec_bv_l32_pop(struct BitVec *const self);

/**
 * @brief Removes the last bit from a bit vector.
 * @param[in] self Pointer to a `BitVec` handle.
 * @return Tristate boolean ofthe last bit in the vector.
 * @retval `False` The last bit was `0`.
 * @retval `True` The last bit was `1`.
 * @retval `Error` `self` is `null`, or `*self` is empty.
 */
extern enum Tristate bitvec_bv_b64_pop(struct BitVec *const self);

/**
 * @brief Removes the last bit from a bit vector.
 * @param[in] self Pointer to a `BitVec` handle.
 * @return Tristate boolean ofthe last bit in the vector.
 * @retval `False` The last bit was `0`.
 * @retval `True` The last bit was `1`.
 * @retval `Error` `self` is `null`, or `*self` is empty.
 */
extern enum Tristate bitvec_bv_l64_pop(struct BitVec *const self);

/**
 * @brief Clears a bit vector.
 * @param[in] self Pointer to a `BitVec` handle.
 */
extern void bitvec_bv_b08_clear(struct BitVec *const self);

/**
 * @brief Clears a bit vector.
 * @param[in] self Pointer to a `BitVec` handle.
 */
extern void bitvec_bv_l08_clear(struct BitVec *const self);

/**
 * @brief Clears a bit vector.
 * @param[in] self Pointer to a `BitVec` handle.
 */
extern void bitvec_bv_b16_clear(struct BitVec *const self);

/**
 * @brief Clears a bit vector.
 * @param[in] self Pointer to a `BitVec` handle.
 */
extern void bitvec_bv_l16_clear(struct BitVec *const self);

/**
 * @brief Clears a bit vector.
 * @param[in] self Pointer to a `BitVec` handle.
 */
extern void bitvec_bv_b32_clear(struct BitVec *const self);

/**
 * @brief Clears a bit vector.
 * @param[in] self Pointer to a `BitVec` handle.
 */
extern void bitvec_bv_l32_clear(struct BitVec *const self);

/**
 * @brief Clears a bit vector.
 * @param[in] self Pointer to a `BitVec` handle.
 */
extern void bitvec_bv_b64_clear(struct BitVec *const self);

/**
 * @brief Clears a bit vector.
 * @param[in] self Pointer to a `BitVec` handle.
 */
extern void bitvec_bv_l64_clear(struct BitVec *const self);

/**
 * @brief Splits a bit vector into two vectors.
 * @param[in,out] self Pointer to a `BitVec` handle. After self function, it
 * will contain the `[.. at]` half of the original vector.
 * @param[out] out Pointer to an *uninitialized* `BitVec` handle. After self
 * function, it will contain a handle governing the `[at ..]` half of the
 * original vector.
 * @param at The index at which to split the vector.
 * @return Whether the split succeeded.
 * @retval `true` The split occurred; `*out` is live.
 * @retval `false` The split failed; `*out` is not live.
 */
extern bool bitvec_bv_b08_split_off(
	struct BitVec *const self,
	struct BitVec *const out,
	const size_t at
);

/**
 * @brief Splits a bit vector into two vectors.
 * @param[in,out] self Pointer to a `BitVec` handle. After self function, it
 * will contain the `[.. at]` half of the original vector.
 * @param[out] out Pointer to an *uninitialized* `BitVec` handle. After self
 * function, it will contain a handle governing the `[at ..]` half of the
 * original vector.
 * @param at The index at which to split the vector.
 * @return Whether the split succeeded.
 * @retval `true` The split occurred; `*out` is live.
 * @retval `false` The split failed; `*out` is not live.
 */
extern bool bitvec_bv_l08_split_off(
	struct BitVec *const self,
	struct BitVec *const out,
	const size_t at
);

/**
 * @brief Splits a bit vector into two vectors.
 * @param[in,out] self Pointer to a `BitVec` handle. After self function, it
 * will contain the `[.. at]` half of the original vector.
 * @param[out] out Pointer to an *uninitialized* `BitVec` handle. After self
 * function, it will contain a handle governing the `[at ..]` half of the
 * original vector.
 * @param at The index at which to split the vector.
 * @return Whether the split succeeded.
 * @retval `true` The split occurred; `*out` is live.
 * @retval `false` The split failed; `*out` is not live.
 */
extern bool bitvec_bv_b16_split_off(
	struct BitVec *const self,
	struct BitVec *const out,
	const size_t at
);

/**
 * @brief Splits a bit vector into two vectors.
 * @param[in,out] self Pointer to a `BitVec` handle. After self function, it
 * will contain the `[.. at]` half of the original vector.
 * @param[out] out Pointer to an *uninitialized* `BitVec` handle. After self
 * function, it will contain a handle governing the `[at ..]` half of the
 * original vector.
 * @param at The index at which to split the vector.
 * @return Whether the split succeeded.
 * @retval `true` The split occurred; `*out` is live.
 * @retval `false` The split failed; `*out` is not live.
 */
extern bool bitvec_bv_l16_split_off(
	struct BitVec *const self,
	struct BitVec *const out,
	const size_t at
);

/**
 * @brief Splits a bit vector into two vectors.
 * @param[in,out] self Pointer to a `BitVec` handle. After self function, it
 * will contain the `[.. at]` half of the original vector.
 * @param[out] out Pointer to an *uninitialized* `BitVec` handle. After self
 * function, it will contain a handle governing the `[at ..]` half of the
 * original vector.
 * @param at The index at which to split the vector.
 * @return Whether the split succeeded.
 * @retval `true` The split occurred; `*out` is live.
 * @retval `false` The split failed; `*out` is not live.
 */
extern bool bitvec_bv_b32_split_off(
	struct BitVec *const self,
	struct BitVec *const out,
	const size_t at
);

/**
 * @brief Splits a bit vector into two vectors.
 * @param[in,out] self Pointer to a `BitVec` handle. After self function, it
 * will contain the `[.. at]` half of the original vector.
 * @param[out] out Pointer to an *uninitialized* `BitVec` handle. After self
 * function, it will contain a handle governing the `[at ..]` half of the
 * original vector.
 * @param at The index at which to split the vector.
 * @return Whether the split succeeded.
 * @retval `true` The split occurred; `*out` is live.
 * @retval `false` The split failed; `*out` is not live.
 */
extern bool bitvec_bv_l32_split_off(
	struct BitVec *const self,
	struct BitVec *const out,
	const size_t at
);

/**
 * @brief Splits a bit vector into two vectors.
 * @param[in,out] self Pointer to a `BitVec` handle. After self function, it
 * will contain the `[.. at]` half of the original vector.
 * @param[out] out Pointer to an *uninitialized* `BitVec` handle. After self
 * function, it will contain a handle governing the `[at ..]` half of the
 * original vector.
 * @param at The index at which to split the vector.
 * @return Whether the split succeeded.
 * @retval `true` The split occurred; `*out` is live.
 * @retval `false` The split failed; `*out` is not live.
 */
extern bool bitvec_bv_b64_split_off(
	struct BitVec *const self,
	struct BitVec *const out,
	const size_t at
);

/**
 * @brief Splits a bit vector into two vectors.
 * @param[in,out] self Pointer to a `BitVec` handle. After self function, it
 * will contain the `[.. at]` half of the original vector.
 * @param[out] out Pointer to an *uninitialized* `BitVec` handle. After self
 * function, it will contain a handle governing the `[at ..]` half of the
 * original vector.
 * @param at The index at which to split the vector.
 * @return Whether the split succeeded.
 * @retval `true` The split occurred; `*out` is live.
 * @retval `false` The split failed; `*out` is not live.
 */
extern bool bitvec_bv_l64_split_off(
	struct BitVec *const self,
	struct BitVec *const out,
	const size_t at
);

/**
 * @brief Resizes a bit vector to a new length.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param new_len The new length of the vector.
 * @param value The value to use if the vector is growing in size.
 */
extern void bitvec_bv_b08_resize(
	struct BitVec *const self,
	const size_t new_len,
	const bool value
);

/**
 * @brief Resizes a bit vector to a new length.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param new_len The new length of the vector.
 * @param value The value to use if the vector is growing in size.
 */
extern void bitvec_bv_l08_resize(
	struct BitVec *const self,
	const size_t new_len,
	const bool value
);

/**
 * @brief Resizes a bit vector to a new length.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param new_len The new length of the vector.
 * @param value The value to use if the vector is growing in size.
 */
extern void bitvec_bv_b16_resize(
	struct BitVec *const self,
	const size_t new_len,
	const bool value
);

/**
 * @brief Resizes a bit vector to a new length.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param new_len The new length of the vector.
 * @param value The value to use if the vector is growing in size.
 */
extern void bitvec_bv_l16_resize(
	struct BitVec *const self,
	const size_t new_len,
	const bool value
);

/**
 * @brief Resizes a bit vector to a new length.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param new_len The new length of the vector.
 * @param value The value to use if the vector is growing in size.
 */
extern void bitvec_bv_b32_resize(
	struct BitVec *const self,
	const size_t new_len,
	const bool value
);

/**
 * @brief Resizes a bit vector to a new length.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param new_len The new length of the vector.
 * @param value The value to use if the vector is growing in size.
 */
extern void bitvec_bv_l32_resize(
	struct BitVec *const self,
	const size_t new_len,
	const bool value
);

/**
 * @brief Resizes a bit vector to a new length.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param new_len The new length of the vector.
 * @param value The value to use if the vector is growing in size.
 */
extern void bitvec_bv_b64_resize(
	struct BitVec *const self,
	const size_t new_len,
	const bool value
);

/**
 * @brief Resizes a bit vector to a new length.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param new_len The new length of the vector.
 * @param value The value to use if the vector is growing in size.
 */
extern void bitvec_bv_l64_resize(
	struct BitVec *const self,
	const size_t new_len,
	const bool value
);

/**
 * @brief Sets each element in a bit vector backing storage to a pattern.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param element The element to use when setting the backing storage.
 */
extern void bitvec_bv_b08_set_elements(
	struct BitVec *const self,
	const uint8_t  element
);

/**
 * @brief Sets each element in a bit vector backing storage to a pattern.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param element The element to use when setting the backing storage.
 */
extern void bitvec_bv_l08_set_elements(
	struct BitVec *const self,
	const uint8_t  element
);

/**
 * @brief Sets each element in a bit vector backing storage to a pattern.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param element The element to use when setting the backing storage.
 */
extern void bitvec_bv_b16_set_elements(
	struct BitVec *const self,
	const uint16_t element
);

/**
 * @brief Sets each element in a bit vector backing storage to a pattern.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param element The element to use when setting the backing storage.
 */
extern void bitvec_bv_l16_set_elements(
	struct BitVec *const self,
	const uint16_t element
);

/**
 * @brief Sets each element in a bit vector backing storage to a pattern.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param element The element to use when setting the backing storage.
 */
extern void bitvec_bv_b32_set_elements(
	struct BitVec *const self,
	const uint32_t element
);

/**
 * @brief Sets each element in a bit vector backing storage to a pattern.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param element The element to use when setting the backing storage.
 */
extern void bitvec_bv_l32_set_elements(
	struct BitVec *const self,
	const uint32_t element
);

/**
 * @brief Sets each element in a bit vector backing storage to a pattern.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param element The element to use when setting the backing storage.
 */
extern void bitvec_bv_b64_set_elements(
	struct BitVec *const self,
	const uint64_t element
);

/**
 * @brief Sets each element in a bit vector backing storage to a pattern.
 * @param[in] self Pointer to a `BitVec` handle.
 * @param element The element to use when setting the backing storage.
 */
extern void bitvec_bv_l64_set_elements(
	struct BitVec *const self,
	const uint64_t element
);

/**
 * @brief Clones a saurce bit vector into a destination handle.
 * @param[out] self Pointer to the destination handle which will become a clone.
 * @param[in] other Pointer to the source handle from which the clone occurs.
 */
extern void bitvec_bv_b08_clone_from(
	struct BitVec *const self,
	const struct BitVec *const other
);

/**
 * @brief Clones a saurce bit vector into a destination handle.
 * @param[out] self Pointer to the destination handle which will become a clone.
 * @param[in] other Pointer to the source handle from which the clone occurs.
 */
extern void bitvec_bv_l08_clone_from(
	struct BitVec *const self,
	const struct BitVec *const other
);

/**
 * @brief Clones a saurce bit vector into a destination handle.
 * @param[out] self Pointer to the destination handle which will become a clone.
 * @param[in] other Pointer to the source handle from which the clone occurs.
 */
extern void bitvec_bv_b16_clone_from(
	struct BitVec *const self,
	const struct BitVec *const other
);

/**
 * @brief Clones a saurce bit vector into a destination handle.
 * @param[out] self Pointer to the destination handle which will become a clone.
 * @param[in] other Pointer to the source handle from which the clone occurs.
 */
extern void bitvec_bv_l16_clone_from(
	struct BitVec *const self,
	const struct BitVec *const other
);

/**
 * @brief Clones a saurce bit vector into a destination handle.
 * @param[out] self Pointer to the destination handle which will become a clone.
 * @param[in] other Pointer to the source handle from which the clone occurs.
 */
extern void bitvec_bv_b32_clone_from(
	struct BitVec *const self,
	const struct BitVec *const other
);

/**
 * @brief Clones a saurce bit vector into a destination handle.
 * @param[out] self Pointer to the destination handle which will become a clone.
 * @param[in] other Pointer to the source handle from which the clone occurs.
 */
extern void bitvec_bv_l32_clone_from(
	struct BitVec *const self,
	const struct BitVec *const other
);

/**
 * @brief Clones a saurce bit vector into a destination handle.
 * @param[out] self Pointer to the destination handle which will become a clone.
 * @param[in] other Pointer to the source handle from which the clone occurs.
 */
extern void bitvec_bv_b64_clone_from(
	struct BitVec *const self,
	const struct BitVec *const other
);

/**
 * @brief Clones a saurce bit vector into a destination handle.
 * @param[out] self Pointer to the destination handle which will become a clone.
 * @param[in] other Pointer to the source handle from which the clone occurs.
 */
extern void bitvec_bv_l64_clone_from(
	struct BitVec *const self,
	const struct BitVec *const other
);

/**
 * @brief Destroys the `BitVec` to which `self` points.
 * @param[in] self Pointer to a `BitVec` which is to be deallocated.
 *
 * Note that after this function executes, `*self`'s memory will be deallocated,
 * and the contents of the `*self` handle will be set to the empty vector in
 * order to prevent use-after-free bugs.
 */
extern void bitvec_bv_b08_drop(struct BitVec *const self);

/**
 * @brief Destroys the `BitVec` to which `self` points.
 * @param[in] self Pointer to a `BitVec` which is to be deallocated.
 *
 * Note that after this function executes, `*self`'s memory will be deallocated,
 * and the contents of the `*self` handle will be set to the empty vector in
 * order to prevent use-after-free bugs.
 */
extern void bitvec_bv_l08_drop(struct BitVec *const self);

/**
 * @brief Destroys the `BitVec` to which `self` points.
 * @param[in] self Pointer to a `BitVec` which is to be deallocated.
 *
 * Note that after this function executes, `*self`'s memory will be deallocated,
 * and the contents of the `*self` handle will be set to the empty vector in
 * order to prevent use-after-free bugs.
 */
extern void bitvec_bv_b16_drop(struct BitVec *const self);

/**
 * @brief Destroys the `BitVec` to which `self` points.
 * @param[in] self Pointer to a `BitVec` which is to be deallocated.
 *
 * Note that after this function executes, `*self`'s memory will be deallocated,
 * and the contents of the `*self` handle will be set to the empty vector in
 * order to prevent use-after-free bugs.
 */
extern void bitvec_bv_l16_drop(struct BitVec *const self);

/**
 * @brief Destroys the `BitVec` to which `self` points.
 * @param[in] self Pointer to a `BitVec` which is to be deallocated.
 *
 * Note that after this function executes, `*self`'s memory will be deallocated,
 * and the contents of the `*self` handle will be set to the empty vector in
 * order to prevent use-after-free bugs.
 */
extern void bitvec_bv_b32_drop(struct BitVec *const self);

/**
 * @brief Destroys the `BitVec` to which `self` points.
 * @param[in] self Pointer to a `BitVec` which is to be deallocated.
 *
 * Note that after this function executes, `*self`'s memory will be deallocated,
 * and the contents of the `*self` handle will be set to the empty vector in
 * order to prevent use-after-free bugs.
 */
extern void bitvec_bv_l32_drop(struct BitVec *const self);

/**
 * @brief Destroys the `BitVec` to which `self` points.
 * @param[in] self Pointer to a `BitVec` which is to be deallocated.
 *
 * Note that after this function executes, `*self`'s memory will be deallocated,
 * and the contents of the `*self` handle will be set to the empty vector in
 * order to prevent use-after-free bugs.
 */
extern void bitvec_bv_b64_drop(struct BitVec *const self);

/**
 * @brief Destroys the `BitVec` to which `self` points.
 * @param[in] self Pointer to a `BitVec` which is to be deallocated.
 *
 * Note that after this function executes, `*self`'s memory will be deallocated,
 * and the contents of the `*self` handle will be set to the empty vector in
 * order to prevent use-after-free bugs.
 */
extern void bitvec_bv_l64_drop(struct BitVec *const self);

#ifdef __cplusplus
} // extern "C"
} // namespace bitvec
#endif

#endif//BITVEC_FFI_BITVEC_H
