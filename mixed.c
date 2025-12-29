#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Safe function - properly checks bounds
void safe_copy(const char *input, size_t max_len) {
    char buffer[64];
    if (input == NULL) {
        return;
    }
    size_t len = strlen(input);
    if (len >= sizeof(buffer)) {
        len = sizeof(buffer) - 1;
    }
    strncpy(buffer, input, len);
    buffer[len] = '\0';
    printf("Safe buffer: %s\n", buffer);
}

// Vulnerable function - buffer overflow
void unsafe_copy(char *input) {
    char buffer[16];
    strcpy(buffer, input);  // No bounds checking - buffer overflow
    printf("Unsafe buffer: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input>\n", argv[0]);
        return 1;
    }

    safe_copy(argv[1], sizeof(argv[1]));
    unsafe_copy(argv[1]);

    return 0;
}
