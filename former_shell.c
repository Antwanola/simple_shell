#include "shell.h"

int main(int ac, char **argv) {
    char *lineptr = NULL;
    char **token = NULL;
    size_t line_len = 100;
    size_t len;
    
    while (1) {
        printf("Hello$:");
        fflush(stdout);
        len = _getline(&lineptr, &line_len);
        printf("%s\n", lineptr);
        printf("%ld\n", len);
        token = _strtok(lineptr, ' ');

        int i = 0;  // Reset i for each iteration
        while (token[i] != NULL) {
            printf("the string token from _strdup(): %s\n", token[i]);
            i++;
        }

        // Free the tokens
        for (int j = 0; token[j] != NULL; ++j) {
            free(token[j]);
        }
        free(token);
    }

    free(lineptr);
    return 0;
}

