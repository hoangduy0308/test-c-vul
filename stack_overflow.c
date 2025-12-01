#include <stdio.h>
#include <string.h>

/*
 * CWE-121: Stack-based Buffer Overflow
 * 
 * Description:
 * This example demonstrates a classic stack buffer overflow vulnerability.
 * The function 'vulnerable_function' allocates a fixed-size buffer on the stack
 * and uses 'strcpy' to copy user-provided input into it without checking the length.
 */

void vulnerable_function(const char *input) {
    // Fixed-size buffer on the stack
    char buffer[64];

    // VULNERABILITY: strcpy does not check if the input string fits in the buffer.
    // If input is larger than 63 characters, it will overflow 'buffer' and corrupt
    // the stack (e.g., return address, saved frame pointer).
    strcpy(buffer, input);

    printf("Buffer content: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    // Create a string that is larger than the buffer size (64 bytes)
    char large_input[100];
    memset(large_input, 'A', 99);
    large_input[99] = '\0';

    printf("Calling vulnerable function with %zu bytes...\n", strlen(large_input));
    
    // Trigger the overflow
    vulnerable_function(large_input);

    return 0;
}
