#include <stdio.h>

int main (void) {
    int x = 1;

    switch(x+3) {
        case 1: 
            x+=2;
            printf("case 1 \n");
        case 4: 
            x+=1;
            printf("case 4 \n");
        case 5: 
            x+=3;
            printf("case 5\n");
        default: x--;
    }
    printf("%d \n", x);
    return 0;
}