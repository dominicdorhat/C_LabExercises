#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

int main () {

    int a[10], i, sum = 0, count = 0;

    srand(time(NULL));

    for (i = 0; i < 10; i++) {
        a[i] = rand() % 21;
        sum += a[i];
        count++;
    }

    printf("The average is %d \n", sum / count);
    

    
}