# Pointer

`bitvec` handles are exactly the same size as their mainstream counterparts:
`&[bool]` is two words wide; `&BitSlice` is two words wide. `Vec<bool>` is three
words wide; `BitVec` is three words wide. Other bit-vector crates have larger
handles, which can make them less convenient to manipulate or carry multiple
handles.

The trade-off is that the other crates use standard Rust slice and vector
handles, with cursor information carried in additional fields. `bitvec` embeds
the cursor information directly in the slice or vector handles, rendering their
values incompatible with standard Rust.

## Semantic Layout

A bit-slice reference has three components: a slice pointer to the underlying
storage type, an index of the head bit within the first storage element, and an
index of the tail bit within the last storage element. A naïve declaration of
this type might be:

```rust
pub struct BitSliceHandle<'a, T>
where T: 'a + Bits {
  data: &'a [T],
  head: u8,
  tail: u8,
}
```

This structure holds all the data we need, however, its size and alignment are
three words, even though two bytes (32-bit systems) or six bytes (64-bit) are
unused padding.

## Binary Layout

`bitvec`’s pointer type compacts this information into just the space used by a
`&[T]` slice handle.

This works by taking advantage of some properties of memory addressing that hold
true on all architectures Rust (as of 1.31.0) targets:

- pointers to fundamental types (`u8`, `u16`, `u32`, `u64` on 64-bit systems)
  are always well-aligned to the width of their type; that is, a pointer to
  `u32` will always have an address value that is an even multiple of four.
- indexing counts elements, not bytes; this means that the
  `usize::max_value()`th index in a bit-slice will be in the
  `usize::max_value() / 8`th byte, and a longer slice than that will waste
  space.
- `usize::max_value()` is four milliard (long scale) on 32-bit systems and
  eighteen trillion (long scale) on 64-bit. Index space can be sacrificed; even
  29 or 61 bits of indexing is far more than the vast majority of use cases will
  require, and use cases that do require this space, require better data
  structures than this crate.

The fundamental types, on Rust supported targets, have bit widths that are even
powers of two. This means that the number of bits required to create an index to
a bit position inside a fundamental type is always
<math><msub><mo>log</mo><mn>2</mn></msub><mo>(</mo><mi>w</mi><mo>)</mo></math>
where <math><mi>w</mi></math> is the width of the type, in bits.

Thus, the head and tail indices for a bit-slice over `u8` are themselves `u3`,
the indices for `u16` are `u4`, the indices for `u32` are `u5`, and the indices
for `u64` are `u6`.

The lowest <math><mi>n</mi></math> bits of a pointer to `T` are always zero,
where <math><mi>n</mi></math> is
<math><msub><mo>log</mo><mn>2</mn></msub><mo>(</mo><mi>W</mi>)</mo></math> and
<math><mi>W</mi></math> is the width of `T` in *bytes*. Rust currently only
targets systems with 8-bit bytes, so <math><mi>n</mi></math> is 0, 1, 2, and 3,
for `u8`, `u16`, `u32`, and `u64`, respectively.

This means that one of the two bit cursors can be split, with its lowest three
bits in the slice length field and its remaining <math><mi>n</mi></math> high
bits can be stored in the low <math><mi>n</mi></math> bits of the slice pointer
field.

Rust does not have bitfields. A naïve declaration of the handle type in C++
might be:

```c++
const ptr_width = sizeof(void*) * 8;
const usz_width = sizeof(size_t) * 8;
template<typename T>
struct BitSliceHandle<T> {
  T* const pointer  : sizeof(T*) * 8 - __builtin_ctzll(alignof(T));
  size_t   elements : sizeof(size_t) * 8 - 6 - __builtin_ctzll(alignof(T));
  size_t   head     : __builtin_ctzll(alignof(T)) + 3;
  size_t   tail     : __builtin_ctzll(alignof(T)) + 3;
};
```

This describes the sizes of each bitfield in the structure, but does not
correctly lay each field out in the underlying `(*const T, usize)` tuple.

The exact layout used is:

- the pointer slot contains two fields:
  - the slice pointer value runs from `MSbit` to `N : N ∈ { 0, 1, 2, 3}`
  - the high `N` bits of the head cursor are placed in bits `N` to `0`
- the length slot contains three fields:
  - the element counter value runs from `MSbit` to `6 + 2N`
  - the tail index runs from `6 + 2N` to `3`.
  - the low three bits of the head cursor are placed in bits `3` to `0`

The pointer structure currently stores absolute tail position, rather than tail
offset in bits from head. This may change in the future.

The Rust documentation states that the underlying representation of slices
cannot be treated as defined or fixed, and user code must not rely on it.
`bitvec` uses the `core::slice` APIs to manage the raw slice representations it
uses under the hood, and as such has the same structural instability guarantees.
Furthermore, the pointer and length members of the slice handle are both mangled
and wholly incompatible with use in any other context.

I write this in every section of the documentation I can:

**Use of `mem::transmute` near the `&BitSlice` or `BitVec` types, no matter**
**whether to or from, is *absolutely* unsafe, *will* result in inconsistent**
**state, and <u>must never</u> occur.**

## Internal Usage

The `pointer` module defines the `BitPtr<T: Bits>` type, which serves as the
internal representation of the handle to a bit-slice, whether in `&BitSlice` or
in `BitVec`.

> Note: Rust transforms between the raw structure and the fundamental slice
> handle types by using a union. Normal crates cannot do this on stable, because
> unions with non-`Copy` fields are still unstable ([#32836]).
>
> ```rust
> union Repr<'a, C, T>
> where C: Cursor, T: 'a + Bits {
>   bits: &'a BitSlice<C, T>,
>   // not Copy
>   bits_mut: &'a mut BitSlice<C, T>,
>   raw: BitPtr<T>,
> }
> ```
>
> Unions are the correct way to perform type transmutation, by writing to one
> field and reading from another, but with the `Copy` restriction, `bitvec` is
> required to fall back to `From`/`Into` implementations using `mem::transmute`.

`BitSlice` and `BitVec` both have a `BitPtr` as their primary element, and defer
to it for all the manipulation of their concept of the domain.

`BitPtr` does not have the capability of modifying the region of memory it
describes; this is left solely to the provenance of `BitSlice`.

[#32836]: https://github.com/rust-lang/rust/issues/32836
