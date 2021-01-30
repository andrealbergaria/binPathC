/*
 * addPositions.c


 *
 *  Created on: Jan 28, 2021
 *      Author: andrec
 */
// check 1 byte table
#include <stdio.h>
#include <time.h>
#define intSize 4294967296

// #define u_longSize 	"8 bytes,0 to 18446744073709551615"
void AddEightToPositions();

int main() {
	AddEightToPositions();
}
void AddEightToPositions() {
	unsigned long arr[] = {1,2,3,4};

	//https://stackoverflow.com/questions/5141960/get-the-current-time-in-c
	 int interval = 65536;
			 int multiple = 65536;

 for (int i = 0 ; i < intSize; i++) {

                arr[0] += 8;
                arr[1] += 8;
                arr[2] += 8;
                arr[3] += 8;
                if (i * interval ==multiple){
                	multiple+=interval;
                	printf("\nKey test %i",i);
                	time_t t;
                    time(&t);
                    printf("\n current time is : %s",ctime(&t));

                }
 }



    }


