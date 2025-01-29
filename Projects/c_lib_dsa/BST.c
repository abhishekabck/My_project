# include <stdio.h>
# include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

typedef node node;

// Methods in BST
void insert(node*, int);
void delete(node*, int);
void inOrder(node*, int);
void preOrder(node*, int);
void postOrder(node*, int);
void levelOrder(node*, int);
int heightOf(node*);
int depthOf(node*);
