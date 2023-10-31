#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a given node in a binary tree.
 * @node: A pointer to the node for which the sibling is to be found.
 *
 * Return: A pointer to the sibling node, or NULL if no sibling is found.
 *
 * Description: This function locates the sibling of the given node in a
 * binary tree. The sibling is the other child of the parent node. If
 * the input node is NULL or has no parent (i.e., it is the root node),
 * or if no sibling is found, the function returns NULL.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL
			return (NULL);

			if (node->parent->left == node)
			return (node->parent->right);
			else
			return (node->parent->left);
}
