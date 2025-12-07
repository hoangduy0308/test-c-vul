/* Test file matching Juliet training format */
void bad()
{
    char * data;
    data = (char *)malloc(100 * sizeof(char));
    if (data == NULL) exit(-1);
    
    memset(data, 'A', 100-1);
    data[100-1] = '\0';
    
    char source[100];
    memset(source, 'C', 100-1);
    source[100-1] = '\0';
    
    strcpy(data, source);
    
    free(data);
}
