#include "binary_trees.h"

/**
 * is_leaf - Checks if a node is a leaf of a binary tree.
 * @node: A pointer to the node to check.
 *
 * Return: (1) if the node is a leaf, (0) otherwise.
 */
unsigned char is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? (1) : (0));
}

/**
 * depth - Returns the depth of a given node in a binary tree.
 * @tree: A pointer to the node to measure the depth of.
 *
 * Return: The depth of the node.
 */
size_t depth(const binary_tree_t *tree)
{
	if (tree->parent)
	{
		return ((1 + depth(tree->parent)));
	}
	return (0);
}

/**
 * get_leaf - Returns a leaf of a binary tree.
 * @tree: A pointer to the root node of the tree to find a leaf in.
 *
 * Return: A pointer to the first encountered leaf.
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree))
	{
		return (tree);
	}
	return ((tree->left ? get_leaf(tree->left) : get_leaf(tree->right)));
}

/**
 * is_perfect_recursive - Checks if a binary tree is perfect recursively.
 * @tree: A pointer to the root node of the tree to check.
 * @leaf_depth: The depth of one leaf in the binary tree.
 * @level: Level of the current node.
 *
 * Return: (1) if the tree is perfect, (0) otherwise.
 */
int is_perfect_recursive(const binary_tree_t *tree, size_t leaf_depth,
		size_t level)
{
	if (is_leaf(tree))
	{
		return ((level == leaf_depth) ? (1) : (0));
	}

	if (tree->left == NULL || tree->right == NULL)
	{
		return (0);
	}

	return ((is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
		is_perfect_recursive(tree->right, leaf_depth, level + 1) ? (1) : (0));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: (1) if the binary tree is perfect, (0) otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

	const binary_tree_t *leaf = get_leaf(tree);

	return (is_perfect_recursive(tree, depth(leaf), 0));
}
