#include "football.h"
#include <stdio.h>

void print_combinations(int points);//initialize function

int main() {//start program
    int points = 2;//initialize minimum points
    while (points>1){//while the points is above 1 loop
        printf("Enter the total points: ");
        scanf("%d", &points);//read total points

        print_combinations(points);//do points calculations
    }

    return 0;//end main
}