#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int hasCrystal(int m, int x, int y) {
    double scaledAmount;
    int xS, yS;
    
    // ending case
    if (m == 1) {
        if (y == 0 && (x == 1 || x == 2 || x == 3)) 1;
        else if (y == 1 && x == 2) 1;
        else return 0;
        // falls through to here
        return 1;
    } else {
        // calculate scaled amounts
        scaledAmount = pow(5, m-1);
        yS = (int)((double)y/scaledAmount);
        xS = (int)((double)x/scaledAmount);
        // in C, casts to int is equivalent of floor()
        
        // check for between the possible area on X (ie, 0 < x < 4)
        if (xS <= 0 || xS >= 4) return 0;
        
        // check for between the possible area on Y (ie, y < 3)
        if (yS >= 3) return 0;
        
        // if it's in (1, 3) or (3,3) it's definitely empty, too
        if (yS == 3 && (xS == 1 || xS == 3)) return 0;
        
        // at this point, if y = 0, it's definitely good.
        if (yS == 0) return 1;
        
        // if it's at (2,1) it's a crystal
        if (xS == 2 && yS == 1) return 1;
        
        // still don't know, so we hand it down to the next mangification level
        
        // recur by reducing magnification and scaling it down by whatever amount
        return hasCrystal(m-1, x % (int)scaledAmount, y % (int)scaledAmount);
    }
}

int main() {
    int T, m, x, y, i;

    scanf("%d", &T);
    
    for (i = 0; i < T; i++) {
        // get input line by line
        scanf("%d %d %d", &m, &x, &y);
        
        if (hasCrystal(m, x, y)) {
            printf("crystal\n");
        } else {
            printf("empty\n");
        }
    }

    return 0;
}
