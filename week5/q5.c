#include <stdio.h>


int main () {
    int a[10], b[10], count = 0;

    printf("Enter 20 integers: \n");
    for(int i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
    }

    for(int i = 0; i < 10; i++) {
        scanf("%d", &b[i]);
    }

    for(int j = 0; j < 10; j++) {
        for(int k = 0; k < 10; k++) {
            if (a[k] == a[j]) {
                printf("%d and %d are common at a[%d] and b[%d] \n", a[k], b[j], k, j);
            }
        }

    }
}