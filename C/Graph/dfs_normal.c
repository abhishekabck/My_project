# include <stdio.h>
# include <stdlib.h>
int top = -1
void push(int *stack, int value){
    int size = sizeof(stack)/sizeof(stack[0]);
    if(top == size - 1){
        printf("\nOverflow");
        return;
    }
    stack[++top] = value;
}

int pop(int *stack){
    if(top == -1){
        printf("\n Underflow");
        return -1;
    }else {
        return stack[top--];
    }
}


int dfs(int** G,int target_v,int n){
    int stack[n];           // Create a stack of size n: Total number of the possible vertices
    int visited[n] = {0};   // Create a array visited of size n, Assign False(0) to all values in visited
    // Push first or any element of stack
    push(&stack, 1);
    while(top != -1){
        int u = pop(&stack);
        if(u == target_v){
            return 1;
        }
        if(!visited[u]){
            visited[u] = 1;
            for(int w = 0; w < v; i++){
                if(G[u][w]) push(&stack, G[u][w]);
            }
        }
    }return 0;
}


int main(){
    int v = 7; // Total number of vertices
    int array[7][7] = {
        {0, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 1, 1},
        {1, 0, 0, 0, 1, 0, 0},
        {1, 1, 1, 1, 0, 1, 0},
        {0, 0, 1, 0, 1, 0, 1},
        {0, 0, 1, 0, 0, 1, 0}
    }
    int result = dfs{&&array, 3,v};
    if(!result) printf("Vertices Does not exist");
    else printf("Vertices Found at %d",result);
    return 0;
}