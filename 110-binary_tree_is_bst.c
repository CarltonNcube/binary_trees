#include "binary_trees.h"
#include "limits.h"

/**
 * is_bst_helper - Helper function to check if a binary tree is a binary search tree.
 * @tree: A pointer to the current node.
 * @min_value: The minimum allowed value for nodes in the tree.
 * @max_value: The maximum allowed value for nodes in the tree.
 *
 * Return: 1 if the tree is a binary search tree, 0 otherwise.
 */
int is_bst_helper(const binary_tree_t *tree, int min_value, int max_value)
{
	if (tree == NULL)
		return 1;

	if (tree->n < min_value || tree->n > max_value)
		return 0;

	return is_bst_helper(tree->left, min_value, tree->n - 1) &&
		is_bst_helper(tree->right, tree->n + 1, max_value);
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a binary search tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is a binary search tree, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return 0;

	return is_bst_helper(tree, INT_MIN, INT_MAX);
}
