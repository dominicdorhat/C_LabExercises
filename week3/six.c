#include <stdio.h>

int main () {
    int x, y, z, a, i = 1;
    int min, max;

    printf("Please enter four product prices: \n");
    scanf("%d%d%d%d", &x, &y, &z, &a);

    min = max;

    // while(i) {
    //     if (min > max) {
    //         max = min;
    //     } else if (max < min) {

    //     }
    // }

    if (x > y && x > z && x > a) {
        printf("%d is the largest number. \n", x);
    }
    else if (y > x && y > z && y > a) {
        printf("%d is the largest number. \n", y);
    }
    else if (z > x && z > y && z > a) {
        printf("%d is the largest number. \n", z);
    }
    else if (a > x && a > y && a > z) {
        printf("%d is the largest number. \n", a);
    }
        return 0;
}