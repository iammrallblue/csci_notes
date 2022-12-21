# Pointer in C

- [Pointer in C](#pointer-in-c)
  - [Introduction to Pointer in C](#introduction-to-pointer-in-c)
    - [What is Pointer?](#what-is-pointer)
    - [Builtin Data types](#builtin-data-types)
    - [Using a Pointer](#using-a-pointer)
    - [Pointer Arithmetic](#pointer-arithmetic)
    - [Pointer types, and void Pointer](#pointer-types-and-void-pointer)
    - [Pointer to Pointer](#pointer-to-pointer)

## Introduction to Pointer in C

### What is Pointer?

- The Pointer in C, is a variable that stores address of another variable.
- A pointer can also be used to refer to another pointer function.
- A pointer can be incremented/decremented,
  - i.e., to point to the next/ previous memory location.

### Builtin Data types

- int type is `4 bytes`
- char type is `1 byte`
- float type is `4 bytes`

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
- `&p` contains the address of the variable `p`, `&p == 64`
- `*p` get the value, `*p = a` or dereferencing
- `p->` the address of `a`, `*p->` the value at address of `a`

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

### Pointer Arithmetic

- Pointer increment/decrement
- The point `int* p` is pointed to the address of the variable `a`
  `int* p = &a`, `p+1` will be increased by **4 bytes** i.e. p = 2002, p+1 = 2002+4
- Pointer `p` MUST pointed to an address of variable before using it,
  `p` contains the address of a, the address of a will be increased by 4 bytes

```c
#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a = 10;
    int *p = &a;
    // Pointer Arithmetic
    printf("p = %p\n", p); // p = 2002
    // show size of int type
    printf("size of int is: %ld bytes\n", sizeof(int));
    printf("p+1 = %p\n", p + 1); // p+1 = 2006

    return 0;
} // main

```

### Pointer types, and void Pointer

- `int` is `4 bytes`, `char` is `1 byte`, `float` is `4 bytes`
- Why strong types, `int* -> int` of `char* -> char`

  - Dereference, easy to access/ modify value of the variable

- Why not generic types?

<img src="img/pointer_types.jpg" alt="pointer" width="800">

```c
#include <stdio.h>
int main(int argc, char const *argv[])
{
    /* code */
    int a = 1025;
    int *p;
    p = &a;                                                 // pointer p = the address of a
    printf("size of integer is %d bytes \n", sizeof(int));  // 4 byts
    printf("pointer p, Address = %d, value = %d\n", p, *p); // p is address, *p is value
    // p + 1
    printf("p + 1, Address = %d, value = %d\n", p + 1, *(p + 1));
    // p + 1 address increases, *(p + 1) is the value in the address (p + 1)

    // typecasting
    char *p0;                                           // p0 is the char pointer
    p0 = (char *)p;                                     //  type casting int pointer p
    printf("size of char is %d byte \n", sizeof(char)); // char is 1 byte
    printf("Address = %d, value = %d\n", p0, *p0);
    // The char pointer p0 has same address with int pointer p,
    // *p0 has the value of a, but *p0 is char type, (casttyping)
    // why the value of *p0 is 1?
    // 1025 in 32-bit binary  0000 0000 0000 0000 0000 0100 0000 0001
    // typecasting made p0 to 0000 0001 (char is 1 byte or 8 bits)

    /* void pointer is a kind of generic pointer. */
    void *p1;
    p1 = p; // void pointer p1 has same addres with int pointer p
    printf("The void* p1, Address = %d\n", p1);
    printf("p= %d\n", p);
    return 0;
} // main
```

### Pointer to Pointer
-



<img src="img" alt="pointer_to_pointer" width="800">