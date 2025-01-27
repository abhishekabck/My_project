# include <stdio.h>
# include <stdlib.h>

// Defining Structure of the Binary Tree
struct node{
    char data;
    struct node* lchild;
    struct node* rchild;
};

typedef struct node node;


node* createnode(char info){
    node* newnode = (node*)malloc(sizeof(node*));
    if (newnode == NULL){
        printf("Node Creation Failed");
        exit(0);
    }
    newnode->data = info;
    newnode->lchild = NULL;
    newnode->rchild = NULL;
    return newnode;
}


node* test_nodes() {
    node* root = createnode('A');
    root->lchild = createnode('B');
    root->rchild = createnode('C');
    root->lchild->lchild = createnode('D');
    root->lchild->rchild = createnode('E');
    root->lchild->rchild->lchild =createnode('I');
    root->rchild->lchild = createnode('F');
    root->rchild->rchild = createnode('G');
    root->rchild->rchild->rchild = createnode('J');
    return root;
}

// Traversal Techniques


// Inorder Technique (LNR)
void inorder(node* root){
    if (root != NULL){
        inorder(root->lchild);
        printf("%c ", root->data);
        inorder(root->rchild);
    }
}


// PreOrder Technique (NLR)
void preOrder(node* root){
    if (root != NULL){
        printf("%c ", root->data);
        preOrder(root->lchild);
        preOrder(root->rchild);
    }
}


// PostOrder Traversal (LRN)
void postOrder(node* root){
    if (root!=NULL){
        postOrder(root->lchild);
        postOrder(root->rchild);
        printf("%c ", root->data);
    }
}



int main(){
    node* root = test_nodes();
    printf("/n Test Tree Creation Successful");
    printf("\n PreOrder Traversal:- ");
    preOrder(root);
    printf("\n InOrder Traversal:- ");
    inorder(root);
    printf("\n postOrder Traversal:- ");
    postOrder(root);
    return 0;
}