#include <stdio.h>

int main() {
    char data[3][3] = {{'*', 'x','*'},{' ', 'x','x'},{'*', ' ','*'}};
    int scaling, i, j, k, l;
    scanf("%d", &scaling);
    // loop for 3 rows
    for (i = 0; i < 3; i++) {
        // loop for scaling times the amount of rows
        for (j = 0; j < scaling; j++) {
            // loop for going through each of the 3 numbers
            for(k = 0; k < 3; k++) {
                // loop for scaling scaling times
                for(l = 0; l < scaling; l++) {
                    printf("%c", data[i][k]);
                }
            }
            printf("\n");
        }
    }
}