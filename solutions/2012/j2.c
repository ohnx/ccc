#include <stdio.h>

int main() {
    int a, b, c, d;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);
    if ((a < b) && (b < c) && (c < d)) {
        printf("Fish Rising\n");
    } else if ((d < c) && (c < b) && (b < a)) {
        printf("Fish Diving\n");
    } else if ((a == b) && (b == c) && (c == d)) {
        printf("Fish At Constant Depth\n");
    } else {
        printf("No Fish\n");
    }
    return 0;
}