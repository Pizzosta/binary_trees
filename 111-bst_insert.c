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
 *              created node must become the root node.
 *              if value is already present in the tree, it must be ignored.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *temp = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	temp = *tree;
	if (value < temp->n)
	{
		if (temp->left == NULL)
		{
			temp->left = binary_tree_node(temp, value);
			return (temp->left);
		}
		return (bst_insert(&(temp->left), value));
	}
	if (value > temp->n)
	{
		if (temp->right == NULL)
		{
			temp->right = binary_tree_node(aux, value);
			return (temp->right);
		}
		return (bst_insert(&(temp->right), value));
	}
	return (NULL);
}
