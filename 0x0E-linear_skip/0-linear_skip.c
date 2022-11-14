#include "search.h"

/**
* linear_search - function that performs a linear search algorithm
*			on a skip list
*
* @start: pointer to the starting node of a sorted linked list
* @end: ending node of linked list
* @value: value to find
*
* Return: pointer to first node where value is located, on failure, NULL.
*/

skiplist_t *linear_search(skiplist_t *start, skiplist_t *end, int value)
{
	skiplist_t *current = start;

	if (current != NULL)
	{
		printf("Value found between indexes [%lu] and [%lu]\n",
			start->index, end->index);
		for (; current->next != NULL && current != end; current = current->next)
		{
			printf("Value checked at index [%lu] = [%d]\n",
			   current->index, current->n);
			if (current->n == value)
				return (current);
		}
		printf("Value checked at index [%lu] = [%d]\n",
			   current->index, current->n);
		if (current->n == value)
			return (current);
	}
	return (NULL);
}

/**
* linear_skip - Function that searches for a value in a sorted
*		skip list of integers
*
* @list: pointer to the head of the skip list to search in
* @value: value to search for
*
* Return: pointer to the first node where value is located, on failure, NULL.
*/

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current = list, *last;

	while (current != NULL)
	{
		if (current->express == NULL)
		{
			for (last = current; last->next != NULL; last = last->next)
				continue;
			return (linear_search(current, last, value));
		}
		printf("Value checked at index [%lu] = [%d]\n",
			current->express->index, current->express->n);
		if (current->express != NULL && current->express->n >= value)
			return (linear_search(current, current->express, value));
		current = current->express;
	}
	return (NULL);
}
