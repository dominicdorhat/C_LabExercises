#include <stdio.h>

int main () {

    int x, y, min, max;
    
    printf("Input two numebers: \n");
    scanf("%d%d", &x, &y);

    if (x > y) {
        max = x;
        min = y;
    } else if (x < y) {
        max = y;
        min = x;
    }

    printf("Output: %d, %d", min, max);
    return 0;
}