#include "binary_trees.h"

/**
 * binary_tree_he - measures the height of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: height of the tree, -1 if tree is NULL
*/
size_t binary_tree_he(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	if (tree->left)
		left_height = binary_tree_he(tree->left);
	if (tree->right)
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

	if (tree->left)
		left_height = binary_tree_he(tree->left);
	if (tree->right)
		right_height = binary_tree_he(tree->right);

	return ((int)(left_height - right_height));
}

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

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if the tree is perfect, 0 otherwise
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (binary_tree_is_full(tree) && binary_tree_balance(tree) == 0)
		return (1);

	return (0);
}
