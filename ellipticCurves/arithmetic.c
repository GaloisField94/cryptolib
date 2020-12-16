#include "ec_p.h"

//----------------------------------------------------------------------------------------------
// High level arithmetics
//----------------------------------------------------------------------------------------------

void ec_p_add(EC_pPoint *rop, const EC_pPoint *op1, const EC_pPoint *op2, const EC_p *curve) {
	//TODO
}

void ec_p_double(EC_pPoint *rop, const EC_pPoint *op, const EC_p *curve) {
	//TODO
}

void ec_p_mul(EC_pPoint *rop, const EC_pPoint *op1, const mpz_t n, const EC_p *curve) {
	//TODO
}

void ec_p_compute_q_h(mpz_t q, mpz_t h, const mpz_t a, const mpz_t b, const mpz_t p) {
	//TODO
}

//----------------------------------------------------------------------------------------------
// Low level arithmetics
//----------------------------------------------------------------------------------------------

void ec_p_add_aff(EC_pPoint *rop, const EC_pPoint *op1, const EC_pPoint *op2, const EC_p *curve) {
//TODO
}

void ec_p_double_aff(EC_pPoint *rop, const EC_pPoint *op, const EC_p *curve) {
//TODO
}

void ec_p_add_pro(EC_pPoint *rop, const EC_pPoint *op1, const EC_pPoint *op2, const EC_p *curve) {
//TODO
}

void ec_p_double_pro(EC_pPoint *rop, const EC_pPoint *op, const EC_p *curve) {
//TODO
}

void ec_p_double_pro_3(EC_pPoint *rop, const EC_pPoint *op, const EC_p *curve) {
//TODO
}