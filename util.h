#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <sys/ioctl.h>
#include <unistd.h>


#define numPositions 8
#define numOfRows 32 // 8*32 => 256





void printAllCombinations(int numOfBits, int startByte);
void printBits(unsigned char number,u_char printDecimals,u_char noLeadingZeros);
void printShortBits(unsigned short number); 
void printIntBits(unsigned int number);

void convertByteToAscii(unsigned char byte,char mask);

void printStrings();
void printFullArray();
void printUsingFunction();
void getAllCombinations();
void check32Bytes();
void launchProg();


void printTemplate(u_char c);
void assignArrayToPosition(int *array,int sizeOfArr,int pos);
void trying8Elems();



bool next_permutation(int array[], size_t length);
void permute(char *a, int l, int r);
