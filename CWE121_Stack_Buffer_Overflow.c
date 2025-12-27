#include <stdio.h>
#include <string.h>

void vulnerable_function(char *input) {
    char buffer[64];
    strcpy(buffer, input);  // CWE-121: Stack Buffer Overflow - no bounds checking
    printf("Input: %s\n", buffer);
}

void bad_gets_example() {
    char password[16];
    printf("Enter password: ");
    gets(password);  // CWE-242: Use of inherently dangerous function
    printf("You entered: %s\n", password);
}

void format_string_vuln(char *user_input) {
    printf(user_input);  // CWE-134: Format String Vulnerability
}

int integer_overflow() {
    int a = 2147483647;
    int b = a + 1;  // CWE-190: Integer Overflow
    return b;
}

char* use_after_free() {
    char *ptr = (char*)malloc(100);
    strcpy(ptr, "Hello");
    free(ptr);
    return ptr;  // CWE-416: Use After Free
}

void null_pointer_deref(char *ptr) {
    printf("%s\n", ptr);  // CWE-476: NULL Pointer Dereference (no null check)
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        vulnerable_function(argv[1]);
        format_string_vuln(argv[1]);
    }
    
    bad_gets_example();
    integer_overflow();
    null_pointer_deref(NULL);
    
    return 0;
}
