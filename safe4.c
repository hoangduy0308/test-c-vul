#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Proper malloc + free usage
// This should score LOW (~43%) because it follows safe patterns

char* create_buffer(size_t size) {
    if (size == 0 || size > 10000) {
        return NULL;
    }
    
    char *buf = malloc(size);
    if (buf == NULL) {
        return NULL;
    }
    
    memset(buf, 0, size);
    return buf;
}

void process_buffer(char *buf, size_t size, const char *data) {
    if (buf == NULL || data == NULL || size == 0) {
        return;
    }
    
    size_t len = strlen(data);
    if (len >= size) {
        len = size - 1;
    }
    
    memcpy(buf, data, len);
    buf[len] = '\0';
}

void free_buffer(char *buf) {
    if (buf != NULL) {
        free(buf);
    }
}

int main(int argc, char *argv[]) {
    char *buffer = create_buffer(64);
    
    if (buffer != NULL) {
        if (argc > 1) {
            process_buffer(buffer, 64, argv[1]);
            printf("Data: %s\n", buffer);
        }
        free_buffer(buffer);
    }
    
    return 0;
}
