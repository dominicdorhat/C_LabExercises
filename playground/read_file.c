#include <stdio.h>

int main () {
    FILE *fp;
    int c;

    // fp = fopen("file.txt", "r+");

    if ((fp = fopen("file.txt", "r+")) == NULL) {
        printf("File not found!\n");
    } else {    
        while( (c = (fgetc(fp))) != EOF ) {
            printf("%c", c);
        }
    }
    fclose(fp);
    return 0;
}