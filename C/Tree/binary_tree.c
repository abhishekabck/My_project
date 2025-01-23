# include <stdio.h>
# include <stdlib.h>

typedef struct n1{
    int data;
    struct n1* left;
    struct n1* right;
}TreeNode;

TreeNode* CreateNode(int data){
    TreeNode* newnode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newnode != NULL){
        newnode->data = data;
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
    }
    return newnode;
}


int main(){
    TreeNode* root = CreateNode(10);
    printf("%d",root->data);
    return 0;
}