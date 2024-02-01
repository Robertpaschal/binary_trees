#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if the tree is full, 0 otherwise
*/
int binary_tree_is_full(const binary_tree_t *tree)
{
	int left_tree, right_tree;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->left)
		left_tree = binary_tree_is_full(tree->left);
	if (tree->right)
		right_tree = binary_tree_is_full(tree->right);

	if (tree->left && tree->right)
		return (left_tree && right_tree);

	return (0);
}
