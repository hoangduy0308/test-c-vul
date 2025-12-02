#include <stdio.h>
#include <string.h>

/**
 * Stack Buffer Overflow Demonstration
 *
 * This code demonstrates a classic stack buffer overflow vulnerability
 * for educational purposes only.
 *
 * WARNING: This code is intentionally vulnerable. Never use patterns
 * like this in production code.
 */

void vulnerable_function(char *input) {
    char buffer[64];  // Fixed-size buffer on the stack

    // VULNERABLE: strcpy does not check bounds
    // If input is longer than 63 characters, it will overflow the buffer
    strcpy(buffer, input);

    printf("You entered: %s\n", buffer);
}

void secret_function() {
    printf("\n*** SECRET FUNCTION CALLED! ***\n");
    printf("Buffer overflow successfully redirected execution!\n");
}

int main(int argc, char *argv[]) {
    printf("=== Stack Buffer Overflow Demo ===\n\n");
    printf("Buffer size: 64 bytes\n");
    printf("Address of secret_function: %p\n\n", (void*)secret_function);

    if (argc < 2) {
        printf("Usage: %s <input_string>\n", argv[0]);
        printf("\nTry with a short string first, then a very long one.\n");
        printf("Example: %s AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n", argv[0]);
        return 1;
    }

    printf("Input length: %zu bytes\n\n", strlen(argv[1]));

    vulnerable_function(argv[1]);

    printf("\nProgram completed normally.\n");
    return 0;
}

/*
 * How this vulnerability works:
 *
 * 1. The stack layout (simplified, grows downward):
 *    +-------------------+
 *    |  return address   |  <- where execution returns after function
 *    +-------------------+
 *    |  saved EBP/RBP    |  <- saved frame pointer
 *    +-------------------+
 *    |                   |
 *    |  buffer[64]       |  <- our vulnerable buffer
 *    |                   |
 *    +-------------------+
 *
 * 2. When strcpy copies more than 64 bytes:
 *    - First 64 bytes fill the buffer
 *    - Additional bytes overwrite saved frame pointer
 *    - More bytes overwrite the return address
 *
 * 3. When the function returns, it jumps to the overwritten address
 *
 * Safe alternatives:
 *    - strncpy(buffer, input, sizeof(buffer) - 1);
 *    - snprintf(buffer, sizeof(buffer), "%s", input);
 *    - Use bounds-checking functions like strcpy_s (C11)
 */
