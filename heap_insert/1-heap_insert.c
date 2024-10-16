#include <stdlib.h>
#include "binary_trees.h"

//size_t binary_tree_size(const binary_tree_t *tree);
//heap_t *get_last_node_parent(heap_t *root, size_t size);

/**
 * heapify_up - Fixes the heap property going up from given node
 * @node: Pointer to the node to start from
 * Return: Pointer to the node after heapify
 */
heap_t *heapify_up(heap_t *node)
{
    int temp;

    while (node->parent && node->n > node->parent->n)
    {
        temp = node->n;
        node->n = node->parent->n;
        node->parent->n = temp;
        node = node->parent;
    }
    return node;
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *parent;
    size_t size;

    if (!root)
        return (NULL);

    new_node = binary_tree_node(NULL, value);
    if (!new_node)
        return (NULL);

    if (!*root)
    {
        *root = new_node;
        return (new_node);
    }

    size = binary_tree_size(*root);
    parent = get_last_node_parent(*root, size + 1);

    if (!parent->left)
        parent->left = new_node;
    else
        parent->right = new_node;
    new_node->parent = parent;

    return heapify_up(new_node);
}

/* Autres fonctions (binary_tree_size, get_last_node_parent) restent inchangées */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (!tree)
        return (0);
    return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * swap - Swaps two integers
 * @a: Pointer to first integer
 * @b: Pointer to second integer
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * get_last_node_parent - Gets the parent of the last node for insertion
 * @root: Pointer to the root of the heap
 * @size: Size of the heap
 * Return: Pointer to the parent of the last node
 */
heap_t *get_last_node_parent(heap_t *root, size_t size)
{
    size_t mask;
    
    for (mask = 1; mask <= size; mask <<= 1)
        ;
    mask >>= 2;
    
    while (mask > 1)
    {
        if (size & mask)
            root = root->right;
        else
            root = root->left;
        mask >>= 1;
    }
    
    return root;
}
