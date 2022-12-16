#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 5;               // //variable declaration
    int *p = &a;             // the address of a, or p = &a
    printf("a = %d\n", a);   // a = 5
    *p = 12;                 // dereferencing, same as a = 12
    printf("p = %p\n", p);   //  p = &a the address of a
    printf("&p = %p\n", &p); // &p = the address of pointer p
    // printf("p = %x\n", p);
    printf("*p = %d\n", *p); // *p = 12
    printf("a = %d\n", a);
    printf("&a = %p\n", &a); // p == &a, the address of a

    return 0;
} // main
