#include "aes256.h"
#include "util.h"

#define cipherTextFile "/home/andrec/workspace_c/binPathC/testCiphers/cipherTextRaw"




int main() {
	u_char *cipherText = (u_char *) malloc(32);
	int retValue;

	char *filename="/home/andrec/workspace_c/binPathC/testCiphers/limits";
	cipherText = readFileToArray(filename) {
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

void printKey(u_int8_t key[]  ,int sizeKey,char hexa) {
	printf("\nKey : [ ");
	for (int i = 0;i < sizeKey; i++)
		if (hexa==1)
			printf("%02x ",key[i]);
		else
			printf("%i ",key[i]);
	printf(" ] ");
}

//https://stackoverflow.com/questions/6687467/converting-char-array-to-long-in-c
void longToCharArray(long l,int *key) {

	key[0] = l         & 0xFF;
	key[1] = (l >>  8) & 0xFF;
	key[2] = (l >> 16) & 0xFF;
	key[3] = (l >> 24) & 0xFF;

}


long charArrayToLong(long l,int *key) {
	l = key[0] | (key[1] << 8) | (key[2] << 16) | (key[3] << 24);
	return l;


}
//https://stackoverflow.com/questions/9721042/count-number-of-digits-which-method-is-most-efficient
int count_digits(int arg) {
    return snprintf(NULL, 0, "%d", arg) - (arg < 0);
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
	ctx.key[0] = 0;
	ctx.key[1] = 1;
	ctx.key[2] = 2;
	ctx.key[3] = 3;
	/*ctx.key[1]=0x1;
	ctx.key[2]=0x2;
	ctx.key[3]=0x3;
*/
	printKey(ctx.key,1);
	memcpy(ctx.deckey,ctx.key,32);
	memcpy(ctx.enckey,ctx.key,32);

// from aes256_lib, aes256_init_aux
	uint8_t rcon = 1;

    for (int i = 8; --i;) aes_expandEncKey((uint8_t *)&(ctx.deckey), &rcon);





    getDate();

    	//int numCombs = intSize/4;
		//int numCombs = 65536;
    int multiple=131072;
    int interval = 4096;
    // Check for 4 bytes
    int maxAttempt= 256*256*256*32; // brutesforce 4 bytes (256 can't be because compiler says overflow

    int totalCombinations = maxAttempt/256;

    int writeTime=0;
    //https://stackoverflow.com/questions/6687467/converting-char-array-to-long-in-c

    aes256_context temp;
    int min=0;
    int max=interval;

		for (register int l=min ; l < max ;l++) {
			printf("Min : %i ... Max : %i .... NumDigits : %i",l,max,count_digits(l));
			longToCharArray(l,&ctx.key,32);
			// Multiple = k * interval
			if (multiple == (4096 * l)) {
				printf("\n%s",getDate());
				printf("\nSearched %i of a total of %i",l,max);
				printKey(&ctx,1);
				multiple+=131072;
				char *filename = "/home/andrec/workspace_c/binPathC/testCiphers/limits";
				writeToFile(min,max,filename);
			}


			memcpy(&temp,ctx.key,32);
			memcpy(&temp,ctx.deckey,32);
			memcpy(&temp,ctx.enckey,32);

			aes256_decrypt_ecb(&temp,cipherText);



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
