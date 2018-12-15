// Question 2, Name: Dominic bin Alphonsus Dorhat, ID: 20011578

#include <stdio.h>

int main()
{
    int num, sum = 0, count = 0;

    printf("Enter number: ");
    scanf("%d", &num);

    switch (num) {
        case 0:
            // if input is 0, adds 1 to the counter 
            count++;
            break;

        default:
            while (num > 0)
            {
                sum += num % 10;
                num = num / 10;
                count++;
            }
            break;
    }    
    printf("%d digits and their sum is %d\n", count, sum);
    return 0;
}
