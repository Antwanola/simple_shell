#include "shell.h"

/**
 * _strncpy- copies str to dest @n byte
 * @dest: the str destination
 * @src: the str source
 * @n: the number of bytes to be coppied
 * Return: string
 */

char *_strncpy(char *dest, char *src, size_t n)
{
	size_t i;

	if (!src)
		return (dest);
	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	for (; i < n; i++)
	{
		dest[i] = '\0';
	}
	return (dest);

}
