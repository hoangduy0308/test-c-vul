/* Safe C code - no vulnerabilities */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void good()
{
    char *data;
    data = (char *)malloc(100 * sizeof(char));
    if (data == NULL) {
        return;
    }
    
    /* Safe: copy within buffer bounds */
    strncpy(data, "Hello World", 99);
    data[99] = '\0';
    
    printf("%s\n", data);
    
    /* Proper cleanup */
    free(data);
    data = NULL;
}

int main()
{
    good();
    return 0;
}
