#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *bigint_sub(char* input_arr1,
                 char* input_arr2,
                 int size_arr1,
                 int size_arr2);

int main()
{
    char *result;

    result = bigint_sub("987", "123", 3, 3);

    printf("987 - 123 = %s\n", result);

    free(result);

    return 0;
}