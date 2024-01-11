#include "shell.h"

void _free(char **dp)
{
	char **str= dp;

	if (!dp)
		return;
	while (*dp)
		free(*dp++);
	free(str);
}