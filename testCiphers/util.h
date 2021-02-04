#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <time.h>
#include <limits.h>
#include <stdint.h>

#define intSize 4294967296

void printAllCombinations(int numOfBits, int startByte);
void printBits(uint8_t number,uint8_t printDecimals,uint8_t noLeadingZeros);
void printShortBits(unsigned short number); 
void printIntBits(unsigned int number);

void convertByteToAscii(unsigned char byte,char mask);

void printStrings();
void printFullArray();
void printUsingFunction();
void getAllCombinations();
void check32Bytes();
void launchProg();


void printTemplate(uint8_t c);
void assignArrayToPosition(int *array,int sizeOfArr,int pos);
void trying8Elems();



bool next_permutation(int array[], size_t length);
void permute(char *a, int l, int r);

void encrypt_file(uint8_t *buf,unsigned key);
void decrypt_file(uint8_t *cipherText);
long charArrayToLong(long l,int *key);


int count_digits(char *arg);


uint8_t* readFileToArray(char *filename);
uint8_t writeToFile(int min,int max,char *filename);
int utc_system_timestamp(char buf[]);
void longToCharArray(long,uint8_t *);
void printKey(uint8_t key[]  ,int sizeKey);
void verbosePrint(unsigned char *buf,char *valueToPrint,int sizeOfBuffer);


