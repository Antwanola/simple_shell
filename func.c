#include "shell.h"
/**
 * _strcat - concat strings
 * @dest: str dest
 * @src: str src
 * Return: pointer to final str
 */
char *_strcat(char *dest, const char *src)
{
	size_t i;

	i = 0;

	while ((dest[i] = src[i]) != '\0')
	{
		i++;
	}
	return (dest);
}

/**
 * _strdup - dup str
 * @str: string for duplication
 * Return: pointer to alloc str
 */
char *_strdup(const char *str)
{
	size_t len;
	char *new_str;
	size_t i;

	len = 0;

	while (str[len] != '\0')
	{
		len++;
	}

	new_str = (char *)malloc(len + 1);

	for (i = 0; i <= len; i++)
	{
		new_str[i] = str[i];
	}
	return (new_str);
}

/**
 * _strcpy - copy str src to dest
 * @dest: the destination
 * @src: the source
 * Return: str pointer
 */
char *_strcpy(char *dest, const char *src)
{
	size_t i;

	i = 0;

	while ((dest[i] = src[i]) != '\0')
	{
		i++;
	}
	return (dest);
}
