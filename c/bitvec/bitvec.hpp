#ifndef BITVEC_FFI_BITVEC_HPP
#define BITVEC_FFI_BITVEC_HPP

#include <cstddef>
#include <cstdint>

#include <array>
#include <type_traits>
#include <utility>

#include "bitslice.hpp"
#include "bitvec.h"

namespace bitvec {

namespace func {
namespace bv {

//  JUMP TABLES
//
//  These tables are used to multiplex template-class method instantiations to
//  the correct C-API boundary function. These tables cannot be observed or used
//  outside this module, and are removed from the compiled output.

using ctor_t = void(BitVec *);
static auto const ctor = std::array<ctor_t *, 8>{{
	reinterpret_cast<ctor_t *>(bitvec_bv_b08_new),
	reinterpret_cast<ctor_t *>(bitvec_bv_l08_new),
	reinterpret_cast<ctor_t *>(bitvec_bv_b16_new),
	reinterpret_cast<ctor_t *>(bitvec_bv_l16_new),
	reinterpret_cast<ctor_t *>(bitvec_bv_b32_new),
	reinterpret_cast<ctor_t *>(bitvec_bv_l32_new),
	reinterpret_cast<ctor_t *>(bitvec_bv_b64_new),
	reinterpret_cast<ctor_t *>(bitvec_bv_l64_new),
}};

using push_t = void(BitVec *, bool);
static auto const push = std::array<push_t *, 8>{{
	reinterpret_cast<push_t *>(bitvec_bv_b08_push),
	reinterpret_cast<push_t *>(bitvec_bv_l08_push),
	reinterpret_cast<push_t *>(bitvec_bv_b16_push),
	reinterpret_cast<push_t *>(bitvec_bv_l16_push),
	reinterpret_cast<push_t *>(bitvec_bv_b32_push),
	reinterpret_cast<push_t *>(bitvec_bv_l32_push),
	reinterpret_cast<push_t *>(bitvec_bv_b64_push),
	reinterpret_cast<push_t *>(bitvec_bv_l64_push),
}};

using pop_t = auto(BitVec *) -> Tristate;
static auto const pop = std::array<pop_t *, 8>{{
	reinterpret_cast<pop_t *>(bitvec_bv_b08_pop),
	reinterpret_cast<pop_t *>(bitvec_bv_l08_pop),
	reinterpret_cast<pop_t *>(bitvec_bv_b16_pop),
	reinterpret_cast<pop_t *>(bitvec_bv_l16_pop),
	reinterpret_cast<pop_t *>(bitvec_bv_b32_pop),
	reinterpret_cast<pop_t *>(bitvec_bv_l32_pop),
	reinterpret_cast<pop_t *>(bitvec_bv_b64_pop),
	reinterpret_cast<pop_t *>(bitvec_bv_l64_pop),
}};

using clear_t = void(BitVec *);
static auto const clear = std::array<clear_t *, 8>{{
	reinterpret_cast<clear_t *>(bitvec_bv_b08_clear),
	reinterpret_cast<clear_t *>(bitvec_bv_l08_clear),
	reinterpret_cast<clear_t *>(bitvec_bv_b16_clear),
	reinterpret_cast<clear_t *>(bitvec_bv_l16_clear),
	reinterpret_cast<clear_t *>(bitvec_bv_b32_clear),
	reinterpret_cast<clear_t *>(bitvec_bv_l32_clear),
	reinterpret_cast<clear_t *>(bitvec_bv_b64_clear),
	reinterpret_cast<clear_t *>(bitvec_bv_l64_clear),
}};

using resize_t = void(BitVec *, std::size_t, bool);
static auto const resize = std::array<resize_t *, 8>{{
	reinterpret_cast<resize_t *>(bitvec_bv_b08_resize),
	reinterpret_cast<resize_t *>(bitvec_bv_l08_resize),
	reinterpret_cast<resize_t *>(bitvec_bv_b16_resize),
	reinterpret_cast<resize_t *>(bitvec_bv_l16_resize),
	reinterpret_cast<resize_t *>(bitvec_bv_b32_resize),
	reinterpret_cast<resize_t *>(bitvec_bv_l32_resize),
	reinterpret_cast<resize_t *>(bitvec_bv_b64_resize),
	reinterpret_cast<resize_t *>(bitvec_bv_l64_resize),
}};

using split_off_t = auto(BitVec *, BitVec *, std::size_t) -> bool;
static auto const split_off = std::array<split_off_t *, 8>{{
	reinterpret_cast<split_off_t *>(bitvec_bv_b08_split_off),
	reinterpret_cast<split_off_t *>(bitvec_bv_l08_split_off),
	reinterpret_cast<split_off_t *>(bitvec_bv_b16_split_off),
	reinterpret_cast<split_off_t *>(bitvec_bv_l16_split_off),
	reinterpret_cast<split_off_t *>(bitvec_bv_b32_split_off),
	reinterpret_cast<split_off_t *>(bitvec_bv_l32_split_off),
	reinterpret_cast<split_off_t *>(bitvec_bv_b64_split_off),
	reinterpret_cast<split_off_t *>(bitvec_bv_l64_split_off),
}};

using set_elements_t = void(BitVec *, void *);
static auto const set_elements = std::array<set_elements_t *, 8>{{
	reinterpret_cast<set_elements_t *>(bitvec_bv_b08_set_elements),
	reinterpret_cast<set_elements_t *>(bitvec_bv_l08_set_elements),
	reinterpret_cast<set_elements_t *>(bitvec_bv_b16_set_elements),
	reinterpret_cast<set_elements_t *>(bitvec_bv_l16_set_elements),
	reinterpret_cast<set_elements_t *>(bitvec_bv_b32_set_elements),
	reinterpret_cast<set_elements_t *>(bitvec_bv_l32_set_elements),
	reinterpret_cast<set_elements_t *>(bitvec_bv_b64_set_elements),
	reinterpret_cast<set_elements_t *>(bitvec_bv_l64_set_elements),
}};

using clone_from_t = void(BitVec *, BitVec *);
static auto const clone_from = std::array<clone_from_t *, 8>{{
	reinterpret_cast<clone_from_t *>(bitvec_bv_b08_clone_from),
	reinterpret_cast<clone_from_t *>(bitvec_bv_l08_clone_from),
	reinterpret_cast<clone_from_t *>(bitvec_bv_b16_clone_from),
	reinterpret_cast<clone_from_t *>(bitvec_bv_l16_clone_from),
	reinterpret_cast<clone_from_t *>(bitvec_bv_b32_clone_from),
	reinterpret_cast<clone_from_t *>(bitvec_bv_l32_clone_from),
	reinterpret_cast<clone_from_t *>(bitvec_bv_b64_clone_from),
	reinterpret_cast<clone_from_t *>(bitvec_bv_l64_clone_from),
}};

using dtor_t = void(BitVec *);
static auto const dtor = std::array<dtor_t *, 8>{{
	reinterpret_cast<dtor_t *>(bitvec_bv_b08_drop),
	reinterpret_cast<dtor_t *>(bitvec_bv_l08_drop),
	reinterpret_cast<dtor_t *>(bitvec_bv_b16_drop),
	reinterpret_cast<dtor_t *>(bitvec_bv_l16_drop),
	reinterpret_cast<dtor_t *>(bitvec_bv_b32_drop),
	reinterpret_cast<dtor_t *>(bitvec_bv_l32_drop),
	reinterpret_cast<dtor_t *>(bitvec_bv_b64_drop),
	reinterpret_cast<dtor_t *>(bitvec_bv_l64_drop),
}};

} // namespace bv
} // namespace func

template <Cursor C, class T>
class BitVector;

namespace impl {

template <Cursor C, class T>
static BitVec * make_bitvec(BitVector<C, T> * bv) {
	return reinterpret_cast<BitVec *>(bv);
}

template <Cursor C, class T>
static BitVec const * make_bitvec(BitVector<C, T> const * bv) {
	return reinterpret_cast<BitVec const *>(bv);
}

} // namespace impl

/**
 * @class BitVector
 *
 * @brief Growable collection of ordered bits.
 *
 * This handle does own the memory it governs, and WILL deallocate it on
 * destruction.
 */
template <Cursor C, class T>
class BitVector : public BitSlice<C, T> {
	static_assert(
		std::is_integral<T>::value && std::is_unsigned<T>::value,
		"BitVector can only be constructed with unsigned integral storage types"
	);
	static_assert(
		not std::is_const<T>::value,
		"BitVector cannot be constructed for immutable data"
	);
public:
	/**
	 * @brief Default constructor. Creates a blank vector without allocating.
	 */
	explicit BitVector(void) noexcept {
		impl::mux<C, T>(func::bv::ctor, impl::make_bitvec(this));
	}

