# Pointer in C

- [Pointer in C](#pointer-in-c)
  - [Introduction to Pointer in C](#introduction-to-pointer-in-c)
    - [What is Pointer?](#what-is-pointer)
    - [Builtin Data types](#builtin-data-types)
    - [Using a Pointer](#using-a-pointer)

## Introduction to Pointer in C

### What is Pointer?

- The Pointer in C, is a variable that stores address of another variable.
- A pointer can also be used to refer to another pointer function.
- A pointer can be incremented/decremented,
  - i.e., to point to the next/ previous memory location.

### Builtin Data types

- int type is `4 bytes`
- char type is `1 byte`
- float tyep is `4 bytes`

<img src="img/variable_in_memory.png" alt="memory" width="800">

### Using a Pointer

- Using a pointer
- `* operator` is the indirection operator, to declare a pointer
- To get the address of a variable, we use the ampersand `& operator`

<img src="img/variable_and_pointer.png" alt="pointer" width="800">

- Declare A pointer `int *p` points to an int variable `int a`, `p = &a`
  the pointer `p` **MUST** be int type,
- `&a` contains the address of the variable `a`
- `p` and `&a` have same address, `p = &a`, in the example is 204
- `&p` contains the address of the varialbe `p`, `&p == 64`
- `*p` get the value, `*p = a` or derefrencing

```c
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 5;  //variable declaration
    int *p = &a;             // the address of a, or p = &a
    printf("a = %d\n", a);   // a = 5
    *p = 12;                 // dereferencing, same as a = 12
    printf("p = %p\n", p);   //  p = &a the address of a
    printf("&p = %p\n", &p); // &p = the address of pointer p
    // printf("p = %x\n", p);
    printf("*p = %d\n", *p); // *p = 12
    printf("a = %d\n", a); // a = 12
    printf("&a = %p\n", &a); // p == &a, the address of a
    return 0;
} // main
```