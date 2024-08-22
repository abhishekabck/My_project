# include <stdio.h>
# include <stdlib.h>

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
    fprintf(out,"%d ",x);
}

void nl(void){
    fprintf(out, "\n");
}

int** allocateArray(int rows, int cols) {
    int** arr = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        arr[i] = (int*)malloc(cols * sizeof(int));
    }
    return arr;
}

void readArr(int** arr,int rows, int cols){
    for (int i = 0; i <  rows; i++) {
        for (int j = 0; j< cols; j++) {
            arr[i][j] =  readint();
        }
    }
}


void cusError(char* str){
    fputs("Error Raised:: ",out);
    fputs(str, out);
}