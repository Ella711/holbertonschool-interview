#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;

int heap_extract(heap_t **root);
void replace_heap(heap_t *node);
heap_t *find_last(heap_t *node);
int get_height(heap_t *node);
void binary_tree_print(const binary_tree_t *);

#endif /* BINARY_TREES_H */
