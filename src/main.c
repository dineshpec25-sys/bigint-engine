#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *bigint_add(char *, char *, int, int);
char *bigint_sub(char *, char *, int, int);
char *bigint_multiplication(char *, char *, int, int);
char *bigint_divide(char *, char *, int, int, char **);
void praser(char *, char *, char *, char *);

int main()
{
    char num1[1000];
    char num2[1000];
    char op;
    char input[2000];
    while(1)
    {
        printf(">>");
        scanf("%1999s", input);

        praser(num1, num2, &op, input);

        char *result = NULL;
        char *remainder = NULL;

        switch (op)
        {
            case '+':
                result = bigint_add(num1, num2, strlen(num1), strlen(num2));
                printf("Result = %s\n", result);
                free(result);
                break;

            case '-':
                result = bigint_sub(num1, num2, strlen(num1), strlen(num2));
                printf("Result = %s\n", result);
                free(result);
                break;

            case '*':
                result = bigint_multiplication(num1, num2, strlen(num1), strlen(num2));
                printf("Result = %s\n", result);
                free(result);
                break;

            case '/':
                result = bigint_divide(num1, num2, strlen(num1), strlen(num2), &remainder);
                if (result == NULL)
                {
                    return 1; // division by zero already reported by bigint_divide
                }
                printf("Quotient  = %s\n", result);
                printf("Remainder = %s\n", remainder);
                free(result);
                free(remainder);
                break;

            default:
                printf("Invalid operator\n");
                return 1;
        }
        if(!strcmp(input, "exit")) return 0;
    }

    return 0;
}