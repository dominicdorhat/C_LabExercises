// Question 6, Name: Dominic bin Alphonsus Dorhat, ID: 20011578
#include <stdio.h>
#include <math.h>

int main () {
    // variable initialization
    float x;
    int i, option;

    while (i)
    {
        printf("\nEnter a floating-point value: ");
        scanf("%f", &x);

        // math formulas
        if (x < -5)
        {
            printf("f(x) = 8\n");
        }

        if (x >= -5 && x < 3)
        {
            printf("f(x) = %f \n\n", 1 / x);
        }

        if (x >= 3 && x < 12)
        {
            printf("f(x) = %f \n\n", pow(x, 2) - 4);
        }

        if (x >= 12)
        {
            printf("f(x) = %f \n\n", 6 / pow((x - 14), 2));
        }

        printf("Run again[1 - Yes | 2 - Exit]: ");
        scanf("%d", &option);

        if (option == 2) { // if user input 2, exit
            i = 0;
            break;
        }

    }
   
    return 0;

}