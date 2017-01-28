/*
 * 2016 CCC Junior P4
 * Simple user input processing, a dab of object-orientedness, and then some loops.
 * 
 * Mason X (ohnx) was here (2016)
 */
#include <stdio.h>

// custom time struct
typedef struct _time {
    int h, m;
} time;

// helper function to print time
void printTime(time *t) {
    if (t->h == 0) printf("00");
    else if (t->h < 10) printf("0%d", t->h);
    else printf("%d", t->h);

    printf(":");

    if (t->m == 0) printf("00");
    else if (t->m < 10) printf("0%d", t->m);
    else printf("%d", t->m);

    printf("\n");
}

// add some minutes to a time
void addTime(time *t, int mins) {
    t->m += mins;
    while (t->m >= 60) {
        t->m -= 60;
        t->h++;
    }
    if (t->h >= 24) {
        t->h -= 24;
    }
}

int main() {
    int hdep, mdep, fakeTimeTraveled = 0;
    time departTime = {0,0};
    time *t = &departTime;

    // scan in time
    scanf("%d:%d", &hdep, &mdep);
    departTime.h = hdep;
    departTime.m = mdep;

    while (fakeTimeTraveled < 120) {
        if ((t->h >= 7) && (t->h < 10) || (t->h >= 15) && (t->h < 19)) {
            // Rush hour time so it's only 1/2 as efficient
            fakeTimeTraveled += 5;
            addTime(t, 10);
        } else {
            // Normal time so it's 100% efficient
            fakeTimeTraveled += 10;
            addTime(t, 10);
        }
    }

    // print the time
    printTime(&departTime);

    return 0;
}