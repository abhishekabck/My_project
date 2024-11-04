# include <stdio.h>
# include <stdlib.h>

// Defining the node structure
struct node {
    int data;
    struct node* next;
};

// Function which generates error by displaying given message
void raise_error(char msg[]){
    fprintf(stdout, "::Error::- %s\n", msg);
    exit(1);
}

// Function to Generate new_node
struct node* __newNode__(int data){
    struct node* otp = (struct node*)malloc(sizeof(struct node));
    if (otp == NULL) raise_error("::Memory limit Exceeded::");
    otp->data = data;
    otp->next = NULL;
    return otp;
}

// Defining Circular Linked lIst structure
struct CircularLList{
    struct node* head;
    struct node* tail;
    int length;

    //  Function pointers
    // Insertion Functions
    void (*append)(struct CircularLList*, int);
    void (*insertAtBeg)(struct CircularLList*, int);
    void (*insert)(struct CircularLList*, int, int);

    // Deletion of nodes
    void (*remove_first)(struct CircularLList*, int);
    void (*remove_all)(struct CircularLList*, int);
    void (*remove_some)(struct CircularLList*, int, int);
    void (*delete)(struct CircularLList*, int);

    // Traversing
    void (*traverse)(struct CircularLList*);
    // Tools
    int (*max)(struct CircularLList*);
    int (*min)(struct CircularLList*);
    void (*sort_using_array)(struct CircularLList*);

    // reversing
    void (*reverse)(struct CircularLList*);
};


// Function to Traverse whole Linked List
void traverse(struct CircularLList* list) {
    if (list->head == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    struct node* temp = list->head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != list->head);
    printf("(back to head)\n");
}

// Defining insertAt Beginning function to insert values any beginning
void insertAtBeg(struct CircularLList* list, int data) {
    struct node* newNode = __newNode__(data);
    list->length++;
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
        newNode->next = newNode; // Point to itself
    } else {
        newNode->next = list->head;
        list->head = newNode;
        list->tail->next = list->head; // Update the tail's next
    }
}


// Append function to add newNode to the Linked list
void append(struct CircularLList* list, int data) {
    struct node* newNode = __newNode__(data);
    list->length++;
    if (list->tail == NULL) {
        list->head = newNode;
        list->tail = newNode;
        newNode->next = newNode; // Point to itself
    } else {
        list->tail->next = newNode;
        newNode->next = list->head; // Point to head
        list->tail = newNode; // Update tail
    }
}

// Defining insert function to insert a value at a given index
void insert(struct CircularLList* list, int data, int index){
    // Case 0: Invalid Index (less than 1)
    if (index < 1) raise_error("Index out of range.");
    // Case 1: Insert at the beginning.
    else if (index == 1) {
        return list->insertAtBeg(list, data);
    }
    // Case 2: Index is greater than the list length, append to the end.
    else if (index > list->length) {
        return list->append(list, data);
    }
    // Case 3: Insert in between the list.
    else {
        struct node* pre = list->head;
        struct node* cur = list->head->next;
        // Traverse to the position before the specified index.
        for (int i = 1; i < index - 1; i++) {
            pre = cur;
            cur = cur->next;
        }
        // Insert the new node between `pre` and `cur`
        struct node* newNode = __newNode__(data);
        pre->next = newNode;
        newNode->next = cur;
        list->length++;
    }
}


