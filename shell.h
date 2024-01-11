#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#define BUFF_SIZE 100
#define ARR_SIZE 10

/*Free things*/
void _free(char **dp);

/*String Functions*/
char *_cpy_from_to(char *str, size_t from, size_t to);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strlen(char *str);
char *_strncpy( char *dest, char *src, size_t n);
char **_strtok(char *str, char del);
int _getchar();
int _getline(char **buffer, size_t *size);
void interactive();

void _signal_handler(int signum)
void h(char **buff, size_t *n, char **copy_bu, char **token, const char *delim);
int tokenize_input(char *copy_bu, char ***argv);
void execute_command(char **argv, char *copy_buff, char **env);
int main(int argc, char **argv, char **env);
void _getpid(char **avg, char *cmd);
char *get_path(const char *command);

#endif
