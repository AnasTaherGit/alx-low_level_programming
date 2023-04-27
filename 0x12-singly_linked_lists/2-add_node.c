#include "lists.h"

/**
 * add_node - adds a new node at the beginning of a list_t list
 * @head: pointer to the head of the list
 * @str: string to be added to the list
 *
 * Return: address of the new element, or NULL if it failed
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *NEW_HEAD = malloc(sizeof(list_t));

	if (NEW_HEAD == NULL)
		return (NULL);

	NEW_HEAD->str = strdup(str);
	NEW_HEAD->len = strlen(str);
	NEW_HEAD->next = *head;

	*head = NEW_HEAD;

	return (*head);
}
