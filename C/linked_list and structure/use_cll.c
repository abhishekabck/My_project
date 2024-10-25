# include <stdio.h>
# include "cyclic_linkedList.c"

int main() {
    // Create circular linked list
    struct CircularLList* list = create_CLL();
    
    // Use the methods
    list->append(list, 235);
    list->append(list, 452);
    list->insertAtBeg(list, 9712);
    list->append(list,345);
    list->append(list, 452);
    list->insertAtBeg(list, 452);
    list->insert(list, -234, 1);
    list->traverse(list);
    list->reverse(list);
    list->traverse(list);
    printf("Length = %d\n", list->length);
    
    // Free memory (optional, but recommended for larger programs)
    free(list); // Add proper memory management for nodes if necessary
    
    return 0;
}
