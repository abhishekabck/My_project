#include <stdio.h>
#include <math.h>

// Define the date structure
typedef struct {
    int day;
    int month;
    int year;
} Date;

// Array to store the number of days in each month for non-leap years
int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Function to check if a year is a leap year
int isLeapYear(int year) {
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        return 1;
    }
    return 0;
}

// Function to count the number of days from the beginning of the year to a given date
int countDaysInYear(Date date) {
    int count = 0;
    for (int i = 0; i < date.month - 1; i++) {
        count += daysInMonth[i];
    }
    count += date.day;

    // Add one day if the date is in a leap year and after February
    if (isLeapYear(date.year) && date.month > 2) {
        count += 1;
    }

    return count;
}

// Function to count the total number of days from 01/01/0000 to a given date
long totalDays(Date date) {
    long total = 0;

    // Add the days for the complete years before the given year
    for (int i = 0; i < date.year; i++) {
        total += 365;
        if (isLeapYear(i)) {
            total += 1;
        }
    }

    // Add the days in the current year up to the given date
    total += countDaysInYear(date);

    return total;
}

// Function to calculate the number of days between two dates
int daysBetweenDates(Date date1, Date date2) {
    long days1 = totalDays(date1);
    long days2 = totalDays(date2);

    return abs(days2 - days1);
}

int main() {
    Date date1, date2;

    // Input the first date
    printf("Enter the first date (dd mm yyyy): ");
    scanf("%d %d %d", &date1.day, &date1.month, &date1.year);

    // Input the second date
    printf("Enter the second date (dd mm yyyy): ");
    scanf("%d %d %d", &date2.day, &date2.month, &date2.year);

    // Calculate the number of days between the two dates
    int days = daysBetweenDates(date1, date2);

    // Output the result
    printf("Number of days between the two dates: %d\n", days);

    return 0;
}
