#include "util.h"
#include "aes256.h"
#define cipherTextFile "/home/andrec/workspace_c/binPathC/testCiphers/cipherTextRaw"


int main() {


	uint8_t *cipherText = (uint8_t *) malloc(32);


	char *filename="/home/andrec/workspace_c/binPathC/testCiphers/limits";
	cipherText = readFileToArray(filename);
	//uint8_t key[] = {0x61,0x61,0x61,0x61};


/*		memset(&(aesCon.key),0,32);
		memset(&(aesCon.enckey),0,32);
		memset(&(aesCon.deckey),0,32);


		memcpy(&(aesCon.key[0]),(int *)&key,4);
		memcpy(&(aesCon.enckey[0]),(int *)&key,4);
		memcpy(&(aesCon.deckey[0]),(int *)&key,4);
*/



	decrypt_file(cipherText);

}


//https://stackoverflow.com/questions/8304259/formatting-struct-timespec

void decrypt_file(uint8_t *cipherText) {


	aes256_context ctx;


	//uint8_t cipherTextBlock1[16];
//	uint8_t cipherTextBlock2[16];


//	memcpy(cipherTextBlock1,cipherText,16);
//	memcpy(cipherTextBlock2,cipherText+16,16);

//	aes256_decrypt_ecb(&aesCon,cipherTextBlock2);
	/*memset(&aesCon.key,0,sizeof(aesCon.key));
	memset(&aesCon.enckey,0,sizeof(aesCon.enckey));
	memset(&aesCon.deckey,0,sizeof(aesCon.deckey));
	*/
	memset(ctx.key,0,32);
	ctx.key[0] = 0x61;
	ctx.key[1] = 0x61;
	ctx.key[2] = 0x61;

	printKey(ctx.key,32);
	memcpy(ctx.deckey,ctx.key,32);
	memcpy(ctx.enckey,ctx.key,32);

// from aes256_lib, aes256_init_aux
	uint8_t rcon = 1;

    for (int i = 8; --i;) aes_expandEncKey(ctx.deckey, &rcon);







    	//int numCombs = intSize/4;
		//int numCombs = 65536;
    int multiple=65536;

    // Check for 4 bytes
 //   int maxAttempt= 256*256*256*32;
    // brutesforce 4 bytes (256 can't be because compiler says overflow

    //int totalCombinations = maxAttempt/256;


    //https://stackoverflow.com/questions/6687467/converting-char-array-to-long-in-c

    aes256_context temp;
    int min=0;
    int max=65536;


    char date[200];
    utc_system_timestamp(date);
    printf("\n%s",date);


		for ( int l=min; l < max ;l++) {



			longToCharArray(l,(unsigned char*) ctx.key);
			// Multiple = k * interval
			// when it reaches 65526 and other prints
			if (multiple == (16384 * l)) {
				utc_system_timestamp(date);
				printKey((uint8_t *)&ctx.key,32);
				char ret[max];
				sprintf(ret,"%c",l);
				printf("Elapsed : %s \nMin : %i ... Max : %i .... NumDigits : %i",date,l,max,count_digits(ret));


			//	printf("\nSearched %i of a total of %i",l,max);
//				printKey(ctx.key,32,1);
				multiple+=65536;
			//	char *filename = "/home/andrec/workspace_c/binPathC/testCiphers/limits";
			//	writeToFile(date,min,max,filename);
			}

			memcpy(&temp,ctx.key,32);
			memcpy(&temp,ctx.deckey,32);
			memcpy(&temp,ctx.enckey,32);

			aes256_decrypt_ecb(&temp,cipherText);



		}


	/*uint8_t *plainText = (uint8_t *) malloc(17);
	for (int i=0; i < 16 ; i++) {
		plainText[i] = cipherTextBlock1[i] ^ cipherTextBlock2[i];
	}
	plainText[16] = '\0';
*/
	printf("\nPlaintext : %s",cipherText);
	free(cipherText);

}
