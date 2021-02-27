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

#define file "keysTried"



extern int tryCombsASM(char *);
extern void writeToFileASM();

//#define DUMP(s,buf, sz)  {printf(s);                   \
 //                             for (int i = 0; i < (sz);i++)    \
  //                                printf("%02x ", buf[i]); \
  //                            printf("\n");}
int utc_system_timestamp(char *buf,int sizeOfBuf) ;
int bytesSize(long);
void sig_handler(int );


int bytesSize(long val) {
                    int size = 0;
                    while(val > 0) {
                    	val >>= 8;
                        size++;
                    }
                    return size;
}





// cipher text to translate
void writeToFile(int minT,int maxT) {
	char timeBuf[100];
	utc_system_timestamp(timeBuf,100);

	FILE *stream;
	char fmt[] = "Min : %i (%i bytes) , Max : %i (%i bytes), ::: %s\n";

	char *buf = (char *) malloc(150);


	 stream = fopen("loggedKeys","a+");

	if (stream == NULL) {
	perror("\ndemo.c writeToFile fopen() error");
		exit(-1);
	}
	sprintf(buf,fmt,minT,bytesSize(minT),maxT,bytesSize(maxT),timeBuf);


	unsigned int numWrite = fwrite(buf,1,strlen(buf),stream);

	if (numWrite == 0) {
		perror("demo.c writeToFile fwrite()");
		exit(-1);
	}
	fflush(stream);
	printf("[demo.c , writeToFile() ] %s ",buf);
	printf("[demo.c , writeToFile() ] Wrote file \"%s\" (%i bytes) ... \n","loggedKeys",numWrite);

}



//https://stackoverflow.com/questions/6687467/converting-char-array-to-long-in-c


int utc_system_timestamp(char *buf,int sizeOfBuf) {

	    struct timespec now;
        struct tm tm;
        int retval = clock_gettime(CLOCK_REALTIME, &now);
        gmtime_r(&now.tv_sec, &tm);
        strftime(buf, sizeOfBuf, "%Y-%m-%dT%H:%M:%S.", &tm);
        sprintf(buf, "%s%09luZ", buf, now.tv_nsec);
        return retval;
}



void sig_handler(int signum) {


	if (signum == SIGTSTP || signum == SIGTERM  || signum == SIGINT)
		writeToFileASM();


}



int main (int argc, char *argv[])
{

		unsigned char *bufMain = (char *) malloc(16);




    unsigned int bytesRead = readFile("files/cipherTextECB",bufMain);
    if (bytesRead != 16 ) {
    	printf("\nDidnt read the cipherFile all the way up\n");
    	exit(-1);
    }

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

   	    printf("\n %p\n",bufMain);
    //tryCombsASM(buf);
   	    tryCombsASM(bufMain);

	return 0;
} /* main */
