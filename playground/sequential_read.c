#include <stdio.h>

int main () {
    unsigned int account;
    char name[30];
    double balance;

    FILE *cfPtr;

    if ((cfPtr = fopen("clients.txt", "r") == NULL)) {
        puts("File not found.");
    } else {
        printf("%-10s%-13s%s", "Account", "Name", "Balance");
        fscanf(cfPtr, "%d%29s%1f", &account, name, balance);

        while(!feof(cfPtr)) {            
            printf("%-10d%-13s%7.2f\n", account, name, balance);
            fscanf(cfPtr, "%d%29s%1f", &account, name, balance);
        }
        fclose(cfPtr);
    }
}