#include <stdio.h>
#define SIZE 15

size_t binarySearch(const int b[], int searchKey, size_t low, size_t high);
void printHeader(void);
void printRow(const int b[], size_t low, size_t mid, size_t high);

int main () {
    int a[SIZE], key;
    size_t i, result;

    // create data
    for (i = 0; i < SIZE; ++i) {
        a [ i ] = 2 * i;
    }

    printf("%s", "Enter a number between 0 and 28: ");
    scanf("%d", &key);

    printHeader();

    // search for key in array a
    result = binarySearch(a, key, 0, SIZE - 1);

    // display result 
    if (result != -1) {
        printf("\n%d found in array element %d\n", key, result);

        } else {
            printf("\n%d not found.\n", key);
        }

        return 0 ;
}

// binary search
size_t binarySearch(const int b [], int searchKey, size_t low, size_t high) {
    // holds middle element of array
    int middle;

    while ( low <= high) {
        // identfy middle element of subarray being searched
        middle = (low + high) / 2;

        printRow(b, low, middle, high);

        // if searched key is the middle element, return
        if (searchKey == b[middle]) {
            return middle;
        } else if (searchKey < b[middle]) {
            high = middle - 1; 
        } else {
            low = middle + 1;
        }

        // searchkey not found
    }
    return -1;
}

void printHeader(void) {
    unsigned int i; // counter

    puts("\nSubscripts: ");

    //output column head
    for (i = 0; i < SIZE; ++i) {
        printf("%3u ", i);
    }

    puts("");

    // output line of '-' characters
    for(i = 1; i < 4 * SIZE; ++i) {
        printf("%s", "-");
    }

    puts("");
}

void printRow(const int b[], size_t low, size_t mid, size_t high) {
    size_t i;

    for(i = 0; i < SIZE; ++i) {
        // display spaces if outside subarray range
        if (i < low || i > high) {
            printf("%s", "     ");

        } else if (i == mid) {
            // display middle element
            printf("%3d*", b[i]);

        } else { 
            // display other elements in array
            printf("%3d ", b [i]);
        }
    }

    puts("");
}