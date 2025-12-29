#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void buffer_overflow_example(char *input) {
    char buffer[10];
    strcpy(buffer, input);  // Buffer overflow vulnerability
    printf("Buffer: %s\n", buffer);
}

char* use_after_free_example() {
    char *ptr = (char*)malloc(100);
    strcpy(ptr, "Hello");
    free(ptr);
    return ptr;  // Use after free vulnerability
}

void format_string_example(char *user_input) {
    printf(user_input);  // Format string vulnerability
}

void sql_injection_example(char *username) {
    char query[256];
    sprintf(query, "SELECT * FROM users WHERE name = '%s'", username);  // SQL injection
    printf("Query: %s\n", query);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input>\n", argv[0]);
        return 1;
    }

    buffer_overflow_example(argv[1]);
    
    char *dangling = use_after_free_example();
    printf("Dangling: %s\n", dangling);  // Accessing freed memory
    
    format_string_example(argv[1]);
    
    sql_injection_example(argv[1]);
    
    return 0;
}
