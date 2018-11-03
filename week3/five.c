#include <stdio.h>

int main() {
    int x, y, z, i;
    int total = 0;

    printf("Enter three integers: \n");
    scanf("%d%d%d", &x,&y,&z);


    if (x + y == z || x + z == y || y + z == x) {
        if( x < 10) { printf("%d ", x); }
        if (y < 10) { printf("%d ", y); }
        if (z < 10) { printf("%d ", z); }
    } else {

        int a, b, c;
        printf("Enter another three integers: \n");
        scanf("%d%d%d", &a,&b,&c);
        
        if(a % 6 == 0) { total++; }
        if(b % 6 == 0) { total++; }
        if(c % 6 == 0) { total++; }

        printf("Total: %d\n", total);
    }


    return 0;
}