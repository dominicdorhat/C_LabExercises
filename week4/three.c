#include <stdio.h>

void multiplier(int, char);

int main () {
    char letter;
    int x;

    printf("Enter an integer: \n");
    scanf("%d", &x);

    printf("Enter a character: \n");
    scanf(" %c", &letter);

    multiplier(x, letter);
    return 0;
}

void multiplier(int integer, char letter) {
    int i;
    for (i = 1; i < integer; i++) {
        printf("%c \n", letter);
    }
    return;
}

