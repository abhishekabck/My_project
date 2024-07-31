#include <stdio.h>
#include <stdlib.h>

/*
Create a C program using structure to store the records of N students.
Each record must contain the following fields: {Roll_No, Name, Year, Branch, Marks}.
Your task is to print the record of the Topper student and the average marks obtained.
*/

typedef struct student {
    int roll;
    char name[30];
    short int year;
    char branch[10];
    int marks;
} stdnt;

int main() {
    // Opning Destination file
    FILE* storage;
    storage = fopen("records.txt","a");

    if (storage == NULL){
        printf("File Does Not Found");
        exit(0);
    }

    stdnt records[1000];
    // Insertion
    int N, t_marks = -1, index = -1, sum = 0;
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        scanf("%d %s",&records[i].roll, records[i].name);
        scanf("%hd %s %d",&records[i].year, records[i].branch, &records[i].marks);
        fprintf(storage,"%d %s %hd %s %d\n",records[i].roll, records[i].name, records[i].year, records[i].branch, records[i].marks);

    }

    fclose(storage);
    printf("\nRecords Stored SuccessFully!");

}
