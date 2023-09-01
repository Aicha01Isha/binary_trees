#include "binary_trees.h"

/**
 * tree_stats - function that computes some statistics about a binary tree.
 * @tree: parameter
 * @n: parameter
 * @leaves: parameter
 * @height: parameter
 * Return: 0 on success
 */

void tree_stats(const binary_tree_t *tree, size_t n,
	size_t *leaves, size_t *height)
{
	if (tree != NULL)
	{
		if ((tree->left == NULL) && (tree->right == NULL))
		{
			if (leaves != NULL)
				(*leaves)++;
			if ((height != NULL) && (n > *height))
				*height = n;
		}
		else
		{
			tree_stats(tree->left, n + 1, leaves, height);
			tree_stats(tree->right, n + 1, leaves, height);
		}
	}
}

/**
 * binary_tree_is_perfect - function that checks if a binary tree is perfect.
 * @tree: parameter
 * Return: 1 on success, 0 on failure
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t leaves_count = 0;
	size_t tree_height = 0;

	tree_stats(tree, 0, &leaves_count, &tree_height);
	return ((int)leaves_count == (1 << tree_height) ? 1 : 0);
}
