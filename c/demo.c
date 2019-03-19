/**
 * @file c/demo.c
 *
 * @brief Demonstration file using the C bindings to libbitvec.
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "bitvec/lib.h"

int main(int argc, char* argv[]) {
	//  init
	struct BitVecB08 bv;
	bitvec_bv_b08_new(RSBV_BV(bv));

	//  modify
	bitvec_bv_b08_push(RSBV_BV(bv), true);
	bitvec_bv_b08_push(RSBV_BV(bv), false);

	//  view
	printf("bv has %llu bits stored\n", bitvec_bs_b08_len(RSBV_BV_IMMUT(bv)));
	printf("The first bit in bv is %i\n", bitvec_bs_b08_get(RSBV_BV_IMMUT(bv), 0));
	printf("The second bit in bv is %i\n", bitvec_bs_b08_get(RSBV_BV_IMMUT(bv), 1));
	printf("The third bit in bv is an error: %i\n", bitvec_bs_b08_get(RSBV_BV_IMMUT(bv), 2));

	//  copy
	struct BitVecB08 bv2;
	bitvec_bv_b08_clone_from(RSBV_BV(bv2), RSBV_BV(bv));

	//  modify
	bitvec_bs_b08_set(RSBV_BV_MUT(bv2), 0, false);
	bitvec_bs_b08_set(RSBV_BV_MUT(bv2), 1, true);
	printf("The first bit in bv2 is now %i\n", bitvec_bs_b08_get(RSBV_BV_IMMUT(bv2), 0));
	printf("The second bit in bv2 is now %i\n", bitvec_bs_b08_get(RSBV_BV_IMMUT(bv2), 1));
	printf("The third bit in bv2 is still an error: %i\n", bitvec_bs_b08_get(RSBV_BV_IMMUT(bv2), 2));

	//  free
	bitvec_bv_b08_drop(RSBV_BV(bv2));
	bitvec_bv_b08_drop(RSBV_BV(bv));
	return 0;
}
