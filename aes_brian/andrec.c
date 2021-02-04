/*
AES_RETURN aes_encrypt_key256(const unsigned char *key, aes_encrypt_ctx cx[1]);
 * andrec.c
 *
 *  Created on: Feb 4, 2021
 *      Author: andrec
 */
#include <brg_types.h>
#include <aes.h>
int main() {

	unsigned char key[32];
	aes_crypt_ctx cx;
	cx.inf.b[0] = 14 * AES_BLOCK_SIZE;

	aes_encrypt_ctx cx
	memset(key,0x61,32);

	//typedef aes_crypt_ctx aes_encrypt_ctx;
	//typedef aes_crypt_ctx aes_decrypt_ctx;
	AES_RETURN aes_encrypt(const unsigned char *in, unsigned char *out, const aes_encrypt_ctx cx[1]);

}
