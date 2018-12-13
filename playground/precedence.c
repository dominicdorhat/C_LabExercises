#include <stdio.h>

int main () {
    int arr[2] = {10, 20}, *p = &arr[0];
    *++p;
    printf("arr[0] = %d, arr[1] = %d, *p = %d\n", arr[0], arr[1], *p);

}