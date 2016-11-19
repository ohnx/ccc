#include <stdio.h>
#include <stdlib.h>

struct bc {
    int l;
    int w;
    int h;
    int v;
};

/* helper function for volume comparing */
int cmpBC(const void *a, const void *b) {
    return ( ((struct bc *)a)->v - ((struct bc *)b)->v );
}

#define swap(a,b) do{t=a;a=b;b=t;}while(0);

int testFit(struct bc box, struct bc itm) {
    int a1, a2;
    int b1, b2;
    int c1, c2;
    int t;
    
    /* sort the numbers */
    a1 = box.l;
    b1 = box.w;
    c1 = box.h;
    
    a2 = itm.l;
    b2 = itm.w;
    c2 = itm.h;
    
    /* the idea is that if the dimensions
     * in order from smallest to greatest
     * of the box are greater than that of
     * the item, then the item will (somehow)
     * be able to fit into the box.
     *
     * thus, we sort the dimensions of each box ...
     */
    
    if (a1 > c1) swap(a1, c1);
    if (a1 > b1) swap(a1, b1);
    if (b1 > c1) swap(b1, c1);
    
    if (a2 > c2) swap(a2, c2);
    if (a2 > b2) swap(a2, b2);
    if (b2 > c2) swap(b2, c2);
    
    /* ... and check to make sure each dimension pair is greater */
    return ((a1 >= a2) && (b1 >= b2) && (c1 >= c2));
}

int main() {
    struct bc *lst, item;
    int c, i, c2, j;
    int v, l, w, h;
    
    /* read in boxes */
    scanf("%d", &c);
    
    /* we store the volume, length, width, and height 
     * since it is all necessary.
     * use a struct to help store
     */
    lst = calloc(c, sizeof(struct bc));
    
    for (i = 0; i < c; i++) {
        scanf("%d %d %d", &(lst[i].l), &(lst[i].w), &(lst[i].h));
        lst[i].v = lst[i].l * lst[i].w * lst[i].h;
    }
    
    /* sort */
    qsort (lst, c, sizeof(struct bc), cmpBC);
    
    /* read in item sizes */
    scanf("%d", &c2);
    
    /* we don't need to store these things. */
    for (i = 0; i < c2; i++) {
        scanf("%d %d %d", &l, &w, &h);
        v = l*w*h;
        item.l = l;
        item.w = w;
        item.h = h;
        item.v = v;
        for (j = 0; j < c; j++) {
            /* check each box */
            if (v <= lst[j].v) {
                /* volume will fit, check other things */
                if (testFit(lst[j], item)) {
                    /* found a valid box, print it out */
                    printf("%d\n", lst[j].v);
                    v = 0;
                    break;
                }
            }
        }
        if (v != 0) {
            printf("Item does not fit.\n");
        }
    }
    
    return 0;
}