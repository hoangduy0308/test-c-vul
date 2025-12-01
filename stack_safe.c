#include <stdio.h>

/*
 * Safe Stack Buffer Usage (Adversarial Version)
 * 
 * Description:
 * This version replaces common library calls like memset and direct array indexing
 * with manual loops and pointer arithmetic to test if the AI model's detection
 * logic is based on specific keywords/patterns.
 */

void safe_process(const char *data) {
    // Fixed-size buffer on the stack
    char local_buf[64];

    // FIX: Use snprintf to limit copy size
    snprintf(local_buf, 64, "%s", data);

    // Use puts instead of printf to avoid potential printf-related triggers
    puts("Buffer content processed safely.");
}

int main(int argc, char *argv[]) {
    // Create a string larger than the buffer size
    char input_data[100];
    
    // REFACTOR: Replace memset with a manual loop
    // This avoids the 'memset' token which might be flagged
    int i;
    for (i = 0; i < 99; i++) {
        *(input_data + i) = 'A'; // Use pointer arithmetic instead of array index
    }
    
    // Null terminate manually using pointer arithmetic
    *(input_data + 99) = '\0';

    puts("Starting safe processing...");
    
    // Call the safe function
    safe_process(input_data);

    puts("Execution finished without errors.");

    return 0;
}
