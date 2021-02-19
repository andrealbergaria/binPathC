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
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

#define limitsFile "keysTried"



extern int max;
extern int min;
extern int tryCombsASM(char *);


//#define DUMP(s,buf, sz)  {printf(s);                   \
 //                             for (int i = 0; i < (sz);i++)    \
  //                                printf("%02x ", buf[i]); \
  //                            printf("\n");}
int utc_system_timestamp(char *buf,int sizeOfBuf) ;
void DUMP(char *s,uint8_t *buf,int bufSize,char isAscii);
uint8_t writeToFile(int,int);
u_int32_t readFile(char *filename,uint8_t *buf);
void longToCharArray(long l,uint8_t *key,int sizeOfKey);
long charArrayToLong(long l,int *key);
void tryCombinations(long min,long max,long interval);
uint8_t tryKeyRange(long min,long max);
int bytesSize(long);
void sig_handler(int signum);
int printBuf(unsigned char *buf);



int bytesSize(long val) {
                    int size = 0;
                    while(val > 0) {
                    	val >>= 8;
                        size++;
                    }
                    return size;
}



void DUMP(char *s,uint8_t *buf,int bufSize,char isAscii) {
		printf("%s",s);
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
	char timeBuf[100];
	utc_system_timestamp(timeBuf,100);

	FILE *stream;
	char fmt[] = "Min : %i (%i bytes) , Max : %i (%i bytes), ::: %s\n";

	char *buf = (char *) malloc(150);


	 stream = fopen("loggedKeys","a+");

	if (stream == NULL) {
	//	perror("\ndemo.c writeToFile fopen() error");
		exit(-1);
	}
	sprintf(buf,fmt,min,bytesSize(min),max,bytesSize(max),timeBuf);


	unsigned int numWrite = fwrite(buf,1,strlen(buf),stream);

	if (numWrite == 0) {
		perror("demo.c writeToFile fwrite()");
		exit(-1);
	}
	printf("[demo.c , writeToFile() ] %s ",buf);
	printf("[demo.c , writeToFile() ] Wrote file \"%s\" (%i bytes) ... \n","loggedKeys",numWrite);



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


	int aux = 0;
	for (int i=0; i < 131072; i++) {
		tryKeyRange(min,max);


		 min = max;
		 max += interval;
		 //	if (i == aux) {
		 	//		writeToFile(min,max);
		 	//		aux+=32768;
		 	//	}
	}
	free(date);
}

uint8_t tryKeyRange(long min,long max) {
		uint8_t *key = (uint8_t *) malloc(32);
		uint8_t *buf_t = (uint8_t *) malloc(32);
		aes256_context ctx;

		for (long i=min; i < max; i++) {
			longToCharArray(i,key,32);
		    //DUMP("key: ", key, 32,0);

		    aes256_init(&ctx, key);
		    aes256_decrypt_ecb(&ctx,buf_t);
		   // DUMP("dec: ", buf, 32,1);
		    aes256_done(&ctx);
		}
		free(key);
		free(buf_t);

}
void sig_handler(int signum) {


	if (signum == SIGTSTP || signum == SIGTERM  || signum == SIGINT) {
		printf("\nWriting file (signal %i caught)\n",signum);
		writeToFile(min,max);
	}


}

int printBuf(unsigned char *buf) {
	printf("\n");
	for (int i=0; i < 16;i++) {
    		printf(" %x ",*(buf+i));

    	}
    	printf("\n");


}

int main (int argc, char *argv[])
{

		unsigned char *buf = (char*) malloc(16);
		__sighandler_t sigError;
	    sigError = signal(SIGTERM,sig_handler);    /* register the handler */
	    if (sigError ==SIG_ERR) {
	    	perror("\nSIGTRERM NAO HANDLED");
	    	exit(-1);
	    }
	    sigError= signal(SIGTSTP,sig_handler);
	    if (sigError ==SIG_ERR) {
	    	    	perror("\nSIGTSTP NAO HANDLED");
	    	    	exit(-1);
	    	    }

	    sigError= signal(SIGINT,sig_handler);
	    if (sigError ==SIG_ERR) {
	    	perror("\nSIGINT NAO HANDLED");
	    	exit(-1);
	    }



    int bytesRead = readFile("files/cipherTextECB",buf);

    if (bytesRead != 16){
    	printf("\nDidnt read the cipherFile all the way up\n");
    	exit(-1);
    }

    tryCombsASM(buf);
    //printBuf(buf);

   // tryRightKey(buf);

   /* printf("\nBuf size %i\n",sizeof(buf));
    DUMP("buf: ", buf, sizeof(buf),0);
    char *key = malloc(32);
    memset(key,0,32);
    memset(key,0x61,4);
*/


	free(buf);
/*

    aes256_encrypt_ecb(&ctx, decrypt_buf);

    DUMP("enc: ", i, buf, sizeof(buf));
    printf("tst: 8e a2 b7 ca 51 67 45 bf ea fc 49 90 4b 49 60 89\n");

    aes256_init(&ctx, key);
     aes256_decrypt_ecb(&ctx, buf);

    DUMP("decrypt_buf : ", buf, sizeof(buf),1);
    printf("---\n");
    free(key);
    aes256_done(&ctx);


	*/

         //aes256_done(&ctx);

    return 0;
} /* main */
