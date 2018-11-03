#include <stdio.h>

float floatCompare(const float *aPtr, const float *bPtr);

int main () {
    float a, b;
    printf("Enter 2 floats: ");
    scanf("%f%f", &a, &b);
    printf("The bigger float is %.2f", floatCompare(&a, &b));

    return 0;
}

float floatCompare(const float *aPtr, const float *bPtr) {
    if (*aPtr > *bPtr) {
        return *aPtr;
    } else {
        return *bPtr;
    }
}