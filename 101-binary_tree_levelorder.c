#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

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
 * binary_tree_levelorder - goes thorugh a binary tree
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	size_t size = binary_tree_si(tree);

	binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * size);

	if (queue == NULL)
		return;

	int front = 0, rear = 0;

	queue[rear] = (binary_tree_t *)tree;
	rear++;

	while (front < rear)
	{
		binary_tree_t *current = queue[front];

		front++;

		func(current->n);

		if (current->left != NULL)
		{
			queue[rear] = current->left;
			rear++;
		}

		if (current->right != NULL)
		{
			queue[rear] = current->right;
			rear++;
		}
	}

	free(queue);
}
