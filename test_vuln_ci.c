/* Test file for CI vulnerability detection */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CWE121_Stack_Buffer_Overflow_bad()
{
    char data[10];
    char source[100];
    
    memset(source, 'A', 99);
    source[99] = '\0';
    
    /* FLAW: buffer overflow - copying 100 bytes into 10 byte buffer */
    strcpy(data, source);
    
    printf("%s\n", data);
}

void CWE401_Memory_Leak_bad()
{
    char *data = (char *)malloc(100 * sizeof(char));
    if (data == NULL) exit(-1);
    
    strcpy(data, "Hello");
    printf("%s\n", data);
    
    /* FLAW: memory leak - no free(data) */
}

int main()
{
    CWE121_Stack_Buffer_Overflow_bad();
    CWE401_Memory_Leak_bad();
    return 0;
}
