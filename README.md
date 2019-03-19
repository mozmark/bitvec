# `BitVec` – Managing Memory Bit by Bit

This repository contains a Rust crate, `bitvec` and a number of bindings to it
in other languages. Each language’s subfolder has more detailed information
about how to use the library.

## Abstract

`bitvec` defines data structures suitable for viewing machine memory as a
sequence of individual bits, rather than of bytes or words. This is useful for a
variety of reasons, including (in the author’s experience) building up data
streams and describing properties of integers.

`bitvec` is explicitly designed for the purpose of manipulating data streams in
machine memory suitable for movement across device boundaries. It has type
parameters describing how a cursor should select a bit from a machine data unit
of any size (Rust only supports `u8`, `u16`, `u32`, and `u64` at this time), and
which of those data units should be the fundamental storage type of the stream.

Users who do not need this level of control do not need to specify these
parameters at all; the default is to traverse individual bytes from left (MSb)
to right (LSb).

## Usage

Each language’s library includes instructions to import it into your project,
and documentation on how to use the provided symbols.
