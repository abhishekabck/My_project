# include <stdio.h>
# include <stdlib.h>

// Defining Structure of the Tree
struct Node {
    int val;
    struct Node* leftchild;
    struct Node* rightchild;
};

struct Node* newnode(int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL){
        printf("\nMemory Allocation Failed..");
        return NULL;
    }
    temp->val = data;
    temp->leftchild = NULL;
    temp->rightchild = NULL;
    return temp;
}

void InorderTraversal(struct Node* root){
    if (root!=NULL){
        InorderTraversal(root->leftchild);
        printf("%d ", root->val);
        InorderTraversal(root->rightchild);
    }
}

void PreOrderTraversal(struct Node* root){
    if (root != NULL){
        printf("%d ", root->val);
        PreOrderTraversal(root->leftchild);
        PreOrderTraversal(root->rightchild);
    }
}

void PostOrderTraversal(struct Node* root){
    if (root!=NULL){
        PostOrderTraversal(root->leftchild);
        PostOrderTraversal(root->rightchild);
        printf("%d ", root->val);
    }
}
int main(){
    struct Node* root = newnode(1);
    root->leftchild = newnode(3);
    root->leftchild->leftchild = newnode(5);
    root->leftchild->rightchild = newnode(2);
    root->rightchild = newnode(4);
    root->rightchild->leftchild = newnode(7);
    root->rightchild->rightchild = newnode(6);
    InorderTraversal(root);
    printf("\n");
    PreOrderTraversal(root);
    printf("\n");
    PostOrderTraversal(root);
    return 0;
}