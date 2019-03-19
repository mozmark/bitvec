# Slice

The `BitSlice<C: Cursor, T: Bits>` type contains all the logic for operating on
sets of bits. It is a reference-only type, and cannot be directly held. Rust’s
existing infrastructure for unsized types is also unsuitable for working with
it – `Box<BitSlice>`, for example, is **not** valid to create, and attempts to
make or use it will result in inconsistent state.

The power of `bitvec`’s data structures comes from storing all the information
needed to work with a memory region as a bitslice in the *access handle*, not
in the *memory region*. `BitSlice` does **not** work like `Rc` and `Arc`, which
store their additional data in the region they govern. This is a deliberate
design choice, which is explained further in the [pointer] chapter.

`BitSlice` regions are always held by reference (`&BitSlice`) or through another
specialized type (`BitVec`, `BitBox`) which implements `Deref`/`Deref` to it.
The rest of this chapter will discuss `&BitSlice` references specifically.

## Slice Handles

The slice handles `&BitSlice<C, T>` and `&mut BitSlice<C, T>` are instances of
the pointer structure, described later, which refer to regions of memory owned
elsewhere. The type parameters [`C: Cursor`] and [`T: Bits`] describe the memory
elements comprising the region the slice describes (`T`) and the order of bit
traversal for each element (`C`).

Slice handles are created from slices of other elements, by

```rust
# extern crate bitvec;
use bitvec::*;

let bits: &BitSlice<Cursor, Bits> = &[0u32].into();
```

or by borrowing `BitBox` or `BitVec` owning handles, or by using range indexing
on any of the collections in this crate.

[`C: Cursor`]: cursor.html
[`T: Bits`]: bits.html
[pointer]: pointer.html
