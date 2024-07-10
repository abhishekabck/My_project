#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE * sourceFile, *destFile;
    char ch;
    sourceFile = fopen("C\\file_handling\\data.txt", "r");

    // Open the destination file in write mode
    destFile = fopen("C\\file_handling\\Destination.txt", "w");

    // Copy the content from source file to destination file
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destFile);
    }

    printf("File copied successfully.\n");

    // Close the files
    fclose(sourceFile);
    fclose(destFile);

    return 0;
}
