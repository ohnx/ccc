#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, N;
    char buf[16], *sto;
    unsigned int correct = 0;
    
    scanf("%d", &N);
    
    sto = malloc(sizeof(char) * N);
    
    for (i = 0; i < N; i++) {
        // get input line by line
        scanf("%s", buf);
        
        // set the student response to the input
        sto[i] = *buf;
    }
    
    for (i = 0; i < N; i++) {
        // get input line by line
        scanf("%s", buf);
        
        // check if the student response equals to the input
        if (sto[i] == *buf) correct++;
    }
    
    printf("%u\n", correct);
    
    return 0;
}
