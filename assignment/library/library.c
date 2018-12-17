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

void copybook(book *, book *);
void writeToOutput(char *);

library *addbook(library *,FILE *);
library *deleteBook(library *, FILE *);

library *addToLibraryList(library **, char *, char *, char * );
library *deleteFromLibraryList(library *, char *);

int searchForBook(library *list, char *detail);
void searchListByAuthor(library *, FILE *, int);
void searchListBySubject(library *, FILE *, int);

#define CHAR_LIMIT 49
#define MAX_UPDATES 100
#define LIBRARY_FILE "library.txt"
#define OUTPUT_FILE "output.txt"

int main () {
    int instructions, i = 0, j = 0;
    unsigned int updates = 0;

    // buffers
    char out_msg[1024], book_search[1024], error_msg[1024];

    // initialized library as linked list
    library *head = (library *)malloc(sizeof(library));
    head = NULL;

    FILE *fp;
    FILE *fp2;
    if ((fp = fopen(LIBRARY_FILE, "a+")) == NULL)
    {
        snprintf(error_msg, sizeof(error_msg), "Error: %s cannot be opened.\n", LIBRARY_FILE);
        fprintf(stderr, error_msg);
        writeToOutput(error_msg);
        return 0;
    }

    // empty output.txt
    if ((fp2 = fopen(OUTPUT_FILE, "w")) == NULL)
    {
        snprintf(error_msg, sizeof(error_msg), "Error: %s cannot be opened.\n", OUTPUT_FILE);
        fprintf(stderr, error_msg);
        writeToOutput(error_msg);
        return 0;
    }
    fclose(fp2);

    fscanf(fp, "%d", &updates);

    for(i = 0; i < updates && i <= MAX_UPDATES; i++) {
        fscanf(fp, "%d", &instructions);
        switch(instructions) {
            case 1:                
                head = addbook(head, fp);
                break;
                
            case 2:
                head = deleteBook(head, fp);
                break;

            case 3:                
                fscanf(fp, "%s", book_search);
                if ((searchForBook(head, book_search)) != 0) {
                    snprintf(out_msg, sizeof(out_msg), "The book %s is currently in the library.\n", book_search);
                } else {
                    snprintf(out_msg, sizeof(out_msg), "The book %s is NOT currently in the library.\n", book_search);
                }
                puts(out_msg);
                writeToOutput(out_msg);
                break;

            case 4:
                // list all by author, ascending order for title
                searchListByAuthor(head, fp, head->num_books);
                break;
            case 5:
                // list all by subject, descending order for title
                searchListBySubject(head, fp, head->num_books);
                 break;
        }
    }

    fclose(fp);
    return 0;
}




/* function declarations */

void copybook(book *dest, book *source)
{
    strcpy(dest->author, source->author);
    strcpy(dest->subject, source->subject);
    strcpy(dest->title, source->title);
}

