#include <stdio.h>

int main () {
    float x, y, z;

    // input
    printf("Enter three prices: \n");
    scanf("%f %f %f", &x, &y, &z);

    // output
    printf("The average price is: %.2f", (x + y+  z) / 3);

    return 0;
}