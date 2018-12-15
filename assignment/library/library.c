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
library *addbook(library *list, book* Book, FILE *file);
void writeToOutput(char *);
library *addToLibraryList(library **, book* );
int searchForBook(library *list, char  *detail);
library *deleteFromLibraryList(library *, char *);
library *deleteBook(library *, book*, FILE *);

    // temp function
void searchAll(library *);

#define CHAR_LIMIT 49
#define LIBRARY_FILE "library.txt"
#define OUTPUT_FILE "output.txt"

int main () {
    int instructions, valid_input, i;
    unsigned int updates = 0;

    // buffers
    // char st[1024], title_input[100], author_input[100], subject_input[100], out_msg[1024];
    char out_msg[1024];

    book *Book;
    library *head = (library *)malloc(sizeof(library));
    head = NULL;

    FILE *fp;
    if ((fp = fopen(LIBRARY_FILE, "a+")) == NULL)
    {
        fprintf(stderr, "Error: %s cannot be opened.\n", LIBRARY_FILE);
        return 0;
    }

    fscanf(fp, "%d", &updates);

    for(i = 0; i < updates; i++) {
        fscanf(fp, "%d", &instructions);
        switch(instructions) {
            case 1:
                Book = (book *)malloc(sizeof(book));
                Book->title = malloc(sizeof(CHAR_LIMIT));
                Book->author = malloc(sizeof(CHAR_LIMIT));
                Book->subject = malloc(sizeof(CHAR_LIMIT));
                head = addbook(head, Book, fp);
                free(Book);
                break;
                
            case 2:
                Book = (book *)malloc(sizeof(book));
                Book->title = malloc(sizeof(CHAR_LIMIT));
                Book->author = malloc(sizeof(CHAR_LIMIT));
                Book->subject = malloc(sizeof(CHAR_LIMIT));
                head = deleteBook(head, Book, fp);
                free(Book);
                break;

            case 3:
                Book = (book *)malloc(sizeof(book));
                Book->title = malloc(sizeof(CHAR_LIMIT));
                Book->author = malloc(sizeof(CHAR_LIMIT));
                Book->subject = malloc(sizeof(CHAR_LIMIT));
                fscanf(fp, "%s", Book->title);
                if ((searchForBook(head, Book->title)) != 0) {
                    snprintf(out_msg, sizeof(out_msg), "The book %s is currently in the library.", Book->title);
                } else {
                    snprintf(out_msg, sizeof(out_msg), "The book %s is NOT currently in the library.", Book->title);
                }
                puts(out_msg);
                writeToOutput(out_msg);
                free(Book);
                break;

            // case 4:
            // case 5:
        }
    }


    fclose(fp);

    return 0;
}

/* function declaration */

void copybook(book *dest, book *source)
{
    strcpy(dest->author, source->author);
    strcpy(dest->subject, source->subject);
    strcpy(dest->title, source->title);
}

int searchForBook(library *list, char *detail)
{    
    library *offset = list;
    while (offset != NULL)
    {
        if (strcmp(offset->collection.title, detail) == 0)
        {
            return 1;
        } else {
            offset = offset->next;
        }
    }
    return 0;
}

void writeToOutput(char *msg)
{
    FILE *fp;
    if ((fp = fopen(OUTPUT_FILE, "a+")) == NULL)
    {
        fprintf(stderr, "Error: %s cannot be opened.\n", OUTPUT_FILE);
    }
    else
    {
        fprintf(fp, "%s\n", msg);
        fprintf(fp, "\n");
        fclose(fp);
    }
}

library *addbook(library *list, book *Book, FILE *file) {
    //TODO: do character length checking if possible
    char out_msg[1024];    

    fscanf(file, "%s%s%s", Book->title, Book->author, Book->subject);  
    
    // check for duplicate first  
    if ((searchForBook(list, Book->title)) == 0) {
        list = addToLibraryList(&list, Book);
        snprintf(out_msg, sizeof(out_msg), "The book %s has been added to the library.", Book->title);
        puts(out_msg);
        writeToOutput(out_msg);
        return list;
    } else {
        fprintf(stderr, "Book %s already exists!\n", Book->title);
        return NULL;
    }    
}

library *deleteBook(library *list, book *Book, FILE *file) {
    char out_msg[1024];

    fscanf(file, "%s", Book->title);
    if ((list = (deleteFromLibraryList(list, Book->title))) != NULL)
    {
        snprintf(out_msg, sizeof(out_msg), "The book %s has been removed from the library.", Book->title);
        puts(out_msg);
        writeToOutput(out_msg);
        return list;
    } else {
        fprintf(stderr, "Book %s not found!", Book->title);
        return list;
    }
}

/* linked-list functions */ 
library *addToLibraryList(library **list, book *book_details)
{
    library *new_book = (library *) malloc(sizeof(library));
        // new_book;
    printf("%p\n", new_book);

    if(new_book == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);        
    }

    // new book details 
    new_book->collection = *book_details;    
    new_book->next = NULL; // prevent next from pointing to somewhere random

    // first insertion when no books exist
    if(*list == NULL) {
        *list = new_book;
        (*list)->num_books++;
        printf("new linked list started\n");
         
        return *list;

    } else {
        library *offset = *list;
        for(; offset->next != NULL; offset = offset->next)
            ;
        (*list)->num_books++;
        offset->next = new_book;
        printf("added to the end of the list\n");
    }    
    return *list;
}

library *deleteFromLibraryList(library *list, char *details)
{
    // 1. search for last and search for book to be deleted
    // 2. copy last book into first book
    // 3. free the last
    // 4. return smth to show sucess or failure
    library *search = NULL, *prev, *last;

    for(last = list, prev = NULL;
        last->next != NULL;
        prev = last, last = last->next)
        ;
        

    search = list;
    // if first node
    if (strcmp(details, search->collection.title) == 0) {
        copybook(&(search->collection), &(last->collection));
        free(last);
        printf("first node detected for deletion\n");
        return list;
    }   
    
    // loop through the nodes
    while(search != NULL) {
        if(strcmp(search->collection.title, details) == 0) {
            printf("other nodes detected for deletion\n");
            break;
        }
        search = search->next;
    }
    
    copybook(&(search->collection), &(last->collection));
    // prev->next = NULL;
    free(last);    
    return list;
}


void searchAll(library *list)
{
    library *offset = list;
    while(offset!= NULL) {
        // if (offset->next == NULL)
        //     return;
        printf("%s\n", offset->collection.title);
        offset = offset->next;
    }
}
