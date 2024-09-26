#include <stdio.h>
#include <stdlib.h>


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify_down(heap_t *heap, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap->size && heap->array[left] > heap->array[largest])
        largest = left;

    if (right < heap->size && heap->array[right] > heap->array[largest])
        largest = right;

    if (largest != i) {
        swap(&heap->array[i], &heap->array[largest]);
        heapify_down(heap, largest);
    }
}

int heap_extract(heap_t **root) {
    if (!root || !*root || (*root)->size == 0)
        return -1;  // Ou une autre valeur pour indiquer une erreur

    heap_t *heap = *root;
    int extracted = heap->array[0];

    // Remplacer la racine par le dernier élément
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;

    // Heapify down pour maintenir la propriété du tas max
    heapify_down(heap, 0);

    return extracted;
}

// Fonction auxiliaire pour créer un nouveau tas
heap_t* create_heap(int capacity) {
    heap_t* heap = (heap_t*)malloc(sizeof(heap_t));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (int*)malloc(sizeof(int) * capacity);
    return heap;
}

// Fonction auxiliaire pour insérer un élément dans le tas
void heap_insert(heap_t *heap, int value) {
    if (heap->size == heap->capacity) {
        printf("Heap is full\n");
        return;
    }
    
    int i = heap->size;
    heap->array[i] = value;
    heap->size++;

    // Heapify up
    while (i > 0 && heap->array[(i-1)/2] < heap->array[i]) {
        swap(&heap->array[i], &heap->array[(i-1)/2]);
        i = (i-1)/2;
    }
}

void print_heap(heap_t *heap) {
    printf("Tas : ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->array[i]);
    }
    printf("\n");
}

int main() {
    heap_t *heap = create_heap(10);
    
    // Insérer des éléments dans le tas
    int elements[] = {100, 90, 80, 70, 60, 50, 40};
    for (int i = 0; i < sizeof(elements)/sizeof(elements[0]); i++) {
        heap_insert(heap, elements[i]);
    }

    printf("Tas original :\n");
    print_heap(heap);

    int extracted = heap_extract(&heap);
    printf("Valeur extraite : %d\n", extracted);

    printf("Tas après extraction :\n");
    print_heap(heap);

    // Libérer la mémoire
    free(heap->array);
    free(heap);

    return 0;
}