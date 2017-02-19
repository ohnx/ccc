#include <stdio.h>

int main() {
    int i, N;
    char input[101], *p;
    unsigned int tC = 0, sC = 0;
    
    fgets(input, 101, stdin);
    sscanf(input, "%d", &N);
    
    for (i = 0; i < N; i++) {
        // get input line by line
        fgets(input, 101, stdin);
        
        p = input;
        // loop through entire string
        while (*p > 0) {
            // incr counters if necessary
            if (*p == 't' || *p == 'T') tC++;
            else if (*p == 's' || *p == 'S') sC++;
            p++;
        }
    }
    
    if (tC > sC) printf("English\n");
    else printf("French\n");
    
    return 0;
}
