/*  
*   Byte-oriented AES-256 implementation.
*   All lookup tables replaced with 'on the fly' calculations. 
*
*   Copyright (c) 2007 Ilya O. Levin, http://www.literatecode.com
*
*   Permission to use, copy, modify, and distribute this software for any
*   purpose with or without fee is hereby granted, provided that the above
*   copyright notice and this permission notice appear in all copies.
*
*   THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
*   WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
*   MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
*   ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
*   WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
*   ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
*   OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "aes256.h"
#include <time.h>


#define limitsFile "minmax.log"
//#define DUMP(s,buf, sz)  {printf(s);                   \
 //                             for (int i = 0; i < (sz);i++)    \
  //                                printf("%02x ", buf[i]); \
  //                            printf("\n");}
int utc_system_timestamp(char *buf,int sizeOfBuf) ;
void DUMP(char *s,uint8_t *buf,int bufSize,char isAscii);
uint8_t writeToFile(int,int);
u_int32_t readFileToArray(char *filename,uint8_t *buf);
void longToCharArray(long l,uint8_t *key,int sizeOfKey);
long charArrayToLong(long l,int *key);
void tryCombinations(long min,long max,long interval);
uint8_t tryKeyRange(long min,long max);



int bytesSize(long val) {
                    int size = 0;
                    while(val > 0) {
                    	val >>= 8;
                        size++;
                    }
                    return size;
}



void DUMP(char *s,uint8_t *buf,int bufSize,char isAscii) {
		printf(s);
		for (int i = 0; i < (bufSize);i++) {
			if (isAscii==1)
				printf("%c ",buf[i]);
			else
				printf("%02x ",buf[i]);

		}
		 printf("\n");
}

// cipher text to translate
uint8_t writeToFile(int min,int max) {
	char arr[300];
	char timeBuf[50];
	utc_system_timestamp(timeBuf,50);
	sprintf(arr,"Min : %i (%i bytes) , Max : %i (%i bytes), ::: %s",min,bytesSize(min),max,bytesSize(max),timeBuf);

	FILE *fPtr = fopen(limitsFile,"a");
	if (fPtr == NULL) {
		perror("[demo.c , fopen()] file pointer returned null");
		exit(-1);
	}
	int arrSize = strlen(arr);
	int retValue = fwrite(arr, 1 , arrSize, fPtr);
	if (retValue == EOF || retValue != arrSize) {
		perror("[util.c writeFile()] Error : ");
		if (fclose(fPtr) != 0)
			perror("[util.c writeFile() fclose() ] Error ");
		return -1;
	}
	else {
		printf(arr,"Min : %i (%i bytes) , Max : %i (%i bytes), ::: %s",min,bytesSize(min),max,bytesSize(max),timeBuf);
		printf("[util.c , writeFile() ] Wrote file %s",limitsFile);
	}
	fclose(fPtr);
		return 0;

}
u_int32_t readFileToArray(char *filename,uint8_t *buf) {
	FILE *cipherFile;
	int retValue;
	int bytesRead = -1;
	uint8_t *cipherText = (uint8_t *) malloc(32);
	cipherFile = fopen( filename, "rb");

	if (cipherFile == NULL) {
		perror("\nCouldnt open cipher text file");
		exit(-1);
	}

	bytesRead = fread(buf,1,32,cipherFile);

	retValue = fclose(cipherFile);

	if (retValue != 0) {
		printf("\nDidnt close file properly");
		exit(-1);
	}

	return bytesRead;


}

//https://stackoverflow.com/questions/6687467/converting-char-array-to-long-in-c
void longToCharArray(long l,uint8_t *key,int sizeOfKey) {
	memset(key,0x0,sizeOfKey);
	key[0] = l         & 0xFF;
	key[1] = (l >>  8) & 0xFF;
	key[2] = (l >> 16) & 0xFF;
	key[3] = (l >> 24) & 0xFF;

}


long charArrayToLong(long l,int *key) {
	l = key[0] | (key[1] << 8) | (key[2] << 16) | (key[3] << 24);
	return l;


}

int utc_system_timestamp(char *buf,int sizeOfBuf) {

	    struct timespec now;
        struct tm tm;
        int retval = clock_gettime(CLOCK_REALTIME, &now);
        gmtime_r(&now.tv_sec, &tm);
        strftime(buf, sizeOfBuf, "%Y-%m-%dT%H:%M:%S.", &tm);
        sprintf(buf, "%s%09luZ", buf, now.tv_nsec);
        return retval;
}

void tryCombinations(long min,long max,long interval) {
	char *date = (char *) malloc(50);

	utc_system_timestamp(date,50);
	if (interval % 2 != 0) {
		printf("\nInterval not multiple of 2...exiting");
		exit(-1);
	}

	printf("\nBegin date %s",date);
	int aux = 0,aux2=0;
	for (int i=0; i < 131072; i++) {
		tryKeyRange(min,max);

		if (i == aux) {
			aux+=8192;
			printf("\nMin : %i (%i bytes) , Max : %i (%i bytes) ",min,bytesSize(min),max,bytesSize(max));
		}
		if (i == aux2) {
			writeToFile(min,max);
			aux2+=32768;
		}
		 min = max;
		 max += interval;
	}
	free(date);
}
uint8_t tryKeyRange(long min,long max) {
		uint8_t *key = (uint8_t *) malloc(32);
		uint8_t *buf = (uint8_t *) malloc(32);
		aes256_context ctx;

		for (long i=min; i < max; i++) {
			longToCharArray(i,key,32);
		    DUMP("key: ", key, 32,0);
		    aes256_init(&ctx, key);
		    aes256_decrypt_ecb(&ctx,buf);
		    DUMP("dec: ", buf, 32,1);
		    aes256_done(&ctx);
		}
		free(key);
		free(buf);

}
int main (int argc, char *argv[])
{
    aes256_context ctx; 
    uint8_t key[32];
    uint8_t decrypt_buf[32];
    int bytesRead = readFileToArray("./files/cipherTextECB",decrypt_buf);
    //uint8_t *encrypt_buf = writeToFile(("./files/cipherTextECB");
    /* put a test vector */
    //for (i = 0; i < sizeof(buf);i++) buf[i] = i * 16 + i;
    //for (i = 0; i < sizeof(key);i++) key[i] = i;
    if (bytesRead != 32){
    	printf("\nDidnt read the cipherFile all the way up");
    }
    memset(key,0x0,sizeof(key));
    key[0] = 0x61;
    key[1] = 0x61;
    key[2] = 0x61;

    DUMP("txt: ", decrypt_buf, sizeof(decrypt_buf),0);
    printf("---\n");

//    aes256_init(&ctx, key);
 //   aes256_encrypt_ecb(&ctx, decrypt_buf);

  //  DUMP("enc: ", i, buf, sizeof(buf));
  //  printf("tst: 8e a2 b7 ca 51 67 45 bf ea fc 49 90 4b 49 60 89\n");

    tryCombinations(0,65536,65536);

    aes256_done(&ctx);

    return 0;
} /* main */
