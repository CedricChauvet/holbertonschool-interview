#ifndef SORT_H
#define SORT_H

#include <math.h>
#include <stddef.h>

void print_array(const int *array, size_t size);
void radix_sort(int *array, size_t size);


int find_max(int *array, size_t size);
int compterChiffres(int nombre);
void countSort(int arr[], int n, int exp);

#endif