#include "util.h"


void verbosePrint(unsigned char *buf,char *valueToPrint,int sizeOfBuffer) {
	char *t = (char *) malloc(sizeOfBuffer+1);
	strncpy(t,(char *)buf,sizeOfBuffer);
	t[sizeOfBuffer] = '\0';

	printf("\n[util.c verbosePrint() (%s)] %s\n",valueToPrint,t);
}

void printKey(uint8_t key[]  ,int sizeKey) {
	printf("\n[util.c printKey()] [ ");
	for (int i = 0;i < sizeKey; i++)
			printf("%i ",key[i]);
	printf(" ] ");
}

//https://stackoverflow.com/questions/6687467/converting-char-array-to-long-in-c
void longToCharArray(long l,uint8_t *key) {

	key[0] = l         & 0xFF;
	key[1] = (l >>  8) & 0xFF;
	key[2] = (l >> 16) & 0xFF;
	key[3] = (l >> 24) & 0xFF;

}


long charArrayToLong(long l,int *key) {
	l = key[0] | (key[1] << 8) | (key[2] << 16) | (key[3] << 24);
	return l;


}


// size in bytes
/* this work by , using one char (1 < 10 < 100 < 256)
 *  (in this case if number == 50
 *  	10<  50 < 100 , 2digits
 * and then going to the second byte and so forth like 1000 (4 digits) 10000(5digits)
 */


int count_digits(char *arg) {

	int countTemp = 0;
	int min=1;
		for (int it=0;  it < strlen(arg); it++) {
			printf("it %i\n",it);
			countTemp++;
			/*
			for (int i=1; i < 256; i = i * 10 ) {

				if (arg[it] > min && arg[it] <= i )  {
					countTemp++;
					min*=10;
				}

			}*/
		}
		printf("\nCount %i",countTemp);
		return countTemp;

	}



int utc_system_timestamp(char buf[]) {

	int bufsize = 31;

        struct timespec now;
        struct tm tm;
        int retval = clock_gettime(CLOCK_REALTIME, &now);
        gmtime_r(&now.tv_sec, &tm);
        strftime(buf, bufsize, "%Y-%m-%dT%H:%M:%S.", &tm);
        sprintf(buf, "%s%09luZ", buf, now.tv_nsec);
        return retval;
}
// cipher text to translate
uint8_t writeToFile(int min,int max,char *filename) {
	char arr[150];
	char timeBuf[50];
	utc_system_timestamp(timeBuf);
	sprintf(arr,"Min : %i , Max : %i , ::: %s",min,max,timeBuf);

	FILE *fPtr = fopen(filename,"a");

	int arrSize = strlen(arr);
	int retValue = fwrite(arr, 1 , arrSize, fPtr);
	if (retValue == EOF || retValue != arrSize) {
		perror("[util.c writeFile()] Error : ");
		if (fclose(fPtr) != 0)
			perror("[util.c writeFile() fclose() ] Error ");
		return -1;
	}
	else
		printf("[util.c , writeFile() ] Wrote file %s",filename);
	fclose(fPtr);
		return 0;

}
uint8_t* readFileToArray(char *filename) {
	FILE *cipherFile;
	int retValue;
	uint8_t *cipherText = (uint8_t *) malloc(32);
	cipherFile = fopen( filename, "rb");

	if (cipherFile == NULL) {
		perror("\nCouldnt open cipher text file");
		exit(-1);
	}

	retValue = fread(cipherText,1,32,cipherFile);

	if (retValue != 32 ) {
		printf("\nCoulndt read 32 bytes of cipher Text");
		exit(-1);
	}

	retValue = fclose(cipherFile);

	if (retValue != 0) {
		printf("\nDidnt close file properly");
		exit(-1);
	}

	return cipherText;


}



// return the numbers on the specified position
void assignArrayToPosition(int *array,int sizeOfArr,int pos) {
    
    
    for (int it= 0; it < sizeOfArr; it++) 
        array[it] = 8*it+pos;
    
}

void printArray(char *arr,int sizeOfArray) {
    printf("   ");
    for (int i=0 ; i < sizeOfArray; i++) {
        printf("%c , ",arr[i]);
    }
}
    

void printPositions() {
    
    int pos = 1;
    int temp = pos;
    for (int i = 1 ; i < 9 ; i++) {
    pos = temp;
    printf("\nuint8_t pos_%i[] = { ",pos);
    for (int i=0; i < 31; i++) {
        pos+=8;
        printf(" %i,",pos);

    }
    printf(" } ");
    temp++;
    }
    
}
// NEed 8 ints....32bytes 8*4 =32


