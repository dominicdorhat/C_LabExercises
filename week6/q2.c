#include <stdio.h>
#define SIZE 100

int countStr(char *sPtr);

int main () {

    char string[SIZE];
    printf("Enter a string: ");
    scanf("%s", string);
    printf("\nString length: %d", countStr(string));
    return 0;
}

int countStr(char *sPtr) {
    int count = 0;
    while(*sPtr != '\0') {
        count++;
        sPtr++;
    }
    return count;
}