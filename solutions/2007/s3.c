#include <stdio.h>

static int friends[10000];

int isFriends(int f1, int f2) {
    int i = 0;
    int start = f1;
    
    /* keep going until we find that
     * the friend of this person is the one we're looking for
     */
    while (friends[f1] != f2) {
        f1 = friends[f1];
        if (f1 == 0) return -1; /* someone is friends with nobody */
        if (f1 == start) return -1; /* we have looped back... */
        i++;
        if (i > 10000) {
            /* seems like we got caught in a loop
             * or there is something else wrong
             * so return a negative number
             * (ie, no connection)
             */
            return -1;
        }
    }
    
    return i;
}

int main() {
    int n, i, f1, f2;
    
    /* read in # of pairs*/
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        /* pair up */
        scanf("%d %d", &f1, &f2);
        
        friends[f1] = f2;
    }
    
    /* start reading in user input */
    while (1) {
        scanf("%d %d", &f1, &f2);
        if (f1 == 0 && f2 == 0) {
            break;
        }
        /* call helper function */
        n = isFriends(f1, f2);
        if (n < 0) {
            /* helper function returns negative #
             * if there is no connection */
            printf("No\n");
        } else {
            printf("Yes %d\n", n);
        }
    }
    
    
    return 0;
}