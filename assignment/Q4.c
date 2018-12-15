// Question 4, Name: Dominic bin Alphonsus Dorhat, ID: 20011578

#include <stdio.h>

// function prototype
int highestPower(int, int);

int main () {
    // variable initialization
    int num, option, i = 1;

    printf("\n\t\t[ Question 4 ]\n\n");    
    printf("\t\t1. Exit. \n");
    printf("\t\t2. Display the next highest power of 2. \n");
    printf("\t\t3. Display the next highest power of 3. \n");
    printf("\t\t4. Display the next highest power of 4. \n");
    printf("\t\t5. Display the next highest power of 5. \n\n");

    while (i) {
        printf("Enter highest number of power within [2,5] or 1 to exit: ");
        scanf("%d", &option);

        if (option == 1) {
            // exits program when input is 1
            printf("Exiting... \n");
            i = 0;
            break;
        }

        if (option <= 0 || option > 5) { 
            // catch invalid/non-positive input, doesn't catch non-integer inputs though
            printf("Please enter a positive/valid integer! \n\n");
            continue;

        } else {
            printf("Enter a positive integer: ");
            scanf("%d", &num);
        }

        switch (option)
        {
            case 2:
                printf("Output: %d \n\n", highestPower(num, option));
                break;

            case 3:
                printf("Output: %d \n\n", highestPower(num, option));
                break;

            case 4:
                printf("Output: %d \n\n", highestPower(num, option));
                break;

            case 5:
                printf("Output: %d \n\n", highestPower(num, option));
                break;
        }
    }    
    return 0;
}

// function definition
// finds the multiple of x and assigns it to p as long as p less than the input
// p refers to result of power of x
int highestPower(int n, int x) {
    int p = 1;
    while (p < n) {
        p *= x;
    }
    return p;
}