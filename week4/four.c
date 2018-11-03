#include <stdio.h>

int sqr(int);
int cub(int);

int main () {
    int x, square, cube;

    printf("Enter an integer: \n");
    scanf("%d", &x);
    printf("The sum is: %d", sqr(x) + cub(x));


    return 0;
}

int sqr(int x) {
    return x * x;
}

int cub(int x) {
    return x * x * x;
}