void printTemplate(uint8_t toTest) {
            unsigned char a[] = {'1','2','3','4','5','6','7','8'};
            unsigned char b[] = {'1','2','3','4','5','6','7','8'};
            unsigned char c[] = {'1','2','3','4','5','6','7','8'};
            unsigned char d[] = {'1','2','3','4','5','6','7','8'};

            printf("\nTemplate of %c",toTest);
                int total_iterations= 0 ;
                        
                        for (int i=0 ; i < 8 ; i++) {
                            total_iterations++;

                            for (int i2=0; i2 < 8; i2++) {
                                total_iterations++;
                                for (int i3=0 ; i3 < 8;i3++) {
                                    total_iterations++;
                                    for (int i4=0; i4 < 8 ; i4++) {
                                        total_iterations++;
                                         printf("\n { '%c','%c','%c','%c' }",a[i],b[i2],c[i3],d[i4]);
                                        if (a[i] == toTest || b[i2] == toTest || c[i3] == toTest || d[i4] == toTest ) {
                                            // show only those that have '0'
                                          if (a[i] == toTest || b[i2] == toTest || c[i3] == toTest || d[i4] == toTest ) {
                                            // show only those that have '0'
                                            
                                            for (int i =0 ; i < 4; i++) {
                                                if (a[i] ==toTest)
                                                    printf("{ 1,");
                                                else
                                                    printf("{ 0,");
                                                if (b[i2] == toTest)
                                                    printf("1,");
                                                else
                                                    printf("{ 0,");
                                                
                                                if (c[i3] == toTest)
                                                    printf("1,");
                                                else
                                                    printf("{ 0,");
                                                
                                                if (d[i4] == toTest)
                                                    printf("1, ");
                                                else
                                                    printf("{ 0,");
                                                
                                            }
                                                
                                            
                                            
                                        }
                                        
                                        
                                    }
                                }
                                
                            }
                            }
                }
                printf("\nTotal iterations : %i",total_iterations);
    
    
}

void check32Bytes() {
	  //p -> Quantidade de elementos por agrupamento
	    //Arranjos = pow(n,p);
	  //  n=8, p=4 = 4096

	// all values => 8^8 = 16777216

	// Cada caracter tem 8^8 posições
	// N=> 1 ,
	// percorrer a array usando arranjos....


	/*
	 *
	 * 32 lines
	 * 	[1 ,2 ,3 ,4, 5, 6, 7, 8,]
	 * 	p=8 n=32
	 *
	 */

 /*   unsigned char a[] = {'1','2','3','4','5','6','7','8'};
    unsigned char b[] = {'1','2','3','4','5','6','7','8'};
    unsigned char c[] = {'1','2','3','4','5','6','7','8'};
    unsigned char d[] = {'1','2','3','4','5','6','7','8'};
    unsigned char e[] = {'1','2','3','4','5','6','7','8'};
    unsigned char f[] = {'1','2','3','4','5','6','7','8'};
    unsigned char g[] = {'1','2','3','4','5','6','7','8'};
    unsigned char h[] = {'1','2','3','4','5','6','7','8'};
   */
    int numOfBytes=0;
    int total_iterations= 0 ;
    
    for (int i1=0 ; i1 < 8; i1++) {
        total_iterations++;
        
        for (int i2=0 ; i2 < 8 ; i2++) {
            total_iterations++;
            
            for (int i3=0 ; i3 < 8 ; i3++) {
                total_iterations++;
                
                for (int i4=0 ; i4 < 8; i4++) {
                    total_iterations++;
                    
                    for (int i5=0 ; i5 < 8 ; i5++) {
                        total_iterations++;
                        numOfBytes++;
                        
                        for (int i6=0 ; i6 < 8 ; i6++) {
                            total_iterations++;
                            for (int i7=0 ; i7 < 8; i7++) {
                                total_iterations++;
                                for (int i8=0 ; i8 < 8; i8++) {
                                    total_iterations++;


                                }
                                printf("\n---byte Mark");
                            }
                            
                        }
                     
                    }
                }
            }
        }
    }
    printf("\nTotal iterations : %i",total_iterations);
    printf("\nNum of Bytes scanned : %i",numOfBytes);
}







void launchProg() {


check32Bytes();


}



void printUsingFunction() {
    
    
    // look at function .. f(pos) = 8*i + pos
    // int combinations 4294967296
    // 
     unsigned int t=0;
     for (int pos = 1; pos < 9;pos++) {
        //printf("\nPos %i = ",pos);
            // 8*32 = 256  (one byte, combinations)
            // 8* 8192  = 65536 (two bytes,combinations)
            // 8* 536870912  = 4294967296 (4bytes , combs)
        for (int it= 0; it <= 8192; it++) {
            //printf(",%u",t);
            t = 8*it+pos;
            if (t % 256 == 0) 
                printf("\n%u",t);
         }
        t=0;
     }
    
        
}



void printBits(unsigned char number,uint8_t printDecimals,uint8_t noLeadingZeros) {
   unsigned char mask = 0x80;
   int it;
   uint8_t zero='0',one='1';
   for (it=0 ;it < 8; it++) {

       if (number & mask)
           putchar(one);
       else
           putchar(zero);

       mask >>= 1;
   }
    if (printDecimals==1)
    	printf(" (%i)",number);


   
}

void printShortBits(unsigned short number) {
   unsigned short mask = 0x8000;
   int it;
   
   for (it=0 ;it < 16; it++) {
       if (number & mask)
           putchar('1');
       else
           putchar('0');
      
       mask >>= 1;
   }
   
   printf("\t%i",number);
   
}


void printIntBits(unsigned int number) {
   unsigned int mask = 0x80000000;
   int it;
   
   for (it=0 ;it < 32; it++) {
       if (it % 8 == 0)
           printf(" ");
       if (number & mask)
           putchar('1');
       else
           putchar('0');
      
       mask >>= 1;
   }
   
    printf("\t%u\n",number);
   
}



