/**
 * Semantic vulnerability example
 * 
 * This code has NO obvious dangerous APIs (no strcpy, gets, sprintf, etc.)
 * But it has real vulnerabilities that require semantic analysis to detect.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Vulnerability 1: Integer overflow leading to heap overflow
// Pattern-based: sees malloc, memcpy (safe APIs) → might not flag
// Semantic: size * sizeof(int) can overflow, causing small allocation
void process_data(int size) {
    int total = size * sizeof(int);  // Integer overflow if size > 536870911
    int *buffer = (int*)malloc(total);
    if (buffer) {
        memcpy(buffer, "data", 4);  // Heap overflow if total overflowed
        free(buffer);
    }
}

// Vulnerability 2: Off-by-one error
// Pattern-based: uses strncpy (safe API) → might not flag
// Semantic: loop goes one past the end
void safe_looking_copy(char *dst, const char *src, size_t len) {
    size_t i;
    for (i = 0; i <= len; i++) {  // BUG: should be i < len
        dst[i] = src[i];
    }
    dst[len] = '\0';
}

// Vulnerability 3: Use-after-free with complex control flow
// Pattern-based: sees proper free() usage → might not flag
// Semantic: p is used after conditional free
char* get_data(int flag, int action) {
    char *p = (char*)malloc(64);
    if (!p) return NULL;
    
    strncpy(p, "initial", 63);
    p[63] = '\0';
    
    if (flag > 0) {
        free(p);  // Free here
        p = NULL;
    }
    
    // Later logic that's hard to trace...
    if (action == 1 && flag <= 0) {
        return p;  // Safe path
    }
    
    if (action == 2) {
        // BUG: If flag > 0, p was freed but we still return it!
        // The condition doesn't properly check if p was freed
        return p;  // Use-after-free!
    }
    
    return NULL;
}

// Vulnerability 4: Double free with complex conditions
// Pattern-based: proper malloc/free pattern → might not flag
// Semantic: resource freed twice under certain conditions
void cleanup_resources(int error_code) {
    char *resource = (char*)malloc(100);
    if (!resource) return;
    
    if (error_code == 1) {
        free(resource);
        return;
    }
    
    if (error_code == 2) {
        // Do some processing
        strncpy(resource, "processed", 99);
    }
    
    if (error_code >= 1) {  // BUG: This includes error_code == 1!
        free(resource);     // Double free when error_code == 1
    }
}

// Vulnerability 5: NULL pointer dereference
// Pattern-based: has NULL checks → looks safe
// Semantic: not all paths initialize the pointer
int calculate(int type, int value) {
    int *result = NULL;
    int temp;
    
    if (type == 1) {
        temp = value * 2;
        result = &temp;
    } else if (type == 2) {
        temp = value + 10;
        result = &temp;
    }
    // BUG: If type is not 1 or 2, result is still NULL!
    
    return *result;  // NULL dereference when type != 1 && type != 2
}

// Vulnerability 6: Race condition (TOCTOU)
// Pattern-based: uses safe fopen → might not flag  
// Semantic: time-of-check to time-of-use gap
void write_to_file(const char *filename, const char *data) {
    FILE *f;
    
    // Check if file is writable
    f = fopen(filename, "r");
    if (f == NULL) {
        return;  // File doesn't exist
    }
    fclose(f);
    
    // BUG: File could be replaced between check and use!
    // Attacker could symlink to /etc/passwd here
    
    f = fopen(filename, "w");  // TOCTOU vulnerability
    if (f) {
        fprintf(f, "%s", data);
        fclose(f);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) return 1;
    
    int input = atoi(argv[1]);
    
    process_data(input);
    
    char buf[64];
    safe_looking_copy(buf, "hello", 5);
    
    char *data = get_data(input, 2);
    if (data) printf("%s\n", data);
    
    cleanup_resources(input);
    
    int result = calculate(input, 10);
    printf("Result: %d\n", result);
    
    return 0;
}
