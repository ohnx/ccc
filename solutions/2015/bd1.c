#include <stdio.h>

int main() {
    static int a[101];
    
    int s, e, i, c;
    
    FILE *in = fopen("paint.in", "r");
    FILE *out =  fopen("paint.out", "w");
    
    fscanf(in, "%d", &s);
    fscanf(in, "%d", &e);
    
    for (i = s; i < e; i++) {
        a[i] = 1;
    }
    
    fscanf(in, "%d", &s);
    fscanf(in, "%d", &e);
    
    for (i = s; i < e; i++) {
        a[i] = 1;
    }
    
    for (i = 0; i < 101; i++) {
        c += a[i];
    }
    
    fprintf(out, "%d\n", c);
    
    fclose(in);
    fclose(out);
}