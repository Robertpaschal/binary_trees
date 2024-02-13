#include "binary_trees.h"
#include <stdlib.h>

size_t avl_tree_height(const avl_t *tree);
avl_t *avl_insert_recursive(avl_t **tree, int value);
avl_t *avl_insert(avl_t **tree, int value);

/**
 * avl_tree_height - caluclate the hieght of an avl tree
 * @tree: pointer to the root node of the tree
 * Return: height of the tree, 0 if tree is NULL
*/
size_t avl_tree_height(const avl_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = avl_tree_height(tree->left);
	right_height = avl_tree_height(tree->right);

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
 * avl_insert_recursive - recursively inserts a value in an AVL tree
 * @tree: pointer to the root node obf the AVL tree
 * @value: vlaue to insert in the tree
 * Return: pointer to the created node, or NULL on failure
*/
avl_t *avl_insert_recursive(avl_t **tree, int value)
{
	int balance;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		if (*tree == NULL)
			return (NULL);
	}
	else
	{
		if (value < (*tree)->n)
			(*tree)->left = avl_insert_recursive(&(*tree)->left, value);
		else if (value > (*tree)->n)
			(*tree)->right = avl_insert_recursive(&(*tree)->right, value);
		else
			return (*tree);
	}

	balance = (avl_tree_height((
		*tree)->left)) - (avl_tree_height((*tree)->right));

	if (balance > 1)
	{
		if (value < (*tree)->left->n)
			*tree = binary_tree_rotate_right(*tree);
		else
		{
			(*tree)->left = binary_tree_rotate_left((*tree)->left);
			*tree = binary_tree_rotate_right(*tree);
		}
	}

	else if (balance < -1)
	{
		if (value > (*tree)->right->n)
			*tree = binary_tree_rotate_left(*tree);
		else
		{
			(*tree)->right = binary_tree_rotate_right((*tree)->right);
			*tree = binary_tree_rotate_left(*tree);
		}
	}

	return (*tree);
}

/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: double pointer to the root node of the AVL tree
 * @value: value to inert in the tree
 * Return: pointer to the created node, or NULL on failure
*/
avl_t *avl_insert(avl_t **tree, int value)
{
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		if (*tree == NULL)
			return (NULL);
	}
	else
	{
		return (avl_insert_recursive(tree, value));
	}

	return (*tree);
}
