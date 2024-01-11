#include "shell.h"

/**
 * _strtok - This gets the token out of a string
 * @str: the inputed string
 * @del: the inputed delimeter
 * Return: Returns an array of strings
 */

char **_strtok(char *str, char del)
{
	size_t i = 0, str_len, arr_iter = 0, free_str, new_size = 0, start = 0, stop = 0;
	char *sub_str = NULL;
	char **new_arr = NULL;
	char **temp = NULL;

	if  (!str || !del)
	{
		perror("failed on first check @ strtok");
		return (NULL);
	}
	new_arr = (char **)malloc(sizeof(char *) * ARR_SIZE);
	if (!new_arr)
	{
		perror("failed at making new_arr ptr");
		return (NULL);
	}
	while (str[i] != '\0' && start <= i)
	{
		if (str[i] == del || str[i] == '\n')
		{
			str_len = i - start;
			sub_str = (char *)malloc(sizeof(char) * (str_len + 2));
			if (!sub_str)
			{
				for (free_str = 0; free_str < arr_iter; free_str++)
				{
					free(new_arr[free_str]);
				}
				free(new_arr);
				perror("failed at making sub_str ptr");
				return (NULL);
			}
			stop = i;
			sub_str = _cpy_from_to(str, start, stop);
			start = i;
			sub_str[str_len + 1] = '\0';
			new_arr[arr_iter++] = sub_str;
			if (arr_iter >= ARR_SIZE)
			{
			new_size = ARR_SIZE * 2;
			temp = (char **)realloc(new_arr, sizeof(char *) * new_size);
			if (!temp)
			{
			for (free_str = 0; free_str < arr_iter; free_str++)
			{
			free(new_arr[free_str]);
			}
			free(new_arr);
			perror("failed at making temp ptr");
			return (NULL);
			}
			new_arr = temp;
			}
		}
		i++;
	}
	new_arr[arr_iter + 1] = NULL;
	return (new_arr);
}
