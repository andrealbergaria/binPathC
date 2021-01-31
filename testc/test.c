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

	arr[0] = 'B';
	//char *tStr = { 'a','b','c',0};
	//printf("%s ",tStr);
	char *buf="ASF";
//	char tempa[200]= {'a','b',0};
//	printf("\n%s",tempa);

	// "aa""bb"


	 //strcpy()
		 char *str ="aa"; //Take address from "aa", which is str;
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
