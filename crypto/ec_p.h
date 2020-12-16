#ifndef EC_P_H
#define EC_P_H

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
	int isOptimized;
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
 * @brief Names usable for EC_p and EC_pPoint initialization.
 * 
 */
typedef enum{
	brainpoolP160r1,
	brainpoolP160t1,
	brainpoolP192r1,
	brainpoolP192t1,
	brainpoolP224r1,
	brainpoolP224t1,
	brainpoolP256r1,
	brainpoolP256t1,
	brainpoolP320r1,
	brainpoolP320t1,
	brainpoolP384r1,
	brainpoolP384t1,
	brainpoolP512r1,
	brainpoolP512t1,
	secp192k1,
	secp192r1,
	secp224k1,
	secp224r1,
	secp256k1,
	secp256r1,
	secp384r1,
	secp521r1
} EC_pName;

//----------------------------------------------------------------------------------------------
// EC_p inits
//----------------------------------------------------------------------------------------------

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
/**
 * @brief Initialize rop and set all its values.
 * 
 * @param rop 
 * @param a 
 * @param b 
 * @param p 
 * @param q
 * @param h
 */
void ec_p_init_all(EC_p *rop, const mpz_t a, const mpz_t b, const mpz_t p, const mpz_t q, const mpz_t h);
/**
 * @brief Initialize rop and set all its values from null-terminated C strings in base.
 * 
 * @param rop 
 * @param a 
 * @param b 
 * @param p 
 * @param q
 * @param h
 * @param base May vary from 2 to 62, or if is 0, then the leading characters are used: 0x and 0X for hexadecimal, 0b and 0B for binary, 0 for octal, decimal otherwise.
 */
void ec_p_init_all_str(EC_p *rop, const char *a, const char *b, const char *p, const char *q, const char *h, int base);
/**
 * @brief Initialize rop and set all its values accordingly to standards.
 * 
 * @param rop
 * @param name Defines values of curves parameters.
 */
void ec_p_init_name(EC_p *rop, const EC_pName name);

//----------------------------------------------------------------------------------------------
// EC_pPoint inits
//----------------------------------------------------------------------------------------------

/**
 * @brief Initialize rop and set its values x and y (z set to 1).
 * 
 * @param rop 
 * @param x 
 * @param y 
 */
void ec_pPoint_init(EC_pPoint *rop, const mpz_t x, const mpz_t y);
/**
 * @brief Initialize rop and set its values x and y from null-terminated C strings in base (z set to 1).
 * 
 * @param rop 
 * @param x 
 * @param y 
 * @param base May vary from 2 to 62, or if is 0, then the leading characters are used: 0x and 0X for hexadecimal, 0b and 0B for binary, 0 for octal, decimal otherwise.
 */
void ec_pPoint_init_str(EC_pPoint *rop, const char *x, const char *y, int base);
/**
 * @brief Initialize rop and set all its values.
 * 
 * @param rop 
 * @param x 
 * @param y 
 * @param z 
 */
void ec_pPoint_init_all(EC_pPoint *rop, const mpz_t x, const mpz_t y, const mpz_t z);
/**
 * @brief Initialize rop and set all its values from null-terminated C strings in base.
 * 
 * @param rop 
 * @param x 
 * @param y 
 * @param z 
 * @param base May vary from 2 to 62, or if is 0, then the leading characters are used: 0x and 0X for hexadecimal, 0b and 0B for binary, 0 for octal, decimal otherwise.
 */
void ec_pPoint_init_all_str(EC_pPoint *rop, const char *x, const char *y, const char *z, int base);
/**
 * @brief Initialize rop and set all its values accordingly to standards (rop is supposed to be a group generator).
 * 
 * @param rop
 * @param name Defines values of point coordinates.
 */
void ec_pPoint_init_name(EC_pPoint *rop, const EC_pName name);

//----------------------------------------------------------------------------------------------
// High level arithmetics
//----------------------------------------------------------------------------------------------

