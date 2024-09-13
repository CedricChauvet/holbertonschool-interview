#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * Fonction récursive pour effectuer la recherche binaire avancée en utilisant la taille du tableau.
 */
int advanced_binary(int *array, size_t size, int value) {
    // Cas de base pour des tableaux très petits
    if (size == 0) {
        return -1;
    }
        // Afficher le sous-tableau actuel.
    print_array(array, size);
    // Cas spécial pour un tableau de 1 élément
    if (size == 1) {
        if (array[0] == value) {
            return 0;
        } else {
            return -1;
        }
    }

    // Cas spécial pour un tableau de 2 éléments
    if (size == 2) {
        if (array[0] == value) {
            return 0;
        }
        if (array[1] == value) {
            return 1;
        }
        return -1;
    }



    size_t mid = size / 2;

    // Si on trouve la valeur au milieu, vérifier si c'est la première occurrence.
    if (array[mid] == value) {
        // Si c'est le premier élément du tableau ou si le précédent élément n'est pas égal à la valeur.
        if (mid == 0 || array[mid - 1] != value) {
            return mid;
        }
        // Sinon, continuer à chercher dans la moitié gauche pour trouver la première occurrence.
        return advanced_binary(array, mid, value);
    }
    // Si la valeur au milieu est plus grande, chercher dans la moitié gauche.
    else if (array[mid] > value) {
        return advanced_binary(array, mid, value);
    }
    // Si la valeur au milieu est plus petite, chercher dans la moitié droite.
    else {
        int result = advanced_binary(array + mid + 1, size - mid - 1, value);
        // Si la valeur est trouvée dans la partie droite, ajuster l'index.
        if (result != -1) {
            return mid + 1 + result;
        } else {
            return -1;
        }
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