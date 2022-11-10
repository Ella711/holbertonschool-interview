#include "binary_trees.h"
/**
 * new_node - creates a new node
 * @n: value to store in new node
 * @tree: pointer to existing tree
 * Return: pointer to new node
*/
avl_t *new_node(int n, avl_t *tree)
{
	avl_t *node = malloc(sizeof(avl_t));

	if (node == NULL)
		return (NULL);

	if (tree == NULL)
	{
		node->parent = NULL;
		tree = node;
	}
	else
		node->parent = tree;

	node->left = NULL;
	node->right = NULL;
	node->n = n;

	return (node);
}
/**
 * recursive_branch - recursively makes the tree
 * @tree: pointer to existing tree
 * @array: array that is being made into sorted tree
 * @start: start of sorted array
 * @end: end of sorted array
 * Return: pointer to tree
*/
avl_t *recursive_branch(avl_t *tree, int *array, int start, int end)
{
	int mid = (start + end) / 2;

	if (start > end)
		return (NULL);

	tree = new_node(array[mid], tree);
	if (tree == NULL)
		return (NULL);

	tree->left = recursive_branch(tree, array, start, (mid - 1));
	tree->right = recursive_branch(tree, array, (mid + 1), end);

	return (tree);
}
/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of elements in the array
 * Return: pointer to AVL tree or Null if failed
*/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size <= 0)
		return (NULL);

	return (recursive_branch(NULL, array, 0, size - 1));
}
