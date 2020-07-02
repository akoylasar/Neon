# Neon
[![Build Status](https://travis-ci.com/akoylasar/Neon.svg?branch=master)](https://travis-ci.com/akoylasar/Neon)

Neon is a super simple single-header linear algebra library that contains necessary utilities tthat you need in your OpenGL graphics demos and small applications
(originally I created this to be able to work on different projects and demos without having to rewrite similar code everytime).
It is still under development (since it lacks some tests and proper documentation) and by no means it is compelete. 
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
