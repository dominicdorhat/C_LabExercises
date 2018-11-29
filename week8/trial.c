#include <stdio.h>

struct stock {
    char *name;
    char *code;
} stockA[5];

int main () {
    stockA[5].name = "hello";
}