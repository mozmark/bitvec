/**
 * @file c/demo.cpp
 *
 * @brief Demonstration file using the C++ bindings to `libbitvec`.
 */

// compile as `driver examples/foreign.cpp target/subdir/libbitvec.so ...`

#include <iostream>

#include "bitvec/lib.hpp"

using bitvec::BitSlice;
using bitvec::BitVector;
using bitvec::Cursor;

int main(int argc, char* argv[]) {
	BitVector<Cursor::BigEndian, std::uint32_t> bv;
	std::cout << "New BitVector has " << bv.size() << " bits" << std::endl;
	bv.push(true);
	bv.push(false);
	std::cout << "Modified BitVector has " << bv.size() << " bit(s). The first "
		<< "bit is " << std::boolalpha << bv.at(0) << std::endl;
	auto bs = bv.view();
	std::cout << "BitVector inherits from BitSlice: Slice has " << bs.size()
		<< "bits" << std::endl;

	//  NEVER DO THIS
	BitSlice<Cursor::LittleEndian, std::uint16_t> bs_dangle;
	{
		BitVector<Cursor::LittleEndian, std::uint16_t> bv_dangle;
		bv_dangle.push(false);
		bv_dangle.push(true);
		bs_dangle = bv_dangle.view();
	}
	//  bs_dangle is now pointing at deallocated memory

	return 0;
}
