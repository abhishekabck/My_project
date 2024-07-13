# include <stdio.h>
# include <stdlib.h>

struct node{
    int data;
    struct node* next_node;
}node1,node2,node3;

int main(){
    node1.data = 10;
    node2.data = 20;
    node3.data = 30;
    node1.next_node = &node2;
    node2.next_node = &node3;
    node3.next_node = NULL;
    printf("%d %d %d",node1.data,node1.next_node->data, node1.next_node->next_node->data);
}
