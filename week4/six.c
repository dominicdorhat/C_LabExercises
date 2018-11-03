#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

int main () {
    float i;
    srand(time(NULL));
    i = (float) (rand() % 4);
    printf("%.2f", i);
    return 0;
}
 