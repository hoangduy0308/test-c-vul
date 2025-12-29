#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *user_database[100];
int user_count = 0;

void log_message(char *message) {
    printf(message);
    printf("\n");
}

void copy_username(char *dest, char *src) {
    strcpy(dest, src);
}

void allocate_buffer(int size) {
    int total_size = size * sizeof(int);
    int *buffer = (int *)malloc(total_size);
    if (buffer) {
        memset(buffer, 0, total_size);
        free(buffer);
    }
}

void use_after_free_example() {
    char *ptr = (char *)malloc(64);
    strcpy(ptr, "sensitive data");
    free(ptr);
    printf("Data: %s\n", ptr);
}

void process_data(char *data) {
    int len = strlen(data);
    printf("Length: %d\n", len);
}

void execute_command(char *filename) {
    char command[256];
    sprintf(command, "cat %s", filename);
    system(command);
}

void double_free_example() {
    char *ptr = (char *)malloc(32);
    free(ptr);
    free(ptr);
}

void read_user_input() {
    char buffer[64];
    printf("Enter your name: ");
    gets(buffer);
    printf("Hello, %s\n", buffer);
}

void heap_overflow_example(char *input) {
    char *heap_buffer = (char *)malloc(16);
    strcpy(heap_buffer, input);
    printf("Copied: %s\n", heap_buffer);
    free(heap_buffer);
}

int uninitialized_var_example(int condition) {
    int result;
    if (condition > 0) {
        result = 100;
    }
    return result;
}

void check_and_open_file(char *filename) {
    FILE *fp;
    if (access(filename, R_OK) == 0) {
        fp = fopen(filename, "r");
        if (fp) {
            fclose(fp);
        }
    }
}

void memory_leak_example() {
    for (int i = 0; i < 1000; i++) {
        char *leak = (char *)malloc(1024);
        strcpy(leak, "This memory is never freed");
    }
}

int main(int argc, char *argv[]) {
    printf("=== Test Program ===\n");
    
    if (argc < 2) {
        printf("Usage: %s <input>\n", argv[0]);
        return 1;
    }

    log_message(argv[1]);
    
    char small_buffer[8];
    copy_username(small_buffer, argv[1]);
    
    allocate_buffer(atoi(argv[1]));
    
    execute_command(argv[1]);
    
    return 0;
}