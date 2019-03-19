#if 0

#include <cstdint>
#include <iterator>
#include <tuple>
#include <type_traits>


class bit_reference
{
public:
    bit_reference(const bit_reference&) = default;
    bit_reference& operator=(const bit_reference&) = default;
    bit_reference(bit_reference&&) = default;
    bit_reference& operator=(bit_reference&&) = default;

    bit_reference& operator=(bool x) noexcept {
        if (x) {
            *byte_ |= static_cast<uint8_t>(mask_);
        } else {
            *byte_ &= ~static_cast<uint8_t>(mask_);
        }
        return *this;
    }

    operator bool() const noexcept {
        return static_cast<bool>(*byte_ & static_cast<uint8_t>(mask_));
    }

    bool operator ~() const noexcept {
        return !bool(*this);
    }

    void flip() noexcept {
        *byte_ ^= static_cast<uint8_t>(mask_);
    }

private:
    uint8_t* byte_;
    uint32_t mask_;

    template <bool, bool>
    friend class bitvec_iterator;

    bit_reference(uint8_t* byte, uint32_t bit):
        byte_(byte),
        mask_(1 << bit)
    {}
};


/// Iterator that goes from the least-significant bit to most-significant.
template <bool little_endian, bool is_const>
class bitvec_iterator
{
private:
    // Private types to help.
    using self_t = bitvec_iterator<little_endian, is_const>;

public:
    // MEMBER TYPES
    // ------------
    // These are the member types expected. Only value_type and
    // iterator_category are required, but you want all 5 (often).
    using value_type = bool;
    using reference = bit_reference;
    using pointer = bitvec_iterator;
    using difference_type = std::ptrdiff_t;
    using iterator_category = std::random_access_iterator_tag;

    // MEMBER FUNCTIONS
    // ----------------
    // Force automatic compiler constructors.
    bitvec_iterator(const self_t&) = default;
    self_t& operator=(const self_t&) = default;
    bitvec_iterator(self_t&&) = default;
    self_t& operator=(self_t&&) = default;

    // These overload the non-const constructor and are **only** enabled
    // when the type is const.
    template <bool is_immut = is_const, std::enable_if_t<is_immut>* = nullptr>
    bitvec_iterator(const bitvec_iterator<little_endian, false>& x):
        bitvec_iterator(x.ptr_, x.bit_)
    {}

    template <bool is_immut = is_const>
    std::enable_if_t<is_immut, self_t&>
    operator=(const bitvec_iterator<little_endian, false>& x) {
        ptr_ = x.ptr_;
        bit_ = x.bit_;
    }

    template <bool is_immut = is_const, std::enable_if_t<is_immut>* = nullptr>
    bitvec_iterator(bitvec_iterator<little_endian, false>&& x):
        bitvec_iterator(x.ptr_, x.bit_)
    {
        ptr_ = nullptr;
        bit_ = 0;
    }

    template <bool is_immut = is_const>
    std::enable_if_t<is_immut, self_t&>
    operator=(bitvec_iterator<little_endian, false>&& x) {
        ptr_ = x.ptr_;
        bit_ = x.bit_;
        ptr_ = nullptr;
        bit_ = 0;
    }

    // OPERATORS
    // Relative operators.
    // Implement in terms of std::make_tuple(ptr, bit)
    bool operator==(const self_t& x) const {
        return std::make_tuple(ptr_, bit_) == std::make_tuple(x.ptr_, x.bit_);
    }

    bool operator!=(const self_t& x) const {
        return std::make_tuple(ptr_, bit_) != std::make_tuple(x.ptr_, x.bit_);
    }

    bool operator<(const self_t& x) const {
        return std::make_tuple(ptr_, bit_) < std::make_tuple(x.ptr_, x.bit_);
    }

    bool operator<=(const self_t& x) const {
        return std::make_tuple(ptr_, bit_) <= std::make_tuple(x.ptr_, x.bit_);
    }

