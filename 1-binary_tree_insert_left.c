#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a new node as the left child.
 * @parent: Node to insert the left child into.
 * @value: Value to store in the new node.
 *
 * Return: New node pointer if successful, NULL on failure.
 *
 * Description: Inserts a new node to the left of 'parent' node. If 'parent'
 * 		already has a left child, the new node takes its place, and the old left
 * 		child becomes the left child of the new node.
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		new_node->left = parent->left;
		parent->left->parent = new_node;
	}
	parent->left = new_node;

	return (new_node);
}
