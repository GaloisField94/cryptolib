#ifndef HASH_H
#define HASH_H

/**
 * @brief Possible values returned from any hash function.
 * 
 */
typedef enum {
	hashSuccess,
	hashError
} hashResult;

/**
 * @brief Computes the value of SHA1 function.
 * 
 * @param rop The resulting 160-bit message digest.
 * @param op Data.
 * @param n Number of bytes in *op*.
 * @return *hashSuccess* if no errors during computation occured, *hashError* otherwise. 
 */
hashResult sha1(unsigned char *rop, const unsigned char *op, size_t n);
/**
 * @brief Computes the value of SHA224 function.
 * 
 * @param rop The resulting 224-bit message digest.
 * @param op Data.
 * @param n Number of bytes in *op*.
 * @return *hashSuccess* if no errors during computation occured, *hashError* otherwise. 
 */
hashResult sha224(unsigned char *rop, const unsigned char *op, size_t n);
/**
 * @brief Computes the value of SHA256 function.
 * 
 * @param rop The resulting 256-bit message digest.
 * @param op Data.
 * @param n Number of bytes in *op*.
 * @return *hashSuccess* if no errors during computation occured, *hashError* otherwise. 
 */
hashResult sha256(unsigned char *rop, const unsigned char *op, size_t n);
/**
 * @brief Computes the value of SHA384 function.
 * 
 * @param rop The resulting 384-bit message digest.
 * @param op Data.
 * @param n Number of bytes in *op*.
 * @return *hashSuccess* if no errors during computation occured, *hashError* otherwise. 
 */
hashResult sha384(unsigned char *rop, const unsigned char *op, size_t n);
/**
 * @brief Computes the value of SHA512 function.
 * 
 * @param rop The resulting 512-bit message digest.
 * @param op Data.
 * @param n Number of bytes in *op*.
 * @return *hashSuccess* if no errors during computation occured, *hashError* otherwise. 
 */
hashResult sha512(unsigned char *rop, const unsigned char *op, size_t n);

#endif