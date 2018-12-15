#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct book {
    char *title;
    char *author;
    char *subject;
} book;

// linked list
typedef struct library {
    struct book collection;
    int num_books;
    struct library *next;
} library;

void copybook(book *dest, book *source);
void addbook(library *thislib);
int writeToLibrary(int, book *);
void writeToOutput(char *);
void addToLibraryList(library **, book *);
library *searchForBook(library*, char *);
int deleteFromLibraryList(library *, book *); 
void updateCounter(unsigned int);

// temp function
void searchAll(library *);

#define CHAR_LIMIT 49
#define LIBRARY_FILE "library.txt"
#define OUTPUT_FILE "output.txt"

int main () {
    int choice, valid_input;
    unsigned int updates = 0;

    // buffers
    char st[1024], title_input[100], author_input[100], subject_input[100], out_msg[1024];    

    book *bookptr;

    library *head = (library * ) malloc(sizeof(library));
    head = NULL;

    do {
        printf("? ");
        fgets(st, sizeof(st), stdin);
        valid_input = sscanf(st, "%d", &choice);

        switch(choice) {
            case 1:
                // memory allocation
                bookptr = (book *)malloc(sizeof(book));
                bookptr->author = malloc(CHAR_LIMIT);
                bookptr->subject = malloc(CHAR_LIMIT);
                bookptr->title = malloc(CHAR_LIMIT);                

                while (1) {
                    printf("Enter title: ");
                    fgets(title_input, sizeof(title_input), stdin);
                    
                    if (strlen(title_input) >= CHAR_LIMIT)
                    {
                        printf("Book title too long! \n");
                        continue;
                        // TODO: Check for existing title with else {}
                        // better to check here
                    } 

                    printf("Enter author: ");
                    fgets(author_input, sizeof(author_input), stdin);
                    if (strlen(author_input) >= CHAR_LIMIT)
                    {
                        printf("Book author too long!\n");
                        continue;
                    }

                    printf("Enter subject: ");
                    fgets(subject_input, sizeof(subject_input), stdin);
                    if (strlen(subject_input) >= CHAR_LIMIT ){
                        printf("Subject name too long!\n");
                        continue;
                    } 

                    sscanf(title_input, "%s", bookptr->title);

                    /*  checkk for duplicate  */
                    if ((searchForBook(head, bookptr->title)) != NULL)
                    {
                        fprintf(stderr, "Book %s already exists!\n", bookptr->title);
                        // printf("Book %s already exists!\n", title_input);
                        continue;
                    }

                    sscanf(author_input, "%s", bookptr->author);
                    sscanf(subject_input, "%s", bookptr->subject);

                    addToLibraryList(&head, bookptr);                    
                    updateCounter(++updates);

                    if (writeToLibrary(choice, bookptr) != 0) {
                        snprintf(out_msg, sizeof(out_msg),"The book %s has been added to the library.", bookptr->title);
                        puts(out_msg);                    
                        writeToOutput(out_msg);
                    }
                                        
                    break;
                }
                choice = 0;
                break;

            case 2:
                printf("Enter book title to be deleted: " );     
                fgets(title_input, sizeof(title_input), stdin);
                sscanf(title_input, "%s", bookptr->title);

                if ( (deleteFromLibraryList(head, bookptr)) > 0) {
                    writeToLibrary(choice, bookptr);
                    updateCounter(++updates);
                    snprintf(out_msg, sizeof(out_msg), "The book %s has been removed from the library.", bookptr->title);
                    puts(out_msg);
                    writeToOutput(out_msg);
                } else {
                    printf("Book %s not found!\n");
                }
                           
                choice = 0;
                break;

            case 3:
                printf("Enter book title to be searched: ");
                fgets(title_input, sizeof(title_input), stdin);
                sscanf(title_input, "%s", bookptr->title);

                if ((searchForBook(head, bookptr->title)) != NULL) {                   
                    snprintf(out_msg, sizeof(out_msg), "The book %s is currently in the library.", bookptr->title);                                        
                } else {                    
                    snprintf(out_msg, sizeof(out_msg), "The book %s is NOT currently in the library.", bookptr->title);                   
                }

                writeToLibrary(choice, bookptr);
                updateCounter(++updates);
                puts(out_msg);
                writeToOutput(out_msg);

                choice = 0;
                break;
            case 4:
                searchAll(head);
                choice = 0;
                break;
            case 5:
                printf("pass5\n");
                choice = 0;
                break;
            default:    
                printf("Wrong input!\n");
        }
    } while (valid_input < 1 || choice > 5 || choice < 1);
    

    return 0;
}

