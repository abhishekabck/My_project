#include <stdio.h>
#include <stdlib.h>

int* survivedRobotsHealths(int* positions, int positionsSize, int* healths, int healthsSize, char* directions, int* returnSize) {
    int s1 = 0;
    for (int i = 1; i < positionsSize; i++) {
        if (directions[i] != directions[0]) {
            s1 = 1;
            break;
        }
    }
    if (s1 == 0) {
        *returnSize = healthsSize;
        int* result = (int*)malloc(healthsSize * sizeof(int));
        for (int i = 0; i < healthsSize; i++) {
            result[i] = healths[i];
        }
        return result;
    }

    while (positionsSize > 1) {
        for (int i = 0; i < positionsSize; i++) {
            if (directions[i] == 'L') positions[i]--;
            else positions[i]++;
        }

        int loc = -1;
        s1 = 0;
        for (int i = 0; i < positionsSize; i++) {
            for (int j = i + 1; j < positionsSize; j++) {
                if (positions[i] == positions[j]) {
                    if (healths[i] > healths[j]) {
                        healths[i] -= healths[j];
                        loc = j;
                    } else if (healths[j] > healths[i]) {
                        healths[j] -= healths[i];
                        loc = i;
                    } else {
                        loc = i;
                        healths[j] = 0;
                    }
                    s1 = 1;
                    break;
                }
            }
            if (s1 == 1) break;
        }

        // Remove robot with health <= 0
        if (loc != -1) {
            for (int i = loc; i < positionsSize - 1; i++) {
                positions[i] = positions[i + 1];
                healths[i] = healths[i + 1];
                directions[i] = directions[i + 1];
            }
            positionsSize--;
            healthsSize--;
        }

        // Breaking condition: all robots moving in the same direction
        s1 = 0;
        for (int i = 1; i < positionsSize; i++) {
            if (directions[i] != directions[0]) {
                s1 = 1;
                break;
            }
        }
        if (s1 == 0) break;
        printf("Hehe\n");
    }

    *returnSize = healthsSize;
    int* result = (int*)malloc(healthsSize * sizeof(int));
    for (int i = 0; i < healthsSize; i++) {
        result[i] = healths[i];
    }
    return result;
}

int main() {
    int pos[4] = {1, 2, 5, 6};
    int health[4] = {10, 10, 11, 11};
    char st[100] = "RLRL";
    int res;
    int *ptr;
    ptr = survivedRobotsHealths(pos, 4, health, 4, st, &res);
    for (int i = 0; i < res; i++) {
        printf("%d ", ptr[i]);
    }
    free(ptr); // Don't forget to free the allocated memory
    return 0;
}
