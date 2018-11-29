#include <stdio.h>

typedef struct {
    char * manufacturer;
    char * model;
    char * processor;
    float price;
} computer;

int main () {

    computer CompA = {"Lenovo", "ThinkPad", "Intel", 4900.50};
    printf("Manufacturer: %s\n", CompA.manufacturer);
    printf("Model: %s\n", CompA.manufacturer);
    printf("Processor: %s\n", CompA.processor);
    printf("Price: %.2f\n", CompA.price);

    return 0;
}