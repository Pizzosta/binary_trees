#include "binary_trees.h"

size_t height(const binary_tree_t *tree);
int is_avl_helper(const binary_tree_t *tree, int down, int up);
int binary_tree_is_avl(const binary_tree_t *tree);

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
 * @down: The value of the smallest node visited thus far.
 * @up: The value of the largest node visited this far.
 *
 * Return: If the tree is a valid AVL tree, 1, otherwise, 0.
 */
int is_avl_helper(const binary_tree_t *tree, int down, int up)
{
	size_t l_height, r_height, diff;

	if (tree != NULL)
	{
		if (tree->n < down || tree->n > up)
			return (0);
		l_height = height(tree->left);
		r_height = height(tree->right);
		diff = l_height > r_height ? l_height - r_height : 
			r_height - l_height;
		if (diff > 1)
			return (0);
		return (is_avl_helper(tree->left, down, tree->n - 1) &&
			is_avl_helper(tree->right, tree->n + 1, up));
	}
	return (1);
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
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
