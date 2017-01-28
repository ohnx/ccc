/*
 * 2016 CCC Junior P5
 * User input processing, dynamic memory allocation, sorting, and then loops.
 * 
 * dmoj vs PEG - which grader will win? (Certainly can't be Waterloo's since it was down...)
 * 
 * Mason X (ohnx) was here (2016)
 */
#include <stdio.h>
// quicksort and memory allocation
#include <stdlib.h>

int *dmoj, *peg;
int N;

// helper functions for quicksort
int increasing(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int decreasing(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int max(int a, int b) {
    return (a > b)? a : b;
}

// we want to pair biggest and biggest in each pair
int minPair() {
    int i, minTotal = 0;
    qsort(dmoj, N, sizeof(int), increasing);
    qsort(peg, N, sizeof(int), increasing);
    for (i = 0; i < N; i++) {
        minTotal += max(dmoj[i], peg[i]);
    }
    return minTotal;
}

// we want to pair biggest with smallest
int maxPair() {
    int i, maxTotal = 0;
    qsort(dmoj, N, sizeof(int), increasing);
    qsort(peg, N, sizeof(int), decreasing);
    for (i = 0; i < N; i++) {
        maxTotal += max(dmoj[i], peg[i]);
    }
    return maxTotal;
}

int main() {
    int i, caseNum;

    // Scan in data
    scanf("%d", &caseNum);
    scanf("%d", &N);

    // Allocate memory
    dmoj = malloc(sizeof(int) * N);
    peg = malloc(sizeof(int) * N);

    // Read in data
    for (i = 0; i < N; i++)
        scanf("%d", &dmoj[i]);
    for (i = 0; i < N; i++)
        scanf("%d", &peg[i]);

    if (caseNum == 1) printf("%d\n", minPair());
    else printf("%d\n", maxPair());

    free(dmoj);
    free(peg);
    return 0;
}