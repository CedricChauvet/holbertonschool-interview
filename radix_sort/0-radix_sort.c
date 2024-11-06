#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sort.h"

/**
 * radix_sort - Trie un tableau d'entiers avec LSD radix sort
 * @array: Le tableau à trier
 * @size: Nombre d'éléments dans le tableau
 */
void radix_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    int max = find_max(array, size);
    int exp;

    // Commencer avec exp = 1 et continuer tant que max/exp > 0
    for (exp = 1; max/exp > 0; exp *= 10)
    {
        countSort(array, size, exp);
        if (max/exp > 0)  // Ne pas imprimer après la dernière itération
            print_array(array, size);
    }
}

/**
 * find_max - Trouve la valeur maximale dans un tableau
 * @array: Le tableau à analyser
 * @size: Taille du tableau
 * Return: La valeur maximale
 */
int find_max(int *array, size_t size)
{
    int max = array[0];
    for (size_t i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    return max;
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

    // Compter les occurrences
    for (i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    // Calculer les positions finales
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Construire le tableau de sortie
    for (i = size - 1; i >= 0; i--)
    {
        int digit = (array[i] / exp) % 10;
        output[count[digit] - 1] = array[i];
        count[digit]--;
    }

    // Copier le tableau trié dans le tableau original
    for (i = 0; i < size; i++)
        array[i] = output[i];

    free(output);
}