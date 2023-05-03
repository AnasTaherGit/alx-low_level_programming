#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t linked list
 * and returns the head node's data (n)
 * @head: double pointer to the head of the list
 * Return: the head node's data (n) or 0 if the linked list is empty
 */
int pop_listint(listint_t **head)
{
	int data;
	listint_t *temp_node;

	if (head == NULL || *head == NULL)
		return (0);

	temp_node = *head;
	data = temp_node->n;
	*head = temp_node->next;
	free(temp_node);

	return (data);
}
