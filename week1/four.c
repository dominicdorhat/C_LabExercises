#include <stdio.h>

int main () {

    // input
    int x, y, q, p, m;
    printf("Please enter two numbers.\n");
    scanf("%d%d", &x, &y);

    // modulus
    q = x / y; // find the quotient
    p = q * y; // find the product 
    m = x - p; // find the modulus

    //output
    printf("Modulus: %d\n", m);
    return 0;
}