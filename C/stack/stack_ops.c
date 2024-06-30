# include <stdio.h>
# define True 1
# define False 2

struct stack_Para(*top,size,*stack)
{
    int *top;
    int size;
    int *stack;
    void is_full(){
        if (*stack_Para.top>=size-1){
            return True;
        }
        return False;
    
    void is_false(){
        if (*stack_Para.top == -1){
            return True;
        }
        return False;
    }

    void push(int data){
        if (is_full()) {
            printf("Stack _overflow");
            return;
        }
        *stack_para.top++;
        stack[top] = data;
    }
}
};

int main(){
int size = 50;
int ls[50] = {};
int top = -1;

struct stack_Para var1 = {&top,size,ls};
printf("%d",var1.isfull());
return 0;
}




