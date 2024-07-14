#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char name[30];
    char mobile[11];
    int room_no;
    char type[7]; // "AC" or "Non AC"
    float charge;
    Date check_in;
    Date check_out;
} brec;

int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int isLeapYear(int year) {
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        return 1;
    }
    return 0;
}

int countDaysInYear(Date date) {
    int count = 0;
    for (int i = 0; i < date.month - 1; i++) {
        count += daysInMonth[i];
    }
    count += date.day;
    if (isLeapYear(date.year) && date.month > 2) {
        count += 1;
    }
    return count;
}

long totalDays(Date date) {
    long total = 0;
    for (int i = 0; i < date.year; i++) {
        total += 365;
        if (isLeapYear(i)) {
            total += 1;
        }
    }
    total += countDaysInYear(date);
    return total;
}

int daysBetweenDates(Date date1, Date date2) {
    long days1 = totalDays(date1);
    long days2 = totalDays(date2);
    return abs(days2 - days1);
}

int main() {
    brec arr[1000];
    int N;
    scanf("%d", &N);
    // Insertions 
    for (int i = 0; i < N; i++) {
        scanf("%s", arr[i].name);
        scanf("%s", arr[i].mobile);
        scanf("%d", &arr[i].room_no);
        scanf("%s", arr[i].type);
        scanf("%f", &arr[i].charge);
        scanf("%d/%d/%d", &arr[i].check_in.day, &arr[i].check_in.month, &arr[i].check_in.year);
        scanf("%d/%d/%d", &arr[i].check_out.day, &arr[i].check_out.month, &arr[i].check_out.year);
    }
    
    // Printing Bill
    for (int i = 0; i < N; i++) {
        int days = daysBetweenDates(arr[i].check_in, arr[i].check_out);
        printf("%s %s %d ", arr[i].name, arr[i].mobile, arr[i].room_no);
        printf("%02d/%02d/%04d ", arr[i].check_in.day, arr[i].check_in.month,arr[i].check_in.year);
        printf("%02d/%02d/%04d ", arr[i].check_out.day, arr[i].check_out.month, arr[i].check_out.year);
        printf("%.2f\n", days * arr[i].charge);
    }
    
    return 0;
}
