#include <stdio.h>

int main () {
    int result, number;
    char st[1024];
    
    printf("Enter a number: ");
    fgets(st, sizeof(st),stdin);
    result = sscanf(st, "%d", &number);

    if (result < 1) {
        printf("You didn't type a number!\n");
    } else {
        printf("The number was %d\n", number);
    }
}