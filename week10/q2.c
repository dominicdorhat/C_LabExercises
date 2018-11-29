#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main () {

    char code[20], prd[20], str[20];
    float price;
    int result, response = 1;
    FILE *fptr;
    
    if ((fptr = fopen("q2.txt", "a+")) == NULL ) {
        puts("File not found!");

    } else {
        while (1) {
            printf("Enter code: ");
            char codein[20];
            // verify input
            // fgets(codein, sizeof(codein), stdin);            
            // result = sscanf(codein,"%s", code);
            scanf("%s", code);
            
            printf("Enter price: ");
            scanf("%f", &price);

            if (sizeof(code) > 20) {
                puts("Invalid input!");

            } else if (price == -1) {
                do {
                    rewind(fptr);
                    printf("Enter code to be search: ");
                    scanf("%s", prd);

                    while(feof(fptr)) {
                        if(fscanf(fptr, "%s%f", str, &price) != 2) {
                        printf("Record not found! \n");
                        break;
                        } 
                                        
                        if(strcmp(prd, str) == 0) {
                            printf("The price for product %s is %.2f\n", prd, price);
                            
                        } else {
                            fptr++;                        
                        }
                    }
                    printf("Do you want to continue? ");
                    scanf("%d", &response);            
                } while (response);
                    
            } else if (price == -2) {
                exit(1);

            } else {
                fprintf(fptr, "%s ", code);
                fprintf(fptr, "%.2f \n", price);
            }            
        }
    }

    return 0;
}