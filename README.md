# CS510 CW 11

**Author(s):** _Kaiqin Huang, Nengyin Zhu_

[![Build Status](https://travis-ci.org/chapman-cs510-2016f/cw-11-redyellow.svg?branch=master)](https://travis-ci.org/chapman-cs510-2016f/cw-11-redyellow)

**Due date:** 2016/11/15

## Specification

**Note: Remember this is a C project.**

Complete the following exercises, saving your solutions in the indicated files. 

1. Recall the following references, which will still be useful throughout the rest of the course.
    * [Learn C in Y Minutes](https://learnxinyminutes.com/docs/c/)
    * [C Cheat Sheet](https://www.cheatography.com/ashlyn-black/cheat-sheets/c-reference/)
    * [C Programming Wikibook](https://en.wikibooks.org/wiki/C_Programming)
    * [Learn Make in Y Minutes](https://learnxinyminutes.com/docs/make/)
1. Examine the source code in ```src/matrix``` carefully. Finish coding the implementation.
    1. In a Jupyter notebook ```Matrix.ipynb```, describe how the ```MATRIX``` type is defined and how it works in detail. Explain in particular the difference between "row-major ordering" and "column-major ordering" for multidimensional arrays, and which is the default in C.
    1. Explain how you could force C to use the non-default array ordering if desired.
    1. Make sure that ```test_matrix``` in the ```test/``` folder compiles and runs correctly after you are finished implementing ```MATRIX```.
1. Examine the source code in ```src/stack``` carefully. Finish coding the implementation.
    1. Add comments that explain in the source code what each line is doing, to make sure you understand everything.
    1. Implement the print functions in a sensible way.
    1. In a Jupyter notebook ```Stack.ipynb```, describe how the ```STACK``` type is defined and how it works in detail. Explain in particular the various use of pointers throughout. Why is ```STACK``` itself defined as a pointer to a struct?
    1. Make sure that ```test_struct``` in the ```test/``` folder compiles and runs correctly after you are finished implementing ```STRUCT```.


## Assessment

Helen:

I learned about stack which is first in last out.  Matrix has column-major ordering and row-major ordering.  But I don't know why STACK itself defined as a pointer to a struct.  I will ask you in class.

Kaiqin:

It is the shortest and hardest-to-understand (the stack thing) C programming homework so far.  But I have got most of it after three whole days' learning, asking, thinking, and practicing.  Specifically, I have learned

Matrix:

1. How a matrix is defined (rows, cols, and mat);
2. What "row-majoring ordering" and "column-majoring ordering" are;
3. How to indicate an element (using \*(m->mat + (m->cols * row) + col) = v);
4. A combination of two *for* loops seems the best way to reach each element in the matrix when we want to print it out or to do math (e.g. addition) on it.

Stack:

1. How a struct stack, a STACK, and a STACK \* is defined;
2. STACK \* confused everything.  Graphs helped me understand where each stach or pointer is and how the system works as a whole;
3. What functions push_stack and pop_stack do.  Push_stack is to add one more element to the top.  Pop_stack is to remove the uppest stack and return the value in it;
4. A *while* loop is very useful to reach each stack and analyze the value in it;

Lingering questions:

1. Matrix: I actually could not answer the question ii. on how to force C to use the non-default array ordering if desired.  It seems impossible to me or maybe I do not know a specific code or trick.  Our answer seems to answering what the existing code should be if C is using column-major ordering.

2. Stack: When adding an element, why do not add the stack to the bottom, so that it is just pointed to by the current bottomest stack, and its own head points to NULL?  We can reach the bottomest stack by a *while* loop.  It seems easier to me because we no longer need to reset the pointer s.

## Honor Pledge

I pledge that all the work in this repository is my own with only the following exceptions:

* Content of starter files supplied by the instructor;
* Code borrowed from another source, documented with correct attribution in the code and summarized here.

Signed,

**Kaiqin Huang, Nengyin Zhu**
