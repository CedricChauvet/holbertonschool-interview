#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>



void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void siftDown(int a[], int start, int end, int length) {
    int root = start;
    while (2 * root + 1 < end) {
        int child = 2 * root + 1;
        if (child + 1 < end && a[child] < a[child + 1]) {
            child++;
        }
        if (a[root] < a[child]) {
            swap(&a[root], &a[child]);
            print_array(a, length); // Utilisation de la taille du tableau
            root = child;
        } else {
            return;
        }
    }
}

void heapify(int a[], int count) {
    int start = (count / 2) - 1;
    while (start >= 0) {
        siftDown(a, start, count, count);
        start--;
    }
}

void heap_sort(int a[], int count) {
    heapify(a, count);
    int end = count;
    while (end > 1) {
        end--;
        swap(&a[0], &a[end]);
        print_array(a, count); // Utilisation de la taille du tableau
        siftDown(a, 0, end, count);
    }
}