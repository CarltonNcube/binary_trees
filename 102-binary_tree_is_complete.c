#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to traverse.
 *
 * Return: If the tree is NULL or not complete, 0.
 *         Otherwise, 1.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    levelorder_queue_t *head, *tail;
    unsigned char flag = 0;

    if (tree == NULL)
        return (0);

    head = tail = create_node((binary_tree_t *)tree);
    if (head == NULL)
        return (0);

    while (head != NULL)
    {
        if (head->node->left != NULL)
        {
            if (flag == 1)
            {
                free_queue(head);
                return (0);
            }
            push(head->node->left, head, &tail);
        }
        else
            flag = 1;

        if (head->node->right != NULL)
        {
            if (flag == 1)
            {
                free_queue(head);
                return (0);
            }
            push(head->node->right, head, &tail);
        }
        else
            flag = 1;

        pop(&head);
    }

    free_queue(head);
    return (1);
}
