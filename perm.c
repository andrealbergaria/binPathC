/* 
 * Next lexicographical permutation algorithm (C)
 * by Project Nayuki, 2017. Public domain.
 * https://www.nayuki.io/page/next-lexicographical-permutation-algorithm
 */
#include <util.h>



/*
 * https://www.nayuki.io/res/next-lexicographical-permutation-algorithm/nextperm.c
 * 
 * Computes the next lexicographical permutation of the specified array of integers in place,
 * returning a Boolean to indicate whether a next permutation existed.
 * (Returns false when the argument is already the last possible permutation.)
 */
bool next_permutation(int array[], size_t length) {
	// Find non-increasing suffix
	if (length == 0)
		return false;
	size_t i = length - 1;
	while (i > 0 && array[i - 1] >= array[i])
		i--;
	if (i == 0)
		return false;
	
	// Find successor to pivot
	size_t j = length - 1;
	while (array[j] <= array[i - 1])
		j--;
	int temp = array[i - 1];
	array[i - 1] = array[j];
	array[j] = temp;
	
	// Reverse suffix
	j = length - 1;
	while (i < j) {
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		i++;
		j--;
	}
	return true;
}

/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
void permute(char *a, int l, int r)
{
   int i;
   if (l == r)
     printf("%s\n", a);
   else
   {
       for (i = l; i <= r; i++)
       {
          swap((a+l), (a+i));
          permute(a, l+1, r);
          swap((a+l), (a+i)); //backtrack
       }
   }
}

/* Driver program to test above functions
int main()
{
    char str[] = "ABC";
    int n = strlen(str);
    permute(str, 0, n-1);
    return 0;
} */
