#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Product
{
    double old_price;
    double new_price;
    unsigned int id;
    char product_type;
    char product_name[21];
};

void generateRandomProducts(struct Product products[], int count)
{
    const char *productNames[] = {"a", "b", "c", "d"};
    const int names = sizeof(productNames) / sizeof(productNames[0]);

    srand(time(NULL));
    for (int i = 0; i < count; i++)
    {
        products[i].old_price = 4.99 + (rand() % 961) / 100.0; 
        products[i].new_price = 4.99 + (rand() % 961) / 100.0;
        products[i].id = i + 1;
        products[i].product_type = 'A' + rand() % 4;
        strcpy(products[i].product_name, productNames[rand() % names]);
    }
}

int compareProducts(const void *a, const void *b)
{
    struct Product *productA = (struct Product *)a;
    struct Product *productB = (struct Product *)b;

    double diff = productB->new_price - productB->old_price - (productA->new_price - productA->old_price);
    if (diff > 0.01){
        return 1;
    }
    else if (diff < -0.01){
        return -1;
    }
    if (productA->product_type != productB->product_type){
        return productA->product_type - productB->product_type;
    }
    int nameCmp = strcmp(productA->product_name, productB->product_name);
    if (nameCmp != 0){
        return nameCmp;
    }
    return productA->id - productB->id;
}

int main()
{
    struct Product products[40];

    generateRandomProducts(products, 40);

    printf("Unsorted:\n");
    for (int i = 0; i < 40; i++)
    {
        printf("ID: %u, Type: %c, Name: %s, Old Price: %.2f, New Price: %.2f\n",
               products[i].id, products[i].product_type, products[i].product_name,
               products[i].old_price, products[i].new_price);
    }

    qsort(products, 40, sizeof(struct Product), compareProducts);

    printf("\nSorted:\n");
    for (int i = 0; i < 40; i++)
    {
        printf("ID: %u, Type: %c, Name: %s, Old Price: %.2f, New Price: %.2f\n",
               products[i].id, products[i].product_type, products[i].product_name,
               products[i].old_price, products[i].new_price);
    }

    return 0;
}