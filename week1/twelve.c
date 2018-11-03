#include <stdio.h>

int main () {

    float i, q, p, m;
    int x;

    printf("Enter a float: ");
    scanf("%f", &i);

    printf("Enter a positive integer: ");
    scanf("%d", &x);

    q = (int) i / x;
    p = (float )q * x;
    m = i - p;
    
    printf("The remainder of their division is : %.2f", m);
    
    return 0;
}