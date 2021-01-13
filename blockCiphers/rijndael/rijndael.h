#ifndef RIJNDAEL_H
#define RIJNDAEL_H

#define aesenc_128(a, b, c) rijndael_enc_ref(a, b, c, 4, 4)
#define aesenc_192(a, b, c) rijndael_enc_ref(a, b, c, 4, 6)
#define aesenc_256(a, b, c) rijndael_enc_ref(a, b, c, 4, 8)
#define aesdec_128(a, b, c) rijndael_dec_ref(a, b, c, 4, 4)
#define aesdec_192(a, b, c) rijndael_dec_ref(a, b, c, 4, 6)
#define aesdec_256(a, b, c) rijndael_dec_ref(a, b, c, 4, 8)

/**
 * @brief Unoptimized version, that follows the specification step by step.
 * 
 * @param ciphertext 
 * @param plaintext 
 * @param key 
 * @param Nb 
 * @param Nk 
 */
void rijndael_enc_ref(unsigned char* ciphertext, const unsigned char* plaintext, const unsigned char* key, const unsigned int Nb, const unsigned int Nk);
/**
 * @brief Version using T-tables, optimized for 32 and more bit platforms.
 * 
 * @param ciphertext 
 * @param plaintext 
 * @param key 
 * @param Nb 
 * @param Nk 
 */
void rijndael_enc(unsigned int* ciphertext, const unsigned int* plaintext, const unsigned int* key, const unsigned int Nb, const unsigned int Nk);
/**
 * @brief Performs key schedule routine for encryption.
 * 
 * @param expandedKey 
 * @param key 
 */
void load_key_e(unsigned int* expandedKey, const unsigned int* key);
/**
 * @brief Version using T-tables, optimized for 32 and more bit platforms. One must call load_key_e() beforehand.
 * 
 * @param ciphertext 
 * @param plaintext 
 * @param expandedKey 
 * @param Nb 
 * @param Nk 
 */
void rijndael_e(unsigned int* ciphertext, const unsigned int* plaintext, const unsigned int* expandedKey, const unsigned int Nb, const unsigned int Nk);
/**
 * @brief Unoptimized version, that follows the specification step by step.
 * 
 * @param plaintext 
 * @param ciphertext 
 * @param key 
 * @param Nb 
 * @param Nk 
 */
void rijndael_dec_ref(unsigned char* plaintext, const unsigned char* ciphertext, const unsigned char* key, const unsigned int Nb, const unsigned int Nk);
/**
 * @brief Version using T-tables, optimized for 32 and more bit platforms.
 * 
 * @param plaintext 
 * @param ciphertext 
 * @param key 
 * @param Nb 
 * @param Nk 
 */
void rijndael_dec(unsigned int* plaintext, const unsigned int* ciphertext, const unsigned int* key, const unsigned int Nb, const unsigned int Nk);
/**
 * @brief Performs key schedule routine for decryption.
 * 
 * @param expandedKey 
 * @param key 
 */
void load_key_d(unsigned int* expandedKey, const unsigned int* key);
/**
 * @brief Version using T-tables, optimized for 32 and more bit platforms. One must call load_key_d() beforehand.
 * 
 * @param ciphertext 
 * @param plaintext 
 * @param expandedKey 
 * @param Nb 
 * @param Nk 
 */
void rijndael_d(unsigned int* plaintext, const unsigned int* ciphertext, const unsigned int* expandedKey, const unsigned int Nb, const unsigned int Nk);

#endif