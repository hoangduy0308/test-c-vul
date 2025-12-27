#include <stdio.h>

int main() {
    char password[8];
    gets(password);
    printf("Password: %s\n", password);
    return 0;
}
