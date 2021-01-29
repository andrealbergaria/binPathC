#include "aes256.h"

void encrypt_file(u_char *stuffToBeEncrypted,aes256_context aesCon) {

	printf("[aes256.c] encrypting...\n");


		printf("\nEncrypting...Text to encrypt -> ");
		for (int i=0; i < 32;i++) {
			printf("%c",stuffToBeEncrypted[i]);
		}
		printf("\n");



		aes256_encrypt_ecb(&aesCon,stuffToBeEncrypted);

		int retValue =  -1;
		FILE *fileToWrite =  fopen(cipherTextFile ,"wb" );

		if (fileToWrite == NULL) {
			printf("\nCouldnt open file %s",cipherTextFile);
			perror("Error on open file to write");
			exit(-1);
		}
		retValue = fwrite(stuffToBeEncrypted,1,32,fileToWrite);

		if (retValue != 32) {
			perror("coudlnt write encrypted buffer to file");
			exit(-1);
		}
		printf("\nWrote bytes  %i to %s ",retValue,cipherTextFile);

		if (fclose(fileToWrite) != 0) {
			perror("\nSomething went wrong on closing the fd");
		}
		printf("\n[encrypt_file] finished");

}

