#include "shell.h"


/**
 * handle_exit - makes things exits properly
 * @input: input
 */
void handle_exit(char *input)
{
	if (_strcmp(input, "exit") == 0)
	{
		free(input);
		exit(EXIT_SUCCESS);
	}
}
