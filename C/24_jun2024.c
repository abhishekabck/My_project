// Linked list
#include <stdio.h>
# include <conio.h>
# include <string.h>
/*
struct student{
    char name;
    int roll_no;

};

int main(){
    struct student s1;
    s1.name = '3';
    s1.roll_no = 40004;
    printf("%c",s1.name);
    printf("%d",s1.roll_no);
    return 0;
}

*/

int main(){
    struct student{
        int rollno;
        char name[20];
        float totalmarks;
    };
    struct student s1 = {1,"Ram",95};
    printf("%d, %s, %f",s1.rollno, s1.name, s1.totalmarks);
}
