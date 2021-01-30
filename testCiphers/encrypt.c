#include "aes256.h"

int main() {
	u_char bufferToEncrypt[32];


				memset(bufferToEncrypt,0x61,16);
				memset(bufferToEncrypt+16,0x62,16);
				unsigned int key = 0x61616161;
				encrypt_file(bufferToEncrypt,key);
}

void encrypt_file(u_char *stuffToBeEncrypted,unsigned int key) {

	printf("[aes256.c] encrypting...\n");
	aes256_context aesCon;

	memset(&aesCon.key,0,32);
	memset(&aesCon.enckey,0,32);
	memset(&aesCon.deckey,0,32);


	memcpy(&aesCon.key,(int *)&key,4);
	memcpy(&aesCon.enckey,(int *)&key,4);
	memcpy(&aesCon.deckey,(int *)&key,4);

	aes256_init(&aesCon,(uint8_t *)&key);


		printf("\nEncrypting...Text to encrypt -> ");
		for (int i=0; i < 32;i++) {
			printf("%c",stuffToBeEncrypted[i]);
		}
		printf("\n");



		aes256_encrypt_ecb(&aesCon,stuffToBeEncrypted);

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
	    aes256_done(&aesCon);
		printf("\n[encrypt.c] finished");

}

