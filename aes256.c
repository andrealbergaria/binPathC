#include "aes256.h"


int encrypt_file(char *strToEncrypt,aes256_context aesCon,char *file) {





		char bufToPrint[17];
		strncpy(bufToPrint,strToEncrypt,16);
		bufToPrint[17] = '\0';

		printf("\nEncrypting...Text to encrypt -> %s\n",bufToPrint);
		FILE *writeBuffer =  fopen(file ,"wb" );
		int retValue =  -1;
		aes256_encrypt_ecb(&aesCon,strToEncrypt);

		retValue = fwrite(strToEncrypt,1,16,writeBuffer);

		printf("\nWrote bytes  %i to %s ",retValue,file);

		if (fclose(writeBuffer) != 0) {
			perror("\nSomething went wrong on closing the fd");
		}

}
int decrypt_file(aes256_context aesCon,char *file) {


	int fileSize = -1;
	// Trying to decrypt "bbbbb..."

	printf("\nDecrypting...%s",file);
	printKey("decrypt_file",aesCon.key,32);
	FILE *f = fopen(file,"rb");

	fseek(f, 0L, SEEK_END);
	fileSize = ftell(f);

	rewind(f);


	char buf[fileSize];

	int retValue = -1;
	retValue = fread(buf ,1,fileSize ,f);
	if (retValue < 0) {
		perror("(decrypt_file) Couldnt read ciphertext_c");
		exit(-1);
	}
	else
		printf("\nRead bytes : %i",fileSize);

		buf[16]='0';

	aes256_decrypt_ecb(&aesCon,buf);
	printf("\nDecrypted file %s \n" ,buf);



}

int main() {

	aes256_context aesCon;

	char bufToPrint[33];
			for (int i=0; i < 32;i++) {
					aesCon.key[i] = 97;
					aesCon.enckey[i]=97;
					aesCon.deckey[i]=97;
				}


	char *bufToEncrypt="abcdabcdabcdabcd";

	//memset(bufToEncrypt,98,16);



	char *strFile = "/home/andrec/workspace_3_8"
				    "/binPath/files/ciphertext_c";

	char *strFileJava = "/home/andrec/workspace_3_8"
		    			"/binPath/files/ciphertext_java";

	//aes256_init(&aesCon, aesCon.key);
	encrypt_file(bufToEncrypt,aesCon,strFile);
	//decrypt_file(aesCon,strFileJava);



}

void printKey(unsigned char *callingFunction,unsigned char *key,int lenOfKey) {
	char buf[33];
	strncpy(buf,key,32);
	buf[33]= '\0';
	printf("\n%s [%i] Key is : %s\n",callingFunction,strlen(buf),buf);

}

