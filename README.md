Getting Started with DevMax
===========================

This repository provides an example project configuration to get you started software development with [DevMax IDE](https://www.microsoft.com/en-us/p/devmax/9mzqlt5d5b39) and its sister app C++ Compiler.

If you do not have C++ Compiler installed yet, head over to [our C++ Compiler project](https://github.com/light-tech/UniversalCppCompiler) for installation instructions.

The key files included are:
 * [`DevMax.h`](DevMax.h): Interpreter API to allow communication between an interpreted program and DevMax IDE.
 * [`HelloWorld.cpp`](HelloWorld.cpp): Standard program to illustrate outputing text to DevMax's console.
 * [`project.json`](project.json): DevMax project file with basic features like reusable commands which you can modify to suit your project.

![Hello World Interpretation Screenshot](Screenshot.PNG)

DevMax Interpreter API
----------------------

A typical compiled C program uses various C's `stdio.h` functions such as `printf` to output information to the console (a.k.a. _Command Prompt_ on Windows or _Terminal_ on Linux). However, it is better that a program which is interpreted by DevMax print out its output to the text box in DevMax so that you don't have to switch back-and-forth between different windows during development. To allow that, DevMax provides a single C function

    void PrintString(const char* string);

that a program can use to pass a text string to DevMax's output terminal. This function is the DevMax-equivalent of `fputs(string, stdout)` or `printf("%s", string)`.

See the header [`DevMax.h`](DevMax.h) file for more details.