#include <stdio.h>

// important

int main() {
    int a, b, c, d;

    printf("Enter four prices: \n");
    scanf("%d%d%d%d", &a, &b, &c, &d);

    printf("Max is %d\n", 
    (a > b && a > c && a > d)? a: 
    (b > a && b > c && b > d)? b :
    (c > a && c > b && c > d) ? c : d);

    return 0;
}