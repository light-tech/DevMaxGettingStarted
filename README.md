Getting Started with DevMax
===========================

This repository provides an example project configuration to get you started software development with [DevMax IDE](https://www.microsoft.com/en-us/p/devmax/9mzqlt5d5b39).

Set up C++ headers and libraries
--------------------------------

We assume that you have set up the C++ headers and libraries at `C:\MSCpp`: either by
 * cloning [our repo](https://github.com/light-tech/MSCpp) in `C:`; or
 * [download](https://github.com/light-tech/MSCpp/archive/master.zip) the repo and either unzip it there; or
 * clone/download+unzip anywhere then use `mklink /j` to create a symbolic link to the repo/extracted folder.

If you have a custom C++ headers and libraries set-up, you might need to change the paths in `project.json` appropriately.
Also, if you use DevMax's menu __Set up system headers and libraries__ (under __Project__)  to download the libraries, you MUST turn the paths into relative paths.
(We are working on improving the set up user interface.)

![Hello World Interpretation Screenshot](Screenshot.PNG)

Project folder structure
------------------------

The key files are:
 * [`project.json`](project.json): DevMax project file with basic features like reusable commands which you can modify to suit your project. This is a human-readable [JSON file](https://en.wikipedia.org/wiki/JSON). This file is necessary. See [here](https://github.com/light-tech/UniversalCppCompiler/blob/master/PROJECT_FILE_SPEC.md) for the specification of this file.
 * [`DevMax.h`](DevMax.h): Our standard interpreter API to allow communication between an interpreted program and DevMax IDE. (See the next section for its purpose.)
 * The source files, for example [`HelloWorld.cpp`](HelloWorld.cpp), the standard program to illustrate outputing text to DevMax's console. It is up to you to structure your own source code, but the correct location needs to be reflected in the project file.

DevMax Interpreter API
----------------------

__UPDATE__: Embedded terminal is not available as of DevMax 2.7.0.0 due to the switch to Win32 compiler. It might be restored in the future.

A typical compiled C program uses various C's `stdio.h` functions such as `printf` to output information to the console (a.k.a. _Command Prompt_ in Windows or _Terminal_ in Linux). However, it is better that a program which is interpreted by DevMax print out its output to the text box in DevMax (see screenshot above) so that you don't have to switch back-and-forth between different windows during development. To allow that, DevMax provides a single C function

    void PrintString(const char* string);

that a program can use to pass a text string to DevMax's output terminal. This function is the DevMax-equivalent of `fputs(string, stdout)` or `printf("%s", string)`.

The header [`DevMax.h`](DevMax.h) declares this function for you.

Standard C API
--------------

DevMax's interpreted program has access to most of the standard C functions. If you don't want to install the system C/C++ headers, you can just add the functions' signatures (a.k.a. prototypes) you want. With this, you can use DevMax's interpretation feature right away without having to perform extra set-up (namely, copying the system headers to the correct locations).

For instance, simply declare

    extern "C" void *malloc(unsigned int);

and then use `malloc` as if you included `<stdlib.h>`. See the header [`DevMax.h`](DevMax.h) for examples of how to do this declaration properly. To see this in action, interpret the [Sort.cpp](Sort.cpp) program.

__Exercise:__ Combining DevMax's `PrintString` and standard C's `sprintf`, implement the function `PrintFormatString` which mimics `printf` but outputs to DevMax's console instead. _Solution_: See the header [`DevMax.h`](DevMax.h).

__Exercise:__ Research the reason it is not a good idea to use `printf` in practice. _Hint:_ (i) Most `printf` are for debugging so there's a need to easily turn on/off these redundant code; (ii) Type safety/security issue; (iii) Hard to remember the format specification; for example `double` or `int64_t`; (iv) Performance: Think about how you would implement `printf` yourself bearing in mind that it is much more efficient to output a long string than individual characters to the console.

Standard C++ API
----------------

At the moment, concerning the __interpreter__, we do not yet support C++ standard library due to its significant dependency of the internal implementation and there are also limitations to the C++ language.

__Exercise:__ The C++ preferred method of textual output is via `iostream` which one could turn on/off easily:
```C++
// Initialize to std::cout or std:cerr when debugging
// and something like /dev/null when releasing (or write to a debug file
// if you want to allow users to send you debug log for debugging).
std::ostream debug_out;
```
Implement `std::cout` using `PrintString`.

__Exercise:__ Implement `std::vector` or test out an open source implementation.