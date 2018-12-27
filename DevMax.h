/**
 * This header provides the API for INTERPRETED programs to
 * communicate with the DevMax IDE.
 *
 * A typical compiled C program uses various C's `stdio` functions
 * such as `printf` to output information to the console (a.k.a.
 * command prompt, terminal). But a program that is interpreted by
 * DevMax has no notion of an output console. In fact, the more
 * desired output method is to print out to DevMax's text box that
 * display the program's output. To support that, DevMax provides
 * the single C function
 *
 *      void PrintString(const char*);
 *
 * that a program can use to pass a text string to DevMax's output
 * terminal.
 *
 * Since a program might be both interpreted during implementation
 * and testing and compiled to executable when releasing, we use
 * conditional compilation to detect whether we are interpreting
 * or compiling with the macro `_DEVMAX_INTERPRETER_`.
 *
 * Author: Lightech (lightech@outlook.com)
 *
 * Public Domain.
 */

#ifndef _DEVMAX_H_
#define _DEVMAX_H_

#ifdef _DEVMAX_INTERPRETER_
	extern "C"
	{
		void PrintString(const char*);
	}
#else
	// When not interpreted, use printf to output.
	#define PrintString(s) printf("%s", (s));
#endif

/*
 * DevMax's interpreted program has access to most of the standard
 * C functions. If you don't want to install the C/C++ headers,
 * you can just copy the functions' signatures (prototypes).
 * With this, you can use DevMax's interpretation without having
 * to perform extra set-up (namely, copying the system headers to
 * the correct locations). We add here the most frequently used
 * functions. Feel free to expand as you need.
 *
 * At the moment, we do not yet support C++ due to its requirement
 * of the internal implementation.
 */

#ifdef _DEVMAX_INTERPRETER_
	extern "C"
	{
		#define EOF (-1)
		typedef void FILE; // opaque type
		FILE *fopen(const char*, const char*);
		void fclose(FILE*);
		int sprintf(char *, const char *, ...);
		int fscanf(FILE *, const char*, ...);
		int sscanf(char *, const char*, ...);
		int fgetc(FILE*);

		void memcpy(void*, void*, int);

		int strcmp(const char *, const char *);
		int strncmp(const char *, const char *, int);
		const char *strchr(const char *, char);
		int strlen(const char *);
		int strcpy(char*, const char*);
		int strcat(char*, const char*);

		void* malloc(unsigned int);
		void* realloc(void *, int);
		void free(void*);

		typedef unsigned int time_t;
		time_t time (time_t* timer);
		void srand (unsigned int seed);
	}
#else
	// When not interpreting, use the headers (requires set-up).
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include <math.h>
	#include <time.h>
#endif

/*
 * Using PrintString, it is easy to implement a convenient method
 * PrintFormatString. Here, we assume the resulting string is of
 * 1023 characters at most!
 * DevMax can't do <stdargs.h> but there's this trick you can use
 * for variadic functions.
 */
template <typename...Ts>
void PrintFormatString(const char *format, const Ts&... args)
{
	char buf[1024];
	sprintf(buf, format, args...);
	PrintString(buf);
}

#endif /* _DEVMAX_H_ */
