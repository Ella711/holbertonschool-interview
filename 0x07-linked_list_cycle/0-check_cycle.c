#include "lists.h"
/**
 * check_cycle - checks if a linked list has a cycle
 * @list: pointer to linked list
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	int i = 0;
	listint_t *turtle = list, *hare = list;

	for (; hare != NULL; i++)
	{
		if (i % 2 == 1)
			turtle = turtle->next;
		hare = hare->next;
		if (turtle == hare)
			return (1);
	}
	return (0);
}
