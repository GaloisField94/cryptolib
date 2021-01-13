#include "rijndael.h"
#include "rijndael_consts.h"

//API
void rijndael_enc_ref(unsigned char* ciphertext, const unsigned char* plaintext, const unsigned char* key, const unsigned int Nb, const unsigned int Nk) {

}

void rijndael_enc(unsigned int* ciphertext, const unsigned int* plaintext, const unsigned int* key, const unsigned int Nb, const unsigned int Nk) {

}

void load_key_e(unsigned int* expandedKey, const unsigned int* key) {

}

void rijndael_e(unsigned int* ciphertext, const unsigned int* plaintext, const unsigned int* expandedKey, const unsigned int Nb, const unsigned int Nk) {

}

void rijndael_dec_ref(unsigned char* plaintext, const unsigned char* ciphertext, const unsigned char* key, const unsigned int Nb, const unsigned int Nk) {

}

void rijndael_dec(unsigned int* plaintext, const unsigned int* ciphertext, const unsigned int* key, const unsigned int Nb, const unsigned int Nk) {

}

void load_key_d(unsigned int* expandedKey, const unsigned int* key) {

}

void rijndael_d(unsigned int* plaintext, const unsigned int* ciphertext, const unsigned int* expandedKey, const unsigned int Nb, const unsigned int Nk) {

}