int searchForBook(library *list, char *detail)
{    
    while (list != NULL)
    {
        if (strcmp(list->collection.title, detail) == 0)
        {
            return 1;
        } else {
            list = list->next;
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
        fprintf(fp, "%s", msg);
        fprintf(fp, "\n");
        fclose(fp);
    }
}

library *addbook(library *list, FILE *file) {
    char out_msg[1024], book_title[50], book_author[50], book_subject[50];    
    int count = 0;

    // initialize counter to check total of books in library
    if (list == NULL) {
        count = 1;
    } else {
        count = list->num_books;
        count++;
    }


    book *Book = malloc(sizeof *Book);
    Book->title = (char *) malloc(49);
    Book->author = (char *) malloc(49);
    Book->subject = (char *) malloc(49);

    fscanf(file, "%s%s%s", Book->title, Book->author, Book->subject);

    // check for duplicate first
    if ((searchForBook(list, Book->title)) == 0)
    {
        if (count > 100) {
            
            snprintf(out_msg, sizeof(out_msg), "Library has reached maximum capcity!\n");
            fprintf(stderr, out_msg);
            writeToOutput(out_msg);
            return list;
        }
        list = addToLibraryList(&list, Book->title, Book->author, Book->subject);
        snprintf(out_msg, sizeof(out_msg), "The book %s has been added to the library.\n", Book->title);
        puts(out_msg);
        writeToOutput(out_msg);

        free(Book);

        return list;
    } else {
        snprintf(out_msg, sizeof(out_msg), "Book %s already exists!\n", book_title);
        fprintf(stderr, out_msg);
        writeToOutput(out_msg);
        free(Book);
        return list;
    }
}

library *deleteBook(library *list, FILE *file) {
    char out_msg[1024], book_title[50];

    fscanf(file, "%s", book_title);
    if ((list = (deleteFromLibraryList(list, book_title))) != NULL)
    {
        list->num_books--;
        snprintf(out_msg, sizeof(out_msg), "The book %s has been removed from the library.\n", book_title);
        puts(out_msg);
        writeToOutput(out_msg);
        return list;
    } else {
        snprintf(out_msg, sizeof(out_msg), "Book %s not found!\n", book_title);
        fprintf(stderr, out_msg);
        writeToOutput(out_msg);
        return list;
    }
}

void searchListByAuthor(library *list, FILE *file, int total_books) {    
    char book_author[50], out_msg[1024], books[total_books][50], temp[50];
    int no_books = 0, i, j;
    
    library *cur = list;

    fscanf(file, "%s", book_author);    
    
    // temporary buffers 
    char *buffer_input, *buffer_list;
    buffer_input = malloc(strlen(book_author) + 1);
    buffer_list = malloc(strlen(book_author) + 1);

    // empty all both arrays to remove junk value
    memset(books, 0, sizeof(char[total_books][50]));
    memset(temp, 0, sizeof(temp));
    memset(out_msg, 0, sizeof(out_msg));

    // copy author to buffer
    strcpy(buffer_input, book_author);
    
    for (; cur != NULL; cur = cur->next)
    {
        // copy each subject of book in a library to buffer
            strcpy(buffer_list, cur->collection.author);
        // strupr to both buffers to compare without capitlization
        if (strcmp(strupr(buffer_list), strupr(buffer_input)) == 0)
        {            
            strcpy(books[no_books++], cur->collection.title);
        }
    }

    // bubble sort ascending order based on ASCII differerence
    for (i = 0; i < no_books; i++)
    {
        for (j = 0; j < no_books - i - 1; j++)
        {
            if ( (strcmp(books[i], books[j + 1])) > 0) {
                strcpy(temp, books[i]);
                strcpy(books[j], books[j + 1]);
                strcpy(books[j + 1], temp);
            }
        }
    }

    if(no_books > 0) {
        snprintf(out_msg, sizeof(out_msg), "List of all books by %s.\n", book_author);
        for (i = 0; i < no_books; i++) {
            if(books[i] != '\0') {
                strcat(out_msg, books[i]);
                strcat(out_msg, "\n");
            }
        }
    } else {
        snprintf(out_msg, sizeof(out_msg), "List of all books by %s.\nNo book from author %s\n", book_author, book_author);
    }
    puts(out_msg);
    writeToOutput(out_msg);
    free(buffer_input);
    free(buffer_list);
}

void searchListBySubject(library * list, FILE *file, int total_books) {
    char book_subject[50], out_msg[1024], books[total_books][50], temp[50];
    int no_books = 0, i, j;

    library *cur = list;

    fscanf(file, "%s", book_subject);

    // temporary buffers
    char *buffer_input, *buffer_list;
    buffer_input = malloc(strlen(book_subject) + 1);
    buffer_list = malloc(strlen(book_subject) + 1);

    // empty all both arrays to remove junk value
    memset(books, 0, sizeof(char[total_books][50]));
    memset(temp, 0, sizeof(temp));

    // copies subject name to a buffer 
    strcpy(buffer_input, book_subject);

    for (; cur != NULL; cur = cur->next)
    {
        // copy each subject of book in a library to buffer
        strcpy(buffer_list, cur->collection.subject);
        // strupr to both buffers to compare without capitlization
        if (strcmp(strupr(buffer_list), strupr(buffer_input)) == 0)
        {
            strcpy(books[no_books++], cur->collection.title);
        }
    }

    // bubble sort descending order based on ASCII differerence
    for (i = 0; i < no_books; i++)
    {
        for (j = 0; j < no_books - i - 1; j++)
        {
            if ((strcmp(books[i], books[j + 1])) < 0)
            {
                strcpy(temp, books[i]);
                strcpy(books[j], books[j + 1]);
                strcpy(books[j + 1], temp);
            }
        }
    }

    snprintf(out_msg, sizeof(out_msg), "List of all books on %s.\n", book_subject);

    if (no_books > 0) {
        // books related to subject are found
        snprintf(out_msg, sizeof(out_msg), "List of all books on %s.\n", book_subject);
        for (i = 0; i < no_books; i++) {
            if (books[i] != '\0') {
                strcat(out_msg, books[i]);
                strcat(out_msg, "\n");
            }
        }
    } else { // not found
        snprintf(out_msg, sizeof(out_msg), "List of all books on %s.\nNo related book for %s is found\n", book_subject, book_subject);    
    }
    puts(out_msg);
    writeToOutput(out_msg);
    free(buffer_input);
    free(buffer_list);
}

/* linked-list functions */ 
library *addToLibraryList(library **list, char *title, char * author, char *subject)
{
    char out_msg[1024];
    library *new_book = (library *) malloc(sizeof(library));

    if(new_book == NULL) {
        snprintf(out_msg, sizeof(out_msg), "Memory allocation failed!\n");
        fprintf(stderr, out_msg);
        writeToOutput(out_msg);
        exit(EXIT_FAILURE);
    }

    // new book details 
    new_book->collection.title = title;
    new_book->collection.author = author;
    new_book->collection.subject = subject;
    new_book->next = NULL; // prevent next from pointing to somewhere random

    // first insertion when no books exist
    if(*list == NULL) {
        *list = new_book;
        (*list)->num_books = 0;
        (*list)->num_books++;
         
        return *list;

    } else {
        (*list)->num_books++;
        library *offset = *list;
        for(; offset->next != NULL; offset = offset->next)
            ;
        offset->next = new_book;
        return *list;
    }    
}

library *deleteFromLibraryList(library *list, char *details)
{
    /* algorithm: */
    // 1. search for last, search for book to be deleted and 2nd last book
    // 2. check if its first, last, or only boo in library
    // 3. copy last book into book to be deleted
    // 4. free the last, point 2nd last book to null if 2nd last book exist
    // 5. return the whole library (list)
    library *search = NULL, *prev, *last;

    // get last node/book and 2nd last book/node
    for(last = list, prev = NULL;
        last->next != NULL;
        prev = last, last = last->next)
        ;
        

    search = list;

    // if only one book
    if(search->next == NULL) {
        free(last);
        return list;
    }
    // delete first book from library
    if (strcmp(details, search->collection.title) == 0) {
        copybook(&(search->collection), &(last->collection));
        free(last);
        prev->next = NULL;
        return list;
    }   
    
    // loop through the nodes (for books in between)
    while(search != NULL) {
        if(strcmp(search->collection.title, details) == 0) {
            break;
        }
        search = search->next;
    }

    // if last book
    if(strcmp(search->collection.title, last->collection.title) == 0) {
        free(last);
        prev->next = NULL;
        return list;
    }
    
    copybook(&(search->collection), &(last->collection));
    prev->next = NULL;
    free(last);    
    return list;
}