	/**
	 * @brief Copy constructor. If `other` is not empty, this creates a new
	 * allocation and copies the data from the source vector.
	 *
	 * @param other `BitVector` to be used as a clone source.
	 */
	BitVector(BitVector const& other) noexcept {
		*this = other;
	}

	/**
	 * @brief Move constructor. Sets `this` to the empty vector, then swaps the
	 * handles of `this` and `other`.
	 *
	 * @param other rvalue reference to a `BitVector` which will be moved into
	 * `this`. After construction occurs, `other` will be the empty vector.
	 */
	BitVector(BitVector&& other) noexcept : BitVector() {
		//  at entry, the default constructor has been run on `this`, making it
		//  the empty vector.
		*this = std::move(other);
	}

	/**
	 * @brief Destructor. Deallocates the owned memory and replaces the object
	 * value with an empty vector.
	 */
	~BitVector(void) noexcept {
		impl::mux<C, T>(func::bv::dtor, impl::make_bitvec(this));
	}

	/**
	 * @brief Copy assignment operator. If `other` is not empty, this creates a
	 * new allocation and copies the data from the source vector.
	 *
	 * @param other `BitVector` to be used as a clone source.
	 */
	BitVector& operator=(BitVector const& other) noexcept {
		//  prevent self-assignment
		if (&other == this) {
			return *this;
		}
		impl::mux<C, T>(
			func::bv::clone_from,
			impl::make_bitvec(this),
			impl::make_bitvec(&other)
		);
	}

