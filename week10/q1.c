#include <stdio.h>
#include <stdlib.h>

int main () {

    int price;

    FILE *fptr;
    fptr = fopen("q1.txt", "w+");

    if (fptr == NULL) {
        puts("File could not be opened.");
        exit(1);

    } else {
        while(1) {
            printf("Enter product price more than $10, less than $20: \n");
            printf("%s", "? $");
            scanf("%d", &price);

            if (price > 10 && price < 20) {
                fprintf(fptr, "%d\n", price);

            } else if (price == -1) {
                break;

            } else {
                puts("Price out of range!");
            }
        }
    }
    
    fclose(fptr);

    return 0;
}