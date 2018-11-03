#include <stdio.h>

int main () {
    int arr[2][4], sum = 0;

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 4; j++) {
            scanf("%d", &arr[i][j]);
            sum += arr[i][j];
        }
    }

    printf("Sum of all elements are %d \n\n", sum);

    for(int row = 0; row < 2; row++){
        int rowsum = 0;
        for(int col = 0; col < 4; col++) {
            rowsum += arr[row][col];
        }
        printf("Sum of row %d is %d \n\n", row, rowsum);
    }
    
    for(int col = 0; col < 4; col++) {
        int colsum = 0;
        for(int row = 0; row < 2; row++) {
            colsum += arr[row][col];
        }
        printf("Sum of col %d is %d \n\n", col, colsum);
    }

}