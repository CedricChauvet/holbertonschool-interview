#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>


// void heap_sort(int *array, size_t size){
//     // Build the heap
//     print_array( array, size);
    
//     // Open a file in write mode
//     FILE *fptr;
//     fptr = fopen("0-O", "w");
//     fprintf(fptr, "Hello, World!\n");
//     fclose(fptr);
//     }


void siftDown(int arr[], int n, int i) {
    int largest = i; // Initialiser largest comme racine
    int left = 2 * i + 1; // gauche = 2*i + 1
    int right = 2 * i + 2; // droite = 2*i + 2

    // Si le fils gauche est plus grand que la racine
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Si le fils droit est plus grand que largest jusqu'à présent
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Si largest n'est pas la racine
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Appliquer récursivement sift-down sur le sous-arbre affecté
        siftDown(arr, n, largest);
    }
}

// Fonction principale pour effectuer le tri par tas
void heap_sort(int arr[], int n) {
    // Construire le tas (réorganiser le tableau)
    for (int i = n / 2 - 1; i >= 0; i--)
        siftDown(arr, n, i);

    // Extraire un par un les éléments du tas
    for (int i = n - 1; i > 0; i--) {
        // Déplacer la racine actuelle à la fin
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        print_array(arr, n);
        // Appeler sift-down sur le tas réduit
        siftDown(arr, i, 0);
    }
}
