
#include <string.h>

int main(int argc, char *argv[]) {
    char buffer[10];
    strcpy(buffer, argv[1]);
    printf("%s\n", buffer);
    return 0;
}

