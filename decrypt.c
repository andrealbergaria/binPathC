#include "aes256.h"

void decrypt_file(aes256_context aesCon) {



	printf("\nDecrypting...%s",cipherTextFile);


	FILE *f = fopen(cipherTextFile,"rb");

	int retValue = -1;
	u_char cipherTextBlock1[16];
	u_char cipherTextBlock2[16];

	retValue = fread(cipherTextBlock1,1,16 ,f);
	retValue = fread(cipherTextBlock2,1,16 ,f);

	if (retValue < 0) {
		perror("(decrypt_file) Couldnt read ciphertext_c");
		exit(-1);
	}

	aes256_decrypt_ecb(&aesCon,cipherTextBlock2);


	u_char *plainText = (u_char *) malloc(17);
	for (int i=0; i < 16 ; i++) {
		plainText[i] = cipherTextBlock1[i] ^ cipherTextBlock2[i];
	}
	plainText[16] = '\0';

	printf("\nPlaintext : %s",plainText);

}
