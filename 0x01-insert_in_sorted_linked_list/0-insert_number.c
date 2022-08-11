#include "lists.h"

/**
 * insert_node - inserts a number in a sorted linked list
 * @head: pointer to head of linked list
 * @number: number to be inserted
 * Return: pointer to new node or NULL if failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *current = *head, *previous = current, *new_node;
	
	/* make the new node to be inserted */
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);
	
	new_node->n = number;
	new_node->next = NULL;

	/* checks if insertion is at beginning */
	if (!head || !*head)
	{
		*head = new_node;
		return (*head);
	}
	
	/* go through list and insert at correct position */
	while ((current->n <= number) && current != NULL)
	{
		if ((current->n <= number) && (current->next == NULL))
		{
			return add_nodeint_end(head, number);
		}
		previous = current;
		current = current->next;
	}
	if (previous->n <= number)
	{
		previous->next = new_node;
		new_node->next = current;
	}
	return (*head);
}