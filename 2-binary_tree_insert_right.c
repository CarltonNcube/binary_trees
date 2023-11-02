#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a new node as the right child.
 * @parent: A pointer to the node where the right child is inserted.
 * @value: The value to store in the new node.
 *
 * Return: If parent is NULL or an error occurs - NULL.
 *         Otherwise - a pointer to the new node.
 *
 * Description: Inserts a new node to the right of 'parent' node. If 'parent'
 * 		already has a right child, the new node takes its place, and
 * 		the old right child becomes the right child of the new node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		new_node->right = parent->right;
		parent->right->parent = new_node;
	}

	parent->right = new_node;

	return (new_node);
}
