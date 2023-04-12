#include "binary_trees.h"

/**
 * bal_factor - Measures balance factor of an AVL tree
 * @tree: pointer to the tree to measure
 *
 * Return: balance factor
 */
int bal_factor(avl_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_balance((const binary_tree_t *)tree));
}

/**
 * rebalance - Rebalances an AVL tree
 * @root: pointer to the root node of the tree to rebalance
 *
 * Return: pointer to the new root node of the tree
 */
avl_t *rebalance(avl_t *root)
{
	int balance, balance_left, balance_right;

	balance = bal_factor(root);
	balance_left = bal_factor(root->left);
	balance_right = bal_factor(root->right);

	if (balance > 1)
	{
		if (balance_left < 0)
			root->left = binary_tree_rotate_left(root->left);
		root = binary_tree_rotate_right(root);
	}
	else if (balance < -1)
	{
		if (balance_right > 0)
			root->right = binary_tree_rotate_right(root->right);
		root = binary_tree_rotate_left(root);
	}

	return (root);
}

/**
 * bst_remove - Removes a node from a BST tree
 * @root: pointer to the root node of the tree
 * @value: value of the node to remove
 *
 * Return: pointer to the new root node of the tree after removing the node
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			bst_t *temp = root->right;

			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			bst_t *temp = root->left;

			free(root);
			return (temp);
		}

		bst_t *temp = root->right;

		while (temp && temp->left)
			temp = temp->left;
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}

	return (root);
}

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: pointer to the root node of the tree
 * @value: value of the node to remove
 *
 * Return: pointer to the new root node of the tree after removing the node
 */
avl_t *avl_remove(avl_t *root, int value)
{
	if (root == NULL)
		return (NULL);

	root = (avl_t *)bst_remove((bst_t *)root, value);
	if (root == NULL)
		return (NULL);

	return (rebalance(root));
}
