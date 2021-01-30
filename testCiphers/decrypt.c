#include "aes256.h"
#include <sys/time.h>

#define cipherTextFile "/home/andrec/workspace_c/binPathC/testCiphers/cipherTextRaw"



void getDate() {
		time_t t;
		time(&t);

		char *beginTimeSecs = ctime(&t);
		printf("\n[decrypt.c getDate() : %s",beginTimeSecs);

}

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

	//u_char key[] = {0x61,0x61,0x61,0x61};


/*		memset(&(aesCon.key),0,32);
		memset(&(aesCon.enckey),0,32);
		memset(&(aesCon.deckey),0,32);


		memcpy(&(aesCon.key[0]),(int *)&key,4);
		memcpy(&(aesCon.enckey[0]),(int *)&key,4);
		memcpy(&(aesCon.deckey[0]),(int *)&key,4);
*/



	decrypt_file(cipherText);

}

void printKey(aes256_context *ctx) {
	printf("\nKey : [ ");
	for (int i = 0;i < sizeof(ctx->key); i++)
		printf("%i ",ctx->key[i]);
	printf(" ] ");
}


void decrypt_file(u_char *cipherText) {


	aes256_context ctx;


	//u_char cipherTextBlock1[16];
//	u_char cipherTextBlock2[16];


//	memcpy(cipherTextBlock1,cipherText,16);
//	memcpy(cipherTextBlock2,cipherText+16,16);

//	aes256_decrypt_ecb(&aesCon,cipherTextBlock2);
	/*memset(&aesCon.key,0,sizeof(aesCon.key));
	memset(&aesCon.enckey,0,sizeof(aesCon.enckey));
	memset(&aesCon.deckey,0,sizeof(aesCon.deckey));
	*/
	memset(ctx.key,0,32);

	ctx.key[0]=0x61;
	ctx.key[1]=0x61;
	ctx.key[2]=0x61;
	ctx.key[3]=0x61;

	memcpy(ctx.deckey,ctx.key,32);
	memcpy(ctx.enckey,ctx.key,32);

// from aes256_lib, aes256_init_aux
	uint8_t rcon = 1;

    for (int i = 8; --i;) aes_expandEncKey((uint8_t *)&(ctx.deckey), &rcon);





    getDate();

    	//int numCombs = intSize/4;
		//int numCombs = 65536;
    int multiple=131072;
   // int interval = 8192;
    // Check for 4 bytes
    //int totalCombinations= 256*256*256*256;
    	int totalCombinations=4;
		for (int k=0 ; k < totalCombinations ;k++) {

			ctx.key[0] += 4;
			ctx.key[1] += 4;
			ctx.key[2] += 4;
			ctx.key[3] += 4;

			// Multiple = k * interval
			if (multiple == (8192 * k)) {
				getDate();
				printf("\nSearched %i of a total of %i",multiple,totalCombinations);
				printKey(&ctx);
				multiple+=131072;
			}

			aes256_decrypt_ecb(&ctx,cipherText);
			printf("\nDeciphered => ");
			printKey(&ctx);

		}
		getDate();
	/*u_char *plainText = (u_char *) malloc(17);
	for (int i=0; i < 16 ; i++) {
		plainText[i] = cipherTextBlock1[i] ^ cipherTextBlock2[i];
	}
	plainText[16] = '\0';
*/
	printf("\nPlaintext : %s",cipherText);
	free(cipherText);

}
