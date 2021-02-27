/*
 * readFile.c
 *
 *  Created on: Feb 15, 2021
 *      Author: andrec
 */
#include <stdio.h>
#include <stdlib.h>

u_int32_t readFile(char *filename,uint8_t *buf);


unsigned int readFile(char *filename,unsigned char *buf) {
	FILE *cipherFile;
	int retValue;
	int bytesRead = -1;
	unsigned char *cipherText = (unsigned char *) malloc(16);
	cipherFile = fopen( filename, "rb");

	if (cipherFile == NULL) {
		printf("\nCouldnt open cipher text file\n PATH = [%s]",filename);
		perror("\nThe error was ");
		exit((int) -1);
	}

	bytesRead = fread(buf,1,16,cipherFile);
	if (bytesRead!=16) {
		printf("\nBytes read from file %s not equal to 16\n",filename);
		exit((int) -1);
	}
	retValue = fclose(cipherFile);

	if (retValue != 0) {
		printf("\nDidnt close file properly");
		exit(-1);
	}

	return bytesRead;


}
