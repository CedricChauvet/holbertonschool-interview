#include <stdlib.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;

heap_t *create_node(int value);
size_t binary_tree_size(const binary_tree_t *tree);
void heapify_up(heap_t *node);
heap_t *get_last_node(heap_t *root, size_t size);

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

    new_node = create_node(value);
    if (!new_node)
        return (NULL);

    if (!*root)
    {
        *root = new_node;
        return (new_node);
    }

    size = binary_tree_size(*root);
    parent = get_last_node(*root, size + 1);  // +1 pour la nouvelle position

    if (!parent->left)
        parent->left = new_node;
    else
        parent->right = new_node;
    new_node->parent = parent;

    heapify_up(new_node);

    // Mettre à jour la racine si nécessaire
    while (new_node->parent)
        new_node = new_node->parent;
    *root = new_node;

    return (new_node);
}

/**
 * create_node - Creates a new binary tree node
 * @value: Value to put in the new node
 * Return: Pointer to the new node, or NULL on failure
 */
heap_t *create_node(int value)
{
    heap_t *new_node = malloc(sizeof(heap_t));

    if (!new_node)
        return (NULL);

    new_node->n = value;
    new_node->parent = NULL;
    new_node->left = NULL;
    new_node->right = NULL;

    return (new_node);
}

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 * Return: Size of the tree, 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (!tree)
        return (0);
    return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * heapify_up - Fixes the heap property going up from given node
 * @node: Pointer to the node to start from
 */
void heapify_up(heap_t *node)
{
    int temp;

    while (node->parent && node->n > node->parent->n)
    {
        temp = node->n;
        node->n = node->parent->n;
        node->parent->n = temp;
        node = node->parent;
    }
}

/**
 * get_last_node - Gets the parent of the last node in level order traversal
 * @root: Pointer to the root of the heap
 * @size: Size of the heap after insertion
 * Return: Pointer to the parent of the last node
 */
heap_t *get_last_node(heap_t *root, size_t size)
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