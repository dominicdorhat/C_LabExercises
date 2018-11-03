#include <stdio.h>
#define SIZE 10

int main () {
    int a[SIZE] = {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0}, x = 0;

    for(int i = 0; i < SIZE; i++) {
        printf("Enter element a[%d]: ", i);
        scanf("%d", &x);
        
        if((i % 2 == 0) && (x > 0)) {
            //even
            if(x % 2 == 0) {
                printf("Even \n");
                a[i] = x;
            } else {
                printf("Do nothing \n");
            }

        } else if ((i % 2 != 0) && (x > 0)) {
            // odd
            if(x / 2 == 0) {
                printf("Odd \n");
                a[i] = x;
                continue;
            } else {
                printf("Do nothing \n");
            }
        } else {
            printf("Do nothing \n");
        }
    }

    for (int j = 0; j < SIZE; j++)
    {
        if(a[j] == 0) {
            a[j] = -1;
        }
    }

    for(int j = 0; j < SIZE; j++) {
        printf("a[%d] = %d \n", j, a[j]);
    }
}