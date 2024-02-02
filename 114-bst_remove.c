#include "binary_trees.h"

/**
 * find_successor - finds the leftmost node in the right subtree
 * @node: pointer to the root of the right subtree
 * Return: pointer to the leftmost node
 */
bst_t *find_successor(bst_t *node)
{
	while (node && node->left)
		node = node->left;
	return (node);
}

/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: pointer to the root node of the tree
 * @value: the value to remove from the tree
 * Return: pointer to the new root node after removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		bst_t *temp;
		if (root->left == NULL)
		{
			bst_t *temp = root->right;

			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			bst_t *temp = root->left;

			free(root);
			return (temp);
		}

		temp = find_successor(root->right);

		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}

	return (root);
}
