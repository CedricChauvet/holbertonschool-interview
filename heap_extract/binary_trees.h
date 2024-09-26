#ifndef BINARY_TREES_H
#define BINARY_TREES_H


typedef struct {
    int *array;
    int size;
    int capacity;
} heap_t;


void swap(int *a, int *b);
void heapify_down(heap_t *heap, int i);
int heap_extract(heap_t **root);

#endif