#include "shell.h"

void interactive()
{
	ssize_t isMessage, status;
	char **new_message = NULL;
	char buffer[BUFF_SIZE];
	pid_t pid;

	while (1)
	{
		fflush(stdin);
		printf("myShell$");
		isMessage = _getline(new_message, BUFF_SIZE);
		if (isMessage == -1)
		{
			if (feof(stdin))
			{
				printf("\n");
				break;
			}
			else
			{
				perror("Error from _getline()");
				exit(EXIT_FAILURE);
			}
		}
		new_message[_strcspn(new_message, '\n')+ 1] = '\0';
		pid = fork();
		if (pid == -1)
		{
			perror("unabale to fork()");
			exit(EXIT_FAILURE);
		}
		if (execve(new_message, NULL, NULL) == -1)
		{
			perror("Error executing command");
			exit(EXIT_FAILURE);
		}
		else
		{
			waitpid(pid, &status, 0);
			if (WIFEXITED(status))
			{
				printf("command executed");
			}
			else
				printf("command execution failure");
		}
	}
	free(new_message);
}

