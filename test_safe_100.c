/**
 * Safe C Program - 100 lines
 * Demonstrates secure coding practices
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_LEN 64
#define MAX_ITEMS 100

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    double value;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    size_t count;
} ItemList;

void init_list(ItemList *list) {
    if (list == NULL) {
        return;
    }
    list->count = 0;
    memset(list->items, 0, sizeof(list->items));
}

bool add_item(ItemList *list, int id, const char *name, double value) {
    if (list == NULL || name == NULL) {
        return false;
    }
    if (list->count >= MAX_ITEMS) {
        return false;
    }
    
    Item *item = &list->items[list->count];
    item->id = id;
    strncpy(item->name, name, MAX_NAME_LEN - 1);
    item->name[MAX_NAME_LEN - 1] = '\0';
    item->value = value;
    list->count++;
    
    return true;
}

Item *find_item(ItemList *list, int id) {
    if (list == NULL) {
        return NULL;
    }
    
    for (size_t i = 0; i < list->count; i++) {
        if (list->items[i].id == id) {
            return &list->items[i];
        }
    }
    return NULL;
}

double calculate_total(const ItemList *list) {
    if (list == NULL) {
        return 0.0;
    }
    
    double total = 0.0;
    for (size_t i = 0; i < list->count; i++) {
        total += list->items[i].value;
    }
    return total;
}

void print_item(const Item *item) {
    if (item == NULL) {
        printf("(null item)\n");
        return;
    }
    printf("ID: %d, Name: %s, Value: %.2f\n", 
           item->id, item->name, item->value);
}

void print_list(const ItemList *list) {
    if (list == NULL) {
        printf("(null list)\n");
        return;
    }
    
    printf("=== Item List (%zu items) ===\n", list->count);
    for (size_t i = 0; i < list->count; i++) {
        print_item(&list->items[i]);
    }
    printf("Total value: %.2f\n", calculate_total(list));
}

int main(void) {
    ItemList inventory;
    init_list(&inventory);
    
    add_item(&inventory, 1, "Apple", 1.50);
    add_item(&inventory, 2, "Banana", 0.75);
    add_item(&inventory, 3, "Orange", 2.00);
    
    print_list(&inventory);
    
    Item *found = find_item(&inventory, 2);
    if (found != NULL) {
        printf("\nFound: ");
        print_item(found);
    }
    
    return 0;
}
