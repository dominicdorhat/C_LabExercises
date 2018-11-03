#include <stdio.h>
#define SIZE 100

void swapStr(char *onePtr, char *twoPtr);

int main () {
    char str1[SIZE], str2[SIZE], tmp[SIZE];
    scanf("%s", str1);
    scanf("%s", str2);
    printf("Before swapping, str1 = \"%s\", str2 = \"%s\"\n", str1, str2);
    
    // swapping
    swapStr(tmp, str1);
    swapStr(str1, str2);
    swapStr(str2, tmp);

    printf("After swapping, str1 = \"%s\", str2 = \"%s\"\n", str1, str2);
}

void swapStr(char *onePtr, char *twoPtr) {
    // copying of string
    while(*twoPtr != '\0') {
        *onePtr = *twoPtr;
        onePtr++;
        twoPtr++;
    }
    *onePtr = '\0';
}