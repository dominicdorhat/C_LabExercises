#include <stdio.h>
#include <string.h>

struct card {
    char name[20]; 
    char *name2;
    int a;
    int b;
};

struct human {
    char *hair;
    char *race;
} Woman;

int main (void) {

    struct card Card;
    strcpy(Card.name, "aces");

    // Card.name[] = "aces"; // error since reassigning array without new size
    // Card.name2 = "acess";
    Card.a = 1; // no error
    // printf("%d", sizeof(Card.name2));
    // printf("%s\n", Card.name);
    // Card = {"aces", 1, 2}; // error
    // struct card Card = {"aces", 1, 2};
    // struct human Man;
    // struct human *ManPtr;
    // struct human *WomanPtr;
    
    // Man.hair = "black"; // possiblr if pointer
    // Man.race = "iban";

    // Woman.hair = "long";
    // Woman.race = "melanau";

    // ManPtr = &Man;
    // WomanPtr = &Woman;

    // printf("Card name:%s \n", Card.name);
    // printf("Card no: %d \n\n", Card.a);

    // printf("Man's hair: %s\n", Man.hair);
    // printf("Man's race via Ptr: %s\n\n", ManPtr->race);

    // printf("Man's race via dot: %s\n", (*ManPtr).race);
    // printf("Woman's hair: %s \n", WomanPtr->hair);
    // printf("Woman's race: %s \n\n", (* WomanPtr).race);


    return 0;
}

