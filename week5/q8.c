#include <stdio.h>

int main () {
    int a[2][3], b[3][2];

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            printf("Enter integer for [%d][%d]", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++)
        {
            printf("Enter integer for [%d][%d]", i, j);
            scanf("%d", &b[i][j]);
        }
    }
}