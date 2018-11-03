#include <stdio.h>

int main () {
    int arr[2][4];

    printf("Enter 8 integers: ");

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 4; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    for(int i = 1;i >= 0; i--) {
        for(int j = 3;j >= 0; j--) {
            printf("%d \n", arr[i][j]);
        }
    }

    return 0;
}