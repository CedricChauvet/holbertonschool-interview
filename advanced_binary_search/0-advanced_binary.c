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
    if (size == 0) {
        return -1;  // Élément non trouvé
    }
   
    // si size est paire on compare par rapport a l'element de gauche 
    if (size % 2 == 0)
        mid = (size / 2) -1;
    // si size est impaire on compare par rapport a l'element du milieu
    else
        mid = floor(size / 2);

    
    // si la valeur tombe sur le milieu de la liste
    if (value == array[mid]) {
        printf("got ");
        return mid ;

    }
    else if (value < array[mid]) {
        //printf("left ");

            return advanced_binary(array, mid, value);
    }
    else {
        int result = advanced_binary(array + mid +1 , size - mid - 1 , value);
        
        
        if  (result == -1) 
            return -1;
        else 
            return result + mid ;
    }
}


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