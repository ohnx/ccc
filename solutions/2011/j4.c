#include <stdio.h>
#include <stdlib.h>

typedef struct _coords {
    int x, y;
} coords;

static char arr[401][202]; // 0,0 is at 200, 1 and can go max to 0 or 400 horizontally and 200 vertically

int main() {
    char cmd;
    int amnt, i, isDanger = 0;
    coords curr = {199, 5};
    // encode pre-existing well
    arr[200][1] = 1;
    arr[200][2] = 1;
    arr[200][3] = 1;
    arr[201][3] = 1;
    arr[202][3] = 1;
    arr[203][3] = 1;
    arr[203][4] = 1;
    arr[203][5] = 1;
    arr[204][5] = 1;
    arr[205][5] = 1;
    arr[205][4] = 1;
    arr[205][3] = 1;
    arr[206][3] = 1;
    arr[207][3] = 1;
    arr[207][4] = 1;
    arr[207][5] = 1;
    arr[207][6] = 1;
    arr[207][7] = 1;
    arr[206][7] = 1;
    arr[205][7] = 1;
    arr[204][7] = 1;
    arr[203][7] = 1;
    arr[202][7] = 1;
    arr[201][7] = 1;
    arr[200][7] = 1;
    arr[199][7] = 1;
    arr[199][6] = 1;
    arr[199][5] = 1;
    
    while (1) { w: 
        scanf(" %c %d", &cmd, &amnt);
        if (cmd == 'q') break; // quit command
        if (cmd == 'l') {
            for (i = 0; i < amnt; i++) {
                curr.x--; // left is x decrease
                if (arr[curr.x][curr.y] == 1) {
                    isDanger = 1; // drilled there before
                } else {
                    arr[curr.x][curr.y] = 1; // haven't drilled there before
                }
            }
        } else if (cmd == 'r') {
            for (i = 0; i < amnt; i++) {
                curr.x++; // right is x increase
                if (arr[curr.x][curr.y] == 1) {
                    isDanger = 1;
                } else {
                    arr[curr.x][curr.y] = 1;
                }
            }
        } else if (cmd == 'u') {
            for (i = 0; i < amnt; i++) {
                curr.y--; // up is y decrease because we go from top down
                if (arr[curr.x][curr.y] == 1) {
                    isDanger = 1;
                } else {
                    arr[curr.x][curr.y] = 1;
                }
            }
        } else if (cmd == 'd') {
            for (i = 0; i < amnt; i++) {
                curr.y++; // down is y increase because we go from top down
                if (arr[curr.x][curr.y] == 1) {
                    isDanger = 1;
                } else {
                    arr[curr.x][curr.y] = 1;
                }
            }
        }
        if (isDanger) {
            printf("%d %d DANGER\n", curr.x-200, 0-curr.y);
            break;
        } else {
            printf("%d %d safe\n", curr.x-200, 0-curr.y);
        }
        goto w;
    }
    return 0;
}