#include "shell.h"

/**
 * _strlen- gets nthe str len
 * @str: the str
 * Return: int
 */
int _strlen(char *str)
{
	size_t i = 0;

	if (!str)
		return (NULL);
	while (str[i] != '\0')
		i++;
	return (i);
}
