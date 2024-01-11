#include "shell.h"

/**
 * _cpy_from_to cp from and to
 * @str: the string to cp
 * @from: the size from
 * @to: the size of to
 * Return: char
 */
char *_cpy_from_to(char *str, size_t from, size_t to)
{
    size_t i, p = 0;
    char *dest = NULL;

   if (!str || from >= _strlen(str) || to >= _strlen(str) || from > to)
        return (NULL);
    dest = (char *)malloc(sizeof(char *) * (to - from + 2));
    if (!dest)
        return (NULL);
    for (i = from; i < to && str[i] != '\0'; i++)
    {
        dest[p++] = str[i];
    }
    dest[p] = '\0';
    return (dest);
}
