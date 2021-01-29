/*
 * addPositions.c


 *
 *  Created on: Jan 28, 2021
 *      Author: andrec
 */
// check 1 byte table
#include <stdio.h>
void AddEightToPositions();

int main() {
	AddEightToPositions();
}
void AddEightToPositions() {

unsigned long arr[] = {1,2,3,4,5,6,7,8};

 for (int i = 0 ; i < 128; i++) {
                arr[0] += 8;
                arr[1] += 8;
                arr[2] += 8;
                arr[3] += 8;
                arr[4] += 8;
                arr[5] += 8;
                arr[6] += 8;
                arr[7] += 8;
               for (int i2=0; i2 < 8;i2++) {
            	   printf(" %lu ",arr[i2]);
               }

    }
}
