
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
	//printf("%s",arr);
	printf("\n\n%p",print());

}
