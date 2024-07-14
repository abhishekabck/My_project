#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int position;
    int health;
    char direction;
} Robot;

int* survivedRobotsHealths(int* positions, int positionsSize, int* healths, int healthsSize, char* directions, int* returnSize) {
    Robot* stack = (Robot*)malloc(positionsSize * sizeof(Robot));
    int stackSize = 0;

    for (int i = 0; i < positionsSize; i++) {
        Robot current = { positions[i], healths[i], directions[i] };

        while (stackSize > 0 && stack[stackSize - 1].direction == 'R' && current.direction == 'L') {
            if (stack[stackSize - 1].health > current.health) {
                stack[stackSize - 1].health -= current.health;
                current.health = 0;
                break;
            } else if (stack[stackSize - 1].health < current.health) {
                current.health -= stack[stackSize - 1].health;
                stackSize--;
            } else {
                stackSize--;
                current.health = 0;
                break;
            }
        }

        if (current.health > 0) {
            stack[stackSize++] = current;
        }
    }

    int* result = (int*)malloc(stackSize * sizeof(int));
    *returnSize = stackSize;
    for (int i = 0; i < stackSize; i++) {
        result[i] = stack[i].health;
    }

    free(stack);
    return result;
}

int main() {
    int pos[] = {1, 2, 5, 6};
    int health[] = {10, 20, 11, 11};
    char st[] = "RLRL";
    int res;
    int* ptr;

    ptr = survivedRobotsHealths(pos, 4, health, 4, st, &res);
    for (int i = 0; i < res; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    free(ptr); // Don't forget to free the allocated memory
    return 0;
}
