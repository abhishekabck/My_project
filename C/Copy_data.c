# include <stdio.h>
# include <string.h>
# include <stdlib.h>

/*
Program to copy data from one file to another file..
*/

int main(){
    FILE* fp, *fp1;
    fp1 = fopen("data.txt","r");  // File From which data is to be copied
    fp = fopen("test1.txt","w"); // Data paste
    if (fp == NULL || fp1 == NULL) {
        printf("Unable to open File..");
        exit(0);
    }
    char ch;
    while ((ch = fgetc(fp1)) != EOF){
        fputc(ch, fp);
    }
    printf("Data Pasted SuccessFully..");
    fclose(fp);
    fclose(fp1);
    return 0;
}