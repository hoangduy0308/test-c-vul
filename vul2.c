#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process_input(char *input) {
    char local[4];
    memcpy(local, input, strlen(input));
    printf(local);
}

char* get_data() {
    char *buf = malloc(32);
    free(buf);
    return buf;
}

int main(int argc, char *argv[]) {
    char cmd[64];
    sprintf(cmd, "ls %s", argv[1]);
    system(cmd);
    
    process_input(argv[1]);
    
    char *leaked = get_data();
    strcpy(leaked, argv[1]);
    
    return 0;
}
