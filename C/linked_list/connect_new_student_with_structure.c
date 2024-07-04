# include <stdio.h>
# include <stdlib.h>

struct student{
    int roll_no;
    struct student *address;
}s1,s2;

int main(){
    s1.roll_no = 10;
    s2.roll_no = 20;
    printf("%d\n",s1.roll_no);
    s1.address = &s2;
    printf("%d\n",s1.address->roll_no);
    return 0;
}
