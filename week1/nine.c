#include <stdio.h>

int main () {
    float x;

    // input
    printf("Enter floating number: \n");
    scanf("%f", &x);
    
    // output
    printf("Next integer: %d\n", (int) x + 1);
    printf("Previous integer: %d", (int) x - 1);

    return 0;
} 