void remove_first(struct CircularLList* list, int data) {
    // Case 1: Linked list is empty
    if (list->head == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    struct node* cur = list->head;
    struct node* pre = list->tail;
    // Case 2: List contains only one element
    if (cur->data == data && cur->next == list->head) {
        free(cur);
        list->head = NULL;
        list->tail = NULL;
        list->length = 0;
        return;
    }
    // Case 3: List contains more than one element
    do {
        if (cur->data == data) {
            pre->next = cur->next;
            if (cur == list->head) {
                list->head = cur->next;
            }
            if (cur == list->tail) {
                list->tail = pre;
            }
            free(cur);
            list->length--;
            return;
        }
        pre = cur;
        cur = cur->next;
    } while (cur != list->head);
    printf("::Data Not Found::\n");
}


// Function to remove all x
void remove_all(struct CircularLList* list, int x){
    // Case 1: Linked list is empty
    if (list->head == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    struct node* cur = list->head;
    struct node* pre = list->tail;
    int found = 0;
    // Case 2: List contains only one element
    if (cur->data == x && cur->next == list->head) {
        free(cur);
        list->head = NULL;
        list->tail = NULL;
        list->length = 0;
        return;
    }
    // Case 3: List contains more than one element
    do {
        if (cur->data == x) {
            pre->next = cur->next;
            if (cur == list->head) {
                list->head = cur->next;
            }
            if (cur == list->tail) {
                list->tail = pre;
            }
            struct node* to_delete = cur;
            cur = cur->next;
            free(to_delete);
            list->length--;
            found = 1;
        } else {
            pre = cur;
            cur = cur->next;
        }
    } while (cur != list->head);
    if (!found) {
        printf("::Data Not Found::\n");
    }
}

// Defining a Function to delete given number of occurrences of x
void remove_some(struct CircularLList* list, int x, int ocr){
    if (ocr <= 0) raise_error("Invalid Input");
    // Case 1: Linked list is empty
    if (list->head == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    struct node* cur = list->head;
    struct node* pre = list->tail;
    int found = 0;
    // Case 2: List contains only one element
    if (cur->data == x && cur->next == list->head) {
        free(cur);
        list->head = NULL;
        list->tail = NULL;
        list->length = 0;
        return;
    }
    // Case 3: List contains more than one element
    do {
        if (cur->data == x) {
            pre->next = cur->next;
            if (cur == list->head) {
                list->head = cur->next;
            }
            if (cur == list->tail) {
                list->tail = pre;
            }
            struct node* to_delete = cur;
            cur = cur->next;
            free(to_delete);
            list->length--;
            found = 1;
            ocr--;
            if (ocr<=0) return;
        } else {
            pre = cur;
            cur = cur->next;
        }
    } while (cur != list->head);
    if (!found) {
    printf("::Data Not Found::\n");
    }
}


// Function to delete any note at any k position
void delete(struct CircularLList* list, int index) {
    if (index <= 0) raise_error("Invalid Index");
    // Case 1: List is empty
    if (list->head == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    struct node* cur = list->head;
    struct node* pre = list->tail;
    // Traverse to the correct node or the last node
    for (int i = 1; i < index && cur != list->tail; i++) {
        pre = cur;
        cur = cur->next;
    }
    // If index exceeds length, delete the last node
    if (index > list->length) {
        cur = list->tail;
        pre = list->head;
        while (pre->next != list->tail) {  // Traverse to the second-last node
            pre = pre->next;
        }
        pre->next = list->head;  // Adjust the second-last node's next to head
        list->tail = pre;  // Update the tail
        free(cur);  // Free the original last node
        list->length--;
        return;
    }
    // Delete the node at the correct index
    pre->next = cur->next;
    if (cur == list->head) list->head = cur->next;
    if (cur == list->tail) list->tail = pre;
    free(cur);  // Free the node
    list->length--;  // Decrease the list length
}

// void reverse(struct CircularLList* list){
//     if (list->length == 0 || list->length == 1){
//         return;
//     }
//     struct node* previous = list->head;
//     list->head = previous->next;
//     struct node* current = list->head;
//     do {
//         list->head = list->head->next;
//         current->next = previous;
//         previous = current;
//         current = list->head;
//     }while (list->head != list->tail);
//     list->head = previous;
//     list->tail->next = previous;
// }

void reverse(struct CircularLList* list) {
    if (list->length == 0 || list->length == 1) {
        return;
    }
    struct node* previous = list->head;
    struct node* current = previous->next;
    struct node* next = NULL;
    struct node* tail = list->head;

    do {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    } while (current != list->head);

    list->head = previous;
    tail->next = list->head;
}

// Function to return maximum element of any linked list
struct node* max(struct CircularLList* list){
    if (list->length == 0) __raise__(" :LinkedList is Empty");
    // Linked list contains some element
    struct node* temp = list->head->next;
    int max_element = list->head->data;
    while (temp != list->head){
        max_element = (max_element>temp->data)?max_element:temp->data;
    }
    return max_element;
}

// Function to return maximum element of any linked list
struct node* min(struct CircularLList* list){
    if (list->length == 0) __raise__(" :LinkedList is Empty");
    // Linked list contains some element
    struct node* temp = list->head->next;
    int min_element = list->head->data;
    while (temp != list->head){
        min_element = (min_element<temp->data)?min_element:temp->data;
    }
    return min_element;
}

// Sorting using array
void sort_using_cll(struct CircularLList* list){
    if (list->length == 0 || list->length == 1) return;
    struct node* temp = list->head, *node_to_delete;
    // using insertion sort techniques
    while (temp->next != list->tail) {
        int key = temp->data;
        struct node* temp1 = list->head;
    }
}


// Defining circular linked list structure
struct CircularLList* create_CLL() {
    struct CircularLList* list = (struct CircularLList*)malloc(sizeof(struct CircularLList));
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
    list->append = append;
    list->insertAtBeg = insertAtBeg;
    list->traverse = traverse;
    list->insert = insert;
    list->remove_first = remove_first;
    list->remove_all = remove_all;
    list->remove_some = remove_some;
    list->delete = delete;
    list->reverse = reverse;
    list->max = max;
    list->min = min;
    list->sort_using_array = sort_using_array;
    return list;
}

