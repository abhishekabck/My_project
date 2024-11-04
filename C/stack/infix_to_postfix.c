#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *input = NULL;
    size_t buffer_size = 100;

    // Allocate memory for input buffer
    input = (char *)malloc(buffer_size * sizeof(char));
    if (input == NULL) {
        perror("Unable to allocate buffer");
        exit(1);
    }

    printf("Enter a string: ");
    if (fgets(input, buffer_size, stdin) == NULL) {
        perror("Error reading input");
        free(input);
        exit(1);
    }

    // Remove the newline character if it's present
    input[strcspn(input, "\n")] = 0;

    size_t length = strlen(input); // Get the length of the input string
    printf("The length of the string is: %zu\n", length);

    free(input); // Free the allocated memory
    return 0;
}
