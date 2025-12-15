/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * Good: Properly bounds-checked buffer operations
 * Flow Variant: 01 Baseline
 * 
 * Based on Juliet Test Suite pattern
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <wchar.h>

#define BUFFER_SIZE 100
#define SOURCE_STRING "Hello, this is a safe string"

/* Good function - uses proper bounds checking */
static void goodG2B()
{
    char dataBuffer[BUFFER_SIZE];
    char *data = dataBuffer;
    
    /* Initialize buffer */
    memset(data, 0, BUFFER_SIZE);
    
    /* FIX: Use strncpy with proper size limit */
    strncpy(data, SOURCE_STRING, BUFFER_SIZE - 1);
    data[BUFFER_SIZE - 1] = '\0';
    
    printf("Data: %s\n", data);
}

/* Good function - validates input length before copy */
static void goodB2G()
{
    char dataBuffer[BUFFER_SIZE];
    char *data = dataBuffer;
    const char *source = SOURCE_STRING;
    
    /* FIX: Check length before copying */
    if (strlen(source) < BUFFER_SIZE)
    {
        strcpy(data, source);
        printf("Data: %s\n", data);
    }
    else
    {
        printf("Error: Source too long\n");
    }
}

/* Good function - uses snprintf for safe formatting */
static void goodSafeFormat()
{
    char dataBuffer[BUFFER_SIZE];
    int value = 42;
    
    /* FIX: Use snprintf instead of sprintf */
    snprintf(dataBuffer, BUFFER_SIZE, "Value is: %d", value);
    
    printf("%s\n", dataBuffer);
}

void good()
{
    goodG2B();
    goodB2G();
    goodSafeFormat();
}

int main(int argc, char *argv[])
{
    printf("Calling good()...\n");
    good();
    
    return 0;
}
