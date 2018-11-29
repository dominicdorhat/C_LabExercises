#include <stdio.h>

typedef struct {
    unsigned int acctNum;
    char lastName[15];
    char firstName[10];
    double balance;
} clientData;

int main () {
    unsigned int i;

    clientData blankClient = {0, "","", 0.0};

    FILE *cfPtr;

    if ((cfPtr = fopen("credit", "wb")) == NULL) {
        puts("File could not be opened");
    } else {
        for(i = 1; i <= 100; ++i) {
            fwrite(&blankClient, sizeof(clientData), 1, cfPtr);
        }

        fclose(cfPtr);
    }

}