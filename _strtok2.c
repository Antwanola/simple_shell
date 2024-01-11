#include "shell.h"

char **_strtok2(char *str, char del)
{
    size_t first_iter, second_iter, str_len = _strlen(str), arr_iter = 0, i;
    size_t start = 0, stop;
    char **new_arr = NULL;
    char *new_str = NULL;

    new_arr = (char **)malloc(sizeof(char *) * ARR_SIZE);
    if (!new_str)
        return (NULL);
    for (first_iter = 0; first_iter < str_len; first_iter++)
    {
        if (str[first_iter] == del)
        {
            new_str = malloc(sizeof(char *) * (stop - start + 2));
            if (!new_str)
            {
                for (i = 0; i < arr_iter; i++)
                {
                    free(new_arr[i]);
                }
                free(new_arr);
            }
            stop = first_iter;
            new_str = _cpy_from_to(str, start, stop);
            new_str[stop + 1] = '\0';
            new_arr[arr_iter++] = new_str;
            start = first_iter + 1;
        }
    }
    new_arr[arr_iter + 1] = NULL;
    return (new_arr);
}