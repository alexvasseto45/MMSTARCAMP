#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define COUNT 10

struct Book {
    char title[150];
    char author[100];
    int pages;
    double price;
    struct Book *next;
};

int cmpTitle(const void *a, const void *b) {
    return strcmp(((struct Book *)a)->title, ((struct Book *)b)->title);
}

void freeList(struct Book *head) {
    while (head != NULL) {
        struct Book *temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    srand(time(NULL));
    struct Book *head = NULL;
    for (int i = 0; i < COUNT; i++) {
        struct Book *newBook = (struct Book *)malloc(sizeof(struct Book));
        if (newBook == NULL) {
            printf("Not allocated");
            freeList(head);
            return 1;
        }
        char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int titleLength = rand() % 11 + 10;
        int authorLength = rand() % 11 + 10;
        for (int j = 0; j < titleLength; j++) {
            newBook->title[j] = alphabet[rand() % (sizeof(alphabet) - 1)];
        }
        newBook->title[titleLength] = '\0';
        for (int j = 0; j < authorLength; j++) {
            newBook->author[j] = alphabet[rand() % (sizeof(alphabet) - 1)];
        }
        newBook->author[authorLength] = '\0';
        newBook->pages = rand() % 1996 + 5;
        newBook->price = (rand() % 100000) / 100.0;
        newBook->next = head;
        head = newBook;
    }
    struct Book *bookArray = (struct Book *)malloc(COUNT * sizeof(struct Book));
    if (bookArray == NULL) {
        printf("Not allocated");
        freeList(head);
        return 1;
    }
    int i = 0;
    struct Book *current = head;
    while (current != NULL) {
        bookArray[i] = *current;
        i++;
        current = current->next;
    }
    qsort(bookArray, COUNT, sizeof(struct Book), cmpTitle);
    printf("Sorted Book List:\n");
    for (int i = 0; i < COUNT; i++) {
        printf("Title: %s\n", bookArray[i].title);
        printf("Author: %s\n", bookArray[i].author);
        printf("Pages: %d\n", bookArray[i].pages);
        printf("Price: %.2f\n", bookArray[i].price);
    }
    freeList(head);
    free(bookArray);
    return 0;
}