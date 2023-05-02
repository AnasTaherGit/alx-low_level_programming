#include "lists.h"

/**
 * print_listint - prints all the elements of a listint_t list
 * @h: pointer to the head of the list
 *
 * Return: number of nodes
 */

size_t print_listint(const listint_t *h)
{
	size_t node_count;

	for (node_count = 0; h != NULL; node_count++)
	{
		printf("%d\n", h->n);
		h = h->next;
	}

	return (node_count);
}