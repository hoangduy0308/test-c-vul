#include <stdio.h>
#include <string.h>

/*
 * Safe Stack Buffer Usage
 * 
 * Description:
 * This example demonstrates how to safely handle string copying to a stack buffer
 * to PREVENT a Stack Buffer Overflow vulnerability.
 * 
 * Instead of using unsafe functions like strcpy, we use snprintf (or strncpy with care)
 * to ensure we never write past the end of the allocated buffer.
 */

void safe_function(const char *input) {
    // Fixed-size buffer on the stack
    char buffer[64];

    // FIX: Use snprintf instead of strcpy.
    // snprintf limits the number of bytes written to the buffer size.
    // It guarantees null-termination as long as the buffer size is > 0.
    // Format: snprintf(destination, size, format, source)
    snprintf(buffer, sizeof(buffer), "%s", input);

    printf("Buffer content (safely truncated if needed): %s\n", buffer);
}

int main(int argc, char *argv[]) {
    // Create a string that is larger than the buffer size (64 bytes)
    char large_input[100];
    memset(large_input, 'A', 99);
    large_input[99] = '\0';

    printf("Calling safe function with %zu bytes...\n", strlen(large_input));
    
    // This will NOT crash or corrupt the stack
    safe_function(large_input);

    printf("Function returned successfully. No overflow occurred.\n");

    return 0;
}
