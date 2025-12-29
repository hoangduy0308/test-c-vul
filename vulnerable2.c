#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void integer_overflow(int size) {
    int total = size * 100;  // Integer overflow vulnerability
    char *buffer = (char*)malloc(total);
    if (buffer) {
        memset(buffer, 'A', size * 100);  // Heap overflow if integer overflowed
        free(buffer);
    }
}

void null_pointer_dereference(char *ptr) {
    int len = strlen(ptr);  // No NULL check - null pointer dereference
    printf("Length: %d\n", len);
}

void command_injection(char *filename) {
    char cmd[256];
    sprintf(cmd, "cat %s", filename);  // Command injection vulnerability
    system(cmd);
}

void stack_buffer_overflow() {
    char password[8];
    printf("Enter password: ");
    gets(password);  // Dangerous - no bounds checking
    printf("You entered: %s\n", password);
}

int* dangling_pointer() {
    int local_var = 42;
    return &local_var;  // Returning address of local variable
}

void double_free_example() {
    char *ptr = (char*)malloc(50);
    free(ptr);
    free(ptr);  // Double free vulnerability
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        null_pointer_dereference(argv[1]);
        command_injection(argv[1]);
        integer_overflow(atoi(argv[1]));
    }
    
    stack_buffer_overflow();
    
    int *bad_ptr = dangling_pointer();
    printf("Value: %d\n", *bad_ptr);  // Undefined behavior
    
    double_free_example();
    
    return 0;
}
