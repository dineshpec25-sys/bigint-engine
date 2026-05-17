#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *bigint_sub(char* input_arr1,
                 char* input_arr2,
                 int size_arr1,
                 int size_arr2);

int main()
{
    char num1[100];
    char num2[100];

    printf("Enter first number : ");
    scanf("%99s", num1);

    printf("Enter second number: ");
    scanf("%99s", num2);

    int len1 = strlen(num1);
    int len2 = strlen(num2);

    if(len1 != len2)
    {
        printf("Only same digit numbers allowed\n");
        return 1;
    }

    char *result = bigint_sub(num1,
                              num2,
                              len1,
                              len2);

    printf("Result = %s\n", result);

    free(result);

    return 0;
}