#include <stdio.h>

int main(int argc, char const *argv[])
{
    /* Array in the memory */
    int A[] = {2, 4, 5, 8, 1};
    int *p = A;
    // A++; // A++ is invalid
    // p++; // valid
    for (int i = 0; i < 5; i++)
    {
        // addresses of each element of the array
        printf("Address = %d\n", &A[i]); // 
        printf("Address = %d\n", A + i); // each i has 4 bytes

        // values of each array element
        printf("value = %d\n", A[i]);
        printf("value = %d\n", *(A + i)); 
    } // for
    return 0;
} // main
