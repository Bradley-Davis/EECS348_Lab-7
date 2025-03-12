#include "report.h"
#include <stdio.h>
//initialize functions
void print_tempurature(int temp, int curr, int out);
void categorize_temperature(float celsius);
//start main function
int main(int argc, char *argv[]) {
    int temp;//initialize variables
    int curr;
    int out;

    while (1) {//repeat forever
        printf("Enter the Temperature: ");//get the starting temp
        scanf("%d", &temp);

        printf("Choose the current scale (1) Fahrenheit, (2) Celsius, (3) Kelvin: ");//get the current unit
        scanf("%d", &curr);

        printf("Convert to (1) Fahrenheit, (2) Celsius, (3) Kelvin: ");//get target unit
        scanf("%d", &out);

        print_tempurature(temp, curr, out);//run the calculator
    }

    return 0;//end main
}