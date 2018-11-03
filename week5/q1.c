#include <stdio.h>

int main () {
    int a[5] = {10, 20, 30, 40, 50}, i;

    for (i = 0; i <= 4; i++){
        if(a[i] > 20) {
            printf("%d \n", a[i]);
        }
    }
    
    return 0;
}