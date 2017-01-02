#include <stdio.h>

//#define __DEBUG

#ifdef __DEBUG
#define in stdin
#define out stdout
#endif

int main() {
    // variable setup
    int x1, y1, x2, y2, dx, dy;
    int minX, maxX, minY, maxY;
    
    // io setup
#ifndef __DEBUG
    FILE *in = fopen("square.in", "r");
    FILE *out =  fopen("square.out", "w");
#endif
    
    // square one - save directly
    fscanf(in, "%d %d %d %d", &minX, &minY, &maxX, &maxY);
    
    // square two - save in temporary variables
    fscanf(in, "%d %d %d %d", &x1, &y1, &x2, &y2);
    
    if (x1 < minX) minX = x1;
    if (y1 < minY) minY = y1;
    if (x2 > maxX) maxX = x2;
    if (y2 > maxY) maxY = y2;
    
    dx = maxX-minX;
    dy = maxY-minY;
    
    if (dx < dy) dx = dy;
    
    fprintf(out, "%d\n", dx*dx);
    
#ifndef __DEBUG
    fclose(in);
    fclose(out);
#endif
    return 0;
}