#include <stdio.h>
#include <string.h>

typedef struct {
    char title[100];
    char code[100];
    float price;
} book;

book A, B;

void swap(book *aPtr, book *bPtr);

int main () {
    char *p;
    book *aPtr, *bPtr;
    aPtr = &A;
    bPtr = &B;

    printf("Enter 1st book: ");
    scanf("%s", A.title);
    scanf(" %s", A.code);
    scanf("%f", &A.price);
    
    printf("Enter 2nd book :");
    scanf(" %s", B.title);
    scanf(" %s", B.code);
    scanf("%f", &B.price);

    swap(aPtr, bPtr);
    printf("\n\n[Book A]\n");
    printf("Title: %s\n", A.title);
    printf("Code: %s\n", A.code);
    printf("Price: %.2f \n", A.price);

    printf("\n\n[Book B]\n");
    printf("Title: %s\n", B.title);
    printf("Code: %s\n", B.code);
    printf("Price: %.2f \n\n", B.price);
}

void swap(book *aPtr, book *bPtr) {
    book temp;
    temp = *aPtr;
    *aPtr = *bPtr;
    *bPtr = temp;
    return;
}