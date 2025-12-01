#include <stdio.h>
#include <string.h>

/*
 * Idiomatic Safe C Version
 * 
 * Description:
 * This version uses high-level, standard C idioms.
 * - No manual memory manipulation (memset, loops).
 * - No pointer arithmetic.
 * - Uses string literals and standard safe functions (snprintf).
 */

void process_data(const char *input) {
    char buffer[64];
    
    // snprintf is the standard safe way to copy strings.
    // It automatically handles truncation and null-termination.
    snprintf(buffer, sizeof(buffer), "%s", input);
    
    printf("Processed: %s\n", buffer);
}

int main(void) {
    // Initialize with a long string literal directly.
    // This avoids manual buffer manipulation (memset/loops) entirely.
    // The string is deliberately longer than 64 bytes to test safe truncation.
    const char *long_string = "This_is_a_very_long_string_that_is_definitely_longer_than_sixty_four_bytes_to_test_safety_mechanisms";

    printf("Input length: %zu\n", strlen(long_string));

    process_data(long_string);

    return 0;
}
