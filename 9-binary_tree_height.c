#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: height of the tree, 0 if tree is NULL
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
	return (0);

	size_t left_height = 0, right_height = 0;

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height > right_height)
	{
		return (left_height + 1);
	}
	else
	{
		return (right_height + 1);
	}
}
