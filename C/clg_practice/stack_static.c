# include <stdio.h>
# include <stdlib.h>


// Defining Stack Structure
struct structure001{
    int Max_size;
    int top;
    int arr*;
    int (*stack)(int*);
    void (*push)(struct structure001*,int);
    void (*pop)(struct structure001*);
    int (*peek)(struct structure001*);
    int (*IsEmpty)(struct structure001);
    int (*IsFull)(struct structure001);
};

typedef structure001 Stack;

// Function Prototypes
Stack* _CREATE_STACK_(int);
void _STACK_POP_(Stack);
void _STACK_PUSH_(Stack, int);
int _STACK_PEEK_(Stack);


// Function Definitions
Stack* _CREATE_STACK_(int Max_size){
    Stack new_stack* = (Stack*)malloc(sizeof(Stack));
    new_stack.Max_size = Max_size;
    new_stack.top = -1;
    (new_stack.arr)* = ((new_stack.arr)*)malloc(sizeof(Max_size)*sizeof(int));
    return new_stack;
}

