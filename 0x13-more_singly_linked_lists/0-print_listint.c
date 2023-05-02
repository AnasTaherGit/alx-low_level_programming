#include "lists.h"

/**
 * print_listint - prints all the elements of a listint_t list
 * @h: pointer to the head of the list
 *
 * Return: the number of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t node_count = 0;
	int current_digit;

	while (h != NULL)
	{
		current_digit = h->n;
		if (current_digit < 0)
		{
			_putchar('-');
			current_digit = -current_digit;
		}
		if (current_digit >= 10)
		{
			_putchar((current_digit / 10) + '0');
		}
		_putchar((current_digit % 10) + '0');
		_putchar('\n');
		h = h->next;
		node_count++;
	}

	return (node_count);
}
