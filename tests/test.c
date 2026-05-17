#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *bigint_add(char *, char *, int, int);
char *bigint_sub(char *, char *, int, int);

int main()
{
    char num1[1000];
    char num2[1000];
    char op;

    printf("Enter first number : ");
    scanf("%999s", num1);

    printf("Enter operator (+/-): ");
    scanf(" %c", &op);

    printf("Enter second number: ");
    scanf("%999s", num2);

    char *result = NULL;

    if(op == '+')
    {
        result = bigint_add(
            num1,
            num2,
            strlen(num1),
            strlen(num2));
    }

    else if(op == '-')
    {
        result = bigint_sub(
            num1,
            num2,
            strlen(num1),
            strlen(num2));
    }

    else
    {
        printf("Invalid operator\n");
        return 1;
    }

    printf("Result = %s\n", result);

    free(result);

    return 0;
}
