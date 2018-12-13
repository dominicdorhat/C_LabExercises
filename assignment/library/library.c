#include <stdio.h>
#include <stdlib.h>

typedef struct book {
    char *title;
    char *author;
    char *subject;
} book;

// linked list
typedef struct {
    struct book collection;
    int num_books;
    struct library *next;
} library;

void copybook(book *dest, book *source);
void addbook(library *thislib);

#define CHARLIMIT 49

int main () {
    int choice, valid_input;
    unsigned int updates;
    char st[1024], title_input[CHARLIMIT];

    book Book;

    // library *first = NULL;

    do {
        printf("? ");
        fgets(st, sizeof(st), stdin);
        valid_input = sscanf(st, "%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter title: ");
                
                if(fgets(title_input, sizeof(title_input), stdin)!= NULL) {
                    sscanf(title_input, "%s", Book.title);

                } else {
                    puts("Book title too long");
                }
                
                printf("Enter author: ");
                printf("Enter subject: ");
                break;
            case 2:
                printf("pass2\n");
                break;
            case 3:
                printf("pass3\n");
                break;
            case 4:
                printf("pass4\n");
                break;
            case 5:
                printf("pass5\n");
                break;
            default:    
                printf("Wrong input!\n");
        }
    } while (valid_input < 1);

    return 0;
}