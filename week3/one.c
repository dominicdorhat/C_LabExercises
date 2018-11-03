#include <stdio.h>

int main () {
    int x;
    scanf("%d", &x);

    if(x < 0) {
        x = x * -1;
    }

    printf("Absolute value: %d", x);

    return 0;
}