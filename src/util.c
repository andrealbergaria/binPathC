#include "util.h"
#include "aes256.h"



// cipher text to translate

u_char* readFileToArray(FILE *ptr) {
	FILE *cipherFile;
	int retValue;
	u_char *cipherText = (u_char *) malloc(16);
	cipherFile = fopen( "files/cipherText", "rb");

	if (cipherFile == NULL) {
		perror("\nCouldnt open cipher text file");
		exit(-1);
	}

	retValue = fseek(cipherFile,16,SEEK_SET);

	if (retValue!=0) {
		printf("\nCoultn fseek");
		exit(-1);
	}

	retValue = fread(cipherText,1,16,cipherFile);

	if (retValue != 16 ) {
		printf("\nCoulndt read 16 bytes of cipher Text");
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
    printf("\nu_char pos_%i[] = { ",pos);
    for (int i=0; i < 31; i++) {
        pos+=8;
        printf(" %i,",pos);

    }
    printf(" } ");
    temp++;
    }
    
}
// NEed 8 ints....32bytes 8*4 =32


void printTemplate(u_char toTest) {
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



void printBits(unsigned char number,u_char printDecimals,u_char noLeadingZeros) {
   unsigned char mask = 0x80;
   int it;
   u_char zero='0',one='1';
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



