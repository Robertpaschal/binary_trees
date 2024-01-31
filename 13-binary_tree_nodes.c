#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child
 * @tree: pointer to the root node of the tree to count the nodes
 * Return: number of nodes with at least 1 child, 0 if tree is NULL
*/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left_nodes, right_nodes;

	if (tree == NULL)
		return (0);

	left_nodes = binary_tree_nodes(tree->left);
	right_nodes = binary_tree_nodes(tree->right);

	if (tree->left || tree->right)
		return (1 + (left_nodes + right_nodes));
	return (0);
}
