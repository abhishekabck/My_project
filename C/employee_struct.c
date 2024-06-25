# include <stdio.h>

int main(){
    struct employee{
        int emp_id;
        char emp_name[30];
        float emp_salary;
    };
    struct employee emps[5] = {
        {1, "David", 35000},
        {2, "Raina", 45900},
        {3, "Ram", 10000},
        {4, "Abhishek", 50000},
        {5, "Rishi", 53555}
    };
    printf("Employee details:- ");
    printf("\nEmployee No, Employee Name, Employee Salary");
    for (int i = 0; i<5; i++){
        printf("\n     %d \t ,   %s \t,   %f\t",emps[i].emp_id, emps[i].emp_name, emps[i].emp_salary);

    }
    return 0;
}