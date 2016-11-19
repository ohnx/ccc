#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* note - I ended up using http://mmhs.ca/ccc/2007/j5recursion.txt
 * to help me solve this problem.
 */

#define between(a,b,c) ((a <= b) && (b <= c))

int *stops;
int c;
int min, max;

/* recursive solution since I don't know dynamic programming yet */
int findPath(int d) {
    int i, t = 0;
    /* the final distance has been reached */
    if (d == 7000) return 1;
    /* loop through all the possible distances */
    for (i = 0; i < c; i++) {
        /* check if the distance that will be
         * travelled is between the min and max
         * going backwards is excluded
         * since that will create a negative number
         */
        if (between(min, stops[i] - d, max)) {
            t += findPath(stops[i]);
        }
    }
    return t;
}

int main() {
    /* hardcoded original stops */
    int dOriginal[15] = {0, 0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
    int n, i;
    
    /* read in starting values */
    scanf("%d", &min);
    scanf("%d", &max);
    scanf("%d", &n);
    
    if (n == 0) {
        /* no additional stops */
        stops = dOriginal;
    } else {
        /* more stops, we need to allocate more memory 
         * to store everything
         */
        stops = calloc(n+15, sizeof(int));
        memcpy(stops, dOriginal, 15*sizeof(int));
    }
    
    /* total number of stops */
    c = n+15;
    
    /* read in all the extra stops */
    for (i = 0; i< n; i++) {
        scanf("%d", &stops[i+15]);
    }
    
    /* call helper function */
    printf("%d\n", findPath(0));
    
    return 0;
}