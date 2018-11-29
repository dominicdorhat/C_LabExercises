#include <stdio.h>

typedef struct {
    unsigned int acctNum;
    char lastName[15];
    char firstName[10];
    double balance;
}clientData;

int main () {

    clientData client = {0, "", "", 0};    
    FILE *cfPtr;
    int result;

    if ((cfPtr = fopen("credit", "rb")) == NULL ){
        puts("File could not be open.");
    } else {
        printf("%-6s%-16s%-11s%10s\n", "Acct", "Last Name", "First Name", "Balance");
        
        while(!feof(cfPtr)) {
            result = fread(&client, sizeof(clientData), 1, cfPtr);

            if(result != 0 && client.acctNum != 0) {
                printf("%-6d%-16s%-11s%10.2f\n",
                client.acctNum, client.lastName,
                client.firstName, client.balance);
            }
        }

        fclose(cfPtr);
    }
}