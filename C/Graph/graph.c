#include <stdio.h>
#include <stdlib.h>
#include "queue.c"
#include "stack.c"

struct node {
    int vertex;
    struct node *next;
};

typedef struct node node;

// Creating Graph
node** CreateGraph(int n) {
    node** adjacent = (node**)malloc(sizeof(node*) * (n + 1));
    if (adjacent == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    int i;
    for (i = 1; i <= n; i++) {
        adjacent[i] = NULL;
    }
    return adjacent;
}

node* newnode(int data) {
    node* nn = (node*)malloc(sizeof(node));
    if (nn == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    nn->vertex = data;
    nn->next = NULL;
    return nn;
}

// Function to input Graph information
void input(node *adjacent[], int n) {
    node *p, *last;
    int i, j, k, value;
    for (i = 1; i <= n; i++) {
        last = NULL;
        printf("How many nodes are in the adjacency list of vertex %d: ", i);
        scanf("%d", &k);
        for (j = 1; j <= k; j++) {
            printf("\nEnter the node: ");
            scanf("%d", &value);
            node *p = newnode(value);
            if (adjacent[i] == NULL)
                adjacent[i] = last = p;
            else {
                last->next = p;
                last = p;
            }
        }
    }
}

// Printing a Graph
void PrintGraph(node *adjacent[], int n) {
    node *p;
    int i;
    for (i = 1; i <= n; i++) {
        p = adjacent[i];
        printf("vertex - %d: ", i);
        while (p != NULL) {
            printf("%d -> ", p->vertex);
            p = p->next;
        }
        printf("NULL\n");
    }
}

// Delete a Graph
void DeleteGraph(node *adjacent[], int n) {
    int i;
    node *temp, *p;
    for (i = 1; i <= n; i++) {
        p = adjacent[i];
        while (p != NULL) {
            temp = p;
            p = p->next;
            free(temp);
        }
        adjacent[i] = NULL;
    }
}

// Traversal of the Graph
void BFS(node *adjacent[], int start_vertex, int n) {
    int visited[n + 1]; 
    for (int i = 0; i <= n; i++) {
        visited[i] = 0;
    }
    Queue(n); 

    printf("BFS Traversal: ");
    enqueue(start_vertex);
    visited[start_vertex] = 1;

    while (!is_empty()) {
        int current_vertex = dequeue();
        printf("%d ", current_vertex);

        node *temp = adjacent[current_vertex];
        while (temp) {
            int adj_vertex = temp->vertex;
            if (!visited[adj_vertex]) {
                enqueue(adj_vertex);
                visited[adj_vertex] = 1;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

void DFS(node* adjacent[], int start_vertex, int n){

}

int main() {
    int n;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    node **adjacency_list = CreateGraph(n);
    printf("\n");
    input(adjacency_list, n);

    printf("Printing the Adjacency list:\n");
    PrintGraph(adjacency_list, n);

    printf("\nStarting BFS traversal from vertex 1:\n");
    BFS(adjacency_list, 1, n);

    printf("Deleting the Graph\n");
    DeleteGraph(adjacency_list, n);
    PrintGraph(adjacency_list, n);

    return 0;
}
