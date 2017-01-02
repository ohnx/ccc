#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define __DEBUG

#ifdef __DEBUG
#define in stdin
#define out stdout
#define debug(...) do { printf(__VA_ARGS__); fflush(stdout); } while (0)
#endif

#ifndef __DEBUG
#define debug(...)
#endif

int main() {
    // variable setup
    int K, M, N, i, j;
    char *input, *output, *ccp;
    
    // io setup
#ifndef __DEBUG
    FILE *in = fopen("cowsignal.in", "r");
    FILE *out =  fopen("cowsignal.out", "w");
#endif
    fscanf(in, "%d %d %d", &M, &N, &K);
    
    // allocate memory for input and output
    input = calloc(N+1, sizeof(char)); // 1-d array: line with a length of N+1 (null terminator).
    output = calloc(N*K+1, sizeof(char)); // 1-d array: line with a length of K*N+1 (null terminator).
                                            // note that the reason why we can do this is since we can print each
                                            // line of this string K times. saves some memory!
    
    // read in the input
    for (i = 0; i < M; i++) { // loop for each line of input
        fscanf(in, "%s", input);
        
        // figure out the expanded string
        ccp = output; // move the char pointer to the start of the string again
        for (j = 0; j < N; j++) { // loop for each character in input
            memset(ccp, *(input+j), sizeof(char)*K); // set K characters in the output to be whatever the input was
            ccp += K; // move on by K characters
        }
        
        // print out K times
        for (j = 0; j < K; j++) {
            fprintf(out, "%s\n", output);
        }
    }

    // clean up
    free(input);
    free(output);
#ifndef __DEBUG
    fclose(in);
    fclose(out);
#endif
    return 0;
}