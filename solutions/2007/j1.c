#include <stdio.h>

#define swap(x, y) do {t = x; x = y; y = t;} while(0);

int main() {
    int a, b, c;
    int t;
    
    /* scan in all the numbers */
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    
    /* order the numbers by swapping them */
    if (a > c) swap(a, c);
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    
    /* print out the middle number */
    printf("%d\n", b);
    
    return 0;
}