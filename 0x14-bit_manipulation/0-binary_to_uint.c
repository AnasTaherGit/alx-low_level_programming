#include "main.h"


/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: pointer to a string of 0 and 1 chars
 * Return: the converted number, or 0 if
 * there is one or more chars in the string b that is not 0 or 1
 * b is NULL
 */
unsigned int binary_to_uint(const char *b)
{
    unsigned int num = 0;
    int i;

    if (!b)
        return (0);

    for (i = 0; b[i] != '\0'; i++)
    {
        if (b[i] != '0' && b[i] != '1')
            return (0);

        num <<= 1; // Shift bits to the left, equivalent to multiplication by 2
        if (b[i] == '1')
            num += 1; // Add 1 if bit is 1
    }

    return (num);
}