	/**
	 * @brief Move assignment operator.
	 *
	 * @param other rvalue reference of the source `BitVector`. After assignment
	 * occurs, `other` will be the empty vector.
	 *
	 * @return lvalue reference of `this`.
	 */
	BitVector& operator=(BitVector&& other) noexcept {
		//  prevent self-assignment
		if (&other != this) {
			//  Exchange the handle values behind `this` and `&other`
			std::swap(*impl::make_bitvec(this), *impl::make_bitvec(&other));
		}
		return *this;
	}

	/**
	 * @brief Gets a non-allocating view handle to the `BitVector` memory.
	 *
	 * The view's lifetime is not tied to the vector's lifetime. If the view
	 * escapes the scope of the vector, then it will dangle. This is not
	 * something that can be prevented by this library.
	 *
	 * @return A view handle, which can modify the bits of the slice but not the
	 * allocator state of the vector, viewing the vector's slice.
	 */
	BitSlice<C, T> view(void) const noexcept {
		return std::move(*static_cast<BitSlice<C, T> const *>(this));
	}

	void push(bool const value) noexcept {
		impl::mux<C, T>(func::bv::push, impl::make_bitvec(this), value);
	}

	Tristate pop_front(BitSlice<C, T>& tail) const noexcept {
		return view().pop_front(tail);
	}

	/**
	 * @brief Remove the last bit from the vector.
	 *
	 * This shrinks the vector's size by one, without changing its allocator
	 * state.
	 *
	 * @return The last bit of the vector, if present.
	 * @retval `Error` The vector was empty.
	 * @retval `False` The vector was not empty and its last bit was `0`.
	 * @retval `True` The vector was not empty and its last bit was `1`.
	 */
	Tristate pop_back(void) noexcept {
		return impl::mux<C, T>(func::bv::pop, impl::make_bitvec(this));
	}

	/**
	 * @brief Attempts to split the last bit from the vector. This does not
	 * change the allocation state of the vector.
	 *
	 * @param[out] head The remainder of the slice after the last bit is
	 * removed.
	 *
	 * @return Tristate boolean of the last bit in the vector.
	 * @retval `Error` The vector is empty.
	 * @retval `False` The vector has a last bit and it is `0`.
	 * @retval `True` The vector has a last bit and it is `1`.
	 */
	Tristate pop_back(BitSlice<C, T>& head) const noexcept {
		return view().pop_front(head);
	}

private:
	/// Allocation capacity, measured in `T` elements, of the vector.
	///
	/// This value is not mangled, and *can* be read by C++.
	std::size_t capacity;

	/**
	 * @brief Removes the front bit from the vector.
	 *
	 * This is private and undefined, because popping the front of the vector
	 * *breaks it*.
	 *
	 * @return Tristate boolean of the first bit.
	 */
	Tristate pop_front(void);
};

} // namespace bitvec

#endif//BITVEC_FFI_BITVEC_HPP
