#include <stdio.h>
#include <stdlib.h>
#define no_of_elements 10

void main()
{
    int **ptr;
    char *p = "65";
    
    ptr = (int **)malloc(no_of_elements * sizeof(int*)); // allocating an array of character pointers
    
    for (int i = 0; i < no_of_elements; i++)
    {
        ptr[i] = (int *)malloc(sizeof(int)); // in each index position of the array, an address of a memory location from heap is stored
        *ptr[i] = atoi(p); // initializing all elements with 65
        p[1]++;
    }
    
    printf("Size - %d and ptr - %d\n", sizeof(ptr), *ptr[0]); // displaying primary heap task positions and dereferencing the location
    
    // for (int k = 0; k < no_of_elements; k++)
    //     free(ptr[k]); // deallocating each block
    
    //free(ptr);
    
    for (int i = 0; i < no_of_elements; i++, p[1]++)
        printf("p[%d] - %c and ptr[%d] - %d\n", i, p[i], i, *ptr[i]); // array prints memory positions after dereferencing the location (giving garbage value)
}
