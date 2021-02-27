#include <stdio.h>
char arr[] = "ABC";
 char *testString = "BCA";
 //-fwritable-strings

 char *print() {
	 /*char *ret = "ABCQWE";
	 char *ret2= ret;
	 printf("\n  Ret value %p",ret);
	 printf("\n String %p",)
	 return ret;*/
	 for (int i=0; i < 32; i+=4) {
		 printf("\n%p","ABCDE"+i);
	 }
	 // copiar o endereco da string "ABCDE" ,para outro pointeiro..assim nao gasta
	 // nao pode ser destruido...string literal RO
	 // ptr = &"ABC"
	 return "ABC";
 }

int main() {

		struct testS {
			int var1;
			short var2;
		} ;

		struct testS test =  {123,321};
		struct testS *ptrT = &test;

		int *deref = ptrT;

		printf("\nVar1 contents : %i",*deref);
		//https://www.geeksforgeeks.org/structures-c/
		//The reason for above error is simple, when a datatype is declared, no memory is allocated for it. Memory is allocated only when variables are created.
		// whaqt about declaring test?

		printf("\nsame? %i",(*ptrT).var1);
		printf("\n same 2? %i",ptrT->var1);

		printf("\ntest addr of var 1 %p\n",&(ptrT->var1));
		printf("\naddress of ptrT %p",ptrT);
		if (ptrT==(int *) &(test.var1)) {
			printf("PTrT = VAR1\n");
		}

		for (int i=0; i < 3; i++) {
			printf("\n*ptr[%i] %i",i,*(ptrT+i));
		}

	arr[0] = 'B';
	//char *tStr = { 'a','b','c',0};
	//printf("%s ",tStr);
	char *buf="ASF";
//	char tempa[200]= {'a','b',0};
//	printf("\n%s",tempa);

	// "aa""bb"


	 //strcpy()
	/*	 char *str ="aa"; //Take address from "aa", which is str;
		 char *dst = str"bb";
		 // todo  saber como funciona o "aa""bb"
		 "aa""bb"
		 printf("\nabc %s",dst);
		 char *ptr1 = "aa";
			 char *ptr2 = "bb";

			 printf("%s",*ptr1*ptr2);


	 // qual o endereco de "aa""bb"
	 printf("\nTest1 : %p ","aa""bb");
	 printf("\nTest2 : %p ",&"aa""bb");
	 // printf("\nTest3 : %p ",&"aaaa"&"bb");
	 /*
	  * test.c:35:33: error: invalid operands to binary & (have ‘char (*)[5]’ and ‘char *’)
   	   printf("\nTest3 : %p ",&"aaaa"&"bb");
	  *
	  *
	  */
	 //printf("\nTest4 : %p ","aa"&"bb");
	 /*
	  * test.c:36:30: error: invalid operands to binary & (have ‘char *’ and ‘char *’)
   printf("\nTest4 : %p ","aa"&"bb");
                          ~~~~^
	  *
	  *
	  */

/*
	 char *ptr1 = "aa";
	 	 char *ptr2 = "bb";
	 	 char *ptr3 = *ptr1(unsigned char *ptr2);
	 	 char *t = &("AB""ABBA");
		 printf("\nT : %p\n",t);


	 printf("\nptr 3 -> %s\n",ptr3);
	 printf("\nptr 1 -> %s\n",ptr1);
	 printf("AB""ABBA");
	 printf("\nptr AB -> %p\n","AB");
*/

	//printf("%s",arr);
	//printf("\n\n%p",print());

}

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
int printBuf(unsigned char *buf) {
	printf("\n");
	for (int i=0; i < 16;i++) {
    		printf(" %x ",*(buf+i));

    	}
    	printf("\n");


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
