#include "binary_trees.h"

/**
 * array_to_bst - Builds a Binary Search Tree (BST) from an array.
 * @array: A pointer to the first element of the array.
 * @size: The number of elements in the array.
 *
 * Return: A pointer to the root node of the created BST, or NULL on failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
    bst_t *tree = NULL;

    if (array == NULL)
        return NULL;

    for (size_t i = 0; i < size; i++)
    {
        bst_t *node = bst_insert(&tree, array[i]);
        if (node == NULL)
        {
            bst_delete(tree);
            return NULL;
        }
    }

    return tree;
}
