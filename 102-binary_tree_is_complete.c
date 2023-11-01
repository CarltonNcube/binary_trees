#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    levelorder_queue_t *queue = NULL;
    int seen_null = 0;

    if (tree == NULL)
        return (0);

    queue = create_node((binary_tree_t *)tree);
    if (queue == NULL)
        return (0);

    while (queue != NULL)
    {
        binary_tree_t *current = queue->node;

        if (current->left)
        {
            if (seen_null)
            {
                free_queue(queue);
                return (0);
            }
            push(current->left, queue);
        }
        else
        {
            seen_null = 1;
        }

        if (current->right)
        {
            if (seen_null)
            {
                free_queue(queue);
                return (0);
            }
            push(current->right, queue);
        }
        else
        {
            seen_null = 1;
        }

        pop(&queue);
    }

    free_queue(queue);
    return (1);
}
