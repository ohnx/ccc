#include <stdio.h>

#define y() printf("Yes\n");
#define n() printf("No\n");

int main() {
    int n, i;
    int y, m, d;
    
    /* read in n */
    scanf("%d", &n);
    
    /* loop */
    for (i = 0; i < n; i++) {
        scanf("%d %d %d", &y, &m, &d);
        if (2007-y > 18) {
            /* person is definitely older */
            y()
        } else if (2007-y < 18) {
            /* person is definitely younger */
            n()
        } else {
            /* need to check further; year is right */
            if (2-m > 0) {
                /* month has happened already; person is definitely older */
                y()
            } else if (2-m < 0) {
                /* month has not happened; person is definitely younger */
                n()
            } else {
                if (27-d >= 0) {
                    /* day already happened */
                    y()
                } else {
                    n()
                }
            }
        }
    }
    
    return 0;
}