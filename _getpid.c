#include "shell.h"
/**
 * getpiddd - create process and exec
 * @rvg: string arr
 * @cmd: cmd strings
 */
void _getpid(char **avg, char *cmd)
{
	pid_t small;
	int status;
	(void)cmd;

	small = fork();

	if (small == -1)
	{
		perror("Process Error");
		exit(1);
	}
	if (small == 0)
	{
		if (execve(avg[0], avg, NULL) == -1)
		{
			perror("Error");
		}
		exit(1);
	}
	else
	{
		wait(&status);
	}
}
