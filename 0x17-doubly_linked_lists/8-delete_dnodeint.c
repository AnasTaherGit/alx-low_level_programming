#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index of a dlistint_t list
 * @head: double pointer to the head of the list
 * @index: index of the node to delete, starts at 0
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current;
	unsigned int i;

	if (head == NULL || *head == NULL) /* check if the list exists */
		return (-1);

	current = *head;

	if (index == 0) /* delete the head */
	{
		*head = current->next;
		if (current->next != NULL)
			current->next->prev = NULL;
		free(current);
		return (1);
	}

	/* traverse the list */
	for (i = 0; i < index; i++)
	{
		if (current == NULL) /* if index is more than the length of the list */
			return (-1);
		current = current->next;
	}

	/* delete the node */
	if (current->next != NULL)
		current->next->prev = current->prev;
	if (current->prev != NULL)
		current->prev->next = current->next;
	free(current);

	return (1);
}
