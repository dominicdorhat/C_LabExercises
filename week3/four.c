#include <stdio.h>

int main () {
    float a, b, x;

    printf("Enter 2 floating numbers: \n");
    scanf("%f%f", &a, &b);

    printf("x is: %.2f", (-b)/a);
        
    return 0;
}