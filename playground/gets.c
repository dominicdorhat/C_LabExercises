#include <stdio.h>

int main () {
    char a[256];
    printf("Enter a message: ");
    scanf("%[^\n]s", a);
    printf("%s\n", a);

    return 0;
}