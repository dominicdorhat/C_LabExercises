#include <stdio.h>

int main() {
    int x = 35;
    int lastDigit = 35 % 10;
    int firstDigit = 35 / 10;

    printf("Sum of 3 and 5 is %d", firstDigit + lastDigit);
}