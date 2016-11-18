#include <stdio.h>

int main() {
    int K, i = 1;
    char arr[21];
    char *curr;
    scanf("%d", &K);
    scanf("%20s", arr);
    curr = arr;
    while(*curr != '\0') {
        *curr -= 3*i + K;
        if(*curr < 65) {
            *curr += 26;
        }
        i++;
        curr++;
    }
    printf("%s\n", arr);
}
