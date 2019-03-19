use super::Tristate;
use crate::{
	BigEndian,
	BitSlice,
	BitVec,
	LittleEndian,
};
use core::ptr;

#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b08_new(this: *mut BitVec<BigEndian, u8>) {
	if this.is_null() { return; }
	ptr::write(this, BitVec::new());
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l08_new(this: *mut BitVec<LittleEndian, u8>) {
	if this.is_null() { return; }
	ptr::write(this, BitVec::new());
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b16_new(this: *mut BitVec<BigEndian, u16>) {
	if this.is_null() { return; }
	ptr::write(this, BitVec::new());
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l16_new(this: *mut BitVec<LittleEndian, u16>) {
	if this.is_null() { return; }
	ptr::write(this, BitVec::new());
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b32_new(this: *mut BitVec<BigEndian, u32>) {
	if this.is_null() { return; }
	ptr::write(this, BitVec::new());
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l32_new(this: *mut BitVec<LittleEndian, u32>) {
	if this.is_null() { return; }
	ptr::write(this, BitVec::new());
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b64_new(this: *mut BitVec<BigEndian, u64>) {
	if this.is_null() { return; }
	ptr::write(this, BitVec::new());
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l64_new(this: *mut BitVec<LittleEndian, u64>) {
	if this.is_null() { return; }
	ptr::write(this, BitVec::new());
}

#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b08_with_capacity(this: *mut BitVec<BigEndian, u8>, capacity: usize) {
	if this.is_null() { return; }
	ptr::write(this, BitVec::with_capacity(capacity));
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l08_with_capacity(this: *mut BitVec<LittleEndian, u8>, capacity: usize) {
	if this.is_null() { return; }
	ptr::write(this, BitVec::with_capacity(capacity));
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b16_with_capacity(this: *mut BitVec<BigEndian, u16>, capacity: usize) {
	if this.is_null() { return; }
	ptr::write(this, BitVec::with_capacity(capacity));
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l16_with_capacity(this: *mut BitVec<LittleEndian, u16>, capacity: usize) {
	if this.is_null() { return; }
	ptr::write(this, BitVec::with_capacity(capacity));
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b32_with_capacity(this: *mut BitVec<BigEndian, u32>, capacity: usize) {
	if this.is_null() { return; }
	ptr::write(this, BitVec::with_capacity(capacity));
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l32_with_capacity(this: *mut BitVec<LittleEndian, u32>, capacity: usize) {
	if this.is_null() { return; }
	ptr::write(this, BitVec::with_capacity(capacity));
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b64_with_capacity(this: *mut BitVec<BigEndian, u64>, capacity: usize) {
	if this.is_null() { return; }
	ptr::write(this, BitVec::with_capacity(capacity));
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l64_with_capacity(this: *mut BitVec<LittleEndian, u64>, capacity: usize) {
	if this.is_null() { return; }
	ptr::write(this, BitVec::with_capacity(capacity));
}

#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b08_capacity(this: *const BitVec<BigEndian, u8>) -> usize {
	if this.is_null() { return 0; }
	(&*this).capacity()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l08_capacity(this: *const BitVec<LittleEndian, u8>) -> usize {
	if this.is_null() { return 0; }
	(&*this).capacity()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b16_capacity(this: *const BitVec<BigEndian, u16>) -> usize {
	if this.is_null() { return 0; }
	(&*this).capacity()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l16_capacity(this: *const BitVec<LittleEndian, u16>) -> usize {
	if this.is_null() { return 0; }
	(&*this).capacity()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b32_capacity(this: *const BitVec<BigEndian, u32>) -> usize {
	if this.is_null() { return 0; }
	(&*this).capacity()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l32_capacity(this: *const BitVec<LittleEndian, u32>) -> usize {
	if this.is_null() { return 0; }
	(&*this).capacity()
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b64_capacity(this: *const BitVec<BigEndian, u64>) -> usize {
	if this.is_null() { return 0; }
	(&*this).capacity()
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l64_capacity(this: *const BitVec<LittleEndian, u64>) -> usize {
	if this.is_null() { return 0; }
	(&*this).capacity()
}

#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b08_reserve(this: *mut BitVec<BigEndian, u8>, additional: usize) {
	if this.is_null() { return; }
	(&mut *this).reserve(additional);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l08_reserve(this: *mut BitVec<LittleEndian, u8>, additional: usize) {
	if this.is_null() { return; }
	(&mut *this).reserve(additional);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b16_reserve(this: *mut BitVec<BigEndian, u16>, additional: usize) {
	if this.is_null() { return; }
	(&mut *this).reserve(additional);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l16_reserve(this: *mut BitVec<LittleEndian, u16>, additional: usize) {
	if this.is_null() { return; }
	(&mut *this).reserve(additional);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b32_reserve(this: *mut BitVec<BigEndian, u32>, additional: usize) {
	if this.is_null() { return; }
	(&mut *this).reserve(additional);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l32_reserve(this: *mut BitVec<LittleEndian, u32>, additional: usize) {
	if this.is_null() { return; }
	(&mut *this).reserve(additional);
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b64_reserve(this: *mut BitVec<BigEndian, u64>, additional: usize) {
	if this.is_null() { return; }
	(&mut *this).reserve(additional);
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l64_reserve(this: *mut BitVec<LittleEndian, u64>, additional: usize) {
	if this.is_null() { return; }
	(&mut *this).reserve(additional);
}

#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b08_shrink_to_fit(this: *mut BitVec<BigEndian, u8>) {
	if this.is_null() { return; }
	(&mut *this).shrink_to_fit();
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l08_shrink_to_fit(this: *mut BitVec<LittleEndian, u8>) {
	if this.is_null() { return; }
	(&mut *this).shrink_to_fit();
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b16_shrink_to_fit(this: *mut BitVec<BigEndian, u16>) {
	if this.is_null() { return; }
	(&mut *this).shrink_to_fit();
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l16_shrink_to_fit(this: *mut BitVec<LittleEndian, u16>) {
	if this.is_null() { return; }
	(&mut *this).shrink_to_fit();
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b32_shrink_to_fit(this: *mut BitVec<BigEndian, u32>) {
	if this.is_null() { return; }
	(&mut *this).shrink_to_fit();
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l32_shrink_to_fit(this: *mut BitVec<LittleEndian, u32>) {
	if this.is_null() { return; }
	(&mut *this).shrink_to_fit();
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b64_shrink_to_fit(this: *mut BitVec<BigEndian, u64>) {
	if this.is_null() { return; }
	(&mut *this).shrink_to_fit();
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l64_shrink_to_fit(this: *mut BitVec<LittleEndian, u64>) {
	if this.is_null() { return; }
	(&mut *this).shrink_to_fit();
}

#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b08_truncate(this: *mut BitVec<BigEndian, u8>, len: usize) {
	if this.is_null() { return; }
	(&mut *this).truncate(len);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l08_truncate(this: *mut BitVec<LittleEndian, u8>, len: usize) {
	if this.is_null() { return; }
	(&mut *this).truncate(len);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b16_truncate(this: *mut BitVec<BigEndian, u16>, len: usize) {
	if this.is_null() { return; }
	(&mut *this).truncate(len);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l16_truncate(this: *mut BitVec<LittleEndian, u16>, len: usize) {
	if this.is_null() { return; }
	(&mut *this).truncate(len);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b32_truncate(this: *mut BitVec<BigEndian, u32>, len: usize) {
	if this.is_null() { return; }
	(&mut *this).truncate(len);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l32_truncate(this: *mut BitVec<LittleEndian, u32>, len: usize) {
	if this.is_null() { return; }
	(&mut *this).truncate(len);
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b64_truncate(this: *mut BitVec<BigEndian, u64>, len: usize) {
	if this.is_null() { return; }
	(&mut *this).truncate(len);
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l64_truncate(this: *mut BitVec<LittleEndian, u64>, len: usize) {
	if this.is_null() { return; }
	(&mut *this).truncate(len);
}

#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b08_as_bitslice(
	this: *const BitVec<BigEndian, u8>,
	slice: *mut *const BitSlice<BigEndian, u8>,
) {
	if this.is_null() { return; }
	ptr::write(slice, (&*this).as_bitslice());
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l08_as_bitslice(
	this: *const BitVec<LittleEndian, u8>,
	slice: *mut *const BitSlice<LittleEndian, u8>,
) {
	if this.is_null() { return; }
	ptr::write(slice, (&*this).as_bitslice());
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b16_as_bitslice(
	this: *const BitVec<BigEndian, u16>,
	slice: *mut *const BitSlice<BigEndian, u16>,
) {
	if this.is_null() { return; }
	ptr::write(slice, (&*this).as_bitslice());
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l16_as_bitslice(
	this: *const BitVec<LittleEndian, u16>,
	slice: *mut *const BitSlice<LittleEndian, u16>,
) {
	if this.is_null() { return; }
	ptr::write(slice, (&*this).as_bitslice());
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b32_as_bitslice(
	this: *const BitVec<BigEndian, u32>,
	slice: *mut *const BitSlice<BigEndian, u32>,
) {
	if this.is_null() { return; }
	ptr::write(slice, (&*this).as_bitslice());
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l32_as_bitslice(
	this: *const BitVec<LittleEndian, u32>,
	slice: *mut *const BitSlice<LittleEndian, u32>,
) {
	if this.is_null() { return; }
	ptr::write(slice, (&*this).as_bitslice());
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b64_as_bitslice(
	this: *const BitVec<BigEndian, u64>,
	slice: *mut *const BitSlice<BigEndian, u64>,
) {
	if this.is_null() { return; }
	ptr::write(slice, (&*this).as_bitslice());
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l64_as_bitslice(
	this: *const BitVec<LittleEndian, u64>,
	slice: *mut *const BitSlice<LittleEndian, u64>,
) {
	if this.is_null() { return; }
	ptr::write(slice, (&*this).as_bitslice());
}

#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b08_as_mut_bitslice(
	this: *mut BitVec<BigEndian, u8>,
	slice: *mut *mut BitSlice<BigEndian, u8>,
) {
	if this.is_null() { return; }
	ptr::write(slice, (&mut *this).as_mut_bitslice());
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l08_as_mut_bitslice(
	this: *mut BitVec<LittleEndian, u8>,
	slice: *mut *mut BitSlice<LittleEndian, u8>,
) {
	if this.is_null() { return; }
	ptr::write(slice, (&mut *this).as_mut_bitslice());
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b16_as_mut_bitslice(
	this: *mut BitVec<BigEndian, u16>,
	slice: *mut *mut BitSlice<BigEndian, u16>,
) {
	if this.is_null() { return; }
	ptr::write(slice, (&mut *this).as_mut_bitslice());
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l16_as_mut_bitslice(
	this: *mut BitVec<LittleEndian, u16>,
	slice: *mut *mut BitSlice<LittleEndian, u16>,
) {
	if this.is_null() { return; }
	ptr::write(slice, (&mut *this).as_mut_bitslice());
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b32_as_mut_bitslice(
	this: *mut BitVec<BigEndian, u32>,
	slice: *mut *mut BitSlice<BigEndian, u32>,
) {
	if this.is_null() { return; }
	ptr::write(slice, (&mut *this).as_mut_bitslice());
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l32_as_mut_bitslice(
	this: *mut BitVec<LittleEndian, u32>,
	slice: *mut *mut BitSlice<LittleEndian, u32>,
) {
	if this.is_null() { return; }
	ptr::write(slice, (&mut *this).as_mut_bitslice());
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b64_as_mut_bitslice(
	this: *mut BitVec<BigEndian, u64>,
	slice: *mut *mut BitSlice<BigEndian, u64>,
) {
	if this.is_null() { return; }
	ptr::write(slice, (&mut *this).as_mut_bitslice());
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l64_as_mut_bitslice(
	this: *mut BitVec<LittleEndian, u64>,
	slice: *mut *mut BitSlice<LittleEndian, u64>,
) {
	if this.is_null() { return; }
	ptr::write(slice, (&mut *this).as_mut_bitslice());
}

#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b08_swap_remove(this: *mut BitVec<BigEndian, u8>, index: usize) -> Tristate {
	if this.is_null() || index >= (&*this).len() { return Tristate::Error; }
	(&mut *this).swap_remove(index).into()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l08_swap_remove(this: *mut BitVec<LittleEndian, u8>, index: usize) -> Tristate {
	if this.is_null() || index >= (&*this).len() { return Tristate::Error; }
	(&mut *this).swap_remove(index).into()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b16_swap_remove(this: *mut BitVec<BigEndian, u16>, index: usize) -> Tristate {
	if this.is_null() || index >= (&*this).len() { return Tristate::Error; }
	(&mut *this).swap_remove(index).into()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l16_swap_remove(this: *mut BitVec<LittleEndian, u16>, index: usize) -> Tristate {
	if this.is_null() || index >= (&*this).len() { return Tristate::Error; }
	(&mut *this).swap_remove(index).into()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b32_swap_remove(this: *mut BitVec<BigEndian, u32>, index: usize) -> Tristate {
	if this.is_null() || index >= (&*this).len() { return Tristate::Error; }
	(&mut *this).swap_remove(index).into()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l32_swap_remove(this: *mut BitVec<LittleEndian, u32>, index: usize) -> Tristate {
	if this.is_null() || index >= (&*this).len() { return Tristate::Error; }
	(&mut *this).swap_remove(index).into()
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b64_swap_remove(this: *mut BitVec<BigEndian, u64>, index: usize) -> Tristate {
	if this.is_null() || index >= (&*this).len() { return Tristate::Error; }
	(&mut *this).swap_remove(index).into()
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l64_swap_remove(this: *mut BitVec<LittleEndian, u64>, index: usize) -> Tristate {
	if this.is_null() || index >= (&*this).len() { return Tristate::Error; }
	(&mut *this).swap_remove(index).into()
}

#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b08_insert(this: *mut BitVec<BigEndian, u8>, index: usize, value: bool) {
	if this.is_null() || index > (&*this).len() { return; }
	(&mut *this).insert(index, value);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l08_insert(this: *mut BitVec<LittleEndian, u8>, index: usize, value: bool) {
	if this.is_null() || index > (&*this).len() { return; }
	(&mut *this).insert(index, value);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b16_insert(this: *mut BitVec<BigEndian, u16>, index: usize, value: bool) {
	if this.is_null() || index > (&*this).len() { return; }
	(&mut *this).insert(index, value);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l16_insert(this: *mut BitVec<LittleEndian, u16>, index: usize, value: bool) {
	if this.is_null() || index > (&*this).len() { return; }
	(&mut *this).insert(index, value);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b32_insert(this: *mut BitVec<BigEndian, u32>, index: usize, value: bool) {
	if this.is_null() || index > (&*this).len() { return; }
	(&mut *this).insert(index, value);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l32_insert(this: *mut BitVec<LittleEndian, u32>, index: usize, value: bool) {
	if this.is_null() || index > (&*this).len() { return; }
	(&mut *this).insert(index, value);
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b64_insert(this: *mut BitVec<BigEndian, u64>, index: usize, value: bool) {
	if this.is_null() || index > (&*this).len() { return; }
	(&mut *this).insert(index, value);
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l64_insert(this: *mut BitVec<LittleEndian, u64>, index: usize, value: bool) {
	if this.is_null() || index > (&*this).len() { return; }
	(&mut *this).insert(index, value);
}

#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b08_remove(this: *mut BitVec<BigEndian, u8>, index: usize) -> Tristate {
	if this.is_null() || index >= (&*this).len() { return Tristate::Error; }
	(&mut *this).remove(index).into()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l08_remove(this: *mut BitVec<LittleEndian, u8>, index: usize) -> Tristate {
	if this.is_null() || index >= (&*this).len() { return Tristate::Error; }
	(&mut *this).remove(index).into()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b16_remove(this: *mut BitVec<BigEndian, u16>, index: usize) -> Tristate {
	if this.is_null() || index >= (&*this).len() { return Tristate::Error; }
	(&mut *this).remove(index).into()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l16_remove(this: *mut BitVec<LittleEndian, u16>, index: usize) -> Tristate {
	if this.is_null() || index >= (&*this).len() { return Tristate::Error; }
	(&mut *this).remove(index).into()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b32_remove(this: *mut BitVec<BigEndian, u32>, index: usize) -> Tristate {
	if this.is_null() || index >= (&*this).len() { return Tristate::Error; }
	(&mut *this).remove(index).into()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l32_remove(this: *mut BitVec<LittleEndian, u32>, index: usize) -> Tristate {
	if this.is_null() || index >= (&*this).len() { return Tristate::Error; }
	(&mut *this).remove(index).into()
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b64_remove(this: *mut BitVec<BigEndian, u64>, index: usize) -> Tristate {
	if this.is_null() || index >= (&*this).len() { return Tristate::Error; }
	(&mut *this).remove(index).into()
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l64_remove(this: *mut BitVec<LittleEndian, u64>, index: usize) -> Tristate {
	if this.is_null() || index >= (&*this).len() { return Tristate::Error; }
	(&mut *this).remove(index).into()
}

#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b08_retain(this: *mut BitVec<BigEndian, u8>, func: fn(bool) -> bool) {
	if this.is_null() { return; }
	(&mut *this).retain(func);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l08_retain(this: *mut BitVec<LittleEndian, u8>, func: fn(bool) -> bool) {
	if this.is_null() { return; }
	(&mut *this).retain(func);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b16_retain(this: *mut BitVec<BigEndian, u16>, func: fn(bool) -> bool) {
	if this.is_null() { return; }
	(&mut *this).retain(func);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l16_retain(this: *mut BitVec<LittleEndian, u16>, func: fn(bool) -> bool) {
	if this.is_null() { return; }
	(&mut *this).retain(func);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b32_retain(this: *mut BitVec<BigEndian, u32>, func: fn(bool) -> bool) {
	if this.is_null() { return; }
	(&mut *this).retain(func);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l32_retain(this: *mut BitVec<LittleEndian, u32>, func: fn(bool) -> bool) {
	if this.is_null() { return; }
	(&mut *this).retain(func);
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b64_retain(this: *mut BitVec<BigEndian, u64>, func: fn(bool) -> bool) {
	if this.is_null() { return; }
	(&mut *this).retain(func);
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l64_retain(this: *mut BitVec<LittleEndian, u64>, func: fn(bool) -> bool) {
	if this.is_null() { return; }
	(&mut *this).retain(func);
}

#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b08_push(this: *mut BitVec<BigEndian, u8>, value: bool) {
	if this.is_null() { return; }
	(&mut *this).push(value);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l08_push(this: *mut BitVec<LittleEndian, u8>, value: bool) {
	if this.is_null() { return; }
	(&mut *this).push(value);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b16_push(this: *mut BitVec<BigEndian, u16>, value: bool) {
	if this.is_null() { return; }
	(&mut *this).push(value);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l16_push(this: *mut BitVec<LittleEndian, u16>, value: bool) {
	if this.is_null() { return; }
	(&mut *this).push(value);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b32_push(this: *mut BitVec<BigEndian, u32>, value: bool) {
	if this.is_null() { return; }
	(&mut *this).push(value);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l32_push(this: *mut BitVec<LittleEndian, u32>, value: bool) {
	if this.is_null() { return; }
	(&mut *this).push(value);
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b64_push(this: *mut BitVec<BigEndian, u64>, value: bool) {
	if this.is_null() { return; }
	(&mut *this).push(value);
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l64_push(this: *mut BitVec<LittleEndian, u64>, value: bool) {
	if this.is_null() { return; }
	(&mut *this).push(value);
}

#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b08_pop(this: *mut BitVec<BigEndian, u8>) -> Tristate {
	if this.is_null() { return Tristate::Error; }
	(&mut *this).pop().into()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l08_pop(this: *mut BitVec<LittleEndian, u8>) -> Tristate {
	if this.is_null() { return Tristate::Error; }
	(&mut *this).pop().into()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b16_pop(this: *mut BitVec<BigEndian, u16>) -> Tristate {
	if this.is_null() { return Tristate::Error; }
	(&mut *this).pop().into()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l16_pop(this: *mut BitVec<LittleEndian, u16>) -> Tristate {
	if this.is_null() { return Tristate::Error; }
	(&mut *this).pop().into()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b32_pop(this: *mut BitVec<BigEndian, u32>) -> Tristate {
	if this.is_null() { return Tristate::Error; }
	(&mut *this).pop().into()
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l32_pop(this: *mut BitVec<LittleEndian, u32>) -> Tristate {
	if this.is_null() { return Tristate::Error; }
	(&mut *this).pop().into()
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b64_pop(this: *mut BitVec<BigEndian, u64>) -> Tristate {
	if this.is_null() { return Tristate::Error; }
	(&mut *this).pop().into()
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l64_pop(this: *mut BitVec<LittleEndian, u64>) -> Tristate {
	if this.is_null() { return Tristate::Error; }
	(&mut *this).pop().into()
}

#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b08_clear(this: *mut BitVec<BigEndian, u8>) {
	if this.is_null() { return; }
	(&mut *this).clear();
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l08_clear(this: *mut BitVec<LittleEndian, u8>) {
	if this.is_null() { return; }
	(&mut *this).clear();
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b16_clear(this: *mut BitVec<BigEndian, u16>) {
	if this.is_null() { return; }
	(&mut *this).clear();
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l16_clear(this: *mut BitVec<LittleEndian, u16>) {
	if this.is_null() { return; }
	(&mut *this).clear();
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b32_clear(this: *mut BitVec<BigEndian, u32>) {
	if this.is_null() { return; }
	(&mut *this).clear();
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l32_clear(this: *mut BitVec<LittleEndian, u32>) {
	if this.is_null() { return; }
	(&mut *this).clear();
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b64_clear(this: *mut BitVec<BigEndian, u64>) {
	if this.is_null() { return; }
	(&mut *this).clear();
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l64_clear(this: *mut BitVec<LittleEndian, u64>) {
	if this.is_null() { return; }
	(&mut *this).clear();
}

#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b08_split_off(this: *mut BitVec<BigEndian, u8>, out: *mut BitVec<BigEndian, u8>, at: usize) -> bool {
	if this.is_null()
	|| out.is_null()
	|| at > (&*this).len() {
		return false;
	}
	ptr::write(out, (&mut *this).split_off(at));
	true
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l08_split_off(this: *mut BitVec<LittleEndian, u8>, out: *mut BitVec<LittleEndian, u8>, at: usize) -> bool {
	if this.is_null()
	|| out.is_null()
	|| at > (&*this).len() {
		return false;
	}
	ptr::write(out, (&mut *this).split_off(at));
	true
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b16_split_off(this: *mut BitVec<BigEndian, u16>, out: *mut BitVec<BigEndian, u16>, at: usize) -> bool {
	if this.is_null()
	|| out.is_null()
	|| at > (&*this).len() {
		return false;
	}
	ptr::write(out, (&mut *this).split_off(at));
	true
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l16_split_off(this: *mut BitVec<LittleEndian, u16>, out: *mut BitVec<LittleEndian, u16>, at: usize) -> bool {
	if this.is_null()
	|| out.is_null()
	|| at > (&*this).len() {
		return false;
	}
	ptr::write(out, (&mut *this).split_off(at));
	true
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b32_split_off(this: *mut BitVec<BigEndian, u32>, out: *mut BitVec<BigEndian, u32>, at: usize) -> bool {
	if this.is_null()
	|| out.is_null()
	|| at > (&*this).len() {
		return false;
	}
	ptr::write(out, (&mut *this).split_off(at));
	true
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l32_split_off(this: *mut BitVec<LittleEndian, u32>, out: *mut BitVec<LittleEndian, u32>, at: usize) -> bool {
	if this.is_null()
	|| out.is_null()
	|| at > (&*this).len() {
		return false;
	}
	ptr::write(out, (&mut *this).split_off(at));
	true
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b64_split_off(this: *mut BitVec<BigEndian, u64>, out: *mut BitVec<BigEndian, u64>, at: usize) -> bool {
	if this.is_null()
	|| out.is_null()
	|| at > (&*this).len() {
		return false;
	}
	ptr::write(out, (&mut *this).split_off(at));
	true
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l64_split_off(this: *mut BitVec<LittleEndian, u64>, out: *mut BitVec<LittleEndian, u64>, at: usize) -> bool {
	if this.is_null()
	|| out.is_null()
	|| at > (&*this).len() {
		return false;
	}
	ptr::write(out, (&mut *this).split_off(at));
	true
}

#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b08_resize(this: *mut BitVec<BigEndian, u8>, new_len: usize, value: bool) {
	if this.is_null() { return; }
	(&mut *this).resize(new_len, value);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l08_resize(this: *mut BitVec<LittleEndian, u8>, new_len: usize, value: bool) {
	if this.is_null() { return; }
	(&mut *this).resize(new_len, value);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b16_resize(this: *mut BitVec<BigEndian, u16>, new_len: usize, value: bool) {
	if this.is_null() { return; }
	(&mut *this).resize(new_len, value);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l16_resize(this: *mut BitVec<LittleEndian, u16>, new_len: usize, value: bool) {
	if this.is_null() { return; }
	(&mut *this).resize(new_len, value);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b32_resize(this: *mut BitVec<BigEndian, u32>, new_len: usize, value: bool) {
	if this.is_null() { return; }
	(&mut *this).resize(new_len, value);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l32_resize(this: *mut BitVec<LittleEndian, u32>, new_len: usize, value: bool) {
	if this.is_null() { return; }
	(&mut *this).resize(new_len, value);
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b64_resize(this: *mut BitVec<BigEndian, u64>, new_len: usize, value: bool) {
	if this.is_null() { return; }
	(&mut *this).resize(new_len, value);
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l64_resize(this: *mut BitVec<LittleEndian, u64>, new_len: usize, value: bool) {
	if this.is_null() { return; }
	(&mut *this).resize(new_len, value);
}

#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b08_set_elements(this: *mut BitVec<BigEndian, u8>, element: u8) {
	if this.is_null() { return; }
	(&mut *this).set_elements(element);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l08_set_elements(this: *mut BitVec<LittleEndian, u8>, element: u8) {
	if this.is_null() { return; }
	(&mut *this).set_elements(element);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b16_set_elements(this: *mut BitVec<BigEndian, u16>, element: u16) {
	if this.is_null() { return; }
	(&mut *this).set_elements(element);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l16_set_elements(this: *mut BitVec<LittleEndian, u16>, element: u16) {
	if this.is_null() { return; }
	(&mut *this).set_elements(element);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b32_set_elements(this: *mut BitVec<BigEndian, u32>, element: u32) {
	if this.is_null() { return; }
	(&mut *this).set_elements(element);
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l32_set_elements(this: *mut BitVec<LittleEndian, u32>, element: u32) {
	if this.is_null() { return; }
	(&mut *this).set_elements(element);
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b64_set_elements(this: *mut BitVec<BigEndian, u64>, element: u64) {
	if this.is_null() { return; }
	(&mut *this).set_elements(element);
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l64_set_elements(this: *mut BitVec<LittleEndian, u64>, element: u64) {
	if this.is_null() { return; }
	(&mut *this).set_elements(element);
}

#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b08_clone_from(
	this: *mut BitVec<BigEndian, u8>,
	source: *const BitVec<BigEndian, u8>
) {
	nullck!(this, source);
	ptr::write(this, (&*source).clone());
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l08_clone_from(
	this: *mut BitVec<LittleEndian, u8>,
	source: *const BitVec<LittleEndian, u8>
) {
	nullck!(this, source);
	ptr::write(this, (&*source).clone());
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b16_clone_from(
	this: *mut BitVec<BigEndian, u16>,
	source: *const BitVec<BigEndian, u16>
) {
	nullck!(this, source);
	ptr::write(this, (&*source).clone());
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l16_clone_from(
	this: *mut BitVec<LittleEndian, u16>,
	source: *const BitVec<LittleEndian, u16>
) {
	nullck!(this, source);
	ptr::write(this, (&*source).clone());
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b32_clone_from(
	this: *mut BitVec<BigEndian, u32>,
	source: *const BitVec<BigEndian, u32>
) {
	nullck!(this, source);
	ptr::write(this, (&*source).clone());
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l32_clone_from(
	this: *mut BitVec<LittleEndian, u32>,
	source: *const BitVec<LittleEndian, u32>
) {
	nullck!(this, source);
	ptr::write(this, (&*source).clone());
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b64_clone_from(
	this: *mut BitVec<BigEndian, u64>,
	source: *const BitVec<BigEndian, u64>
) {
	nullck!(this, source);
	ptr::write(this, (&*source).clone());
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l64_clone_from(
	this: *mut BitVec<LittleEndian, u64>,
	source: *const BitVec<LittleEndian, u64>
) {
	nullck!(this, source);
	ptr::write(this, (&*source).clone());
}

#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b08_drop(this: *mut BitVec<BigEndian, u8>) {
	drop(ptr::replace(this, BitVec::new()));
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l08_drop(this: *mut BitVec<LittleEndian, u8>) {
	drop(ptr::replace(this, BitVec::new()));
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b16_drop(this: *mut BitVec<BigEndian, u16>) {
	drop(ptr::replace(this, BitVec::new()));
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l16_drop(this: *mut BitVec<LittleEndian, u16>) {
	drop(ptr::replace(this, BitVec::new()));
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b32_drop(this: *mut BitVec<BigEndian, u32>) {
	drop(ptr::replace(this, BitVec::new()));
}
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l32_drop(this: *mut BitVec<LittleEndian, u32>) {
	drop(ptr::replace(this, BitVec::new()));
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_b64_drop(this: *mut BitVec<BigEndian, u64>) {
	drop(ptr::replace(this, BitVec::new()));
}
#[cfg(target_pointer_width = "64")]
#[no_mangle]
pub unsafe extern "C"
fn bitvec_bv_l64_drop(this: *mut BitVec<LittleEndian, u64>) {
	drop(ptr::replace(this, BitVec::new()));
}
