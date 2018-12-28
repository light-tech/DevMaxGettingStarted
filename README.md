Getting Started with DevMax
===========================

This repository provides an example project configuration to get you started software development with [DevMax IDE](https://www.microsoft.com/en-us/p/devmax/9mzqlt5d5b39) and its sister app C++ Compiler.

If you do not have C++ Compiler installed yet, head over to [our C++ Compiler project](https://github.com/light-tech/UniversalCppCompiler) for installation instructions.

![Hello World Interpretation Screenshot](Screenshot.PNG)

The project folder
------------------

Due to the limitation of the Universal Windows Platform (UWP), our DevMax and C++ Compiler apps can only accessed _certain designated places_. 

To open the location where DevMax stores the projects, first click on the _Open project_ button (the one between the + and the settings gear button) and then on the _Open project folder in Explorer_ in the pop-up dialog. DevMax should open a folder named `C++Projects` in Windows Explorer. __Note that ONLY projects placed there can be interpreted or compiled.__

The easiest way to get started is to clone this repository

    git clone https://github.com/light-tech/DevMaxGettingStarted

in the opened folder `C++Projects`.

__Tip:__ It is a good idea to make a shortcut to this folder on the desktop so that you can have quick access to your projects.

Project folder structure
------------------------

The key files are:
 * [`project.json`](project.json): DevMax project file with basic features like reusable commands which you can modify to suit your project. This is a human-readable [JSON file](https://en.wikipedia.org/wiki/JSON).
 * [`DevMax.h`](DevMax.h): Our standard interpreter API to allow communication between an interpreted program and DevMax IDE. (See the next section for its purpose.)
 * [`HelloWorld.cpp`](HelloWorld.cpp): Standard program to illustrate outputing text to DevMax's console.

DevMax Interpreter API
----------------------

A typical compiled C program uses various C's `stdio.h` functions such as `printf` to output information to the console (a.k.a. _Command Prompt_ in Windows or _Terminal_ in Linux). However, it is better that a program which is interpreted by DevMax print out its output to the text box in DevMax (see screenshot above) so that you don't have to switch back-and-forth between different windows during development. To allow that, DevMax provides a single C function

    void PrintString(const char* string);

that a program can use to pass a text string to DevMax's output terminal. This function is the DevMax-equivalent of `fputs(string, stdout)` or `printf("%s", string)`.

The header [`DevMax.h`](DevMax.h) declares this function for you.

Standard C API
--------------

DevMax's interpreted program has access to most of the standard C functions. If you don't want to install the system C/C++ headers, you can just add the functions' signatures (a.k.a. prototypes) you want. With this, you can use DevMax's interpretation feature right away without having to perform extra set-up (namely, copying the system headers to the correct locations). For instance, simply declare

    extern "C" void *malloc(unsigned int);

and then use `malloc` as if you included `<stdlib.h>`. See the header [`DevMax.h`](DevMax.h) for examples of how to do this.

At the moment, we do not yet support C++ standard library due to its significant dependency of the internal implementation.