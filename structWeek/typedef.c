#include <stdio.h>

typedef struct {
    char *name;
    char *type;

} card;

int main (void) {

    card CardA;
    card *cardAPtr;

    CardA.name = "Aces";
    CardA.type = "Plastic";

    cardAPtr = &CardA;

    return 0;
}