/**
 * @brief Adds two points on given elliptic curve. Please note that no check if the points belong to the curves additive group is performed.
 * 
 * @param rop The result.
 * @param op1 
 * @param op2 
 * @param curve
 */
void ec_p_add(EC_pPoint *rop, const EC_pPoint *op1, const EC_pPoint *op2, const EC_p *curve);
/**
 * @brief Doubles a point on given elliptic curve. Please note that no check if the point belongs to the curves additive group is performed.
 * 
 * @param rop The result.
 * @param op 
 * @param curve 
 */
void ec_p_double(EC_pPoint *rop, const EC_pPoint *op, const EC_p *curve);
/**
 * @brief Multiplies given point by n on given elliptic curve. Please note that no check if the point belongs to the curves additive group is performed, neither if n < q (the latter is relevant only for performance). 
 * 
 * @param rop The result.
 * @param op1 
 * @param n 
 * @param curve 
 */
void ec_p_mul(EC_pPoint *rop, const EC_pPoint *op1, const mpz_t n, const EC_p *curve);

//----------------------------------------------------------------------------------------------
// MISC
//----------------------------------------------------------------------------------------------

/**
 * @brief Computes parameters q and h given a, b and p.
 * 
 * @param q 
 * @param h 
 * @param a 
 * @param b 
 * @param p 
 */
void ec_p_compute_q_h(mpz_t q, mpz_t h, const mpz_t a, const mpz_t b, const mpz_t p);
/**
 * @brief Compares points on a given elliptic curve.
 * 
 * @param op1 
 * @param op2 
 * @param curve 
 * @return 1 if points are equivalent, 0 otherwise.
 */
int areEqual(const EC_pPoint *op1, const EC_pPoint *op2, const EC_p *curve);
/**
 * @brief Checks if the point is infinite.
 * 
 * @param op 
 * @return 1 if the point is infinite, 0 otherwise.
 */
int isInfinite(const EC_pPoint *op);
/**
 * @brief Checks if a = -3 (mod p)
 * 
 * @param op 
 * @return 1 if a = -3 (mod p), 0 otherwise.  
 */
int isOptimized(const EC_p *op);

//----------------------------------------------------------------------------------------------
// Low level arithmetics
//----------------------------------------------------------------------------------------------

/**
 * @brief Adds two points on given elliptic curve. Please note that no check if the points belong to the curves additive group is performed.
 * 
 * @param rop The result.
 * @param op1 
 * @param op2 
 * @param curve
 */
void ec_p_add_aff(EC_pPoint *rop, const EC_pPoint *op1, const EC_pPoint *op2, const EC_p *curve);
/**
 * @brief Doubles a point on given elliptic curve. Please note that no check if the point belongs to the curves additive group is performed.
 * 
 * @param rop The result.
 * @param op 
 * @param curve 
 */
void ec_p_double_aff(EC_pPoint *rop, const EC_pPoint *op, const EC_p *curve);
/**
 * @brief Adds two points on given elliptic curve. Please note that no check if the points belong to the curves additive group is performed.
 * 
 * @param rop The result.
 * @param op1 
 * @param op2 
 * @param curve
 */
void ec_p_add_pro(EC_pPoint *rop, const EC_pPoint *op1, const EC_pPoint *op2, const EC_p *curve);
/**
 * @brief Doubles a point on given elliptic curve. Please note that no check if the point belongs to the curves additive group is performed.
 * 
 * @param rop The result.
 * @param op 
 * @param curve 
 */
void ec_p_double_pro(EC_pPoint *rop, const EC_pPoint *op, const EC_p *curve);
/**
 * @brief Doubles a point on given elliptic curve, where a = -3 (mod p). Please note that no check if the point belongs to the curves additive group or if a = -3 (mod p) is performed.
 * 
 * @param rop The result.
 * @param op 
 * @param curve 
 */
void ec_p_double_pro_3(EC_pPoint *rop, const EC_pPoint *op, const EC_p *curve);

#endif
