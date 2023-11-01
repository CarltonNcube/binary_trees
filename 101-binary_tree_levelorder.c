#include "binary_trees.h"

/**
 * binary_tree_levelorder - Performs level-order traversal of a binary tree
 *                          and applies a given function to each node's value.
 * @tree: A pointer to the root node of the binary tree.
 * @func: A pointer to a function that takes an integer as a parameter.
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	queue_t *queue = NULL;
	binary_tree_t *node = NULL;

	queue = queue_create();
	if (queue == NULL)
		return;

	queue_push(queue, (void *)tree);

	while (queue_size(queue) > 0)
	{
		node = (binary_tree_t *)queue_pop(queue);
		func(node->n);

		if (node->left != NULL)
			queue_push(queue, (void *)node->left);

		if (node->right != NULL)
			queue_push(queue, (void *)node->right);
	}

	queue_delete(queue);
}
