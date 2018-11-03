#include <stdio.h>

int minimum(int, int, int);
int main () {

    int x, y, z, min;
    
    printf("Enter 3 integers: \n");
    scanf("%d%d%d", &x, &y, &z);
    
    min = minimum(x,y,z);
    printf("The minimum is %d", min);


    return 0;
}

int minimum(int x, int y, int z) {
    if (x < y && x < z) {
        return x;
    } else if (y < x && y < z) {
        return y;
    } else if (z < y && z < x) {
        return z;
    }
}