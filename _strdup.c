#include "shell.h"

/**
  * _strdup- make duplicate string
  * @str: the string to be copied
  * Return: duplicated string
  */

char *_strdup(char *str)
{
	char *temp = NULL;
	int i = 0, k = 0, len;

	if (!str)
	{
		perror("Error from _strdup()");
		return (NULL);
	}
	len = _strlen(str);
	temp = (char *)malloc((len + 1) * sizeof(char));
	if (!temp)
	{
		perror("failed to make temp @ _strdup");
	}
	while (str[i] != '\0')
	{
		temp[k] = str[i];
		k++;
		i++;
	}
	return (temp);
}
