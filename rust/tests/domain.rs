/*! Domain Test

This test crawls the entire domain of `BitPtr::<u64>`, ensuring that the
`BitPtr` can safely round-trip its component data, and also that the assertions
will not fire on known valid source data.
!*/

#![cfg(all(feature = "testing", feature = "domain-test"))]

use bitvec::BitPtr;

#[test]
fn main() {
	let data = 8 as *const u64;
	for tail in 1 ..= 64 {
		for head in 0 .. tail {
			// eprintln!("Elts: {}, Head: {}, Tail: {}", 1, head, tail);
			BitPtr::new(data, 1, head, tail);
		}
	}
	for n in 0 ..= 55usize {
		eprintln!("Element power: {}", n);
		for elts in 2usize ..= (1usize << n) {
			for tail in 1 ..= 64 {
				for head in 0 .. 64 {
					// eprintln!("Elts: {}, Head: {}, Tail: {}", elts, head, tail);
					let bp = BitPtr::new(data, elts, head, tail);
					assert_eq!(bp.raw_parts(), (data, elts, head, tail));
				}
			}
		}
	}
}
