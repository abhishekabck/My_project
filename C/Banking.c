# include <stdio.h>




int main(){
    int choice1;
    char* record[5]; // Format = Name, Account_no, Balance = 0, DOB, AGE,
    printf("Choices:-\n1.For Banking\n2.For DBMS\n3.For Networking\n");
    scanf("%d", &choice1);
    switch (choice1){
        case 1:
            banking();
        case 2:
            DBMS();
        case 3:
            Networking();
    }
}