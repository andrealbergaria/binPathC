/*
 * aesCBC.c
 *
 *  Created on: Feb 4, 2021
 *      Author: andrec
 */
#include <wolfssl/wolfcrypt/aes.h>

Aes enc;

Aes dec;



const byte key[] = {  /*some 24 byte key*/ };

const byte iv[] = { /*some 16 byte iv*/ };



byte plain[32];   /*an increment of 16, fill with data*/

byte cipher[32];



/*encrypt*/

wc_AesSetKey(&enc, key, sizeof(key), iv, AES_ENCRYPTION);

wc_AesCbcEncrypt(&enc, cipher, plain, sizeof(plain));



cipher now contains the ciphertext from the plain text.



/*decrypt*/

wc_AesSetKey(&dec, key, sizeof(key), iv, AES_DECRYPTION);

wc_AesCbcDecrypt(&dec, plain, cipher, sizeof(cipher));



plain now contains the original plaintext from the ciphertext.

