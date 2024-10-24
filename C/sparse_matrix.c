# include <stdio.h>
# include <stdlib.h>

struct node{
    int row;
    int column;
    int value;
    struct node* next;
};

struct node* createNode(int row, int col, int value){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->row = row;
    new->column = col;
    new->value = value;
    new->next = NULL;
    return new;
}

struct node* insertAtEnd(struct node* head,int row, int col, int value){
    if (head == NULL){
        return createNode(row, col, value);
    }
    else {
        struct node* temp = head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = createNode(row, col, value);
        return head;
    }
}

int main(){
    int mat1[4][5] = {{0,0,3,0,4}, {0,0,5,7,0}, {0,0,0,0,0},{0,2,6,0,0}};
    struct node* head = NULL, *temp;
    temp = head;
    for (int i = 0; i<4; i++){
        for (int j = 0; j < 5; j++){
            if (mat1[i][j]!=0){
                head = insertAtEnd(head, i, j, mat1[i][j]);
            }
        }
    }
    temp = head;
    while (temp!=NULL){
        printf("%d, %d [%d] -> ", temp->row, temp->column, temp->value);
        temp = temp->next;
    }
    return 0;
}