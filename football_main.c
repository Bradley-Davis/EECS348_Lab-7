#include "football.h"
#include <stdio.h>

void print_combinations(int points);

int main() {
    int points;

    printf("Enter the total points: ");
    scanf("%d", &points);

    print_combinations(points);

    return 0;
}