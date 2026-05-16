#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* s_add(char*, char*, int, int);

int main()
{
    char *result;

    result = s_add("999", "1", 3, 1);
    printf("999 + 1 = %s\n", result);
    free(result);

    result = s_add("0", "0", 1, 1);
    printf("0 + 0 = %s\n", result);
    free(result);

    result = s_add("123", "456", 3, 3);
    printf("123 + 456 = %s\n", result);
    free(result);

    result = s_add("999999", "1", 6, 1);
    printf("999999 + 1 = %s\n", result);
    free(result);

    return 0;
}