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

    /* If tree is empty, create a new node as the root node */
    if (*tree == NULL)
    {
        *tree = binary_tree_node(NULL, value);
        return (*tree);
    }

    /* If value is less than the current node, recursively insert to the left */
    if (value < (*tree)->n)
    {
        if ((*tree)->left == NULL)
        {
            (*tree)->left = binary_tree_node(*tree, value);
            return ((*tree)->left);
        }
        else
        {
            return bst_insert(&((*tree)->left), value);
        }
    }
    /* If value is greater than the current node, recursively insert to the right */
    else if (value > (*tree)->n)
    {
        if ((*tree)->right == NULL)
        {
            (*tree)->right = binary_tree_node(*tree, value);
            return ((*tree)->right);
        }
        else
        {
            return bst_insert(&((*tree)->right), value);
        }
    }
    /* If value is equal to the current node, ignore duplicate value */
    else
    {
        return (*tree);
    }
}
