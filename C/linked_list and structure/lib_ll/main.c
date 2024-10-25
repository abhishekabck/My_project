#include <stdio.h>
#include <stdlib.h>
#include "cyclic_linkedList.h"

int main() {
    // Create circular linked list
    struct CircularLList* list = create_CLL();

    // Use the methods
    list->append(list, 235);
    list->append(list, 452);
    list->insertAtBeg(list, 9712);
    list->append(list, 453);
    list->insertAtBeg(list, 453);
    // list->append(list, 234); // Correct way to append
    // append(list, 234); // This line should cause an error if `append` is static and not accessible directly
    
    list->traverse(list);

    // Free memory (optional, but recommended for larger programs)
    free(list); // Add proper memory management for nodes if necessary

    return 0;
}
