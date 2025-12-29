#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process_input(const char *input) {
    if (input == NULL) {
        return;
    }
    char local[64];
    size_t len = strlen(input);
    if (len >= sizeof(local)) {
        len = sizeof(local) - 1;
    }
    memcpy(local, input, len);
    local[len] = '\0';
    printf("%s\n", local);
}

char* get_data(size_t size) {
    if (size == 0 || size > 1024) {
        return NULL;
    }
    char *buf = malloc(size);
    if (buf == NULL) {
        return NULL;
    }
    memset(buf, 0, size);
    return buf;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input>\n", argv[0]);
        return 1;
    }
    
    process_input(argv[1]);
    
    char *data = get_data(32);
    if (data != NULL) {
        strncpy(data, argv[1], 31);
        data[31] = '\0';
        printf("%s\n", data);
        free(data);
    }
    
    return 0;
}
