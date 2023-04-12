#include "binary_trees.h"

/**
 * count_nnodes - Counts the number of nodes inside a tree
 * @root: Pointer to tree's root node
 *
 * Return: Number of tree nodes
 */
int count_nnodes(binary_tree_t *root)
{
	if (!root)
		return (0);

	return (1 + count_h_nodes(root->left) +
		    count_h_nodes(root->right));
}

/**
 * heap_to_sorted_array - converts a BMH to a sorted array of integers
 * @heap: pointer to the root node of the heap to convert
 * @size: address to store the size of the array
 *
 * Return: array of integers in descending order
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int i, nodes, *arr = NULL;

	*size = 0;
	if (!heap)
		return (NULL);

	nodes = count_nnodes(heap);
	arr = malloc(sizeof(*arr) * nodes);
	if (!arr)
		return (NULL);

	*size = nodes;
	for (i = 0; i < nodes; i++)
		arr[i] = heap_extract(&heap);

	return (arr);
}
