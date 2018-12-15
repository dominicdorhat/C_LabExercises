// Question 1, Name: Dominic bin Alphonsus Dorhat, ID: 20011578

#include <stdio.h>

int main()
{
    int num, sum = 0, count = 0;

    printf("Enter number: ");
    scanf("%d", &num);

    if (num == 0) {
        count++; 
    } else {
        while (num > 0)
        {
            /* skip loop for negative integer input, 
             unsigned int not used as the hexademical value of the negative integer stored in unsigned variable 
            is considered a positive value */
            if (num < 0) { continue; } 
            sum += num % 10; 
            num = num / 10;
            count++;
        }
    }

    printf("%d digits and their sum is %d\n", count, sum);
    return 0;
}
