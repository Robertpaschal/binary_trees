#include "binary_trees.h"

/**
 * binary_tree_he - measures the height of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: height of the tree, -1 if tree is NULL
*/
size_t binary_tree_he(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (-1);

	left_height = binary_tree_he(tree->left);
	right_height = binary_tree_he(tree->right);

	if (left_height > right_height)
	{
		return (left_height + 1);
	}
	else
	{
		return (right_height + 1);
	}
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance
 * Return: balance factor of the tree, 0 if tree is NULL
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_he(tree->left);
	right_height = binary_tree_he(tree->right);

	return ((int)(left_height - right_height));
}
