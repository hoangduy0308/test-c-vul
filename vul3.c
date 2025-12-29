#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int arr[10];
    int index = atoi(argv[1]);
    arr[index] = 999;
    
    char *ptrs[3];
    ptrs[0] = malloc(20);
    ptrs[1] = ptrs[0];
    free(ptrs[0]);
    free(ptrs[1]);
    
    char temp[16];
    scanf("%s", temp);
    
    FILE *f = fopen(argv[1], "r");
    char content[100];
    fread(content, 1, 200, f);
    
    int *null_ptr = NULL;
    *null_ptr = 42;
    
    return 0;
}
