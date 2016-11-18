#include <stdio.h>
#include <stdlib.h>

static int inviteCount[7]; // 7 because i don't want to use 0-started array

static int numPeople;

int possibleForN(int N) { // possible ways for people who have invited N others
    int i, validPeopleCount = 0;
    printf("N = %d\n", N);
    for (i = 1; i < numPeople; i++) {
        if (inviteCount[i] == N) validPeopleCount++;
        if (inviteCount[i] == N) printf("\tinviteCount[%d] == %d\n", i, N);
        else printf("\tinviteCount[%d] != %d (= %d)\n", i, N, inviteCount[i]);
    }
    printf("N = %d has %d people\n", N, validPeopleCount);
    // hardcoded to save time
    switch (validPeopleCount) {
        case 0:
        return 0;
        case 1:
        return 1;
        case 2:
        return 3;
        case 3:
        return 6;
        case 4:
        return 10;
        case 5:
        return 15;
        case 6:
        return 21;
        default:
        return 0;
    }
}

int main() {
    int N, i, j;
    
    // set up everything
    scanf("%d", &N);
    
    // get which friend invited who
    for (i = 1; i < N; i++) {
        scanf("%d", &j);
        inviteCount[j]++;
    }
    
    numPeople = N;
    j = 1; // j = 1 since case where none are removed and all are removed
    for (i = 0; i <= numPeople; i++) {
        N = possibleForN(i);
        j += N;
        printf("incr %d (total %d)\n", N, j);
    }
    printf("%d", j);
    return 0;
}