


int main () {
    do
    {
        printf("? ");
        fgets(st, sizeof(st), stdin);
        valid_input = sscanf(st, "%d", &choice);

        switch (choice)
        {
        case 1:
            // memory allocation
            bookptr = (book *)malloc(sizeof(book));
            bookptr->author = malloc(CHAR_LIMIT);
            bookptr->subject = malloc(CHAR_LIMIT);
            bookptr->title = malloc(CHAR_LIMIT);

            while (1)
            {
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
                if (strlen(subject_input) >= CHAR_LIMIT)
                {
                    printf("Subject name too long!\n");
                    continue;
                }

                sscanf(title_input, "%s", bookptr->title);

                /*  checkk for duplicate  */
                if ((searchForBook(head, bookptr->title)) != 0)
                {
                    fprintf(stderr, "Book %s already exists!\n", bookptr->title);
                    // printf("Book %s already exists!\n", title_input);
                    continue;
                }

                sscanf(author_input, "%s", bookptr->author);
                sscanf(subject_input, "%s", bookptr->subject);

                addToLibraryList(&head, bookptr);

                if (writeToLibrary(choice, bookptr) != 0)
                {
                    snprintf(out_msg, sizeof(out_msg), "The book %s has been added to the library.", bookptr->title);
                    puts(out_msg);
                    writeToOutput(out_msg);
                }
                // bookptr = NULL;

                break;
            }
            choice = 0;
            break;

        case 2:
            printf("Enter book title to be deleted: ");
            scanf("%s", title_input);
            // fgets(title_input, sizeof(title_input), stdin);
            // sscanf(title_input, "%s", bookptr->title);

            if ((deleteFromLibraryList(head, title_input)) > 0)
            {
                writeToLibrary(choice, bookptr);
                snprintf(out_msg, sizeof(out_msg), "The book %s has been removed from the library.", title_input);
                puts(out_msg);
                writeToOutput(out_msg);
            }
            else
            {
                printf("Book %s not found!\n");
            }

            choice = 0;
            break;

        case 3:
            printf("Enter book title to be searched: ");
            scanf("%s", title_input);
            // fgets(title_input, sizeof(title_input), stdin);
            // sscanf(title_input, "%s", bookptr->title);

            if ((searchForBook(head, title_input)) != 0)
            {
                snprintf(out_msg, sizeof(out_msg), "The book %s is currently in the library.", title_input);
            }
            else
            {
                snprintf(out_msg, sizeof(out_msg), "The book %s is NOT currently in the library.", title_input);
            }

            writeToLibrary(choice, bookptr);
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
            // default:
            // printf("Wrong input!\n");
        }
    } while (1);
}
    




int writeToLibrary(int choice, book *details)
{
    // add more parameters for flag to choose what to write
    FILE *fp;
    if ((fp = fopen(LIBRARY_FILE, "a+")) == NULL)
    {
        fprintf(stderr, "Error: %s cannot be opened.\n", LIBRARY_FILE);
        return 0;
    }
    else
    {
        switch (choice)
        {
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

void updateCounter(unsigned int updates)
{
    // find 1st integer
    // overwrite
    // skip others using scanset
    FILE *fp;

    if ((fp = fopen(LIBRARY_FILE, "r+")) == NULL)
    {
        fprintf(stderr, "Error: %s cannot be opened.\n", OUTPUT_FILE);
    }
    else
    {
        if ((fgetc(fp)) > 0)
        {
            rewind(fp);
            fprintf(fp, "%d\n", updates);
        }
        else
        {
            fprintf(fp, "%d\n", updates);
        }
        // fprintf(fp, "%d\n", updates);
    }
    fclose(fp);
}