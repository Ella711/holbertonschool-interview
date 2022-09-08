#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to the first node of a singly linked list
 *
 * Return: 0 if not palindrome, 1 if palindrome
 */

int is_palindrome(listint_t **head)
{
	if (head == NULL)
		return (0);
	if (*head == NULL)
		return (1);
	return (check_palindrome(head, *head));
}

/**
 * check_palindrome - recursive function to check if list is palindrome
 * @head: double pointer to beginning of list
 * @traverse: single pointer to list to move to end
 *
 * Return: 0 if not palindrome, 1 if palindrome
 */
int check_palindrome(listint_t **head, listint_t *traverse)
{
	/* move to the end of linked list */
	if (traverse->next)
	{
		/* if true traverse will keep moving forward */
		/* will check values on way back */
		if (check_palindrome(head, traverse->next))
			(*head) = (*head)->next;
		else
			return (0);
	}
	/* checks values */
	if ((*head)->n == traverse->n)
		return (1);
	return (0);
}
