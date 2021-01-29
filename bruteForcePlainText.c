#include "util.h"


//void printFullArray() {
    // int a[3][4] = {  
//   {0, 1, 2, 3} ,   /*  initializers for row indexed by 0 */
//   {4, 5, 6, 7} ,   /*  initializers for row indexed by 1 */
 //  {8, 9, 10, 11}   /*  initializers for row indexed by 2 */
// };



    unsigned char base[8][8];
 //   unsigned char firstArray[8]; // just here for clearing 
 //   unsigned char secondArray[8];                
       

/*
    
    We can concatenate variables,  for example
                 0x38     0x05         
                0111000 00000101
                
                011100000000101 = 0x3805
                
    
    
     One 2), use 8 in 1), as a mask to 2)
     
           
                    (pos1 = 00000000 00001000 00010000 00011000 0001000 100000)
                    (add =  00000001 00000001 00000001 00000001 0000001 000001)
                     add (137977929793 to pos1 or use or mask on 1)
                              
                
                   // int pos1 = 00000000 00001000 00010000 00011000;
                      //      OR 00000001 00000001 00000001 00000001     
                            
                            
                            
                    // FROM https://stackoverflow.com/questions/7787423/c-get-nth-byte-of-integer
                    //int x = (number >> (8*n)) & 0xff;
                    // where n is 0 for the first byte, 1 for the second byte, etc.

                     // Access nth byte same site      int x = ((unsigned char *)(&number))[n];
                     
                  int mask =   0b00000001
                               00000001
                               00000001
                               00000001;
                  
                  int pos2 = pos1 | mask;
                  printf("\n");
                  printIntBits(pos2);
                  printf("\n");

                                        
                /*
                           
                           shifting left 4 bits, equals multiplying by 16 (16 = 2^4)
                           00001000 8
                           10000000 128
                           
                           8*16 = 128
                           
                         left 3 bits multiplying by 8 (2^3 = 8)
                         00001000 8
                         01000000 64
                         
                    // FALSO       com bits seguidos, nao é multiplo de 2
                    //             com bits nao seguidos mulitple de 2
                           
            //      add 1 bit leading 3 bits = > 4bits . How many bits 0 and 1's         
    // Add bit in msb
                  */         
              

    
    
    // copy base to int and then do OR with first set and then increment first set
    
   /*
    pos1 pos2 pos3
    1     1    1 -> representa 3 numeros, um por cada bit
                                                ----4posicioes---
    1 at pos1 (represents 1 0 0 , 8 positions { 001,010,000,100, 011,101,110,111
    
    1 at pos2 (represents 1 0 , 4positions {01,10,00,11})
    
    8 positions has 4positions plus other
    
    2bit * 2bit * 2bit => 2bit * 2bit AND adding one and zeros on the leading bits
    
    2bit * 2bit * 2bit * 2bit => { 0001,0010,0100,0000,1000,1100,1110,1111,0011,0111,
  
}
*/
#define NumberOfBytes 12

void add();
void testCombination();

static unsigned char str[NumberOfBytes+1];
static int idx=0;
static int min = 0;
static int max = 279841; // 23^4
static int interval =279841;

   void add() {
	   // 0x7E is last printable character
	   if (str[idx]==0x7E) {
		   idx++;
		   // first printable character
		   str[idx]=0x20;

	   }
	   else
		   str[idx]++;


   }

   void print() {

	   for (int i = 0; i < NumberOfBytes ; i ++) {
	           printf(" %2x", str[i]);
	       }
	   printf("\n");
   }
   void testCombination() {
	   while (min <= max) {
	      add();
	      print();
		   min++;

	   }
   }
int main() {


	memset(str,0x20,NumberOfBytes);
	str[NumberOfBytes+1] = '\0';
	// 'a'---'z' z => 0x7a a=>0x61
	for (int it=0; it < 1; it++) {


		testCombination();
		max += interval;
	}



	//algorithm = start wth 000, and change one bit, until can't change nomre...then use 111 and change one bit of it
            /* algorithm       
      a)  [0] Bit bit Bit [0] bit bit bits 
             
      b)  [0] bit bit bit [1] bit bit bits 
               
      c)  [1] bit bit bit [0] bit bit bit 
             
      d)  [1] bit bit bit [1] bit bit bit 
      
      
     
      a) [0] bit bit bit [0] bit bit bit [0] bit bit bit [0] bit bit bit
           
           2^4 , 2^3 * 2^3 * 2^3 * 2^3 = 65536
           
           2^3 ^4 = 
           8 ^4 = 4096 bits (4096 combinações)
           
           testing 4 bytes....
           
           32bytes / 4 bytes = 8
           
           1 byte = 8bits
           X       11bits
           11 / 8 = 
           
                            
                                            
                            
                         
                            
       
       256 bits =  128 comb of 0 and 1 (prefixes)
       256 / 8 bits = 32bytes
       
       */                   

    //launchProg();
}

