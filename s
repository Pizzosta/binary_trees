#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a BST.
 *
 * @tree: double pointer to the root node of the BST to insert the value.
 * @value: value to store in the node to be inserted.
 *
 * Return: pointer to the created node. NULL on failure
 *
 * Description: if the address stored in tree is NULL,
 * created node must become the root node.
 * if value is already present in the tree, it must be ignored.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (tree == NULL)
	{
		return (NULL);
	}
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	if ((*tree)->value == value)
	{
		return (NULL);
	}
	if (value < (*tree)->value)
	{
		return bst_insert(&((*tree)->left), value);
	}
	else
	{
		return bst_insert(&((*tree)->right), value);
	}
}
