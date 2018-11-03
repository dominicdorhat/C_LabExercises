#include <stdio.h>
#include <string.h>
#define SIZE 100

int countChar(char a, char *cPtr);

int main () {
    char character, string[SIZE];
    int x = 1;

    while(x) {
        printf("\nPlease enter a character and a string: ");
        scanf("%c", &character);
        scanf("%s", string);
        if (strcmp(string, "end") == 0)
        {
            x = 0;
            break;
        } else {
            printf("Number of times %c appeared is %d", character, countChar(character, string));
        }
    }

    return 0;
}

int countChar(char a ,char *cPtr) {
    int count = 0;
    while(*cPtr != '\0') {
        if (*cPtr == a) {
            count++;
        }
        cPtr++;
    }
    return count;

}
