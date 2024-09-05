#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>


void heap_sort(int *array, size_t size){
    // Build the heap
    print_array( array, size);
    
    // Open a file in write mode
    FILE *fptr;
    fptr = fopen("0-O", "w");
    fprintf(fptr, "Hello, World!\n");
    fclose(fptr);
    }