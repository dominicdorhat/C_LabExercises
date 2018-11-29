#include <stdio.h>

int main () 
{
    int *yPtr, y = 9;
    yPtr = &y;

    printf("%d\n", *yPtr);
    printf("%p\n", yPtr);
    printf("%p\n", &y);
    printf("%p\n", &yPtr);
    return 0;
}