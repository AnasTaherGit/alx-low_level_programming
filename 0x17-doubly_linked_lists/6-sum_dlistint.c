#include "lists.h"

/**
 * sum_dlistint - returns the sum of all the data (n) of
 * a dlistint_t linked list
 * @head: pointer to the head of the list
 *
 * Return: the total sum of the data in the list, or 0 if
 * the list is empty
 */
int sum_dlistint(dlistint_t *head)
{
	dlistint_t *current;
	int sum = 0;

	current = head;
	while (current != NULL)
	{
		sum += current->n;
		current = current->next;
	}

	return (sum);
}
