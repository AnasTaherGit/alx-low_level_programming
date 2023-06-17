#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t linked list
 * @head: pointer to the head of the list
 * @index: the index of the node, starting from 0
 *
 * Return: the node at index 'index', or NULL if the node does not exist
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *current;
	unsigned int count;

	current = head;
	count = 0;
	while (current != NULL)
	{
		if (count == index)
			return (current);
		count++;
		current = current->next;
	}

	/* if we got here, it means the node does not exist */
	return (NULL);
}
