#include <memory.h>
#include <string.h>
#include <stdio.h>

int main () {
    char str1[] = "Home Sweet Home";
    printf("String is: %s\n", str1);
    printf("String after memmove() is: %s\n", (char *) memmove(str1, str1 + 5, 10));
    

}