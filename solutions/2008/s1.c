#include <stdio.h>
#include <string.h>

int main() {
    static char a[257];
    static char t[257];
    int minT = 220, n = 0;
    
    while (strcmp(a, "Waterloo") != 0) {
        scanf("%s %d", a, &n);
        if (n < minT) {
            minT = n;
            strcpy(t, a);
        }
    }
    
    printf("%s\n", t);
    
    return 0;
}
