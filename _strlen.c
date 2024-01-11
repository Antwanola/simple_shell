#include "shell.h"

int _strlen(char *str)
{
	size_t i = 0;

	if (!str)
		return (NULL);
	while (str[i] != '\0')
		i++;
	return (i);
}
