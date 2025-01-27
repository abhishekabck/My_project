# include <stdio.h>
# include <stdlib.h>

struct node
{
    int num;
    struct node* left;
    struct node* right;
};
typedef struct node node;
node *root = NULL;
node* insert(node* tree, long num);
void preorder(node* tree);
void inorder(node* tree);
void postorder(node* tree);
int select();
int count = 1;


main(){
    int choice;
    long digit;
    do {
        choice = select();
        switch (choice)
        {
        case 1:
            puts("Enter integer : To quit enter 0");
            scanf("%d", &digit);;
            while (digit != 0){
                root = insert(root, digit);
                scanf("%d", &digit);
            }
            continue;
        case 2:
            puts("\n Preorder Traversing TREE");
            preorder(root);
            continue;
        case 3:
            puts("\n Inorder traversing TREE");
            inorder(root);
            continue;
        case 4:
            puts("\n Postorder traversing TREE");
            postorder(root);
            continue;
        case 5:
            puts("END");
            exit(0);
        }
    } while(choice != 5);
}

int select(){
    int selection;
    do
    {
        puts("Enter 1 : Insert a node in a BT");
        puts("Enter 2 : Display (preorder) the BT");
        puts("Enter 3 : Display (inorder) the BT");
        puts("Enter 4 : Display (postorder) the BT");
        puts("Enter 5 : END");
        puts("Enter your choice");
        scanf("%d", &selection);
        if ((selection < 1|| selection > 5))
        {
            puts("Wrong Choice : Try Again");
            getchar();
        }
    } while ((selection < 1) || (selection > 5));
    return (selection);
}


node *insert(node *p, long digit){
    if (p == NULL){
        p = (node*)malloc(sizeof(node));
        p->left = p->right = NULL;
        p->num = digit;
        count++;
    }
    else if (count % 2 == 0)
        p->left = insert(p->left, digit);
    else
        p->right = insert(p->right, digit);
    return (p);
}

// Inorder Technique (LNR)
void inorder(node* root){
    if (root != NULL){
        inorder(root->left);
        printf("%d\n", root->num);
        inorder(root->right);
    }
}


// PreOrder Technique (NLR)
void preorder(node* root){
    if (root != NULL){
        printf("%d\n", root->num);
        preorder(root->left);
        preorder(root->right);
    }
}


// PostOrder Traversal (LRN)
void postorder(node* root){
    if (root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d\n", root->num);
    }
}
