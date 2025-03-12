#include "football.h"
#include <stdio.h>

static int results[1000][5]; 
static int count = 0;      

int count_combinations(int points) {
    count = 0; 

    for (int tds2 = 0; tds2 * 8 <= points; tds2++) {  
        for (int tds1 = 0; tds2 * 8 + tds1 * 7 <= points; tds1++) {  
            for (int tds = 0; tds2 * 8 + tds1 * 7 + tds * 6 <= points; tds++) {  
                for (int fg = 0; tds2 * 8 + tds1 * 7 + tds * 6 + fg * 3 <= points; fg++) {
                    for (int sf = 0; tds2 * 8 + tds1 * 7 + tds * 6 + fg * 3 + sf * 2 <= points; sf++) { 
                        if (tds2 * 8 + tds1 * 7 + tds * 6 + fg * 3 + sf * 2 == points) {
                            results[count][0] = tds2;
                            results[count][1] = tds1;
                            results[count][2] = tds;
                            results[count][3] = fg;
                            results[count][4] = sf;
                            count++;
                        }
                    }
                }
            }
        }
    }
    return count;
}

void print_combinations(int points) {
    int i;
    int num_combinations = count_combinations(points);

    for (i = 0; i < num_combinations; i++) {
        
        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
               results[i][0], results[i][1], results[i][2], results[i][3], results[i][4]);
    }
}