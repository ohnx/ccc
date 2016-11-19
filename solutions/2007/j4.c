#include <stdio.h>

int main() {
    static int counts[256];
    static char in[512];
    char *p;
    int i;
    
    fgets(in, 511, stdin);
    p = in;
    
    /* increase the count of a certain letter
     * the end result is that we will have an array
     * with the # of letters in the first string
     */
    while (*p != '\0') {
        counts[*p]++;
        p++;
    }
    
    fgets(in, 511, stdin);
    p = in;
    
    /* for the second one, we want to decrease
     * all the characters. If, at the end, there
     * are any letters that are not 0, the
     * input string was not an anagram.
     */
    while (*p != '\0') {
        counts[*p]--;
        p++;
    }
    
    /* loop through character counts and check
     * to make sure they all = 0
     */
    for (i = 'A'; i <= 'Z'; i++) {
        if (counts[i] != 0) {
            /* not an anagram */
            printf("Is not an anagram.\n");
            return 0;
        }
    }
    
    /* went through the entire array with no problem */
    
    printf("Is an anagram.\n");
    return 0;
}