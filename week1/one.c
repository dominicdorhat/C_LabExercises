#include <stdio.h>

int main () {
    int x = 30;
    int y = 30; 

    int sum = x + y;
    int diff = x - y;
    int prod = x * y;
    int division = x / y;
    int remain = x % y;

    printf("Sum is: %d \n", sum);
    printf("Difference is: %d \n", diff);
    printf("Product is: %d \n", prod);
    printf("Division is: %d \n", division);
    printf("Remainder is: %d \n", remain);
    
    return 0;
}