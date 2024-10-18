#ifndef _SORT_H_
#define _SORT_H_
#include <stddef.h>

void merge_sort(int *array, size_t size);
void merge_sort_recursive(int *array, size_t left, size_t right, int *temp);
void merge(int *array, size_t left, size_t mid, size_t right, int *temp);

void print_array(const int *array, size_t size);
#endif /* _SORT_H_ */