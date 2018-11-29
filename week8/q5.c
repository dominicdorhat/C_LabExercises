// more accurate to the question where codeCheck() returns pointer

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[100];
    int code;
    float price;
} product;

product * codeCheck(product p[], size_t size, int x);

int main () {
    int input;
    product Product[20];

    printf("Enter product name, code and price: \n");
    for (int i = 0; i < 20; i++) {
        printf("Product %d: %s ", i+1,"?");
        scanf("%s %d %f", Product[i].name, &Product[i].code, &Product[i].price);

    }

    printf("\nEnter code: ");
    scanf("%d", &input);
    
    product *pPtr = codeCheck(Product, sizeof(Product), input);
    
    if (pPtr != NULL) {
        printf("\nProduct: %s\n", pPtr->name);
        printf("Code: %d\n", pPtr->code);
        printf("Price: %.2f\n", pPtr->price);

    } else {
        printf("No items were found.\n");
    }

}

product * codeCheck(product p[], size_t size, int x) {
    for (int j = 0;j < 20; j++) {
        if (p[j].code == x) {
            product *pPtr = malloc(sizeof *pPtr);
            pPtr = &p[j];
            return pPtr;
        }
    }
    return NULL;
}