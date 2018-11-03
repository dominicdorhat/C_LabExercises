#include <stdio.h>

int main () {
    int x, y;

    printf("Enter 2 integers: \n");
    scanf("%d%d", &x, &y);

    x > y ? 
    printf("%d is bigger than %d \n", x, y) 
    : printf("%d is bigger than %d \n", y, x);
}