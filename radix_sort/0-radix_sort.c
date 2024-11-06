#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sort.h"

/**
 * radix_sort - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void radix_sort(int *array, size_t size)
{
    /* compute radix  sort with Less Significant Digit*/
	int n = 0;
    int max = 0;
	int exp = 1;
	max = find_max(array, size);
	// printf("max: %d\n", max);
	n = compterChiffres(max);
	// printf("n: %d\n", n);

	for (int i = 0; i < n; i++)
	{	
	
		print_array(array, size);
		countSort(array, size, exp);
		exp = 10*exp;
	}
}

/**
 * compterChiffres - Prints an array of integers
 *
 * @nombre: The number n
 * @returns: Number of elements in a n
 */
int compterChiffres(int nombre) {
    
	int compte = 0;
    if (nombre == 0) return 1;
    while (nombre != 0) {
        nombre /= 10;
        compte++;
    }
    return compte;
}

/**
 * find_max - Prints an array of integers
 *
 * @array: The array to compute
 * @size: Size of the array
 * @returns: The max value of the array
 */
int find_max(int *array, size_t size)
{
	int max = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	return max;
}

// Fonction pour effectuer le tri par comptage sur un chiffre spécifique
void countSort(int arr[], int size, int exp) {
    	// int *output = malloc(size * sizeof(int));
	// int *output = (int *)malloc(n * sizeof(int));
	int *output = (int *)malloc(size * sizeof(int));
	int count[10] = {0}; // Pour stocker le compte des chiffres (0-9)
    
    // Compter les occurrences
    for (int i = 0; i < size; i++) {
        count[(arr[i] / exp) % 10]++;
    }
    
    // Modifier count[i] pour contenir la position réelle de ce chiffre dans output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    
    // Construire le tableau de sortie
    for (int i = size - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    
    // Copier le tableau de sortie dans arr[]
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
}