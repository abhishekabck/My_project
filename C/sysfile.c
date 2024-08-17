# include <stdio.h>

FILE* in = fopen("input.txt","r");
FILE* out = fopen("output.txt","w");


int readint(){
    int num;
    if (fscanf(in,"%d",&num) != 1){
        printf("Error Reading Integer");
    }
    return num;
}

void writeint(int x){
    fprintf(out,"%d",x);
}