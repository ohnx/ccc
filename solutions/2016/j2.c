/*
 * 2016 CCC Junior P2
 * Simple user input processing, and then many if statements.
 * 
 * Mason X (ohnx) was here (2016)
 */
#include <stdio.h>

int main() {
    int square[4][4];
    int magicnum;
    // Read in square
    scanf("%d %d %d %d", &square[0][0], &square[0][1], &square[0][2], &square[0][3]);
    scanf("%d %d %d %d", &square[1][0], &square[1][1], &square[1][2], &square[1][3]);
    scanf("%d %d %d %d", &square[2][0], &square[2][1], &square[2][2], &square[2][3]);
    scanf("%d %d %d %d", &square[3][0], &square[3][1], &square[3][2], &square[3][3]);
    // Calculate magic number
    magicnum = square[0][0] + square[0][1] + square[0][2] + square[0][3];
    // large amount of if statements to check each row
    if (square[1][0] + square[1][1] + square[1][2] + square[1][3] != magicnum) goto invalid;
    if (square[2][0] + square[2][1] + square[2][2] + square[2][3] != magicnum) goto invalid;
    if (square[3][0] + square[3][1] + square[3][2] + square[3][3] != magicnum) goto invalid;
    // and each col
    if (square[0][0] + square[1][0] + square[2][0] + square[3][0] != magicnum) goto invalid;
    if (square[0][1] + square[1][1] + square[2][1] + square[3][1] != magicnum) goto invalid;
    if (square[0][2] + square[1][2] + square[2][2] + square[3][2] != magicnum) goto invalid;
    if (square[0][3] + square[1][3] + square[2][3] + square[3][3] != magicnum) goto invalid;
    // reached here, it's magic!
    printf("magic\n");
    goto end;
invalid:
    printf("not magic\n");
end:
    return 0;
}