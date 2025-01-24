#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"
#include "priority_queue.h"
#include "set.h"

struct node {
    int vertex;
    struct node *next;
};

struct weighted_node {
    int vertex;
    int weight;
    struct* weighted_node;
};

typedef struct node node;

typedef struct weighted_node w_node;

// Creating Graph
node** CreateGraph(int n) {
    node** adjacent = (node**)malloc(sizeof(node*) * (n + 1));
    if (adjacent == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    for (int i = 1; i <= n; i++) {
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

// Manually creating a graph for testing
void create_test_graph(node *adjacent[]) {
    node *p;

    // Vertex 1 adjacency list
    p = newnode(2);
    p->next = newnode(3);
    adjacent[1] = p;

    // Vertex 2 adjacency list
    p = newnode(1);
    p->next = newnode(4);
    adjacent[2] = p;

    // Vertex 3 adjacency list
    p = newnode(1);
    p->next = newnode(4);
    adjacent[3] = p;

    // Vertex 4 adjacency list
    p = newnode(2);
    p->next = newnode(3);
    adjacent[4] = p;
}

// Printing a Graph
void PrintGraph(node *adjacent[], int n) {
    for (int i = 1; i <= n; i++) {
        node *p = adjacent[i];
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
    for (int i = 1; i <= n; i++) {
        node *p = adjacent[i];
        while (p != NULL) {
            node *temp = p;
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

// Depth-First Search Traversal
void DFS(node* adjacent[], int start_vertex, int n){
    if (start_vertex < 1 || start_vertex > n){
        printf("Invalid Vertex..\n");
        exit(0);
    }
    printf("DFS Traversal: ");
    Stack(n);
    int visited[n + 1] = {0};
    push_stack(start_vertex);
    while(!is_empty_stack()){
        int u = pop_stack();
        if(!visited[u]){
            printf("%d ", u);
            visited[u] = 1;
            node* temp = adjacent[u];
            while(temp != NULL){
                if (!visited[temp->vertex]) push_stack(temp->vertex);
                temp = temp->next;
            }
        }
    }
    printf("\n");
}

int min(int w1, int w2){
    return (w1 > w2)? w2: w1;
}

void Dijkstra_source_to_all(w_node* G, int v, int source) {
    // Initializing the set
    Set visited;
    initializeSet(&visited);

    // Initializing distance array with all values as infinite(NULL)
    int D[v+1] = {INT_MAX};

    // Initializing Priority Queue
    PriorityQueue pq;
    initializePriorityQueue(&pq);

    // Adding source to the set and giving it's distance to 0
    addElement(&visited, source);
    D[source] = 0;

    // Initializing useful variables
    int i = 0;
    w_node* temp;
    temp = G[source];

    // Insert all the directed element from source in priority Queue
    while(temp != NULL){
        // Insert the element in pq only if the element if the element is non-visited.
        if (!containsElement(&visited, temp->vertex))
            insert(&pq, temp->vertex);

        D[temp->vertex] = min(D[source] + D[temp->weight], D[temp->vertex]);
    }
    // After all inserting in Priority Queue, calculate minimum element from the priority and mark it as visited and apply same process;
    int u = extractMin(&pq);
    if (u!=-1){
        
    }

}

int main() {
    int n = 4;  // Number of vertices in the graph

    node **adjacency_list = CreateGraph(n);
    // input(adjacency_list, n); // Commenting out the input system

    create_test_graph(adjacency_list);  // Creating a test graph

    printf("Printing the Adjacency list:\n");
    PrintGraph(adjacency_list, n);

    printf("Starting BFS traversal from vertex 1:\n");
    BFS(adjacency_list, 1, n);

    printf("Starting DFS traversal from vertex 1:\n");
    DFS(adjacency_list, 1, n);

    printf("Deleting the Graph\n");
    DeleteGraph(adjacency_list, n);
    PrintGraph(adjacency_list, n);

    return 0;
}
