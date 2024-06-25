# include <stdio.h>

int main() {
    short int n_array[5], cp = 0, total = 0;

    // Storing Marks in an Array
    scanf("%d %d %d %d %d",&n_array[0], &n_array[1], &n_array[2], &n_array[3], &n_array[4]);

    // Checking Validity of Numbers
    for (int i = 0; i<5; i++){
        if (n_array[i]>100 || n_array[i]<0) {
            printf("INVALID MARKS");
            return 0;
        }
        if (n_array[i]<30) {
            cp++;
        }
        total += n_array[i];
    }

    float perc = total/5;
    if (perc>=(float)75){
        printf("Pass First division %.1f CP:%d", perc, cp);
    }
    else if (perc>=(float)60){
        printf("Pass Second division %.1f CP:%d", perc, cp);
    }
    else if (perc>=(float)33){
        printf("Pass Third division %.1f CP:%d", perc, cp);
    }
    else printf("Fail");
    return 0;
}