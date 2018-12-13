#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    struct node *next;
} node;

int main () {

    node *first = NULL; // first in the empty list 

    first = add_to_list(first, 10);
    first = add_to_list(first, 20);

    return 0;
}

node *add_to_list(node *list, int n) {
    node *new_node;

    new_node = malloc(sizeof(node));
    if(new_node == NULL) {
        printf("Error: malloc failed!\n");
        exit(EXIT_FAILURE);
    }

    new_node->value = n;
    new_node->next = list;
    return new_node;
}

node *searchList(node *list, int n) {
    for(;list != NULL; list = list->next)
        ;
    return list;
}


