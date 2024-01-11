#include "shell.h"
/**
 * _getchar- gets char
 * Return: int
 */
int _getchar(void)
{
	int c;

	if (read(0, &c, 1) == 1)
		return ((int)c);
	else
		return (EOF);
}
