/*
 * 2016 CCC Junior P1
 * Simple user input processing, and then switch statements.
 * 
 * Mason X (ohnx) was here (2016)
 */
#include <stdio.h>

int main() {
    int i, Ws = 0;
    char in;
    for (i = 0; i < 6; i++) {
        scanf(" %c", &in); // get W or L
        if (in == 'W') { // check if won
            Ws++;
        }
    }
    // Switch statement
    switch (Ws) {
    case 5:
    case 6:
        printf("1\n");
        break;
    case 3:
    case 4:
        printf("2\n");
        break;
    case 1:
    case 2:
        printf("3\n");
        break;
    case 0:
        printf("-1\n");
        break;
    }

    return 0;
}