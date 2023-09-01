#include "binary_trees.h"

/**
 * node_height_2 - function that computes the height of a binary tree's node.
 * @tree: parameter
 * @n: parameter
 * @height: parameter
 * Return: 0 on success
 */

void node_height_2(const binary_tree_t *tree, size_t n, size_t *height)
{
	if (tree != NULL)
	{
		if ((tree->left == NULL) && (tree->right == NULL))
		{
			if (n > *height)
			{
				*height = n;
			}
		}
		else
		{
			node_height_2(tree->left, n + 1, height);
			node_height_2(tree->right, n + 1, height);
		}
	}
}

/**
 * binary_tree_height - function that measures the height of a binary tree.
 * @tree: parameter
 * Return: Height
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height = 0;

	node_height_2(tree, 0, &height);
	return (height);
}
