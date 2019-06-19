/**
 * Example of using standard C `qsort` function.
 *
 * Author: Lightech (lightech@outlook.com)
 *
 * Public Domain.
 */

#include <stdio.h>
#include <stdlib.h>

void PrintArray(int *A, int n)
{
	for(int i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");
}

int main(int argc, const char **argv)
{
	printf("Sorting\n");
	int A[] = {9, -1, 3, 4, 7, -3, -2, 8};
	int n = sizeof(A) / sizeof(int);
	printf("Original array: ");
	PrintArray(A, n);
	qsort(A, n, sizeof(int), [](const void *x, const void *y)
	{
		int a = *(int*)x;
		int b = *(int*)y;
		return a - b;
	});
	printf("Sorted array: ");
	PrintArray(A, n);

	return 0;
}