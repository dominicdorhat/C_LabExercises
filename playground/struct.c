#include <stdio.h>

struct guy{
    char * name;
} Guy, *fPtr;

int main () {
    fPtr = &Guy;
    printf("print sommeting: ");
    scanf("%s", fPtr->name);

    printf("%s\n", fPtr->name);


}