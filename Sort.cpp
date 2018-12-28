/**
 * Example of using standard C `qsort` function.
 *
 * Author: Lightech (lightech@outlook.com)
 *
 * Public Domain.
 */

#include "DevMax.h"

typedef unsigned int size_t;
extern "C" void qsort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*));

void PrintArray(int *A, int n)
{
	for(int i = 0; i < n; i++)
		PrintFormatString("%d ", A[i]);
	PrintString("\n");
}

int main(int argc, const char **argv)
{
	int A[] = {9, -1, 3, 4, 7, -3, -2, 8};
	int n = sizeof(A) / sizeof(int);
	PrintString("Original array: ");
	PrintArray(A, n);
	qsort(A, n, sizeof(int), [](const void *x, const void *y)
	{
		int a = *(int*)x;
		int b = *(int*)y;
		return a - b;
	});
	PrintString("Sorted array: ");
	PrintArray(A, n);

	return 0;
}