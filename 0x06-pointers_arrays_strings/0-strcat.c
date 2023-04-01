#include "main.h"
#include <string.h>

/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: source string
 *
 * Return: pointer to resulting string dest
 */

char *_strcat(char *dest, char *src)
{
	int i;

	int destlen=strlen(dest);
	
	int srclen=strlen(src);

	for (i=0; i < srclen ; i++)
	{
		
		dest[destlen+i] = src[i];
	}

	dest[destlen + srclen] = '\0';

	return dest;
}