#include <stdlib.h>
#include "dog.h"
/**
 * _strcpy - copies the string pointed to by src, including the terminating
 * null byte (\0), to the buffer pointed to by dest.
 * @dest: pointer to the buffer in which we copy the string.
 * @src: pointer to the string we copy.
 *
 * Return: the pointer to dest.
 */

char *_strcpy(char *dest, char *src)
{
	int c;

	for (c = 0; src[c] != '\0'; c++)
	{
		dest[c] = src[c];
	}

	dest[c] = '\0';

	return (dest);
}

/**
 * new_dog - creates a new dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 *
 * Return: pointer to the new dog, NULL if the function fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new_dog = NULL;
	char *name_copy = NULL;
	char *owner_copy = NULL;

	new_dog = malloc(sizeof(dog_t));
	if (new_dog == NULL)
		return (NULL);

	name_copy = _strcpy(name_copy, name);
	if (name_copy == NULL)
	{
		free(new_dog);
		return (NULL);
	}

	owner_copy = _strcpy(owner_copy, owner);
	if (owner_copy == NULL)
	{
		free(name_copy);
		free(new_dog);
		return (NULL);
	}

	new_dog->name = name_copy;
	new_dog->age = age;
	new_dog->owner = owner_copy;

	return (new_dog);
}
