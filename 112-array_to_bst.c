#include "binary_trees.h"

/**
 * array_to_bst - Builds a binary search tree from an array.
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of elements in @array.
 *
 * Return: A pointer to the root node of the created BST, or NULL upon failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;

	if (array == NULL || size == 0)
		return (NULL);

	for (size_t i = 0; i < size; i++)
	{
		if (bst_insert(&tree, array[i]) == NULL)
		{
			bst_delete(tree);
			return (NULL);
		}
	}

	return (tree);
}
