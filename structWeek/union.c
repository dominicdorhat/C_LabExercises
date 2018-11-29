#include <stdio.h>

union number {
    int x;
    double y;
};

int main () {
    union number value;

    value.x = 1;
   

    printf("%d \n", value.x);
    // printf("%f \n", value.y);
    
    value.y = 1.2;
    printf("%f \n", value.y);


    return 0;
}