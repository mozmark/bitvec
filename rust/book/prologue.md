# Prologue

This documents the design and implementation of the `bitvec` data structures.
The API documentation rendered by `rustdoc` should be sufficient to use `bitvec`
in your projects; the purpose of this book is to explain why `bitvec` made the
choices it did and how it fulfills its contracts.

The `bitvec` crate aims to provide a fully-featured implementation of `[u1]` –
which is distinct from `[bool]` in that (as of Rust 1.31.0), Rust specifies that
`bool` is one system byte wide, of which only one bit will be used. `bitvec`’s
representation of `u1` is exactly one bit wide, and sequences of `u1` are
guaranteed to be correctly packed in a CPU register type.
