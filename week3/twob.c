#include <stdio.h>

int main () {
    int x, y;
    char operator;
    
    printf("Enter an arithmetic operation: \n");
    scanf("%d%c%d", &x, &operator, &y);

    switch(operator) {
        case '+':
            printf("%d + %d = %d", x, y, x+y);
            break;
        case '-':
            printf("%d - %d = %d", x, y, x - y);
            break;
        case 'x':
            printf("%d x %d = %d", x, y, x * y);
            break;
        case '/':
            printf("%d / %d = %d", x, y, x / y);
            break;
        case '%':
            printf("%d % %d = %d", x, y, x % y);
            break;
        default:
            break;
    }
    return 0;
}