#include "binary_trees.h"
/**
 * len_heap - counts nodes in heap
 * 
 * @root: pointer to root 
 * Return: int with number of nodes in heap
 */
int len_heap(heap_t *root)
{
	int count;

	if (!root)
		return (0);
	if (root)
		count = 1;
	
	count += len_heap(root->left);
	count += len_heap(root->right);

	return (count);
}
/**
 * check_perfection - checks if binary tree is perfect
 * 
 * @tree: pointer to binary tree
 * Return: 1 if perfect, 0 if not
 */
int check_perfection(const heap_t *tree)
{
	int left, right;

	if (!tree)
		return (0);
	
	left = len_heap(tree->left);
	right = len_heap(tree->right);
	if (left == right)
		return (1);
	return(0);
}
/**
 * find_parent - finds the parent node
 * 
 * @root: pointer to root of binary tree
 * Return: pointer to parent node
 */
heap_t *find_parent(heap_t *root)
{
	heap_t *parent;
	int left_count, right_count, left_check, right_check;

	if (!root)
		return (NULL);
	
	parent = root;
	left_count = len_heap(parent->left);
	right_count = len_heap(parent->right);

	left_check = check_perfection(parent->left);
	right_check = check_perfection(parent->right);

	if (!left_count || !right_count)
		return (parent);
	if (!left_check || (left_check && right_check && left_count == right_count))
		return (find_parent(parent->left));
	else if (!right_check || (left_check && right_check && left_count > right_count))
		return (find_parent(parent->right));
	return (parent);

}
/**
 * sort_nodes - sorts the node values between parent and child
 * 
 * @new_node: double pointer to the new node
 */
void sort_nodes(heap_t **new_node)
{
	heap_t *current;
	int temp;

	current = *new_node;
	while (current->parent)
	{
		if (current->parent->n < current->n)
		{
			temp = current->parent->n;
			current->parent->n = current->n;
			current->n = temp;
			*new_node = current->parent;
		}
		current = current->parent;
	}
}
/**
 * heap_insert - creates a binary tree node
 * @root: double pointer to the root node of the Heap
 * @value: value to put in the new node
 * Return: pointer to new node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;

	parent = find_parent(*root);
	new_node = binary_tree_node(parent, value);

	if (!parent)
		*root = new_node;
	else if (!(parent->left))
		parent->left = new_node;
	else
		parent->right = new_node;
	sort_nodes(&new_node);
	return (new_node);
}