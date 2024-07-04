# include <stdio.h>
# include <stdlib.h>
struct node{
    int data;
    struct node* address;
    struct dob{
        int month;
        int year;
    }d;
}node1,node2;

int main(){
    node1.data = 10;
    node2.data = 20;
    node1.d.month = 10;
    node1.d.year = 2004;
    node1.address = &node2;
    node2.d.month = 12;
    node2.d.year = 2006;
    printf("%d %d %d \n%d %d %d",node1.data,node1.d.month, node1.d.year, node1.address->data, node1.address->d.month, node1.address->d.year);
    return 0;
}
