#include "binary_trees.h"
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(heap_t *root)
{
    heap_t *largest = root;
    heap_t *left = root->left;
    heap_t *right = root->right;

    if (left && left->n > largest->n)
        largest = left;
    if (right && right->n > largest->n)
        largest = right;

    if (largest != root)
    {
        swap(&root->n, &largest->n);
        heapify(largest);
    }
}

heap_t *get_last_node(heap_t *root)
{
    heap_t *queue[10000];
    int front = 0, rear = 0;
    heap_t *last = NULL;

    queue[rear++] = root;
    while (front < rear)
    {
        last = queue[front++];
        if (last->left)
            queue[rear++] = last->left;
        if (last->right)
            queue[rear++] = last->right;
    }
    return last;
}

int heap_extract(heap_t **root)
{
    int extracted_value;
    heap_t *last_node, *parent;

    if (!root || !*root)
        return 0;

    extracted_value = (*root)->n;
    last_node = get_last_node(*root);

    if (last_node == *root)
    {
        free(*root);
        *root = NULL;
        return extracted_value;
    }

    (*root)->n = last_node->n;
    parent = last_node->parent;
    if (parent->left == last_node)
        parent->left = NULL;
    else
        parent->right = NULL;

    free(last_node);
    heapify(*root);

    return extracted_value;
}