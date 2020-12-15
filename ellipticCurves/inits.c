#include "ec_p.h"

//----------------------------------------------------------------------------------------------
// EC_p inits
//----------------------------------------------------------------------------------------------
void ec_p_init(EC_p *rop, const mpz_t a, const mpz_t b, const mpz_t p) {
	mpz_inits(rop->a, rop->b, rop->p, rop->q, rop->h, NULL);
	mpz_set(rop->a, a);
	mpz_set(rop->b, b);
	mpz_set(rop->p, p);
}

void ec_p_init_str(EC_p *rop, const char *a, const char *b, const char *p, int base) {
	mpz_inits(rop->a, rop->b, rop->p, rop->q, rop->h, NULL);
	mpz_set_str(rop->a, a, base);
	mpz_set_str(rop->b, b, base);
	mpz_set_str(rop->p, p, base);
}

void ec_p_init_compute_q_h(EC_p *rop, const mpz_t a, const mpz_t b, const mpz_t p) {
	//TODO
}

void ec_p_init_compute_q_h_str(EC_p *rop, const char *a, const char *b, const char *p, int base) {
	//TODO
}

void ec_p_init_all(EC_p *rop, const mpz_t a, const mpz_t b, const mpz_t p, const mpz_t q, const mpz_t h) {
	mpz_inits(rop->a, rop->b, rop->p, rop->q, rop->h, NULL);
	mpz_set(rop->a, a);
	mpz_set(rop->b, b);
	mpz_set(rop->p, p);
	mpz_set(rop->q, q);
	mpz_set(rop->h, h);
}

void ec_p_init_all_str(EC_p *rop, const char *a, const char *b, const char *p, const char *q, const char *h, int base) {
	mpz_inits(rop->a, rop->b, rop->p, rop->q, rop->h, NULL);
	mpz_set_str(rop->a, a, base);
	mpz_set_str(rop->b, b, base);
	mpz_set_str(rop->p, p, base);
	mpz_set_str(rop->q, q, base);
	mpz_set_str(rop->h, h, base);
}

void ec_p_init_name(EC_p *rop, const EC_pName name) {
	mpz_inits(rop->a, rop->b, rop->p, rop->q, rop->h, NULL);
	switch(name) {
		case brainpoolP160r1: 
			return;
		default: 
			return;	
	}
}

//----------------------------------------------------------------------------------------------
// EC_pPoint inits
//----------------------------------------------------------------------------------------------
void ec_pPoint_init(EC_pPoint *rop, const mpz_t x, const mpz_t y) {
	mpz_inits(rop->x, rop->y, rop->z, NULL);
	mpz_set(rop->x, x);
	mpz_set(rop->y, y);
	mpz_set_si(rop->z, 1);
}

void ec_pPoint_init_str(EC_pPoint *rop, const char *x, const char *y, int base) {
	mpz_inits(rop->x, rop->y, rop->z, NULL);
	mpz_set_str(rop->x, x, base);
	mpz_set_str(rop->y, y, base);
	mpz_set_si(rop->z, 1);
}

void ec_pPoint_init_all(EC_pPoint *rop, const mpz_t x, const mpz_t y, const mpz_t z) {
	mpz_inits(rop->x, rop->y, rop->z, NULL);
	mpz_set(rop->x, x);
	mpz_set(rop->y, y);
	mpz_set(rop->z, z);
}

void ec_pPoint_init_all_str(EC_pPoint *rop, const char *x, const char *y, const char *z, int base) {
	mpz_inits(rop->x, rop->y, rop->z, NULL);
	mpz_set_str(rop->x, x, base);
	mpz_set_str(rop->y, y, base);
	mpz_set_str(rop->z, z, base);
}

void ec_pPoint_init_name(EC_pPoint *rop, const EC_pName name) {
	mpz_inits(rop->x, rop->y, rop->z, NULL);
	switch(name) {
		case brainpoolP160r1: 
			return;
		default: 
			return;	
	}
}
