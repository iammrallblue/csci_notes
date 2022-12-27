#include <stdio.h>

int sumOfElement(int A[], int size)
{
    int i, sum = 0;
    for (i = 0; i < size; i++)
    {
        sum += A[i];
    }

} // sumOfElement

int main(int argc, char const *argv[])
{
    /* code */
    int A[] = {1, 2, 3, 4, 5};
    int size = sizeof(A) / sizeof(A[0]);
    int total = sumOfElement(A, size);
    return 0;
} // main
