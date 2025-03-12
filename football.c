#include "football.h"
#include <stdio.h>
//initialize variables
static int results[10000][5]; 
static int count = 0;      

int count_combinations(int points) {//count the variations
    count = 0; 

    for (int tds2 = 0; tds2 * 8 <= points; tds2++) {  //determine the number of touch downs and 2 extra points
        for (int tds1 = 0; tds2 * 8 + tds1 * 7 <= points; tds1++) {  //determine the number of touch downs and 1 extra point
            for (int tds = 0; tds2 * 8 + tds1 * 7 + tds * 6 <= points; tds++) {  //determine the number of touch downs 
                for (int fg = 0; tds2 * 8 + tds1 * 7 + tds * 6 + fg * 3 <= points; fg++) {//determine the number of Field goals
                    for (int sf = 0; tds2 * 8 + tds1 * 7 + tds * 6 + fg * 3 + sf * 2 <= points; sf++) { //determine the number of safties
                        if (tds2 * 8 + tds1 * 7 + tds * 6 + fg * 3 + sf * 2 == points) {//check if the combination creates the desired output number
                            results[count][0] = tds2;//adds each amount to each category
                            results[count][1] = tds1;
                            results[count][2] = tds;
                            results[count][3] = fg;
                            results[count][4] = sf;
                            count++;//next iteration
                        }
                    }
                }
            }
        }
    }
    return count;//end function
}

void print_combinations(int points) {//print the valid combinations
    int i;
    int num_combinations = count_combinations(points);//initialize variabels

    for (i = 0; i < num_combinations; i++) {//for every combination
        
        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",//print the amount of each variable
               results[i][0], results[i][1], results[i][2], results[i][3], results[i][4]);
    }
}