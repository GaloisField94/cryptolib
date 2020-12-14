#include "ec.h"

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