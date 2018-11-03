#include <stdio.h>

int main () {

    int x;
    float y, sum, triple;

    // input
    printf("Please enter an integer: \n");
    scanf("%d", &x);

    printf("Please enter a floating number: \n");
    scanf("%f", &y);

    // operation
    sum = x + y;
    triple = sum * 3;

    // output
    printf("The triple of the sum is %0.2f", triple);    
    return 0;
}