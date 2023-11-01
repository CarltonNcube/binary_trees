/**
 * binary_trees_ancestor - Finds the lowest common ancestor of
 * 			two nodes in a binary tree.
 * @first: A pointer to the first node.
 * @second: A pointer to the second node.
 *
 * Return: A pointer to the lowest common ancestor, or NULL if
 * 	no common ancestor is found.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
    if (first == NULL || second == NULL)
        return (NULL);

    if (first == second)
        return ((binary_tree_t *)first);

    if (first == second->parent)
        return ((binary_tree_t *)second);

    if (second == first->parent)
        return ((binary_tree_t *)first);

    if (first->parent == second->parent)
        return (binary_trees_ancestor(first->parent, first->parent));

    if (first->parent == NULL || second->parent == NULL)
        return (NULL);

    return (binary_trees_ancestor(first->parent, second->parent));
}
