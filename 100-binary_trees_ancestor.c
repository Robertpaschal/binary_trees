#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the lowest common ancestor node, or NULL if not found
*/
binary_tree_t *binary_trees_ancestor(
	const binary_tree_t *first, const binary_tree_t *second)
{
	if (first == NULL || second == NULL)
		return (NULL);

	const binary_tree_t *ancestor = first;

	while (ancestor != NULL)
	{
		if (binary_trees_is_ancestor(ancestor, second))
			return ((binary_tree_t *)ancestor);

		ancestor = ancestor->parent;
	}

	return (NULL);
}

/**
 * binary_trees_is_ancestor - checks if a node is an ancestor of another node
 * @ancestor: potential ancestor node
 * @node: node to check if it is a descendant
 * Return: 1 if ancestor is an ancestor of node, 0 otherwise
*/
int binary_trees_is_ancestor(
	const binary_tree_t *ancestor, const binary_tree_t *node)
{
	while (node != NULL)
	{
		if (node == ancestor)
			return (1);

		node = node->parent;
	}

	return (0);
}
