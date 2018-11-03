#include <stdio.h>

int main () {
    char string[256];
    int code;
    float price;

    printf("Key in name: \n");
    scanf("%s", string);
    printf("Key in code: \n");
    scanf("%d", &code);
    printf("Key in price: \n");
    scanf("%f", &price);

    printf("\n\n");
    printf("Product: %s \nCode: %d \nPrice: RM%.2f\n", string, code, price);

    return 0;
}