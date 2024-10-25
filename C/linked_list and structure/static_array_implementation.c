#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

struct Node {
    int data;
    int next;
};

struct SinglyLinkedList {
    struct Node nodes[MAX_SIZE];
    int head;
    int size;
};

void initialize(struct SinglyLinkedList* list) {
    list->head = -1;
    list->size = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        list->nodes[i].next = -1;
    }
}

void insert(struct SinglyLinkedList* list, int data) {
    if (list->size == MAX_SIZE) return;

    int newNodeIndex = list->size;
    list->nodes[newNodeIndex].data = data;
    list->nodes[newNodeIndex].next = list->head;
    list->head = newNodeIndex;
    list->size++;
}

void display(struct SinglyLinkedList* list) {
    int currentIndex = list->head;
    while (currentIndex != -1) {
        printf("%d -> ", list->nodes[currentIndex].data);
        currentIndex = list->nodes[currentIndex].next;
    }
    printf("NULL\n");
}

int main() {
    struct SinglyLinkedList* list = (struct SinglyLinkedList*)malloc(sizeof(struct SinglyLinkedList));
    if (list == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    initialize(list);
    insert(list, 523);
    insert(list, 64);
    insert(list, 2643);
    display(list);
    free(list);
    return 0;
}
