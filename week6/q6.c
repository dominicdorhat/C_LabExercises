#include <stdio.h>
#define SIZE 100

int compStr(const char *s1Ptr, const char *s2Ptr);

int main () {
    char str1[SIZE], str2[SIZE];

    printf("Enter 2 strings: ");
    scanf("%s", str1);
    scanf("%s", str2);

    if (compStr(str1, str2) == 1) {
        printf("The bigger string is %s", str1);
    } else if(compStr(str1, str2) == 2) {
        printf("The bigger string is %s", str2);
    } else {
        printf("They are of the same length");
    }
    
}

int compStr(const char *s1Ptr, const char *s2Ptr) {
    int count1 = 0, count2 = 0;
    for(; *s1Ptr != '\0'; s1Ptr++) {
        count1++;
    }

    for (; *s2Ptr != '\0'; s2Ptr++)
    {
        count2++;
    }

    if(count1 == count2) {
        return NULL;
    } else if (count1 > count2) {
        return 1;
    } else if (count2 > count1) {
        return 2;
    }
}