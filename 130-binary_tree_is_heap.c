#include "binary_trees.h"

/**
 * binary_tree_is_heap_helper - Helper function to check if a binary tree
 * is a valid Max Binary Heap
 *
 * @tree: Pointer to the current node of the tree to check
 * @prev_value: Value of the parent node of the current node
 *
 * Return: 1 if tree is a valid Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap_helper(const binary_tree_t *tree, int prev_value)
{
	if (tree == NULL)
		return (1);

	if (tree->n > prev_value)
		return (0);

	return (binary_tree_is_heap_helper(tree->left, tree->n) &&
		binary_tree_is_heap_helper(tree->right, tree->n));
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_is_heap_helper(tree, INT_MIN));
}
