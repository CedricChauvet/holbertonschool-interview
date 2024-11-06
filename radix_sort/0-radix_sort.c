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
	if (array == NULL || size < 2)
		{
		return;
		}
    /* compute radix  sort with Less Significant Digit*/
	int n;
	int max;
	int exp = 1;

	max = find_max(array, size);
	/* printf("max: %d\n", max); */
	n = compterChiffres(max);
	/* printf("n: %d\n", n);*/

	for (int i = 0; i < n; i++)
	{
		countSort(array, size, exp);
		print_array(array, size);
		exp = 10 * exp;
	}
}

/**
 * compterChiffres - Prints an array of integers
 *
 * @nombre: The number n
 * Return: Number of elements in a n
 */
int compterChiffres(int nombre)
	{
	int compte = 0;

	if (nombre == 0)
		return (1);
	while (nombre != 0)
		{
		nombre /= 10;
		compte++;
		}
	return (compte);
}

/**
 * find_max - Prints an array of integers
 *
 * @array: The array to compute
 * @size: Size of the array
 * Return: The max value of the array
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
	return (max);
}

/**
 * countSort - Effectue le tri par comptage pour un chiffre spécifique
 * @array: Le tableau à trier
 * @size: Taille du tableau
 * @exp: L'exposant actuel (1, 10, 100, etc.)
 */
void countSort(int *array, int size, int exp)
{
	int *output = malloc(size * sizeof(int));
	int count[10] = {0};
	int i;

	if (output == NULL)
		return;

    /* Compter les occurrences */
	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

    /* Calculer les positions finales */
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

    /* Construire le tableau de sortie */
	for (i = size - 1; i >= 0; i--)
		{
		int digit = (array[i] / exp) % 10;

		output[count[digit] - 1] = array[i];
		count[digit]--;
		}

	/* Copier le tableau trié dans le tableau original*/
	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}
