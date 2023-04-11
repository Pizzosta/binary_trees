#include "binary_trees.h"

/**
 * is_avl_helper - Checks if a binary tree is a valid AVL tree.
 *
 * @tree: A pointer to the root node of the tree to check.
 * @is_avl: A pointer to the flag indicating if the tree is a valid AVL tree.
 *
 * Return: The height of the current subtree if it is a valid AVL tree,
 *         otherwise, 0.
 */
size_t is_avl_helper(const binary_tree_t *tree, int *is_avl)
{
	if (tree == NULL)
		return (0);

	size_t left_height = is_avl_helper(tree->left, is_avl);
	size_t right_height = is_avl_helper(tree->right, is_avl);

	size_t height_diff = abs((int)left_height - (int)right_height);

	if (height_diff > 1)
	{
		*is_avl = 0;
		return (0);
	}

	return (1 + ((left_height > right_height) ? left_height : right_height));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 *
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL tree, and 0 otherwise.
 *         If tree is NULL, return 0.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	int is_avl = 1;

	is_avl_helper(tree, &is_avl);
	return (is_avl);
}

