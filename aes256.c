#include "aes256.h"


int main() {

	aes256_context aesCon;
	u_char bufferToEncrypt[16];
			for (int i=0; i < 32;i++) {
					aesCon.key[i] = 97;
					aesCon.enckey[i]=97;
					aesCon.deckey[i]=97;
				}


			memset(bufferToEncrypt,0x61,8);
			memset(bufferToEncrypt+8,0x62,8);


	printf("\n[main] Key used ");
	for (int i=0; i < 32; i++) {
		printf("%c",aesCon.key[i]);
	}
	printf("\n");

	encrypt_file(bufferToEncrypt,aesCon);
//	decrypt_file(aesCon,strFileJava);



}

