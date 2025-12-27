#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

void secure_function(const char *input) {
    char buffer[64];
    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    printf("Input: %s\n", buffer);
}

void safe_input_example() {
    char password[16];
    printf("Enter password: ");
    if (fgets(password, sizeof(password), stdin) != NULL) {
        password[strcspn(password, "\n")] = '\0';
        printf("You entered: %s\n", password);
    }
}

void safe_format_string(const char *user_input) {
    printf("%s", user_input);
}

int safe_addition(int a, int b) {
    if ((b > 0 && a > INT_MAX - b) || (b < 0 && a < INT_MIN - b)) {
        printf("Integer overflow detected!\n");
        return 0;
    }
    return a + b;
}

char* safe_memory_usage() {
    char *ptr = (char*)malloc(100);
    if (ptr == NULL) return NULL;
    strcpy(ptr, "Hello");
    return ptr;
}

void safe_pointer_usage(const char *ptr) {
    if (ptr != NULL) {
        printf("%s\n", ptr);
    }
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        secure_function(argv[1]);
        safe_format_string(argv[1]);
    }
    
    safe_input_example();
    safe_addition(100, 200);
    safe_pointer_usage("Safe string");
    
    char *mem = safe_memory_usage();
    if (mem != NULL) {
        printf("%s\n", mem);
        free(mem);
    }
    
    return 0;
}
