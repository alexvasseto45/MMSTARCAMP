#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#define ITEMS_COUNT 4

typedef struct Book{
    uint16_t number;
    char name[100];
    double quantity;
    char currency[4];
}Book ;

typedef struct Node {
    Book book;
    struct Node *next;
} Node;

typedef struct LL {
    Node *head;
    Node *tail;
} LL;




void print_linked_list(LL *ll) {
    Node *head = ll->head;
    for(;head != NULL; head=head->next) {
        // ......
        printf("%d ", head->book.number);
        printf("%s",head->book.name);
        printf("%lf",head->book.quantity);
        printf("%s",head->book.currency);
    }
    if(ll->tail != NULL) {
        //.....
        printf("\nLAST ELEMENT VALUE IS: %d\n\n", ll->tail->book.number);
    }
}

LL* init_linked_list() {
    LL *ll = (LL*)malloc(sizeof(LL));
    if(!ll) {
        perror("Could not malloc\n");
        exit(-1);
    }
    ll -> head = NULL; 
    ll -> tail = NULL;
    return ll;
}

void generateRandomValues(Book *book) {
    book->number = rand() % 100 + 1;
    for (int i = 0; i < sizeof(book->name) - 1; i++) {
        if (rand() % 2 == 0) {
            book->name[i] = 'A' + rand() % 26;
        } else {
            book->name[i] = 'a' + rand() % 26;
        }
    }
    book->name[sizeof(book->name) - 1] = '\0';
    book->quantity = (double)rand() / RAND_MAX * 100.0;

}

Node* maxBalance(Node* head){
    int max = 0;
    if(!(head)) {
        perror("Node not found\n");
        exit(-1);
    }
    for(;head !=NULL; head=head->next){
        if(*(head->book.currency)>max){
            max = *(head->book.currency);
        }
    }
    printf("%d",max);
    return head;
}
double totalBalance(Node* head){
    double sum = 0;
    if(!(head)) {
        perror("Node not found\n");
        exit(-1);
    }
    for(;head != NULL; head=head->next){
        sum+=head->book.quantity;
    }
    return sum;
}


int main(){

}