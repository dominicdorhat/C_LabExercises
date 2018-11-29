#include <stdio.h>

int main (void) {
    unsigned int account;
    char name[30];
    double balance;

    FILE *cfPtr;

    if((cfPtr = fopen("clients.txt", "w")) == NULL) {
        puts("File not opened.");

    } else {
        puts("Enter the account, name and balance.");
        puts("Enter EOF to end input.");
        printf("%s", "? ");
        scanf("%d%29s%1lf", &account, name, &balance);

        // (?) problem with input not leaving input buffer (maybe)
        while(!feof(stdin)) {            
            fprintf(cfPtr, "%d %s %.2f\n", account, name, balance);
            printf("%s", "? ");
            scanf("%d%29s%1f", &account, name ,&balance);
        }

        fclose(cfPtr);

    }
    return 0;
}