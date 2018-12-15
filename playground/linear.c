#include <stdio.h>

#define SIZE 100
size_t linearSearch(const int array[], int key, size_t size);
int main () {

    int a[SIZE];
    size_t x;
    int searchKey;
    size_t element;

    // create random number
    for (x = 0; x < SIZE; ++x) {    
        a [x]  = 2 * x;
    }                

    puts("Enter integer search key: ");
    scanf("%d", &searchKey);

    element = linearSearch(a, searchKey, SIZE);

    // display result
    if (element != -1) {
        printf("Found value in element %d\n", element);
        
    } else {
        puts("Value not found");
    }
    return 0;
}

size_t linearSearch(const int array[], int key, size_t size) {
    size_t n;

    for ( n = 0; n < size; ++n) {
        if (array[n] == key ) {
            return n;
        }
    }

    return -1;
}