#include <stdio.h>

int main () {
    int marks[10], i, j;

    printf("Please enter the marks of 10 students: \n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &marks[i]);
    }

    for (j = 0; j < 10; j++) {
        
        if (marks[j] >= 5 && marks[j] <= 10) {
            printf("%d ", marks[j]);
        }
    }
}