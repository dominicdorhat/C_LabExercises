// Question 3, Name: Dominic bin Alphonsus Dorhat, ID: 20011578

#include <stdio.h>

int main () {

    // variable initialization
    int option, x, y, z, i = 1;    

    // Menu display
    printf("\t\t[ Question 3 ]\n\n");
    printf("\t\t1. Check if all integers are the same. \n");
    printf("\t\t2. Check if any two integers are the same. \n");
    printf("\t\t3. Check how many integers fall within [-10, 10]. \n");
    printf("\t\t4. Display smallest integer. \n");
    printf("\t\t5. Exit. \n\n");

    while(i) { // loops infinitely as long as i = 1 or true

        printf("Enter input: ");
        scanf("%d", &option);

        if (option == 5) { // exits program when input is 5 
            break;
        } 

        if (option < 0 || option > 5) { // catch invalid input, doesn't catch non-integer inputs though
            printf("Please enter a valid input! \n\n");
            continue;
            
        } else {
            printf("Enter three integers: ");
            scanf("%d%d%d", &x, &y, &z);
        }

        switch(option) {
            case 1:            
                (x == y && x == z && y == z?
                 printf("The integers are equal. \n\n" ):
                  printf("The integers are different. \n\n"));
                break;    

            case 2:
                (x == y || x == z || y == z ? 
                 printf("Two of the integers are equal. \n\n") : 
                  printf("No two integers are equal. \n\n"));
                break;

            case 3:; // semicolon to allow intialization of variable within a switch case due to scope labeling issues
                int count = 0;
                if (x >= -10 && x <= 10 ) { count++; }
                if (y >= -10 && y <= 10) { count++; }
                if (z >= -10 && z <= 10) { count++; }

                if (count > 0) {
                    printf("%d of them are within [-10, 10]. \n\n", count);
                } else {
                    printf("None of them are within [-10, 10]. \n\n");
                }
                break;

            case 4:
                printf("%d is the smallest integer. \n\n",
                 (x < y && x < z)? x:
                  (y < z && y < x)? y : z);
                break;             
        }
    }
    return 0;
}