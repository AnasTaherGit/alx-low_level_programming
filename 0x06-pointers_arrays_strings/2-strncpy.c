#include "main.h"
#include <string.h>

/**
 * _strncpy - Copy from dest to src
 * @dest: Destination
 * @src: Source
 * @n: Length to copy
 * Return: Pointer to resulting string dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while (i < n)
	{
		dest[i] = src[i];
		if (src[i] == '\0')
		{
			i++;
			break;
		}
		i++;
	}

	return (dest);
}