    bool operator>(const self_t& x) const {
        return std::make_tuple(ptr_, bit_) > std::make_tuple(x.ptr_, x.bit_);
    }

    bool operator>=(const self_t& x) const {
        return std::make_tuple(ptr_, bit_) >= std::make_tuple(x.ptr_, x.bit_);
    }

    // Deref operators
    reference operator*() const noexcept {
        return bit_reference(ptr_, bit_);
    }

    // Pre and post-increment operators.
    // Go from lsb to msb, bytes are ordering in increasing importance
    // with little-endian.
    template <bool endian = little_endian>
    std::enable_if_t<endian, self_t&>
    operator++() {
        if (bit_ == 7) {
            ptr_++;
            bit_ = 0;
        } else {
            bit_++;
        }
        return *this;
    }

    // Go from lsb to msb, bytes are ordering in decreasing importance
    // with big-endian.
    template <bool endian = little_endian>
    std::enable_if_t<!endian, self_t&>
    operator++() {
        if (bit_ == 7) {
            ptr_--;
            bit_ = 0;
        } else {
            bit_++;
        }
        return *this;
    }

    self_t operator++(int) {
        self_t copy(*this);
        ++(*this);
        return copy;
    }

    // Pre and post-decrement operators.

    // Go from msb to lsb, bytes are ordering in increasing importance
    // with little-endian.
    template <bool endian = little_endian>
    std::enable_if_t<endian, self_t&>
    operator--() {
        if (bit_ == 0) {
            ptr_--;
            bit_ = 7;
        } else {
            bit_--;
        }
        return *this;
    }

    // Go from msb to lsb, bytes are ordering in decreasing importance
    // with big-endian.
    template <bool endian = little_endian>
    std::enable_if_t<!endian, self_t&>
    operator--() {
        if (bit_ == 0) {
            ptr_++;
            bit_ = 7;
        } else {
            bit_--;
        }
        return *this;
    }

    self_t operator--(int) {
        self_t copy(*this);
        --(*this);
        return copy;
    }

    // Increment or decrement pointers by number of bits.
    template <bool endian = little_endian>
    std::enable_if_t<endian, self_t&>
    operator+=(difference_type n) {
        difference_type v = n + bit_;
        ptr_ += v / 8;
        bit_ = v % 8;
    }

    template <bool endian = little_endian>
    std::enable_if_t<!endian, self_t&>
    operator+=(difference_type n) {
        difference_type v = n + bit_;
        ptr_ -= v / 8;
        bit_ = v % 8;
    }

    self_t& operator-=(difference_type n) {
        operator+=(-n);
    }

    self_t operator+(difference_type n) {
        self_t copy(*this);
        copy += n;
        return copy;
    }

    self_t operator-(difference_type n) {
        self_t copy(*this);
        copy -= n;
        return copy;
    }

    // Index by number of bits.
    reference operator[](difference_type n) const {
        self_t copy(*this);
        copy += n;
        return *copy;
    }

    // Get distance between two iterators.
    difference_type operator-(const bitvec_iterator& x) {
        auto bytes = ptr_ - x.ptr_;
        auto bits = bit_ - x.bit_;
        return 8 * bytes + bits;
    }

private:
    uint8_t* ptr_;
    uint32_t bit_;

public:
    // Constructor with ptr and bit.
    bitvec_iterator(uint8_t* ptr, uint32_t bit):
        ptr_(ptr),
        bit_(bit)
    {}
};


#include <iostream>


int main() {
    using iterator = bitvec_iterator<true, true>;
    uint8_t x[4] = {32, 164, 1, 0};
    iterator first(x, 0);
    iterator last(x+4, 0);

    uint32_t counter = 0;
    for (auto it = first; it != last; ++it) {
        std::cout << "bit: " << bool(*it) << ", count: " << counter << "\n";
        counter++;
    }

    return 0;
}

#endif//0
