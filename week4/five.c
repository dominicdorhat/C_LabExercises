#include <stdio.h>
int average(int, int, int);

int main () {
    int x, y, z;
    printf("Enter three prices: \n");
    scanf("%d%d%d", &x, &y, &z);
    printf("Average price within [1, 5] is %d", average(x, y, z));
    return 0;
}

int average(int x, int y, int z) {
    int sum = 0;
    if (x <= 5) {
        sum += x;
    }  
    
    if (y <= 5) {
        sum += y;
    }  
    
    if (z <= 5) {
        sum += z;
    }
    return sum/3;
}