#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    char st[1024];
    char title_input[100], author_input[100], subject_input[100];
    char test1[100], test2[100], test3[100];

    book Book;

    // library *first = NULL;

    do {
        printf("? ");
        fgets(st, sizeof(st), stdin);
        valid_input = sscanf(st, "%d", &choice);

        switch(choice) {
            case 1:
                valid_input = 0;
                while (1) {
                    printf("Enter title: ");
                    fgets(title_input, sizeof(title_input), stdin);
                    printf("Enter author: ");
                    fgets(author_input, sizeof(author_input), stdin);
                    printf("Enter subject: ");
                    fgets(subject_input, sizeof(subject_input), stdin);

                    if (strlen(title_input) <= CHARLIMIT ) {                        
                        sscanf(title_input, "%s", test1);
                        printf("%s\n", test1);            
                        // TODO: Check for existing title             
                    } else {
                        printf("Book title too long! \n");
                        break;
                    }

                    if (strlen(author_input) <= CHARLIMIT ){
                        sscanf(author_input, "%s", test2);
                        printf("%s\n", test2);
                    } else {
                        printf("Book author too long!\n");
                        break;
                    }

                    if (strlen(subject_input) <= CHARLIMIT ){
                        sscanf(subject_input, "%s", test3);
                        printf("%s\n", test3);
                    } else {
                        printf("Subject name too long!\n");
                        break;
                    }
                    break;
                }
                printf("pass\n");                
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