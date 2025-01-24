#include <stdio.h>
#include <string.h>

// Function to compute the LPS array
void computeLPSArray(char *pattern, int M, int *lps) {
    int length = 0;
    lps[0] = 0; // lps[0] is always 0
    int i = 1;

    while (i < M) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Function to search the pattern in the text using the KMP algorithm
void KMPSearch(char *pattern, char *text) {
    int M = strlen(pattern);
    int N = strlen(text);

    // Create the LPS array
    int lps[M];
    computeLPSArray(pattern, M, lps);

    int i = 0; // index for text
    int j = 0; // index for pattern
    while (i < N) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == M) {
            printf("Found pattern at index %d\n", i - j);
            j = lps[j - 1];
        } else if (i < N && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    char text[] = "ABABDABACDABABCABAB";
    char pattern[] = "ABABCABAB";

    KMPSearch(pattern, text);

    return 0;
}
