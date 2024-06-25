#include <stdio.h>

int date_check(int d, int m, int y){
    if (m <= 12){
        int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
        if (days[m - 1]>=d)
            return 0;
        else if(m == 2 && d == 29) {
            if ((y%4 == 0 && y%100 != 0) || (y%100 == 0 && y%400 == 0)) return 0;
        }
    }
    return 1;
}

int day() {
    int day, month, year;
    printf("Enter date (DD MM YYYY): ");
    scanf("%d %d %d", &day, &month, &year);
    int d = day, m = month, y = year;
    if (date_check(d,m,y)){
        printf("INVALID DATE");
        return 0;
    }
    int weekday;

    if (m < 3) {
        m += 12;
        y -= 1;
    }

    weekday = (d + (m * 2) + (3 * (m + 1) / 5) + y + (y / 4) - (y / 100) + (y / 400)) % 7;
    char days[7][10] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday","Sunday"};
    printf("%s\n", days[weekday]);
    return 0;
}


int main(){
    while (1){
        day();
    }
    return 0;
}