#include "shell.h"

/**
  * _getline- Get stdin line
  * @buffer: the address of the buffer to be wrriten
  * @size: the size of the expected word
  * Return: Return the number of words written to buffer
  */

int _getline(char **buffer, int *size)
{
	int ch, buff_len = 0, length = 0;

	*buffer = (char *)malloc(*size * sizeof(char));
	if (!*buffer)
		return (-1);
	while (1)
	{
		ch = _getchar();
		(*buffer)[length] = (char)ch;
		length++;
		if (ch == EOF || ch == '\n')
		{
			(*buffer)[length] = '\0';
			break;
		}
		if (length >= *size)
		{
			*size *= 2;
			*buffer = (char *)realloc(*buffer, *size * sizeof(char));
			if (!*buffer)
			{
				free(buffer);
				perror("failed to realloc buffer @ _getline");
				return (-1);
			}
		}
	}
	return (length);
}
