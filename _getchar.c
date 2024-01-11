#include "shell.h"

int _getchar()
{
	int c;

	if (read(0, &c, 1) == 1)
		return ((int)c);
	else
		return (EOF);
}
