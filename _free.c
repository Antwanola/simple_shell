#include "shell.h"

/**
 * _free- frees things
 * @dp: pointer of pointer to be freed
 * Return: void
 */

void _free(char **dp)
{
	char **str= dp;

	if (!dp)
		return;
	while (*dp)
		free(*dp++);
	free(str);
}
