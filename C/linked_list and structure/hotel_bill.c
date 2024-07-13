#include <stdio.h>
#include <stdlib.h>

typedef struct rcrds{
    char name[30];
    long long mobile;
    int no;
    char type[7]; // 1 for AC 2 for Non AC
    float charge;
    struct date{
        int day;
        int month;
        int year;
    }check_in,check_out;
}brec;

int main() {
    brec arr[1000];
    int n;
    scanf("%d",&n);
    for (int i = 0; i<N; i++){
        scanf("%s %lld %d %s %f %s %d/%d/%d",brec[i].name, &brec[i].mobile, &brec[i].no, brec[i].type, &brec[i].check_in.day, &brec[i].check_in.month, &brec[i].check_in.year,&brec[i].check_out.day, &brec[i].check_out.month, &brec[i].check_out.year);
    }
    
}
