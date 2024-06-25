/*
To create a simple C program for temperature conversion, I'll assume you're looking for a
program that converts temperature from Fahrenheit to Celsius (and vice versa) based on
the user's choice. Here's a concise example:
*/
#include <stdio.h>

void FahrenheitToCelsius(float temp) {
	float celsius = (temp - 32) * 5 / 9;
	printf("%.2f Fahrenheit = %.2f Celsius\n", temp, celsius);
}

void CelsiusToFahrenheit(float temp) {
	float fahrenheit = (temp * 9 / 5) + 32;
	printf("%.2f Celsius = %.2f Fahrenheit\n", temp, fahrenheit);
}

int main() {
	int choice;
	float temp;
	printf("Temperature Conversion\n");
	printf("1: Fahrenheit to Celsius\n");
	printf("2: Celsius to Fahrenheit\n");
	printf("Enter your choice (1 or 2): ");
	scanf("%d", &choice);
	switch (choice) {
		case 1:
			printf("Enter temperature in Fahrenheit: ");
			scanf("%f", &temp);
			FahrenheitToCelsius(temp);
			break;
		case 2:
			printf("Enter temperature in Celsius: ");
			scanf("%f", &temp);
			CelsiusToFahrenheit(temp);
			break;
		default:
			printf("Invalid choice.\n");
	}
	return 0;
}
