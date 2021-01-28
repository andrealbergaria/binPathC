#include "aes256.h"

#define cipherTextFile "/home/andre/workspace_3_8/binPathC/files/cipherText"
int encrypt_file(u_char *stuffToBeEncrypted,aes256_context aesCon) {

	printf("[aes256.c] encrypting...\n");


		printf("\nEncrypting...Text to encrypt -> ");
		for (int i=0; i < 32;i++) {
			printf("%c",stuffToBeEncrypted[i]);
		}
		printf("\n");



		aes256_encrypt_ecb(&aesCon,stuffToBeEncrypted);

		int retValue =  -1;
		FILE *fileToWrite =  fopen(file ,"wb" );

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

		if (fclose(writeBuffer) != 0) {
			perror("\nSomething went wrong on closing the fd");
		}
		printf("\n[encrypt_file] finished");

}
int decrypt_file(aes256_context aesCon,char *file) {



	printf("\nDecrypting...%s",file);
	printKey("decrypt_file",aesCon.key,32);

	FILE *f = fopen(file,"rb");

	char buf[32];

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

int main() {

	aes256_context aesCon;
	u_char bufferToEncrypt[16];
	u_char bufToPrint[33];
			for (int i=0; i < 32;i++) {
					aesCon.key[i] = 97;
					aesCon.enckey[i]=97;
					aesCon.deckey[i]=97;
				}


			memset(bufferToEncrypt,0x61,8);
			memset(bufferToEncrypt+8,0x62,8);


			int ret=-1;



	char *strFile = "/home/andrec/workspace_3_8"
				    "/binPathC/files/cipherText";



	ret = sprintf(bufToPrint,"%i",aesCon.key);

	if (ret != 32) {
		printf("\nCouldnt convert key to buffer");
		exit(-1);
	}

	printf("\nKey used %s",bufToPrint);

	encrypt_file(bufferToEncrypt,aesCon);
//	decrypt_file(aesCon,strFileJava);



}


void printKey(unsigned char *callingFunction,unsigned char *key,int lenOfKey) {
	char buf[33];
	strncpy(buf,key,32);
	buf[33]= '\0';
	printf("\n%s [%i] Key is : %s\n",callingFunction,strlen(buf),buf);

}

