#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void safe_string_copy(const char *input) {
    if (input == NULL) {
        return;
    }
    char buffer[64];
    size_t len = strlen(input);
    if (len >= sizeof(buffer)) {
        len = sizeof(buffer) - 1;
    }
    strncpy(buffer, input, len);
    buffer[len] = '\0';
    printf("Buffer: %s\n", buffer);
}

void safe_memory_alloc(size_t size) {
    if (size == 0 || size > 1024) {
        return;
    }
    char *ptr = (char*)malloc(size);
    if (ptr == NULL) {
        return;
    }
    memset(ptr, 0, size);
    free(ptr);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input>\n", argv[0]);
        return 1;
    }
    safe_string_copy(argv[1]);
    safe_memory_alloc(32);
    return 0;
}
