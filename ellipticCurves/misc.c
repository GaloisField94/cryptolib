#include "ec_p.h"

//----------------------------------------------------------------------------------------------
// MISC
//----------------------------------------------------------------------------------------------

void ec_p_compute_q_h(mpz_t q, mpz_t h, const mpz_t a, const mpz_t b, const mpz_t p) {
	//TODO
}

int areEqual(const EC_pPoint *op1, const EC_pPoint *op2, const EC_p *curve) {
	//TODO
	return 0;
}

int isInfinite(const EC_pPoint *op) {
	return (0 == mpz_sgn(op->z) ? 1 : 0);
}

int isOptimized(const EC_p *op) {
	//TODO
	return 0;
}