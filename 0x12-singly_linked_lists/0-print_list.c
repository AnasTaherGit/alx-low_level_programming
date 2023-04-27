#include "lists.h"

/**
 * print_list - prints all the elements of a list_t list
 * @h: pointer to the list_t list
 *
 * Return: the number of nodes
 */

size_t print_list(const list_t *h)
{
	int i;
	list_t *current = h;

	while (current != NULL)
	{
		printf("[%d] %s\n", current->len, current->str);
		current = current->next;
		i++;
	}

	return (i);
}