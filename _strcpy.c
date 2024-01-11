#include "shell.h"

/**
 * _strcpy- make string copy
 * @dest: The container to hold copy
 * @src: string source
 * Return: string
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0, len;

	if (!src || !dest)
		return (NULL);

	len = _strlen(src);

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[len] = '\0';

	return (dest);
}
