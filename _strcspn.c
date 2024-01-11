#include "shell.h"

/**
 * _strcspn-compare and returns the number of chars before it reaches str2
 * @str1: the first string
 * @str2: the second char
 * Return: the number of chars before getting to str2
 */

int _strcspn(char *str1, char str2)
{
	int i = 0, count = 0;

	while (str1[i] != '\0')
	{
		if (str1[i] != str2)
		{
			count++;
		}
		else
		{
			break;
		}
		i++;
	}
	return (count);
}
