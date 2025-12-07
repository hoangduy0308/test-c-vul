/* test_vulnerable.c - Test file for vulnerability scanner */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* CWE-121: Stack-Based Buffer Overflow */
void stack_buffer_overflow() {
    char buffer[10];
    char source[] = "This string is way too long for the buffer";
    strcpy(buffer, source);  // VULNERABLE: No bounds checking
    printf("%s\n", buffer);
}

/* CWE-122: Heap-Based Buffer Overflow */
void heap_buffer_overflow() {
    char *buffer = (char *)malloc(10);
    if (buffer == NULL) return;
    
    char source[] = "This is also too long for heap buffer";
    memcpy(buffer, source, strlen(source));  // VULNERABLE: Overflow
    
    free(buffer);
}

/* CWE-415: Double Free */
void double_free() {
    char *ptr = (char *)malloc(100);
    if (ptr == NULL) return;
    
    free(ptr);
    free(ptr);  // VULNERABLE: Double free
}

/* CWE-416: Use After Free */
void use_after_free() {
    char *data = (char *)malloc(50);
    if (data == NULL) return;
    
    strcpy(data, "Hello");
    free(data);
    
    printf("%s\n", data);  // VULNERABLE: Use after free
}

/* CWE-476: NULL Pointer Dereference */
void null_pointer_deref(char *input) {
    char *ptr = NULL;
    
    if (input != NULL) {
        ptr = input;
    }
    
    printf("%c\n", *ptr);  // VULNERABLE: ptr could be NULL
}

/* CWE-190: Integer Overflow */
void integer_overflow() {
    int a = 2147483647;  // INT_MAX
    int b = a + 1;       // VULNERABLE: Integer overflow
    
    char *buffer = (char *)malloc(b);
    if (buffer) free(buffer);
}

/* CWE-401: Memory Leak */
void memory_leak() {
    char *data = (char *)malloc(100);
    if (data == NULL) return;
    
    strcpy(data, "Leaked memory");
    // VULNERABLE: No free() - memory leak
    return;
}

int main() {
    printf("Vulnerability test file\n");
    return 0;
}
