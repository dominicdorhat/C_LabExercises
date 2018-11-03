#include <stdio.h>

int main () {
    
    float a, b, c, temp;

    printf("Enter three floating point digits: \n");
    scanf("%f %f %f", &a, &b, &c);

   temp = a;
   a = c;
   c = b;
   b = temp;

    printf("a = %.2f,  b = %.2f, c = %.2f", a, b, c);
    
    return 0;
}