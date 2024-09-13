#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "search_algos.h"

int mid = 0;

int advanced_binary(int *array, size_t size, int value)
{
    int result;
    printf("Searching in array: ");
    print_array(array, size);
    if (size == 1) {
        return -1;  // Élément non trouvé
    }
   
    // printf("size     %lld\n", size);
    size_t mid = size / 2;

    // printf("mid     %lld\n", mid);
    
    if (value == array[mid]) {
        printf("got ");
        return mid;
    }
    else if (value < array[mid]) {
        printf("left ");

        if (size % 2 == 0)
            return advanced_binary(array, mid, value);
        else    
            return advanced_binary(array, mid-1, value);
    }
    else {
        printf("right ");
        if(size % 2 == 0)
        {
            result = advanced_binary(array + mid , size - mid , value);
        }
        else
        {
            result = advanced_binary(array + mid +1 , size - mid - 1 , value);
        }   
        
        if  (result == -1) 
            return -1;
        else 
            return result + mid;
    }
}

    // printf("Searching in array: ");
    // print_array(array, size);
    // // printf(" index %ld \n", size / 2);
    // // printf("Val milieu %d \n", array[size/2]);
    // int new_size = (int)floor(size / 2);
    // printf("index milieu %d \n", new_size);
    // // if (size == 0)
    // //     return (-1);




    /**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}