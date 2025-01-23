// Non weighted Graph
# include <stdio.h>
# include <stdlib.h>
# include "queue.c"
struct node
{
    int vertex;
    struct node * next;
};

// For Weighted Graphs
/*
struct node{
    int vertex;
    int weight;
    struct node* next;
}
*/

typedef struct node node;

// assuming total vertices of the graph = 4

// Creating Graph
void CreateGraph(node* adjacent[], int n){
    int i;
    for(i = 1; i <= n; i++){
        adjacent[i] = NULL;
    }
}

// Function to input Graph information
void input(node* adjacent[], int n){
    node *p, *last;
    int i, j, k, value;
    for(i = 1; i <= n; i++){
        last = NULL;
        printf("Home many nodes are in adjacency list of vertex %d :-", i);
        scanf("%d", &k);
        for(j = 1; j <= k; j++){
            printf("\nEnter the node:- ");
            scanf("%d", &value);
            node* p = (node*)malloc(sizeof(node));
            p->vertex = value;
            p->next = NULL;
            if (adjacent[i] == NULL)
                adjacent[i] = last = p;
            else{
                last->next = p;
                last = p;
            }
        }
    }
}


// Printing a Graph
void PrintGraph(node* adjacent[], int n){
    node* p;
    int i;
    for(i = 1; i<=n; i++){
        p = adjacent[i];
        printf("vertex - %d: ", i);
        while(p!=NULL){
            printf("%d ->", p->vertex);
            p = p->next;
        }
        printf("NULL\n");
    }
}


// Delete a Graph
void DeleteGraph(node* adjacent[], int n){
    int i;
    node* temp, *p;
    for(i = 1; i <= n; i++){
        p = adjacent[i];
        while(p != NULL){
            temp = p;
            p = p->next;
            free(p);
        }
        adjacent[i] = NULL;
    }
}

// Traversal of the Graph
void BFS(int )

int main(){
    node* adjacency_list;
    int n;
    printf("Enter the number of the vertices: ");
    scanf("%d", &n);
    CreateGraph(&adjacency_list, n);
    printf("\n");
    input(&adjacency_list, n);
    printf("Printing the Adjacency list:\n");
    PrintGraph(&adjacency_list, n);
    printf("Deleting the Graph");
    DeleteGraph(&adjacency_list, n);
    PrintGraph(&adjacency_list, n);
    return 0;
}