#include <stdio.h>
#include <string.h>

int main() {
    static char c[513];
    
    while (1) {
        scanf("%s", c);
        
        cptr = c;
        
        /* simmply check for each string. */
        if (strcmp(c, "CU") == 0) {
            printf("see you\n");
        } else if (strcmp(c, ":-)") == 0) {
            printf("I'm happy\n");
        } else if (strcmp(c, ":-(") == 0) {
            printf("I'm unhappy\n");
        } else if (strcmp(c, ";-)") == 0) {
            printf("wink\n");
        } else if (strcmp(c, ":-P") == 0) {
            printf("stick out my tongue\n");
        } else if (strcmp(c, "(~.~)") == 0) {
            printf("sleepy\n");
        } else if (strcmp(c, "TA") == 0) {
            printf("totally awesome\n");
        } else if (strcmp(c, "CCC") == 0) {
            printf("Canadian Computing Competition\n");
        } else if (strcmp(c, "CUZ") == 0) {
            printf("because\n");
        } else if (strcmp(c, "TY") == 0) {
            printf("thank-you\n");
        } else if (strcmp(c, "YW") == 0) {
            printf("you're welcome\n");
        } else if (strcmp(c, "TTYL") == 0) {
            printf("talk to you later\n");
            break;
        } else {
            printf("%s\n", c);
        }
    }
    return 0;
}