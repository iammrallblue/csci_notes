#include <stdio.h>

int main(int argc, char const *argv[])
{
    /* Array in the memory */
    int A[] = {2, 4, 5, 8, 1};
    int *p = A; // same as int *p = A[0]
    // A++; // A++ is invalid
    // p++; // valid
    for (int i = 0; i < 5; i++)
    {
        // addresses of each element of the array
<<<<<<< HEAD:C_C++/c_lang/pointer_and_array_06.c
        printf("Address = %d\n", &A[i]); // &A[0] the starting address of the array A
        printf("Address = %d\n", A + i);
=======
        printf("Address = %d\n", &A[i]); // 
        printf("Address = %d\n", A + i); // each i has 4 bytes
>>>>>>> 07f53513973de38507154bd5f3e365440ae3dc0b:C_C++/c_lang_pointer/pointer_and_array_06.c

        // values of each array element
        printf("value = %d\n", A[i]);
        printf("value = %d\n", *(A + i)); 
    } // for
    return 0;
} // main
