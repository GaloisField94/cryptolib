#ifndef EC_H
#define EC_H

#include "gmp.h"

/**
 * @brief An elliptic curve over a prime field GF(p).
 * 
 */
typedef struct{
	mpz_t a;
	mpz_t b;
	mpz_t p;
	mpz_t q;
	mpz_t h;
} EC_p;
/**
 * @brief A point possibly fulfilling an elliptic curve equation over a prime field GF(p).
 * 
 */
typedef struct{
	mpz_t x;
	mpz_t y;
	mpz_t z;
} EC_pPoint;
/**
 * @brief Initialize rop and set its values a, b and p (q, h set to 0).
 * 
 * @param rop 
 * @param a 
 * @param b 
 * @param p 
 */
void ec_p_init(EC_p *rop, const mpz_t a, const mpz_t b, const mpz_t p);
/**
 * @brief Initialize rop and set its values a, b and p from null-terminated C strings in base (q, h set to 0).
 * 
 * @param rop 
 * @param a 
 * @param b 
 * @param p 
 * @param base May vary from 2 to 62, or if is 0, then the leading characters are used: 0x and 0X for hexadecimal, 0b and 0B for binary, 0 for octal, decimal otherwise.
 */
void ec_p_init_str(EC_p *rop, const char *a, const char *b, const char *p, int base);
/**
 * @brief Initialize rop and set its values a, b and p, then compute q, h. 
 * 
 * @param rop 
 * @param a 
 * @param b 
 * @param p 
 */
void ec_p_init_compute_q_h(EC_p *rop, const mpz_t a, const mpz_t b, const mpz_t p);
/**
 * @brief Initialize rop and set its values a, b and p from null-terminated C strings in base, then compute q, h.
 * 
 * @param rop 
 * @param a 
 * @param b 
 * @param p 
 * @param base May vary from 2 to 62, or if is 0, then the leading characters are used: 0x and 0X for hexadecimal, 0b and 0B for binary, 0 for octal, decimal otherwise.
 */
void ec_p_init_compute_q_h_str(EC_p *rop, const char *a, const char *b, const char *p, int base);

#endif