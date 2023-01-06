#include "binary_trees.h"

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to the root node of the heap
 * Return: value stored in the root node
 */

int heap_extract(heap_t **root)
{
	int max;
	heap_t *last;

	if (root == NULL || *root == NULL)
		return (0);

	max = (*root)->n;

	if (get_height(*root) == 1)
	{
		free(*root);
		*root = NULL;
		return (max);
	}

	last = find_last(*root);

	(*root)->n = last->n;

	if (last->parent->right == last)
		last->parent->right = NULL;
	else
		last->parent->left = NULL;
	free(last);

	replace_heap(*root);

	return (max);
}


/**
 * get_height - Finds the height of a max heap.
 * @node: Root node of heap.
 * Return: height of heap.
 */

int get_height(heap_t *node)
{
	int height;

	if (node == NULL)
		return (0);

	height = get_height(node->left);
	return (height + 1);
}

/**
 * find_last - Finds the last node of a max heap.
 * @node: Root node of heap.
 * Return: last node of heap.
 */

heap_t *find_last(heap_t *node)
{
	int lefth = 0, righth = 0;

	if (node->left == NULL && node->right == NULL)
		return (node);
	if (node->left)
		lefth = get_height(node->left);
	if (node->right)
		righth = get_height(node->right);
	if (righth == lefth)
		return (find_last(node->right));
	return (find_last(node->left));
}

/**
 * replace_heap - replaces the heap
 * @node: Root node of heap.
 */

void replace_heap(heap_t *node)
{
	int temp;
	heap_t *max;

	if (node->left == NULL && node->right == NULL)
		return;

	max = node->left;

	if (node->right && node->right->n > max->n)
		max = node->right;

	if (max->n > node->n)
	{
		temp = node->n;
		node->n = max->n;
		max->n = temp;
		replace_heap(max);
	}
}
