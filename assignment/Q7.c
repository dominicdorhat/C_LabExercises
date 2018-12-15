// Question 7, Name: Dominic bin Alphonsus Dorhat, ID: 20011578

#include <stdio.h>

int main () {
    // variable intialization
    int x = 1, asc[4], option, i, j, k;

    do {
        // loop to fill in array index-by-index
        printf("Enter 4 integers: ");
        for (i = 0; i < 4; i++) {
            scanf("%d", &asc[i]);
        }
                
        // sorting array elements in ascending order [bubble sort]
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 4; k++) {

                if (asc[k] > asc [j]) { // if k > j, swap values                   
                    int tmp = asc[j]; // store value into temp.
                    asc[j] = asc[k]; // swap value
                    asc[k] = tmp; // get temp. value 
                }
            }
        }

        // display output of operations
        printf("%d + %d = %d \n", asc[3], asc[0], asc[3] + asc[0]);
        printf("%d * %d = %d \n", asc[2], asc[1], asc[2] * asc[1]);

        printf("Run again[1 - Yes | 2 - Exit]: ");
        scanf("%d", &option);
        if (option == 2) {
            x = 0;
            break;
        }
    } while (x); // infinite loop until x is 0
    return 0;
}