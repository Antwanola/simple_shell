#include <stdio.h>

void printStringArray(char **arr) {
    if (arr == NULL) {
        printf("NULL\n");
        return;
    }

    for (int i = 0; arr[i] != NULL; i++) {
        printf("%s\n", arr[i]);
    }
}

int main() {
    char input[] = "This is a test string";
    char delimiter = ' ';

    char **result = _strtok(input, delimiter);

    printf("Tokenized String:\n");
    printStringArray(result);

    // Free allocated memory
    for (int i = 0; result[i] != NULL; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}
