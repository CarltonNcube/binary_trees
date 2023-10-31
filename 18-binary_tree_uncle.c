#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node in a binary tree.
 * @node: A pointer to the node for which the uncle is to be found.
 *
 * Return: A pointer to the uncle node, or NULL if no uncle exists.
 *
 * Description: This function locates the uncle of the given node in a
 * binary tree. The uncle is the sibling of the parent node. If the
 * input node is NULL, has no parent, or has no uncle, the function
 * returns NULL.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	if (node->parent == node->parent->parent->left)
		return (node->parent->parent->right);
	else
		return (node->parent->parent->left);
}
