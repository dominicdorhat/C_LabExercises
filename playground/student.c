#include <stdio.h>

typedef struct {
    char *c;
}student;

int main () {
    student m;
    student *s = &m;
    scanf("%s\n", s->c);
    // s->c = "hello";
    printf("%s", m.c);
    return 0;
    
}