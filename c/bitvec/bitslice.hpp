#ifndef BITVEC_FFI_BITSLICE_HPP
#define BITVEC_FFI_BITSLICE_HPP

#include <cstddef>
#include <cstdint>

#include <array>
#include <type_traits>
#include <utility>

#include <bitvec/bitslice.h>

namespace bitvec {

namespace func {
namespace bs {

//  JUMP TABLES
//
//  These tables are used to multiplex template-class method instantiations to
//  the correct C-API boundary function. These tables cannot be observed or used
//  outside this module, and are removed from the compiled output.

using from_span_t = auto(BitPtrImmut *, void const *, std::size_t) -> bool;
static auto const from_span = std::array<from_span_t *, 8>{{
	reinterpret_cast<from_span_t *>(bitvec_bs_b08_from_span),
	reinterpret_cast<from_span_t *>(bitvec_bs_l08_from_span),
	reinterpret_cast<from_span_t *>(bitvec_bs_b16_from_span),
	reinterpret_cast<from_span_t *>(bitvec_bs_l16_from_span),
	reinterpret_cast<from_span_t *>(bitvec_bs_b32_from_span),
	reinterpret_cast<from_span_t *>(bitvec_bs_l32_from_span),
	reinterpret_cast<from_span_t *>(bitvec_bs_b64_from_span),
	reinterpret_cast<from_span_t *>(bitvec_bs_l64_from_span),
}};

using from_span_mut_t = auto(BitPtrMut *, void *, std::size_t) -> bool;
static auto const from_span_mut = std::array<from_span_mut_t *, 8>{{
	reinterpret_cast<from_span_mut_t *>(bitvec_bs_b08_from_span_mut),
	reinterpret_cast<from_span_mut_t *>(bitvec_bs_l08_from_span_mut),
	reinterpret_cast<from_span_mut_t *>(bitvec_bs_b16_from_span_mut),
	reinterpret_cast<from_span_mut_t *>(bitvec_bs_l16_from_span_mut),
	reinterpret_cast<from_span_mut_t *>(bitvec_bs_b32_from_span_mut),
	reinterpret_cast<from_span_mut_t *>(bitvec_bs_l32_from_span_mut),
	reinterpret_cast<from_span_mut_t *>(bitvec_bs_b64_from_span_mut),
	reinterpret_cast<from_span_mut_t *>(bitvec_bs_l64_from_span_mut),
}};

using from_span_partial_t = auto(BitPtrImmut *, void const *, std::size_t, std::uint8_t, std::uint8_t) -> bool;
static auto const from_span_partial = std::array<from_span_partial_t *, 8>{{
	reinterpret_cast<from_span_partial_t *>(bitvec_bs_b08_from_span_partial),
	reinterpret_cast<from_span_partial_t *>(bitvec_bs_l08_from_span_partial),
	reinterpret_cast<from_span_partial_t *>(bitvec_bs_b16_from_span_partial),
	reinterpret_cast<from_span_partial_t *>(bitvec_bs_l16_from_span_partial),
	reinterpret_cast<from_span_partial_t *>(bitvec_bs_b32_from_span_partial),
	reinterpret_cast<from_span_partial_t *>(bitvec_bs_l32_from_span_partial),
	reinterpret_cast<from_span_partial_t *>(bitvec_bs_b64_from_span_partial),
	reinterpret_cast<from_span_partial_t *>(bitvec_bs_l64_from_span_partial),
}};

using from_span_partial_mut_t = auto(BitPtrMut *, void *, std::size_t, std::uint8_t, std::uint8_t) -> bool;
static auto const from_span_partial_mut = std::array<from_span_partial_mut_t *, 8>{{
	reinterpret_cast<from_span_partial_mut_t *>(bitvec_bs_b08_from_span_partial_mut),
	reinterpret_cast<from_span_partial_mut_t *>(bitvec_bs_l08_from_span_partial_mut),
	reinterpret_cast<from_span_partial_mut_t *>(bitvec_bs_b16_from_span_partial_mut),
	reinterpret_cast<from_span_partial_mut_t *>(bitvec_bs_l16_from_span_partial_mut),
	reinterpret_cast<from_span_partial_mut_t *>(bitvec_bs_b32_from_span_partial_mut),
	reinterpret_cast<from_span_partial_mut_t *>(bitvec_bs_l32_from_span_partial_mut),
	reinterpret_cast<from_span_partial_mut_t *>(bitvec_bs_b64_from_span_partial_mut),
	reinterpret_cast<from_span_partial_mut_t *>(bitvec_bs_l64_from_span_partial_mut),
}};

using empty_t = void(BitPtrImmut *);
static auto const empty = std::array<empty_t *, 8>{{
	reinterpret_cast<empty_t *>(bitvec_bs_b08_empty),
	reinterpret_cast<empty_t *>(bitvec_bs_l08_empty),
	reinterpret_cast<empty_t *>(bitvec_bs_b16_empty),
	reinterpret_cast<empty_t *>(bitvec_bs_l16_empty),
	reinterpret_cast<empty_t *>(bitvec_bs_b32_empty),
	reinterpret_cast<empty_t *>(bitvec_bs_l32_empty),
	reinterpret_cast<empty_t *>(bitvec_bs_b64_empty),
	reinterpret_cast<empty_t *>(bitvec_bs_l64_empty),
}};

using empty_mut_t = void(BitPtrMut *);
static auto const empty_mut = std::array<empty_mut_t *, 8>{{
	reinterpret_cast<empty_mut_t *>(bitvec_bs_b08_empty_mut),
	reinterpret_cast<empty_mut_t *>(bitvec_bs_l08_empty_mut),
	reinterpret_cast<empty_mut_t *>(bitvec_bs_b16_empty_mut),
	reinterpret_cast<empty_mut_t *>(bitvec_bs_l16_empty_mut),
	reinterpret_cast<empty_mut_t *>(bitvec_bs_b32_empty_mut),
	reinterpret_cast<empty_mut_t *>(bitvec_bs_l32_empty_mut),
	reinterpret_cast<empty_mut_t *>(bitvec_bs_b64_empty_mut),
	reinterpret_cast<empty_mut_t *>(bitvec_bs_l64_empty_mut),
}};

using len_t = auto(BitPtrImmut const *) -> std::size_t;
static auto const len = std::array<len_t *, 8> {{
	reinterpret_cast<len_t *>(bitvec_bs_b08_len),
	reinterpret_cast<len_t *>(bitvec_bs_l08_len),
	reinterpret_cast<len_t *>(bitvec_bs_b16_len),
	reinterpret_cast<len_t *>(bitvec_bs_l16_len),
	reinterpret_cast<len_t *>(bitvec_bs_b32_len),
	reinterpret_cast<len_t *>(bitvec_bs_l32_len),
	reinterpret_cast<len_t *>(bitvec_bs_b64_len),
	reinterpret_cast<len_t *>(bitvec_bs_l64_len),
}};

using is_empty_t = auto(BitPtrImmut const *) -> Tristate;
static auto const is_empty = std::array<is_empty_t *, 8>{{
	reinterpret_cast<is_empty_t *>(bitvec_bs_b08_is_empty),
	reinterpret_cast<is_empty_t *>(bitvec_bs_l08_is_empty),
	reinterpret_cast<is_empty_t *>(bitvec_bs_b16_is_empty),
	reinterpret_cast<is_empty_t *>(bitvec_bs_l16_is_empty),
	reinterpret_cast<is_empty_t *>(bitvec_bs_b32_is_empty),
	reinterpret_cast<is_empty_t *>(bitvec_bs_l32_is_empty),
	reinterpret_cast<is_empty_t *>(bitvec_bs_b64_is_empty),
	reinterpret_cast<is_empty_t *>(bitvec_bs_l64_is_empty),
}};

using first_t = auto(BitPtrImmut const *) -> Tristate;
static auto const first = std::array<first_t *, 8>{{
	reinterpret_cast<first_t *>(bitvec_bs_b08_first),
	reinterpret_cast<first_t *>(bitvec_bs_l08_first),
	reinterpret_cast<first_t *>(bitvec_bs_b16_first),
	reinterpret_cast<first_t *>(bitvec_bs_l16_first),
	reinterpret_cast<first_t *>(bitvec_bs_b32_first),
	reinterpret_cast<first_t *>(bitvec_bs_l32_first),
	reinterpret_cast<first_t *>(bitvec_bs_b64_first),
	reinterpret_cast<first_t *>(bitvec_bs_l64_first),
}};

using split_first_t = auto(BitPtrImmut *) -> Tristate;
static auto const split_first = std::array<split_first_t *, 8>{{
	reinterpret_cast<split_first_t *>(bitvec_bs_b08_split_first),
	reinterpret_cast<split_first_t *>(bitvec_bs_l08_split_first),
	reinterpret_cast<split_first_t *>(bitvec_bs_b16_split_first),
	reinterpret_cast<split_first_t *>(bitvec_bs_l16_split_first),
	reinterpret_cast<split_first_t *>(bitvec_bs_b32_split_first),
	reinterpret_cast<split_first_t *>(bitvec_bs_l32_split_first),
	reinterpret_cast<split_first_t *>(bitvec_bs_b64_split_first),
	reinterpret_cast<split_first_t *>(bitvec_bs_l64_split_first),
}};

using split_last_t = auto(BitPtrImmut *) -> Tristate;
static auto const split_last = std::array<split_last_t *, 8>{{
	reinterpret_cast<split_last_t *>(bitvec_bs_b08_split_last),
	reinterpret_cast<split_last_t *>(bitvec_bs_l08_split_last),
	reinterpret_cast<split_last_t *>(bitvec_bs_b16_split_last),
	reinterpret_cast<split_last_t *>(bitvec_bs_l16_split_last),
	reinterpret_cast<split_last_t *>(bitvec_bs_b32_split_last),
	reinterpret_cast<split_last_t *>(bitvec_bs_l32_split_last),
	reinterpret_cast<split_last_t *>(bitvec_bs_b64_split_last),
	reinterpret_cast<split_last_t *>(bitvec_bs_l64_split_last),
}};

using last_t = auto(BitPtrImmut const *) -> Tristate;
static auto const last = std::array<last_t *, 8>{{
	reinterpret_cast<last_t *>(bitvec_bs_b08_last),
	reinterpret_cast<last_t *>(bitvec_bs_l08_last),
	reinterpret_cast<last_t *>(bitvec_bs_b16_last),
	reinterpret_cast<last_t *>(bitvec_bs_l16_last),
	reinterpret_cast<last_t *>(bitvec_bs_b32_last),
	reinterpret_cast<last_t *>(bitvec_bs_l32_last),
	reinterpret_cast<last_t *>(bitvec_bs_b64_last),
	reinterpret_cast<last_t *>(bitvec_bs_l64_last),
}};

using get_t = auto(BitPtrImmut const *, std::size_t) -> Tristate;
static auto const get = std::array<get_t *, 8>{{
	reinterpret_cast<get_t *>(bitvec_bs_b08_get),
	reinterpret_cast<get_t *>(bitvec_bs_l08_get),
	reinterpret_cast<get_t *>(bitvec_bs_b16_get),
	reinterpret_cast<get_t *>(bitvec_bs_l16_get),
	reinterpret_cast<get_t *>(bitvec_bs_b32_get),
	reinterpret_cast<get_t *>(bitvec_bs_l32_get),
	reinterpret_cast<get_t *>(bitvec_bs_b64_get),
	reinterpret_cast<get_t *>(bitvec_bs_l64_get),
}};

using set_t = void(BitPtrMut const *, std::size_t, bool);
static auto const set = std::array<set_t *, 8>{{
	reinterpret_cast<set_t *>(bitvec_bs_b08_set),
	reinterpret_cast<set_t *>(bitvec_bs_l08_set),
	reinterpret_cast<set_t *>(bitvec_bs_b16_set),
	reinterpret_cast<set_t *>(bitvec_bs_l16_set),
	reinterpret_cast<set_t *>(bitvec_bs_b32_set),
	reinterpret_cast<set_t *>(bitvec_bs_l32_set),
	reinterpret_cast<set_t *>(bitvec_bs_b64_set),
	reinterpret_cast<set_t *>(bitvec_bs_l64_set),
}};

using as_ptr_t = auto(BitPtrImmut const *) -> void const *;
static auto const as_ptr = std::array<as_ptr_t *, 8>{{
	reinterpret_cast<as_ptr_t *>(bitvec_bs_b08_as_ptr),
	reinterpret_cast<as_ptr_t *>(bitvec_bs_l08_as_ptr),
	reinterpret_cast<as_ptr_t *>(bitvec_bs_b16_as_ptr),
	reinterpret_cast<as_ptr_t *>(bitvec_bs_l16_as_ptr),
	reinterpret_cast<as_ptr_t *>(bitvec_bs_b32_as_ptr),
	reinterpret_cast<as_ptr_t *>(bitvec_bs_l32_as_ptr),
	reinterpret_cast<as_ptr_t *>(bitvec_bs_b64_as_ptr),
	reinterpret_cast<as_ptr_t *>(bitvec_bs_l64_as_ptr),
}};

using as_mut_ptr_t = auto(BitPtrMut const *) -> void *;
static auto const as_mut_ptr = std::array<as_mut_ptr_t *, 8>{{
	reinterpret_cast<as_mut_ptr_t *>(bitvec_bs_b08_as_mut_ptr),
	reinterpret_cast<as_mut_ptr_t *>(bitvec_bs_l08_as_mut_ptr),
	reinterpret_cast<as_mut_ptr_t *>(bitvec_bs_b16_as_mut_ptr),
	reinterpret_cast<as_mut_ptr_t *>(bitvec_bs_l16_as_mut_ptr),
	reinterpret_cast<as_mut_ptr_t *>(bitvec_bs_b32_as_mut_ptr),
	reinterpret_cast<as_mut_ptr_t *>(bitvec_bs_l32_as_mut_ptr),
	reinterpret_cast<as_mut_ptr_t *>(bitvec_bs_b64_as_mut_ptr),
	reinterpret_cast<as_mut_ptr_t *>(bitvec_bs_l64_as_mut_ptr),
}};

using swap_t = void(BitPtrMut const *, std::size_t, std::size_t);
static auto const swap = std::array<swap_t *, 8>{{
	reinterpret_cast<swap_t *>(bitvec_bs_b08_swap),
	reinterpret_cast<swap_t *>(bitvec_bs_l08_swap),
	reinterpret_cast<swap_t *>(bitvec_bs_b16_swap),
	reinterpret_cast<swap_t *>(bitvec_bs_l16_swap),
	reinterpret_cast<swap_t *>(bitvec_bs_b32_swap),
	reinterpret_cast<swap_t *>(bitvec_bs_l32_swap),
	reinterpret_cast<swap_t *>(bitvec_bs_b64_swap),
	reinterpret_cast<swap_t *>(bitvec_bs_l64_swap),
}};

using reverse_t = void(BitPtrMut const *);
static auto const reverse = std::array<reverse_t *, 8>{{
	reinterpret_cast<reverse_t *>(bitvec_bs_b08_reverse),
	reinterpret_cast<reverse_t *>(bitvec_bs_l08_reverse),
	reinterpret_cast<reverse_t *>(bitvec_bs_b16_reverse),
	reinterpret_cast<reverse_t *>(bitvec_bs_l16_reverse),
	reinterpret_cast<reverse_t *>(bitvec_bs_b32_reverse),
	reinterpret_cast<reverse_t *>(bitvec_bs_l32_reverse),
	reinterpret_cast<reverse_t *>(bitvec_bs_b64_reverse),
	reinterpret_cast<reverse_t *>(bitvec_bs_l64_reverse),
}};

using split_at_t = auto(BitPtrImmut *, BitPtrImmut *, std::size_t) -> bool;
static auto const split_at = std::array<split_at_t *, 8>{{
	reinterpret_cast<split_at_t *>(bitvec_bs_b08_split_at),
	reinterpret_cast<split_at_t *>(bitvec_bs_l08_split_at),
	reinterpret_cast<split_at_t *>(bitvec_bs_b16_split_at),
	reinterpret_cast<split_at_t *>(bitvec_bs_l16_split_at),
	reinterpret_cast<split_at_t *>(bitvec_bs_b32_split_at),
	reinterpret_cast<split_at_t *>(bitvec_bs_l32_split_at),
	reinterpret_cast<split_at_t *>(bitvec_bs_b64_split_at),
	reinterpret_cast<split_at_t *>(bitvec_bs_l64_split_at),
}};

using split_at_mut_t = auto(BitPtrMut *, BitPtrMut *, std::size_t) -> bool;
static auto const split_at_mut = std::array<split_at_mut_t *, 8>{{
	reinterpret_cast<split_at_mut_t *>(bitvec_bs_b08_split_at_mut),
	reinterpret_cast<split_at_mut_t *>(bitvec_bs_l08_split_at_mut),
	reinterpret_cast<split_at_mut_t *>(bitvec_bs_b16_split_at_mut),
	reinterpret_cast<split_at_mut_t *>(bitvec_bs_l16_split_at_mut),
	reinterpret_cast<split_at_mut_t *>(bitvec_bs_b32_split_at_mut),
	reinterpret_cast<split_at_mut_t *>(bitvec_bs_l32_split_at_mut),
	reinterpret_cast<split_at_mut_t *>(bitvec_bs_b64_split_at_mut),
	reinterpret_cast<split_at_mut_t *>(bitvec_bs_l64_split_at_mut),
}};

using rotate_left_t = void(BitPtrMut const *, std::size_t);
static auto const rotate_left = std::array<rotate_left_t *, 8>{{
	reinterpret_cast<rotate_left_t *>(bitvec_bs_b08_rotate_left),
	reinterpret_cast<rotate_left_t *>(bitvec_bs_l08_rotate_left),
	reinterpret_cast<rotate_left_t *>(bitvec_bs_b16_rotate_left),
	reinterpret_cast<rotate_left_t *>(bitvec_bs_l16_rotate_left),
	reinterpret_cast<rotate_left_t *>(bitvec_bs_b32_rotate_left),
	reinterpret_cast<rotate_left_t *>(bitvec_bs_l32_rotate_left),
	reinterpret_cast<rotate_left_t *>(bitvec_bs_b64_rotate_left),
	reinterpret_cast<rotate_left_t *>(bitvec_bs_l64_rotate_left),
}};

using rotate_right_t = void(BitPtrMut const *, std::size_t);
static auto const rotate_right = std::array<rotate_right_t *, 8>{{
	reinterpret_cast<rotate_right_t *>(bitvec_bs_b08_rotate_right),
	reinterpret_cast<rotate_right_t *>(bitvec_bs_l08_rotate_right),
	reinterpret_cast<rotate_right_t *>(bitvec_bs_b16_rotate_right),
	reinterpret_cast<rotate_right_t *>(bitvec_bs_l16_rotate_right),
	reinterpret_cast<rotate_right_t *>(bitvec_bs_b32_rotate_right),
	reinterpret_cast<rotate_right_t *>(bitvec_bs_l32_rotate_right),
	reinterpret_cast<rotate_right_t *>(bitvec_bs_b64_rotate_right),
	reinterpret_cast<rotate_right_t *>(bitvec_bs_l64_rotate_right),
}};

using all_t = auto(BitPtrImmut const *) -> bool;
static auto const all = std::array<all_t *, 8>{{
	reinterpret_cast<all_t *>(bitvec_bs_b08_all),
	reinterpret_cast<all_t *>(bitvec_bs_l08_all),
	reinterpret_cast<all_t *>(bitvec_bs_b16_all),
	reinterpret_cast<all_t *>(bitvec_bs_l16_all),
	reinterpret_cast<all_t *>(bitvec_bs_b32_all),
	reinterpret_cast<all_t *>(bitvec_bs_l32_all),
	reinterpret_cast<all_t *>(bitvec_bs_b64_all),
	reinterpret_cast<all_t *>(bitvec_bs_l64_all),
}};

using any_t = auto(BitPtrImmut const *) -> bool;
static auto const any = std::array<any_t *, 8>{{
	reinterpret_cast<any_t *>(bitvec_bs_b08_any),
	reinterpret_cast<any_t *>(bitvec_bs_l08_any),
	reinterpret_cast<any_t *>(bitvec_bs_b16_any),
	reinterpret_cast<any_t *>(bitvec_bs_l16_any),
	reinterpret_cast<any_t *>(bitvec_bs_b32_any),
	reinterpret_cast<any_t *>(bitvec_bs_l32_any),
	reinterpret_cast<any_t *>(bitvec_bs_b64_any),
	reinterpret_cast<any_t *>(bitvec_bs_l64_any),
}};

using not_all_t = auto(BitPtrImmut const *) -> bool;
static auto const not_all = std::array<not_all_t *, 8>{{
	reinterpret_cast<not_all_t *>(bitvec_bs_b08_not_all),
	reinterpret_cast<not_all_t *>(bitvec_bs_l08_not_all),
	reinterpret_cast<not_all_t *>(bitvec_bs_b16_not_all),
	reinterpret_cast<not_all_t *>(bitvec_bs_l16_not_all),
	reinterpret_cast<not_all_t *>(bitvec_bs_b32_not_all),
	reinterpret_cast<not_all_t *>(bitvec_bs_l32_not_all),
	reinterpret_cast<not_all_t *>(bitvec_bs_b64_not_all),
	reinterpret_cast<not_all_t *>(bitvec_bs_l64_not_all),
}};

using not_any_t = auto(BitPtrImmut const *) -> bool;
static auto const not_any = std::array<not_any_t *, 8>{{
	reinterpret_cast<not_any_t *>(bitvec_bs_b08_not_any),
	reinterpret_cast<not_any_t *>(bitvec_bs_l08_not_any),
	reinterpret_cast<not_any_t *>(bitvec_bs_b16_not_any),
	reinterpret_cast<not_any_t *>(bitvec_bs_l16_not_any),
	reinterpret_cast<not_any_t *>(bitvec_bs_b32_not_any),
	reinterpret_cast<not_any_t *>(bitvec_bs_l32_not_any),
	reinterpret_cast<not_any_t *>(bitvec_bs_b64_not_any),
	reinterpret_cast<not_any_t *>(bitvec_bs_l64_not_any),
}};

using some_t = auto(BitPtrImmut const *) -> bool;
static auto const some = std::array<some_t *, 8>{{
	reinterpret_cast<some_t *>(bitvec_bs_b08_some),
	reinterpret_cast<some_t *>(bitvec_bs_l08_some),
	reinterpret_cast<some_t *>(bitvec_bs_b16_some),
	reinterpret_cast<some_t *>(bitvec_bs_l16_some),
	reinterpret_cast<some_t *>(bitvec_bs_b32_some),
	reinterpret_cast<some_t *>(bitvec_bs_l32_some),
	reinterpret_cast<some_t *>(bitvec_bs_b64_some),
	reinterpret_cast<some_t *>(bitvec_bs_l64_some),
}};

using count_ones_t = auto(BitPtrImmut const *) -> std::size_t;
static auto const count_ones = std::array<count_ones_t *, 8>{{
	reinterpret_cast<count_ones_t *>(bitvec_bs_b08_count_ones),
	reinterpret_cast<count_ones_t *>(bitvec_bs_l08_count_ones),
	reinterpret_cast<count_ones_t *>(bitvec_bs_b16_count_ones),
	reinterpret_cast<count_ones_t *>(bitvec_bs_l16_count_ones),
	reinterpret_cast<count_ones_t *>(bitvec_bs_b32_count_ones),
	reinterpret_cast<count_ones_t *>(bitvec_bs_l32_count_ones),
	reinterpret_cast<count_ones_t *>(bitvec_bs_b64_count_ones),
	reinterpret_cast<count_ones_t *>(bitvec_bs_l64_count_ones),
}};

using count_zeros_t = auto(BitPtrImmut const *) -> std::size_t;
static auto const count_zeros = std::array<count_zeros_t *, 8>{{
	reinterpret_cast<count_zeros_t *>(bitvec_bs_b08_count_zeros),
	reinterpret_cast<count_zeros_t *>(bitvec_bs_l08_count_zeros),
	reinterpret_cast<count_zeros_t *>(bitvec_bs_b16_count_zeros),
	reinterpret_cast<count_zeros_t *>(bitvec_bs_l16_count_zeros),
	reinterpret_cast<count_zeros_t *>(bitvec_bs_b32_count_zeros),
	reinterpret_cast<count_zeros_t *>(bitvec_bs_l32_count_zeros),
	reinterpret_cast<count_zeros_t *>(bitvec_bs_b64_count_zeros),
	reinterpret_cast<count_zeros_t *>(bitvec_bs_l64_count_zeros),
}};

using set_all_t = void(BitPtrMut const *, bool);
static auto const set_all = std::array<set_all_t *, 8>{{
	reinterpret_cast<set_all_t *>(bitvec_bs_b08_set_all),
	reinterpret_cast<set_all_t *>(bitvec_bs_l08_set_all),
	reinterpret_cast<set_all_t *>(bitvec_bs_b16_set_all),
	reinterpret_cast<set_all_t *>(bitvec_bs_l16_set_all),
	reinterpret_cast<set_all_t *>(bitvec_bs_b32_set_all),
	reinterpret_cast<set_all_t *>(bitvec_bs_l32_set_all),
	reinterpret_cast<set_all_t *>(bitvec_bs_b64_set_all),
	reinterpret_cast<set_all_t *>(bitvec_bs_l64_set_all),
}};

using as_slice_t = auto(BitPtrImmut const *, std::size_t *) -> void const *;
static auto const as_slice = std::array<as_slice_t *, 8>{{
	reinterpret_cast<as_slice_t *>(bitvec_bs_b08_as_slice),
	reinterpret_cast<as_slice_t *>(bitvec_bs_l08_as_slice),
	reinterpret_cast<as_slice_t *>(bitvec_bs_b16_as_slice),
	reinterpret_cast<as_slice_t *>(bitvec_bs_l16_as_slice),
	reinterpret_cast<as_slice_t *>(bitvec_bs_b32_as_slice),
	reinterpret_cast<as_slice_t *>(bitvec_bs_l32_as_slice),
	reinterpret_cast<as_slice_t *>(bitvec_bs_b64_as_slice),
	reinterpret_cast<as_slice_t *>(bitvec_bs_l64_as_slice),
}};

using as_mut_slice_t = auto(BitPtrMut const *, std::size_t *) -> void *;
static auto const as_mut_slice = std::array<as_mut_slice_t *, 8>{{
	reinterpret_cast<as_mut_slice_t *>(bitvec_bs_b08_as_mut_slice),
	reinterpret_cast<as_mut_slice_t *>(bitvec_bs_l08_as_mut_slice),
	reinterpret_cast<as_mut_slice_t *>(bitvec_bs_b16_as_mut_slice),
	reinterpret_cast<as_mut_slice_t *>(bitvec_bs_l16_as_mut_slice),
	reinterpret_cast<as_mut_slice_t *>(bitvec_bs_b32_as_mut_slice),
	reinterpret_cast<as_mut_slice_t *>(bitvec_bs_l32_as_mut_slice),
	reinterpret_cast<as_mut_slice_t *>(bitvec_bs_b64_as_mut_slice),
	reinterpret_cast<as_mut_slice_t *>(bitvec_bs_l64_as_mut_slice),
}};

} // namespace bs
} // namespace func

/**
 * @enum Cursor
 *
 * @brief Selects the bit ordering cursor for bit handles to use.
 */
enum class Cursor : bool {
	/// Big-endian bit ordering: increases indices from MSb to LSb.
	BigEndian = 0,
	/// Little-endian bit ordering: increases indices from LSb to MSb.
	LittleEndian = 1,
};

namespace impl {

/**
 * @brief Multiplexes a templated function call to the correct concrete binding.
 *
 * @param funcs A table of functions over which to perform dispatch.
 * @param args The set of arguments to be passed to the dispatched function.
 * @return The return value of the dispatched function.
 *
 * Type parameters:
 *
 * `Cursor C`: The cursor type parameter of the handle class calling this.
 * `class T`: The storage type parameter of the handle class calling this. This
 * type must satisfy `std::is_integral`.
 * `class Ret`: The return type of the dispatched function.
 * `class... Params`: The parameter types of the dispatched function.
 * `class... Args`: The argument types of the arguments given to the mux call.
 *
 * Operation:
 *
 * This function computes a fixed offset in a dispatch table from the `Cursor C`
 * and `class T` type parameters, then forwards all its remaining arguments to
 * the selected function from the dispatch table. The return value of the
 * dispatched function is the return value of the mux call.
 */
template <Cursor C, class T, class Ret, class... Params, class... Args>
auto mux(
	std::array<auto (*)(Params...) noexcept -> Ret, 8> const& funcs,
	Args&&... args
) noexcept -> Ret {
	constexpr auto index =
		(static_cast<std::size_t>(__builtin_ctzll(sizeof(T))) << 1)
		|static_cast<std::size_t>(C);

	return funcs[index](std::forward<Args>(args)...);
}

/**
 * @brief Freeze a const-handle-mutable-bits to a const-handle-const-bits.
 */
static BitPtrImmut const * make_immut(BitPtrMut const * bp) {
	return reinterpret_cast<BitPtrImmut const *>(bp);
}

/**
 * @brief Freeze a const-handle-const-bits to itself.
 */
static BitPtrImmut const * make_immut(BitPtrImmut const * bp) {
	return bp;
}

/**
 * @brief Freeze a mutable-handle-mutable-bits to a mutable-handle-const bits.
 */
static BitPtrImmut * make_immut(BitPtrMut * bp) {
	return reinterpret_cast<BitPtrImmut *>(bp);
}

/**
 * @brief Freeze a mutable-handle-const-bits to itself.
 */
static BitPtrImmut * make_immut(BitPtrImmut * bp) {
	return bp;
}

} // namespace impl

/**
 * @class BitSlice
 *
 * @brief Handle to a collection of ordered bits, without any memory management.
 *
 * This handle does NOT own the memory it governs, and WILL NOT attempt to
 * deallocate it on destruction.
 *
 * When it is constructed from `T const *` pointers to `const` data, it is
 * copyable; when constructed from `T *` pointers to mutable data, it is *not*.
 *
 * The eight valid instances of this class are:
 *
 * - `BitSlice<Cursor::BigEndian,    uint8_t >`
 * - `BitSlice<Cursor::LittleEndian, uint8_t >`
 * - `BitSlice<Cursor::BigEndian,    uint16_t>`
 * - `BitSlice<Cursor::LittleEndian, uint16_t>`
 * - `BitSlice<Cursor::BigEndian,    uint32_t>`
 * - `BitSlice<Cursor::LittleEndian, uint32_t>`
 * - `BitSlice<Cursor::BigEndian,    uint64_t>`
 * - `BitSlice<Cursor::LittleEndian, uint64_t>`
 */
template <Cursor C, class T>
class BitSlice : public std::conditional<
	std::is_const<T>::value,
	BitPtrImmut,
	BitPtrMut
>::type {
	static_assert(
		std::is_integral<T>::value && std::is_unsigned<T>::value,
		"BitSlice can only be constructed with unsigned integral storage types"
	);
public:
	/**
	 * @brief Default constructor for the slice handle. Produces an empty slice.
	 */
	explicit BitSlice(void) noexcept {
		impl::mux<C, T>(func::bs::empty, impl::make_immut(this));
	}

	/**
	 * @brief Standard constructor for the slice handle. Produces a slice of
	 * constant bits.
	 * @param ptr Pointer to the domain over which the slice will govern.
	 * @param len Element count (not bytes) of the domain.
	 */
	BitSlice(T const * ptr, std::size_t const len) noexcept {
		if (not impl::mux<C, T>(
			func::bs::from_span, impl::make_immut(this), ptr, len
		)) {
			*this = BitSlice();
		}
	}

	/**
	 * @brief Standard constructor for the slice handle. Produces a slice of
	 * mutable bits.
	 * @param ptr Pointer to the domain over which the slice will govern.
	 * @param len Element count (not bytes) of the domain.
	 */
	BitSlice(T * ptr, std::size_t const len) noexcept {
		if (not impl::mux<C, T>(
			func::bs::from_span_mut, this, ptr, len
		)) {
			*this = BitSlice();
		}
	}

	/**
	 * @brief Detailed constructor for the slice handle. Produces a slice of
	 * constant bits.
	 * @param ptr Pointer to the domain over which the slice will govern.
	 * @param len Element count (not bytes) of the domain.
	 * @param head Index of the first live bit in the first element.
	 * @param tail Index of the first dead bit in the last element.
	 */
	BitSlice(
		T const * ptr,
		std::size_t const len,
		std::uint8_t const head,
		std::uint8_t const tail
	) noexcept {
		if (not impl::mux<C, T>(
			func::bs::from_span_partial,
			impl::make_immut(this),
			ptr, len, head, tail
		)) {
			*this = BitSlice(ptr, len);
		}
	}

	/**
	 * @brief Detailed constructor for the slice handle. Produces a slice of
	 * mutable bits.
	 * @param ptr Pointer to the domain over which the slice will govern.
	 * @param len Element count (not bytes) of the domain.
	 * @param head Index of the first live bit in the first element.
	 * @param tail Index of the first dead bit in the last element.
	 */
	BitSlice(
		T * ptr,
		std::size_t const len,
		std::uint8_t const head,
		std::uint8_t const tail
	) noexcept {
		if (not impl::mux<C, T>(
			func::bs::from_span_partial_mut, this, ptr, len, head, tail
		)) {
			*this = BitSlice(ptr, len);
		}
	}

	/**
	 * @brief Copy constructor.
	 * @param other `BitSlice` to duplicate.
	 */
	BitSlice(BitSlice const& other) noexcept {
		*this = other;
	}

	/**
	 * @brief Copy assignment operator,
	 * @param other `BitSlice` from to duplicate.
	 */
	BitSlice& operator=(BitSlice const& other) noexcept {
		if (&other != this) {
			*impl::make_immut(this) = *impl::make_immut(&other);
		}
		return *this;
	}

	/**
	 * @brief Gets the length, in bits, of the slice.
	 * @return The length, in bits, of the slice.
	 */
	size_t size(void) const noexcept {
		return impl::mux<C, T>(func::bs::len, impl::make_immut(this));
	}

	/**
	 * @brief Tests if the slice is empty.
	 * @return Whether the slice is empty.
	 * @retval `true` The slice is empty (`size() == 0`).
	 * @retval `false` The slice is not empty (`size() != 0`).
	 */
	bool empty(void) const noexcept {
		return 0 != mux(func::bs::is_empty, impl::make_immut(this));
	}

	/**
	 * @brief Attempts to get the first bit from the slice.
	 * @return The first bit, if any, as a `Tristate` boolean.
	 * @retval `Error` The slice is empty, and has no first bit.
	 * @retval `False` The slice is not empty, and the first bit is `0`.
	 * @retval `True` The slice is not empty, and the first bit is `1`.
	 */
	Tristate front(void) const noexcept {
		return impl::mux<C, T>(func::bs::first, impl::make_immut(this));
	}

	/**
	 * @brief Attempts to get the last bit from the slice.
	 * @return The last bit, if any, as a `Tristate` boolean.
	 * @retval `Error` The slice is empty, and has no last bit.
	 * @retval `False` The slice is not empty, and the last bit is `0`.
	 * @retval `True` The slice is not empty, and the last bit is `1`.
	 */
	Tristate back(void) const noexcept {
		return impl::mux<C, T>(func::bs::last, impl::make_immut(this));
	}

	Tristate pop_front(void) {
		return impl::mux<C, T>(func::bs::split_first, impl::make_immut(this));
	}

	/**
	 * @brief Attempts to split the first bit from the slice. This does not
	 * modify the receiving slice handle; rather, a handle to the remainder of
	 * the original slice is produced as an outparam.
	 * @param[out] tail Handle to the remaining bits after the first is split
	 * away. If `*this` is empty, then `tail` will also be empty.
	 * @return The first bit, if any, as a `Tristate` boolean.
	 * @retval `Error` The slice was empty, and had no first bit.
	 * @retval `False` The slice was not empty, and the first bit was `0`.
	 * @retval `True` The slice was not empty, and the first bit was `1`.
	 */
	Tristate pop_front(BitSlice<C, T>& tail) const {
		tail = *this;
		return impl::mux<C, T>(func::bs::split_first, impl::make_immut(&tail));
	}

	Tristate pop_back(void) {
		return impl::mux<C, T>(func::bs::split_last, impl::make_immut(this));
	}

	/**
	 * @brief Attempts to split the last bit from the slice. This does not
	 * modify the receiving slice handle; rather, a handle to the remainder of
	 * the original slice is produced as an outparam.
	 * @param[out] head Handle to the remaining bits before the last is split
	 * away. If `*this` is empty, then `head` will also be empty.
	 * @return The last bit, if any, as a `Tristate` boolean.
	 * @retval `Error` The slice was empty, and had no last bit.
	 * @retval `False` The slice was not empty, and the lats bit was `0`.
	 * @retval `True` The slice was not empty, and the last bit was `1`.
	 */
	Tristate pop_back(BitSlice<C, T>& head) const {
		head = *this;
		return impl::mux<C, T>(func::bs::split_last, impl::make_immut(&head));
	}

	/**
	 * @brief Attempts to get the bit at an index.
	 * @param index An index in the slice to attempt to retrieve.
	 * @return The bit, if any, at the requested index.
	 * @retval `Error` The slice does not reach the requested index.
	 * @retval `False` The bit at the requested index is `0`.
	 * @retval `True` The bit at the requested index is `1`.
	 */
	Tristate at(std::size_t const index) const noexcept {
		return impl::mux<C, T>(func::bs::get, impl::make_immut(this), index);
	}

	/**
	 * @brief Attempts to set the bit at an index. If the index is out of
	 * bounds, this method does nothing, and raises no error.
	 * @param index An index in the slice to attempt to set.
	 * @param value A new bit value for the requested index.
	 */
	void set(std::size_t const index, const bool value) const noexcept {
		impl::mux<C, T>(func::bs::set, this, index, value);
	}

	/**
	 * @brief Provides direct access to the underlying `T const` array.
	 * @return A const pointer to the `T const` data this handle is using.
	 *
	 * This method does not provide the count of `T` elements in the array.
	 */
	T const *const data(void) const noexcept {
		return static_cast<const T *const>(impl::mux<C, T>(
			func::bs::as_ptr, impl::make_immut(this)
		));
	}

	/**
	 * @brief Provides direct access to the underlying `T const` array.
	 * @param[out] len The length, in `T` elements, of the array.
	 * @return A const pointer to the `T const` data this handle is using.
	 */
	T const *const data(size_t * len) const noexcept {
		return static_cast<const T *const>(impl::mux<C, T>(
			func::bs::as_slice, impl::make_immut(this), len
		));
	};

	/**
	 * @brief Provides direct access to the underlying `T` array.
	 * @return A const pointer to the `T` data this handle is using.
	 *
	 * This method does not provide the count of `T` elements in the array.
	 */
	T *const data_mut(void) const noexcept {
		return static_cast<T *const>(impl::mux<C, T>(func::bs::as_mut_ptr, this));
	}

	/**
	 * @brief Provides direct access to the underlying `T` array.
	 * @param[out] len The length, in `T` elements, of the array.
	 * @return A const pointer to the `T` data this handle is using.
	 */
	T *const data_mut(size_t * len) const noexcept {
		return static_cast<T *const>(impl::mux<C, T>(
			func::bs::as_mut_slice, this, len
		));
	}

	/**
	 * @brief Swaps the bits at two indices in the slice.
	 *
	 * @param a The first index whose bit is to be swapped.
	 * @param b The second index whose bit is to be swapped.
	 *
	 * If either `a` or `b` is outside the bounds of the slice, then this
	 * function does nothing.
	 */
	void swap(std::size_t const a, std::size_t const b) const noexcept {
		impl::mux<C, T>(func::bs::swap, this, a, b);
	}

	/**
	 * @brief Reverses the order of all bits in the slice.
	 */
	void reverse(void) const noexcept {
		impl::mux<C, T>(func::bs::reverse, this);
	}

	/**
	 * @brief Attempts to split the slice at a given index.
	 *
	 * @param mid The index at which to perform the split. If the split is in
	 * bounds, then `this` will govern the front half (`[.. mid]`).
	 * @return A handle governing the back half (`[mid ..]`), or empty.
	 *
	 * If `mid` is outside the bounds of the slice, then `this` is not modified
	 * and the returned slice is empty.
	 */
	BitSlice<C, T const> split_at(std::size_t const mid) noexcept {
		BitSlice<C, T const> out;
		impl::mux<C, T>(
			func::bs::split_at,
			make_immut(this),
			make_immut(this),
			mid
		);
		return out;
	}

	/**
	 * @brief Attempts to split the slice at a given index.
	 *
	 * @param mid The index at which to perform the split. If the split is in
	 * bounds, then `this` will govern the front half (`[.. mid]`).
	 * @return A handle governing the back half (`[mid ..]`), or empty.
	 *
	 * If `mid` is outside the bounds of the slice, then `this` is not modified
	 * and the returned slice is empty.
	 */
	BitSlice<C, T> split_at_mut(std::size_t const mid) noexcept {
		BitSlice<C, T> out;
		impl::mux<C, T>(func::bs::split_at_mut, this, out, mid);
		return out;
	}

	/**
	 * @brief Rotates the bits in the slice towards the front, wrapping to the
	 * back.
	 *
	 * @param by The amount by which each bit will be moved forwards in the
	 * slice.
	 */
	void rotate_left(std::size_t const by) const noexcept {
		impl::mux<C, T>(func::bs::rotate_left, this, by);
	}

	/**
	 * @brief Rotates the bits in the slice towards the back, wrapping back to
	 * the front.
	 *
	 * @param by The amount by which each bit will be moved backwards in the
	 * slice.
	 */
	void rotate_right(std::size_t const by) const noexcept {
		impl::mux<C, T>(func::bs::rotate_right, this, by);
	}

	/**
	 * @brief Tests if all bits in the slice are set to `1`.
	 * @return Whether all bits in the slice are set to `1`.
	 * @retval `true` All bits in the slice are set to `1`.
	 * @retval `false` At least one bit in the slice is set to `0`.
	 */
	bool all(void) const noexcept {
		return impl::mux<C, T>(func::bs::all, impl::make_immut(this));
	}

	/**
	 * @brief Tests if any bit in the slice is set to `1`.
	 * @return Whether any bit in the slice is set to `1`.
	 * @retval `true` At least one bit in the slice is set to `1`.
	 * @retval `false` All bits in the slice are set to `0`.
	 */
	bool any(void) const noexcept {
		return impl::mux<C, T>(func::bs::any, impl::make_immut(this));
	}

	/**
	 * @brief Tests if all bits in the slice are set to `0`.
	 * @return Whether all bits in the slice are set to `0`.
	 * @retval `true` All bits in the slice are set to `0`.
	 * @retval `false` At least one bit in the slice is set to `1`.
	 */
	bool not_all(void) const noexcept {
		return impl::mux<C, T>(func::bs::not_all, impl::make_immut(this));
	}

	/**
	 * @brief Tests if any bit in the slice is set to `0`.
	 * @return Whether any bit in the slice is set to `0`.
	 * @retval `true` At least one bit in the slice is set to `0`.
	 * @retval `false` All bits in the slice are set to `1`.
	 */
	bool not_any(void) const noexcept {
		return impl::mux<C, T>(func::bs::not_any, impl::make_immut(this));
	}

	/**
	 * @brief Tests if some bits in the slice are `0` and some are `1`.
	 * @return Whether the slice is heterogenous or homogenous.
	 * @retval `true` The slice is heterogenous -- some `0`, some `1`.
	 * @retval `false` The slice is homogenous -- all `0` or all `1`.
	 */
	bool some(void) const noexcept {
		return impl::mux<C, T>(func::bs::some, impl::make_immut(this));
	}

	/**
	 * @brief Counts how many bits in the slice are set to `1`.
	 * @return The number of bits in the slice that are set to `1`.
	 */
	size_t count_ones(void) const noexcept {
		return impl::mux<C, T>(func::bs::count_ones, impl::make_immut(this));
	}

	/**
	 * @brief Counts how many bits in the slice are set to `0`.
	 * @return The number of bits in the slice that are set to `0`.
	 */
	size_t count_zeros(void) const noexcept {
		return impl::mux<C, T>(func::bs::count_zeros, impl::make_immut(this));
	}

	/**
	 * @brief Sets all bits in the slice to the given value.
	 * @param value The value to which all bits in the slice will be set.
	 */
	void set_all(const bool value) const noexcept {
		impl::mux<C, T>(func::bs::set_all, this, value);
	}
private:
};

}; // namespace bitvec

#endif//BITVEC_FFI_BITSLICE_HPP
