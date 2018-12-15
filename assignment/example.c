#include <stdio.h>
int pow2roundup(int);

int main()
{
    int x;
    scanf("%d", &x);
    printf("%d", pow2roundup(x));

    return 0;
}

inline int
pow2roundup(int x)
{
    if (x < 0)
        return 0;
    --x;
    x |= x >> 1;
    printf("%d\n", x + 1);
    x |= x >> 2;
    printf("%d\n", x + 1);
    x |= x >> 4;
    printf("%d\n", x + 1);
    x |= x >> 8;
    printf("%d\n", x + 1);
    x |= x >> 16;
    printf("%d\n", x + 1);
    return x + 1;
}