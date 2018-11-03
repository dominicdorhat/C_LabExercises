#include <stdio.h>

int main() {
    int x, count = 1, pass = 0, fail = 0; 

    printf("Enter data[1 = pass, 2 = fail]: \n");
    while(count <= 10) {    
        scanf("%d", &x);

        if (x == 1) {
            pass++;
            count++;
        }
        else if(x == 2) {
            fail++;
            count++;
        }
    }

    printf("Passes: %d\n", pass);
    printf("Fails: %d", fail);    
}