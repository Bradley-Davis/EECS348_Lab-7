#include "football.h"
#include <stdio.h>

void print_combinations(int points);

int main() {
    int points = 2;
    while (points>1){
        printf("Enter the total points: ");
        scanf("%d", &points);

        print_combinations(points);
    }

    return 0;
}