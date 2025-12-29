

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME 50
#define MAX_ITEMS 10

typedef struct {
    char name[MAX_NAME];
    int quantity;
    double price;
} Product;

void to_uppercase(char *str) {
    while (*str) {
        *str = toupper((unsigned char)*str);
        str++;
    }
}

int count_vowels(const char *str) {
    int count = 0;
    while (*str) {
        char c = tolower((unsigned char)*str);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
        str++;
    }
    return count;
}

double calculate_total(Product items[], int count) {
    double total = 0.0;
    for (int i = 0; i < count; i++) {
        total += items[i].quantity * items[i].price;
    }
    return total;
}

void print_product(const Product *p) {
    printf("Product: %s\n", p->name);
    printf("Quantity: %d\n", p->quantity);
    printf("Price: %.2f\n", p->price);
    printf("Subtotal: %.2f\n\n", p->quantity * p->price);
}

int find_max(int arr[], int size) {
    if (size <= 0) return 0;
    
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int find_min(int arr[], int size) {
    if (size <= 0) return 0;
    
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

double calculate_average(int arr[], int size) {
    if (size <= 0) return 0.0;
    
    long sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (double)sum / size;
}

int is_palindrome(const char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    Product products[3] = {
        {"Apple", 10, 1.50},
        {"Banana", 5, 0.75},
        {"Orange", 8, 2.00}
    };
    
    for (int i = 0; i < 3; i++) {
        print_product(&products[i]);
    }
    
    double total = calculate_total(products, 3);
    printf("Total: %.2f\n\n", total);
    
    int numbers[] = {23, 45, 12, 67, 34, 89, 10};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    printf("Max: %d\n", find_max(numbers, size));
    printf("Min: %d\n", find_min(numbers, size));
    printf("Average: %.2f\n\n", calculate_average(numbers, size));
    
    char word[] = "radar";
    printf("'%s' is palindrome: %s\n", word, is_palindrome(word) ? "yes" : "no");
    
    char text[] = "hello";
    printf("Vowels in '%s': %d\n", text, count_vowels(text));
    
    to_uppercase(text);
    printf("Uppercase: %s\n", text);
    
    return 0;
}
