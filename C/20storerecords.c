# include <stdio.h>
# include <stdlib.h>


int main(){
    //Initialization of Variables
    int num;
    unsigned int roll_no, marks;
    char name[30], branch[10];

    // Taking number of records as Input
    printf("Enter the number of records you wish to enter:-");
    scanf("%d", &num);

    // Declaring File pointer and opninig file record.doc
    FILE* fp = fopen("record.doc", "w");
    if (fp == NULL) {
        printf("File does not exist.");
        exit(0);
    }

    // Taking records from user and recording them in record.doc
    while (num--){
        printf("\nEnter Your Roll No:- ");
        scanf("%d", &roll_no);
        printf("\nEnter your name:- ");
        scanf("%s", name);
        printf("\nEnter Your Branch:- ");
        scanf("%s", branch);
        printf("Enter Your Marks:- ");
        scanf("%d", &marks);
        fprintf(fp,"%d %s %s %d\n",roll_no, name, branch, marks);
    }

    printf("Data Recorded SuccessFully.");
    fclose(fp);
    return 0;
}