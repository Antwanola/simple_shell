#include "shell.h"
/**
 * sign_handler - this interrupt curent process
 * @signum: signal number
 */
void _signal_handler(int signum)
{
	int child_running = 0;

	(void)signum;

	if (child_running)
	{
		write(STDOUT_FILENO, "Terminating process \n", 40);
		kill(child_running, SIGTERM);
	}
	else
	{
		write(STDOUT_FILENO, "\n$", 3);
	}
}
/**
 * h - user input processor
 * @buff: buff pointer
 * @n: pointer to buffer size
 * @copy_bu: pointer of store of buff string
 * @token: pointer to token
 * @delim: delimiter
 */
void h(char **buff, size_t *n, char **copy_bu, char **token, const char *delim)
{
	ssize_t count = 0;

	count = _getline(buff, n, stdin);

	if (count == -1)
	{
		free(*buff);
		exit(EXIT_SUCCESS);
	}

	if ((*buff)[count - 1] == '\n')
		(*buff)[count - 1] = '\0';

	*copy_bu = malloc(sizeof(char) * (count + 1));

	if (*copy_bu == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	_strcpy(*copy_bu, *buff);
	*token = _strtok(*buff, delim);

	if (*buff == NULL)
	{
		free(*copy_bu);
		exit(EXIT_FAILURE);
	}
}
/**
 * tokenize_input - input tokenizer
 * @copy_bu: buffer copy
 * @argv: args
 * Return: new_token
 */
int tokenize_input(char *copy_bu, char ***argv)
{
	char *token;
	const char *delim = " \n";
	int new_token = 0;
	int i;

	token = _strtok(copy_bu, " \n");
	while (token != NULL)
	{
		new_token++;
		token = _strtok(NULL, delim);
	}
	new_token++;

	*argv = malloc(sizeof(char *) * new_token);
	if (*argv == NULL)
	{
		perror("_strdup");
		exit(EXIT_FAILURE);
	}
	token = _strtok(copy_bu, " \n");
	for (i = 0; token != NULL; i++)
	{
		(*argv)[i] = _strdup(token);
		if ((*argv)[i] == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
		token = _strtok(NULL, delim);
	}
	(*argv)[i] = NULL;

	if (*argv != NULL)
	{
		for (i = 0; i < n_token; i++)
		{
			free((*argv)[i]);
		}
		free(*argv);
	}

	return (n_token);
}

/**
 * execute_command - execute commands
 * @argv: argv
 * @copy_buff: buffer copy
 * @env: env
 */
void execute_command(char **argv, char *copy_buff, char **env)
{
	int n_token;
	int i;
	(void) **env;

	n_token = tokenize_input(copy_buff, &argv);
	if (handle_path(argv, argv[0]) != NULL || argv[0][0] == '/')
	{
		getpiddd(argv, copy_buff);
	}
	else if (argv[0][0] != '/')
	{
		const char program_name[] = "./hsh: ";
		const char error_message[] = "No such file or directory \n";

		write(STDERR_FILENO, program_name, strlen(program_name));
		write(STDERR_FILENO, error_message, strlen(error_message));

		exit(2);
	}
	if (argv != NULL)
	{
		for (i = 0; i < n_token; i++)
		{
			free(argv[i]);
		}
		free(argv);
	}
	free(copy_buff);
}
/**
 * main - 	displays the prompt
 * @argv: 	args
 * @env:	environ variable
 * @argc: 	argument int
 * Return: 	return 1 if sucessful 
 */
int main(int argc, char **argv, char **env)
{
	size_t n = 0;
	char *buff = NULL;
	char *copy_buff;
	char *token;
	const char *delim = " \n";
	(void)argc;
	(void)env;


	signal(SIGINT, _signal_handler);
	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			char prompt[] = "$ ";

			write(STDOUT_FILENO, prompt, _strlen(prompt));
		}

		h(&buff, &n, &copy_buff, &token, delim);
		handle_exit(copy_buff);

		if (strcmp(copy_buff, "env") == 0)
		{
			_env(env);
			continue;
		}
		execute_command(argv, copy_buff, env);
	}

	free(buff);
	return (0);
}
