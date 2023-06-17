#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: double pointer to the head of the dlistint_t list
 * @idx: index where the new node should be added, starts at 0
 * @n: data for the new node
 *
 * Return: the address of the new node, or NULL if it fails
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new;
	dlistint_t *current;
	unsigned int i;

	if (h == NULL) /* check if the list exists */
		return (NULL);

	if (idx == 0) /* add node at the beginning */
		return (add_dnodeint(h, n));

	/* create new node */
	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;

	/* traverse the list */
	current = *h;
	for (i = 0; i < idx - 1; i++)
	{
		if (current == NULL)
		{
			free(new);
			return (NULL);
		}
		current = current->next;
	}
	new->next = current->next;
	new->prev = current;
	if (current->next != NULL)
		current->next->prev = new;
	current->next = new;

	return (new);
}
