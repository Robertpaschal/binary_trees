#include "binary_trees.h"
#include <limits.h>

/**
 * is_bst_util - helper function to check if a binary tree is a valid BST
 * @tree: pointer to the root node of the tree
 * @min: the minimum value the current node's value can be
 * @max: the maximum value the current node's value can be
 * Return: 1 if the tree is a vlaid BST, 0 otherwise
*/
int is_bst_util(const binary_tree_t *tree, int min, int max)
{
	int left, right;

	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	left = is_bst_util(tree->left, min, tree->n);
	right = is_bst_util(tree->right, tree->n, max);

	return (left && right);
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a vlaid BST, and 0 otherwise
 * if tree is NULL, return 0
*/
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_bst_util(tree, INT_MIN, INT_MAX));
}
