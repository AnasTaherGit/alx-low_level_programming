#include "main.h"
#include <ctype.h>
#include <stdbool.h>

/**
 * is_separator - checks if a character is a word separator
 * @c: character to check
 *
 * Return: true if the character is a separator, false otherwise
 */
bool is_separator(char c)
{
	char separators[] = " \t\n,;.!?\")(}{";
	int i;

	for (i = 0; separators[i]; i++)
	{
		if (c == separators[i])
		{
			return (true);
		}
	}
	return (false);
}

/**
 * cap_string - capitalizes the first character of each word in a string
 * @str: string to capitalize
 *
 * Return: pointer to the modified string
 */
char *cap_string(char *str)
{
	bool new_word = true;
	int i;

	for (i = 0; str[i]; i++)
	{
		if (is_separator(str[i]))
		{
			new_word = true;
		}
		else if (new_word)
		{
			str[i] = toupper(str[i]);
			new_word = false;
		}
	}
	return (str);
}
