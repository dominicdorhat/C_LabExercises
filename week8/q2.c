#include <stdio.h>

struct stock {
    char name[100];
    char code[100];
    float price;
} StockA[2];

int main () {

    float price;
    printf("Enter stock name, code and price: \n");
    for(int i = 0; i < 2; i++) {
        printf("%s ", "?");
        scanf("%s", StockA[i].name);
        scanf("%s", StockA[i].code);
        scanf("%f", &StockA[i].price);
    }

    printf("\n\nSearch price: ");
    scanf("%f", &price);
    printf("%-10s%-10s%-10s \n", "Stock", "Code", "Price");

    for(int j = 0; j < 2; j++) {
        if(StockA[j].price <= price) {
            printf("%-10s%-10s%-10.2f\n", StockA[j].name, StockA[j].code, StockA[j].price);
        }
    } 


    return 0;
}