#include <stdio.h>
#include <stdlib.h>

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
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

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int main(void) {
    int numbers[5] = {10, 25, 8, 42, 17};
    
    printf("Sum: %d\n", add(5, 3));
    printf("Product: %d\n", multiply(4, 7));
    
    printf("Array: ");
    print_array(numbers, 5);
    
    printf("Max: %d\n", find_max(numbers, 5));
    printf("Factorial of 5: %d\n", factorial(5));
    
    return 0;
}
