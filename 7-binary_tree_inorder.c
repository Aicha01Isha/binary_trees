#include "binary_trees.h"

/**
 * binary_tree_inorder - function that goes through a binary tree
 * @tree: parameter
 * @func: parameter
 * Return: 0 on success
 */

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if ((tree != NULL) && (func != NULL))
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
