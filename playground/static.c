#include <stdio.h>

void staticArrayInit(void);
void automaticArrayInit(void);

int main () {
    puts("First call to each function: ");
    staticArrayInit();
    automaticArrayInit();

    puts("\nSecond call to each function: ");
    staticArrayInit();
    automaticArrayInit();

    return 0;
}

void staticArrayInit() {
    static int array1[3];
    size_t i;

    puts("\nValues on entering staticArrayInit:");

    for(i = 0; i <= 2; ++i) {
        printf("array[%u] = %d ", i, array1[i]);

    }

    puts("\nValues on exiting staticArrayInit:");

    for(i = 0; i <= 2; ++i) {
        printf("array1[%u] = %d ", i, array1[i] +=5);
    }
}

void automaticArrayInit() {
    int array2[3] = {1, 2, 3};
    size_t i;

    puts("\n\nValues on entering automaticArrayInit:");

    for (i = 0; i <= 2; ++i) {
        printf("array[%u] = %d ", i, array2[i]);

    }

    puts("\nValues on exiting automaticArrayInit:");

    for (i = 0; i <= 2; ++i) {
        printf("array2[%u] = %d ", i, array2[i] +=5 );
    }
}