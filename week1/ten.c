#include <stdio.h>

int main () {
    int x, y, z;

    // input 
    printf("Enter two integers: \n");
    scanf("%d %d", &x, &y);

    // swapping
    z = x;
    x = y;
    y = z;

    // output
    printf("Value of swapped X: %d \n", x);
    printf("Value of swapped Y: %d", y);
    
    return 0;
}