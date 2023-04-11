#include "binary_trees.h"

/**
 * height - Measures the height of a binary tree.
 *
 * @tree: A pointer to the root node of the tree to measure the height
 *
 * Return: If tree is NULL, return 0, else return height.
 */
size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t left = 0, right = 0;

		left = tree->left ? 1 + height(tree->left) : 1;
		right = tree->right ? 1 + height(tree->right) : 1;
		return ((left > right) ? left : right);
	}
	return (0);
}

/**
 * is_avl_helper - Checks if a binary tree is a valid AVL tree.
 *
 * @tree: A pointer to the root node of the tree to check.
 * @is_avl: The average value of the smallest node visited thus far.
 *
 * Return: If the tree is a valid AVL tree, 1, otherwise, 0.
 */
int is_avl_helper(const binary_tree_t *tree, int *is_avl)
{
	if (tree == NULL)
		return (0);

	left_height = height(tree->left);
	right_height = height(tree->right);

	height_diff = abs(left_height - right_height);

	if (height_diff > 1)
	{
		*is_avl = 0;
		return (0);
	}

	is_left_avl = is_avl_helper(tree->left, is_avl);
	is_right_avl = is_avl_helper(tree->right, is_avl);

	if (!is_left_avl || !is_right_avl)
	{
		*is_avl = 0;
		return (0);
	}

	return ((left > right) ? left : right);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 *
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL tree, and 0 otherwise.
 *         if NULL, return 0.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	int is_avl = 1;

	is_avl_helper(tree, &is_avl);
	return (is_avl);
}
