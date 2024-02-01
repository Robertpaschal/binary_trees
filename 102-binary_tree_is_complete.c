#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

size_t binary_tree_si(const binary_tree_t *tree);
int binary_tree_is_complete(const binary_tree_t *tree);

/**
 * binary_tree_si - measures the size of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: size of the tree, 0 if the tree is NULL
*/
size_t binary_tree_si(const binary_tree_t *tree)
{
	size_t left_tree = 0, right_tree = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
	{
		left_tree = binary_tree_si(tree->left);
	}
	if (tree->right)
		right_tree = binary_tree_si(tree->right);

	return (left_tree + 1 + right_tree);
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if the tree is complete, 0 otherwise
*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int non_full, front, rear;
	binary_tree_t **queue;

	if (tree == NULL)
		return (0);

	non_full = 0;

	queue = malloc(
		sizeof(binary_tree_t *) * binary_tree_si(tree));

	if (queue == NULL)
		return (0);

	front = 0, rear = 0;

	queue[rear] = (binary_tree_t *)tree;

	rear++;

	while (front < rear)
	{
		binary_tree_t *current = queue[front];

		front++;

		if (current->left)
			queue[rear++] = current->left;
		else
			non_full = 1;

		if (current->right)
			queue[rear++] = current->right;
		else
			non_full = 1;

		if (non_full && (current->left || current->right))
		{
			free(queue);
			return (0);
		}
	}

	free(queue);
	return (1);
}
