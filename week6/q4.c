#include <stdio.h>
#include <string.h>

int checkStr(char *str1, char *str2);

int main () {
    char str1[100], str2[100];
    int ans = 0;
    scanf("%s", str1);
    scanf("%s", str2);

    ans = checkStr(str1, str2);
    if (ans == 0) {
        printf("%s is not contained behind %s \n", str2, str1);
    } else {
        printf("%s is contained behind %s", str2, str1);
    }
}

int checkStr(char *str1, char *str2) {
    int i, len1, len2;
    len1 = strlen(str1);
    len2 = strlen(str2);

    if (len1 < len2) {
        return 0;
    }

    for ( i = 1; i <= len2; i++) {
        if(str1[len1 - i] != str2[len2 - i]) {
            return 0;
        }
    }

    return 1;
}