/*  
*   Byte-oriented AES-256 implementation.
*   All lookup tables replaced with 'on the fly' calculations. 
*
*   Copyright (c) 2007 Ilya O. Levin, http://www.literatecode.com
*
*   Permission to use, copy, modify, and distribute this software for any
*   purpose with or without fee is hereby granted, provided that the above
*   copyright notice and this permission notice appear in all copies.
*
*   THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
*   WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
*   MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
*   ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
*   WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
*   ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
*   OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/
#include "util.h"
#include "aes256.h"

int main (int argc, char *argv[])
{
    aes256_context ctx; 
    unsigned char key[32];
    unsigned char buf[16];



    /* put a test vector */
  //  for (i = 0; i < sizeof(buf);i++) buf[i] = i * 16 + i;
   // for (i = 0; i < sizeof(key);i++) key[i] = i;
    memset(key,0,32);
    key[0] = 0x61;
    key[1] = 0x61;
    key[2] = 0x61;

    verbosePrint(key,"key",32);
    // By me
    /*DUMP("txt: ", i, buf, sizeof(buf));
    DUMP("key: ", i, key, sizeof(key));
    printf("---\n");*/

    aes256_init(&ctx, key);
    aes256_encrypt_ecb(&ctx, buf);

    verbosePrint(buf,"buf",16);
    //printf("tst: 8e a2 b7 ca 51 67 45 bf ea fc 49 90 4b 49 60 89\n");


    aes256_init(&ctx, key);
    aes256_decrypt_ecb(&ctx, buf);
    verbosePrint(buf,"buf",16);
    //DUMP("dec: ", i, buf, sizeof(buf));

    aes256_done(&ctx);

    return 0;
} /* main */
