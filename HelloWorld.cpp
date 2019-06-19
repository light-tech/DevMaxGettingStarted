/**
 * Standard hello world program.
 *
 * Author: Lightech (lightech@outlook.com)
 *
 * Public Domain.
 */

#ifdef _DEVMAX_INTERPRETER_
extern "C" int printf(const char* format, ...);
#else
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#endif

int main(int argc, const char **argv)
{
	printf("Hello world!\n");
	return 0;
}