#ifndef SET_H
#define SET_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define HASH_SIZE 101

typedef struct SetNode {
    int element;
    struct SetNode *next;
} SetNode;

typedef struct {
    SetNode *buckets[HASH_SIZE];
} Set;

unsigned int hash(int key) {
    return key % HASH_SIZE;
}

void initializeSet(Set *s) {
    for (int i = 0; i < HASH_SIZE; i++) {
        s->buckets[i] = NULL;
    }
}

bool addElement(Set *s, int element) {
    unsigned int idx = hash(element);
    SetNode *current = s->buckets[idx];
    
    while (current != NULL) {
        if (current->element == element) {
            return false;  // Element already in the set
        }
        current = current->next;
    }

    SetNode *newNode = (SetNode *)malloc(sizeof(SetNode));
    newNode->element = element;
    newNode->next = s->buckets[idx];
    s->buckets[idx] = newNode;
    return true;
}

bool containsElement(Set *s, int element) {
    unsigned int idx = hash(element);
    SetNode *current = s->buckets[idx];
    
    while (current != NULL) {
        if (current->element == element) {
            return true;
        }
        current = current->next;
    }
    return false;
}

bool removeElement(Set *s, int element) {
    unsigned int idx = hash(element);
    SetNode *current = s->buckets[idx];
    SetNode *prev = NULL;
    
    while (current != NULL) {
        if (current->element == element) {
            if (prev == NULL) {
                s->buckets[idx] = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}

void freeSet(Set *s) {
    for (int i = 0; i < HASH_SIZE; i++) {
        SetNode *current = s->buckets[i];
        while (current != NULL) {
            SetNode *temp = current;
            current = current->next;
            free(temp);
        }
    }
}

void printSet(Set *s) {
    for (int i = 0; i < HASH_SIZE; i++) {
        SetNode *current = s->buckets[i];
        if (current != NULL) {
            printf("Bucket %d: ", i);
            while (current != NULL) {
                printf("%d ", current->element);
                current = current->next;
            }
            printf("\n");
        }
    }
}

#endif // SET_H
