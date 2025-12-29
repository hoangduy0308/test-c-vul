#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char buffer[8];
    char password[8];
    
    strcpy(buffer, argv[1]);
    
    gets(password);
    
    printf(argv[1]);
    
    system(argv[1]);
    
    char *ptr = malloc(100);
    free(ptr);
    free(ptr);
    
    char *data = malloc(50);
    free(data);
    strcpy(data, "exploit");
    
    return 0;
}
