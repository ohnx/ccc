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
    static int maxNeeded[26];
    static int countsW2[26];
    int i, j, mw1, mw2, N;
    char *cc, w1[256], w2[256];
    int *letterCountsW;
    
    // io setup
#ifndef __DEBUG
    FILE *in = fopen("blocks.in", "r");
    FILE *out =  fopen("blocks.out", "w");
#endif
    fscanf(in, "%d", &N);
    
    // allocate memory for all the word counts
    letterCountsW = calloc(N, sizeof(int)*26);
    
    for (i = 0; i < N; i++) {
        // read in word
        fscanf(in, "%255s %255s", w1, w2);
        
        mw1 = strlen(w1);
        mw2 = strlen(w2);
        
        // count letters in w1
        cc = w1;
        for (j = 0; j < mw1; j++) {
            *(letterCountsW+i*26 + (*cc - 'a')) += 1; // 2-d array, we move by the offset and add letter.
            cc++;
        }
        
        // count letters in w2
        cc = w2;
        for (j = 0; j < mw2; j++) {
            countsW2[*cc - 'a'] += 1; // 1-d array, we only add letter.
            cc++;
        }
        
        debug("for word 1 %s, there are %d a's\n", w1, *(letterCountsW+i*26));
        debug("for word 2 %s, there are %d a's\n", w2, *(letterCountsW+i*26));
        debug("for word pair %s %s, there are %d a's\n", w1, w2, *(letterCountsW+i*26));
        
        // set to the larger one for each
        for (j = 0; j < 26; j++) {
            if (*(letterCountsW+i*26 + j) < countsW2[j]) {
                // stored value is less than the count of this letter for the other word, so replace it
                *(letterCountsW+i*26 + j) = countsW2[j];
                debug("incr count for %c to %d\n", j+'a', *(letterCountsW+i*26 + j));
            } // if not, no need to change, as it is already in memory
        }
        
        debug("for word pair %s %s, there are %d a's\n", w1, w2, *(letterCountsW+i*26));
    
        // clear current counts
        memset(countsW2, 0, sizeof(int)*26);
    }
    
    // sum up all the countsW for each letter
    for (i = 0; i < 26; i++) { // for all the letters
        for (j = 0; j < N; j++) { // look through all the letter counts
            maxNeeded[i] += *(letterCountsW+j*26 + i); // and add
        }
    }
    
    for (i = 0; i < 26; i++) {
        fprintf(out, "%d\n", maxNeeded[i]);
    }
    
    // clean up
    free(letterCountsW);
#ifndef __DEBUG
    fclose(in);
    fclose(out);
#endif
    return 0;
}