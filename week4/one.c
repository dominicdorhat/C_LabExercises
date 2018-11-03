#include <stdio.h>
#define PI 3.142

float area(float);

int main () {

    float r;
    printf("Enter length or radius: \n");
    scanf("%f", &r);
    printf("Area: %.2f", area(r));

    return 0;
}


float area(float r) {
    return PI*r*r;
}