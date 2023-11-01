#include "binary_trees.h"

/**
 * binary_tree_height - Get the height of a binary tree.
 * @tree: A pointer to the root of the tree.
 * Return: The height of the tree, or -1 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_is_avl - Check if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree.
 * Return: 1 if tree is a valid AVL tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (1);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (abs(left_height - right_height) <= 1 &&
	    binary_tree_is_avl(tree->left) &&
	    binary_tree_is_avl(tree->right))
		return (1);

	return (0);
}
