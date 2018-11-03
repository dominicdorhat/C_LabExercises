#include <stdio.h>

int main () {
 
    int x, y;

    // input 
    printf("Enter two integers: \n");
    scanf("%d %d", &x, &y);

    // output
    printf("\nSum: %d \n", x + y);
    printf("Difference: %d \n", x - y);
    printf("Product: %d \n", x * y);
    printf("Quotient: %d \n", x / y);
    printf("Remainder: %d \n", x % y);

    return 0;
}