#include <stdio.h>

int main() {
    int amnts[11] = {0, 100, 500, 1000, 5000, 10000, 25000, 50000, 100000, 500000, 1000000};
    int n, i, q, c = 10, a = 0, o;
    
    scanf("%d", &n);
    
    /* read in all the cases opened */
    for (i = 0; i < n; i++) {
        scanf("%d", &q);
        /* set the value of that case to 0, and total count decreases */
        amnts[q] = 0;
        c--;
    }
    
    scanf("%d", &o);
    
    /* go through all of the cases and sum up*/
    for (i = 1; i <= 10; i++) {
        a += amnts[i];
    }
    
    /* divide to find the average */
    a = a/c;
    
    /* if offer is less than average, no deal */
    if (o < a) printf("no ");
    printf("deal\n");
    
    return 0;
}