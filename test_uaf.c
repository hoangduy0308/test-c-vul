/* CWE-416: Use After Free */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void bad()
{
    char *data;
    data = (char *)malloc(100 * sizeof(char));
    
    strcpy(data, "Hello World");
    printf("%s\n", data);
    
    free(data);
    
    /* FLAW: use after free */
    printf("%s\n", data);
}

int main()
{
    bad();
    return 0;
}
