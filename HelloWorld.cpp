/**
 * Standard hello world program.
 *
 * Author: Lightech (lightech@outlook.com)
 *
 * Public Domain.
 */

// When interpreting, one can #define _CRT_STDIO_ARBITRARY_WIDE_SPECIFIERS
// (see $WIN_SDK\ucrt\corecrt_stdio_config.h lines 47-71) to avoid LLVM
// invalid linker options.
#include <stdio.h>

int main(int argc, const char **argv)
{
	printf("Hello world!\n");
	return 0;
}