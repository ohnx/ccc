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

int findPath(int d) {
    int i, t = 0;
    if (d == 7000) return 1;
    for (i = 0; i < c; i++) {
        if (between(min, stops[i] - d, max)) {
            t += findPath(stops[i]);
        }
    }
    return t;
}

int main() {
    int dOriginal[15] = {0, 0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
    int n, i;
    
    scanf("%d", &min);
    scanf("%d", &max);
    scanf("%d", &n);
    
    if (n == 0) {
        stops = dOriginal;
    } else {
        stops = calloc(n+15, sizeof(int));
        memcpy(stops, dOriginal, 15*sizeof(int));
    }
    
    c = n+15;
    
    for (i = 0; i< n; i++) {
        scanf("%d", &stops[i+15]);
    }
    
    printf("%d\n", findPath(0));
    
    return 0;
}