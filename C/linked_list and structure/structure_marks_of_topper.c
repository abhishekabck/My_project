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
    stdnt records[1000];
    // Insertion
    int N, t_marks = -1, index = -1, sum = 0;
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        scanf("%d %s %hd %s %d", &records[i].roll, records[i].name, &records[i].year, records[i].branch, &records[i].marks);
        if (records[i].marks > t_marks) {
            t_marks = records[i].marks;
            index = i;
        }
        sum += records[i].marks;
    }
    
    if (index != -1) {
        printf("Topper Student Record:\n");
        printf("%d %s %hd %s %d\n", records[index].roll, records[index].name, records[index].year, records[index].branch, records[index].marks);
        printf("Average Marks: %.2f\n", (float)sum / N);
    } else {
        printf("No records found.\n");
    }
    
    return 0;
}