/* function declaration */
int writeToLibrary(int choice, book *details) {
    // add more parameters for flag to choose what to write
    FILE *fp;
    if((fp = fopen(LIBRARY_FILE, "a+" )) == NULL) {
        fprintf(stderr, "Error: %s cannot be opened.\n", LIBRARY_FILE);
        return 0;

    } else {
        switch (choice) {
            case 1:
                if (fprintf(fp, "%d %12s %12s %12s\n", choice, details->title, details->author, details->subject) > 0)
                {
                    fclose(fp);
                    return 1;
                }
                break;
            
            case 2:
            case 3:
                if (fprintf(fp, "%d %12s\n", choice, details->title) > 0)
                {
                    fclose(fp);
                    return 1;
                }
                break;    
        }
         
    }
}

void writeToOutput(char *msg) {
    FILE *fp;
    if ((fp = fopen(OUTPUT_FILE, "a+")) == NULL) {
        fprintf(stderr, "Error: %s cannot be opened.\n", OUTPUT_FILE);        
    } else {
        fprintf(fp, "%s\n", msg);
        fprintf(fp, "\n");
        fclose(fp);
    }
}

void addToLibraryList(library **head, book *book_details) {
    library *new_book;
    new_book = malloc(sizeof(library));

    if(new_book == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    // new book details 
    new_book->collection = *book_details;    
    new_book->next = NULL; // prevent next from pointing to somewhere random

    // first insertion when no books exist
    if(*head == NULL) {
        *head = new_book;
        (*head)->num_books++;
        printf("new linked list started\n");
        return;

    } else {
        library *offset = *head;
        for(; offset->next != NULL; offset = offset->next)
            ;
        (*head)->num_books++;
        offset->next = new_book;
        printf("added to the end of the list\n");
    }    
    return;
}

library *searchForBook(library *list, char *detail) {    
    // for (; (strcmp(offset->collection.title, detail)) != 0 && offset != NULL; offset = offset->next)
    //     ;

    library *offset = list;
    while(offset != NULL ) {
        if((strcmp(offset->collection.title, detail)) == 0) { 
            printf("%s\n", offset->collection.title);
            return offset;
        }        
        offset = offset->next;
    }
    return NULL;
    // if(offset == NULL)
    //     return NULL;

    // if (offset->collection.title == detail) {
    //     return offset;
    // }

    return searchForBook(offset->next, detail);
}


void copybook(book *dest, book *source) {
    dest->author = source->author;    
    dest->subject = source->subject;
    dest->title = source->title;
}

int deleteFromLibraryList(library *list, book *details) {
    // 1. search for last and search for book to be deleted
    // 2. copy last book into first book
    // 3. free the last
    // 4. return smth to show sucess or failure
    // library *last = list;
    library *search, *prev, *last;
    

    // for(;last->next != NULL; last = last->next)
    //     ;

    for(last = list, prev = NULL;
        last->next != NULL;
        prev = last, last = last->next)
        ;
        
    if( (search = searchForBook(list, details->title)) == NULL) {
        return 0;
    }

    // book *searchPtr = &search->collection;
    // book *lastPtr = &last->collection;
    
    copybook(&(search->collection), &(last->collection));
    // prev->next = NULL;
    free(last);    
    return 1;
}



void updateCounter(unsigned int updates) {
    // find 1st integer
    // overwrite
    // skip others using scanset
    FILE *fp;

    if( (fp = fopen(LIBRARY_FILE, "r+")) == NULL ) {
        fprintf(stderr, "Error: %s cannot be opened.\n", OUTPUT_FILE);
    } else {
        if ((fgetc(fp)) > 0) {
            rewind(fp);
            fprintf(fp, "%d\n", updates);
        } else {
            fprintf(fp, "%d\n", updates);

        }
            // fprintf(fp, "%d\n", updates);
    }
    fclose(fp);
}

void searchAll(library *list) {
    library* offset = list;
    while(list != NULL) {
        printf("%s\n", offset->collection.title);
        offset = offset->next;
    }
}

