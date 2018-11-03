#include <stdio.h>
#define SIZE 10

int main () {
    int a[SIZE], i, count;

    for(i = 0; i < SIZE; i++){
        printf("Enter element a[%d]: ", i);
        scanf("%d", &a[i]);
    }

    for(int j = 0; j < SIZE / 2; j++) {
        if(a[j] != a[SIZE -1 - j]) {
            printf("Non symmetric array\n");
            return 0;
        }
    }

    printf("Symmetric array \n");
    return 0;
}