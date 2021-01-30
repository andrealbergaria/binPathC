#include "aes256.h"

int main() {
	u_char *cipherText = (u_char *) malloc(32);
	int retValue;

	FILE *f = fopen(cipherTextFile,"r");
	if (f == NULL) {
		perror("[decrypt.c fopen() cipherTextFile");
		exit(-1);
	}
	else {
		printf("\n[decrypt.c] opened cipherTextFile");
	}


	retValue = fread((u_char *)cipherText,1,32,f);
	if (retValue != 32) {
		perror("\n[decrypt.c] couldnt read cipher text file");
	}
	else {
		printf("\n[ðecrypt.c] read cipherTextFile size :  %i",retValue);
	}
	u_char key[] = {0x61,0x61,0x61,0x61};
	aes256_context aesCon;

/*		memset(&(aesCon.key),0,32);
		memset(&(aesCon.enckey),0,32);
		memset(&(aesCon.deckey),0,32);


		memcpy(&(aesCon.key[0]),(int *)&key,4);
		memcpy(&(aesCon.enckey[0]),(int *)&key,4);
		memcpy(&(aesCon.deckey[0]),(int *)&key,4);
*/
		aes256_init(&aesCon,key);



	decrypt_file(aesCon,cipherText);
}

void decrypt_file(aes256_context aesCon,u_char *cipherText) {

	//u_char cipherTextBlock1[16];
//	u_char cipherTextBlock2[16];


//	memcpy(cipherTextBlock1,cipherText,16);
//	memcpy(cipherTextBlock2,cipherText+16,16);

//	aes256_decrypt_ecb(&aesCon,cipherTextBlock2);
	aes256_decrypt_ecb(&aesCon,cipherText);


	/*u_char *plainText = (u_char *) malloc(17);
	for (int i=0; i < 16 ; i++) {
		plainText[i] = cipherTextBlock1[i] ^ cipherTextBlock2[i];
	}
	plainText[16] = '\0';
*/
	printf("\nPlaintext : %s",cipherText);
	aes256_done(&aesCon);

}
