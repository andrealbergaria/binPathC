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
#define multiple 63556
// #define u_longSize 	"8 bytes,0 to 18446744073709551615"
void AddEightToPositions();

int main() {
	AddEightToPositions();
}
void AddEightToPositions() {
	unsigned long arr[] = {1,2,3,4};

	//https://stackoverflow.com/questions/5141960/get-the-current-time-in-c
	 time_t t;
	 time(&t);
	 printf("\n current time is : %s",ctime(&t));

	 int interval = 65536;

 for (int i = 0 ; i < intSize; i++) {
                arr[0] += 8;
                arr[1] += 8;

                if (interval == 65536) {
                	interval=0;
                }
                	interval++;
 }

                // b=an , b multiple , a=i, n must be integer, hence remainder of b/a integer
                // mulitple = multiplier * i
                //multiplier = interval
                 // interval = multiple / i


                arr[2] += 8;
                arr[3] += 8;
                for (int i2=0; i2 < 8;i2++) {
            	   printf(" %lu ",arr[i2]);
               }

    }
*/ mk = n
}
