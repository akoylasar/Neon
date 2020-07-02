# Neon
[![Build Status](https://travis-ci.com/akoylasar/Neon.svg?branch=master)](https://travis-ci.com/akoylasar/Neon)

Neon is a super simple single-header linear algebra library that contains necessary utilities tthat you need in your OpenGL graphics demos and small applications.
Originally I created this to be able to work on different projects and demos without having to rewrite similar code everytime.
It is still under development (since it lacks some tests and proper documentation) and by no means it is complete. 
Definitely not meant to be used in serious performance-critical applications (well.. at least not yet!).

## Usage
Just add the header to your project and you should be good to go! (Proper CMake compatible project will be added in future...).

## Running tests
In the root project direcotry create a folder and run cmake:
  * ```mkdir Build```
  * ```cd Build```
  * ```cmake -G"Your Favorite Compiler" ../Test```

## What you need
Any decent C++11 compiler! 

## License
The MIT License (MIT)

Copyright (c) Fouad Valadbeigi (akoylasar@gmail.com)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
