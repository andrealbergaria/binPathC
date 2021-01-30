#include "aes256.h"

#define cipherTextFile "/home/andrec/workspace_c/binPathC/testCiphers/cipherTextRaw"

int main() {
	u_char bufferToEncrypt[32];


				memset(bufferToEncrypt,0x61,16);
				memset(bufferToEncrypt+16,0x62,16);
				unsigned int key = 0x61616161;
				encrypt_file(bufferToEncrypt,key);
}

void encrypt_file(u_char *stuffToBeEncrypted,unsigned int keyParam) {

	printf("[aes256.c] encrypting...\n");
		aes256_context ctx;

		uint8_t key[32];
		memset(key,0,32);

		key[0]=0x61;
		key[1]=0x61;
		key[2]=0x61;
		key[3]=0x61;

		memcpy(ctx.deckey,key,32);
		memcpy(ctx.enckey,key,32);

		printf("\nEncrypting...Text to encrypt -> ");
		for (int i=0; i < 32;i++) {
			printf("%02x ",stuffToBeEncrypted[i]);
		}
		printf("\n");



		aes256_encrypt_ecb(&ctx,stuffToBeEncrypted);
		aes256_encrypt_ecb(&ctx,stuffToBeEncrypted+16);

		int retValue =  -1;
		FILE *fileToWrite =  fopen(cipherTextFile ,"wb" );

		if (fileToWrite == NULL) {
			printf("\n[encrypt.c] Couldnt open file %s",cipherTextFile);
			perror("Error on open file to write");
			exit(-1);
		}
		retValue = fwrite(stuffToBeEncrypted,1,32,fileToWrite);

		if (retValue != 32) {
			perror("[encrypt.c] coudlnt write encrypted buffer to file");
			exit(-1);
		}
		printf("\n[encrpypt.c] Wrote bytes  %i to %s ",retValue,cipherTextFile);

		if (fclose(fileToWrite) != 0) {
			perror("\n[encrypt.c] Something went wrong on closing the fd");
		}
	    aes256_done(&ctx);
		printf("\n[encrypt.c] finished");

}

