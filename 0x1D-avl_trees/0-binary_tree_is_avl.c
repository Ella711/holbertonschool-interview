#include "binary_trees.h"
/**
 * tree_height - measures the height of a binary tree
 * @tree: pointer to root node of tree to measure the height
 *
 * Return: height or 0 if tree is NULL
 */
size_t tree_height(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_l = 1 + tree_height(tree->left);

	if (tree->right)
		height_r = 1 + tree_height(tree->right);

	if (height_l > height_r)
		return (height_l);
	return (height_r);
}
/**
 * isBST - check if to the left of each node has a lesser value than itself
 * @root: node to check
 * @min: min value to check with node to the left
 * @max: max value to check with node to the right
 * Return: 1 if is a BST or 0 otherwise
 */
int isBST(const binary_tree_t *root,
	  const binary_tree_t *min, const binary_tree_t *max)
{
	if (root == NULL)
		return (1);

	if (min != NULL && root->n <= min->n)
		return (0);

	if (max != NULL && root->n >= max->n)
		return (0);

	return (isBST(root->left, min, root) &&
		isBST(root->right, root, max));
}
/**
 * tree_is_bst - checks if a binary tree is a BST
 * @tree: a pointer to node of tree to check
 * Return: 1 if tree is a nid BST, and 0 otherwise
 */
int tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (isBST(tree, NULL, NULL));
}
/**
 * avl_check - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to root node of tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int avl_check(const binary_tree_t *tree)
{
	int delta, heightL = 0, heightR = 0;

	if (!tree)
		return (1);

	if (!tree_is_bst(tree))
		return (0);

	heightL = tree_height(tree->left);
	heightR = tree_height(tree->right);

	delta = abs(heightL - heightR);

	if (delta == 0 && avl_check(tree->left) && avl_check(tree->right))
		return (1);
	return (0);
}
/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to root node of tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (avl_check(tree));
}
