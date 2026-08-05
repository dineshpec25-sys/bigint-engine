#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void praser(char *num1, char *num2, char *op, char *input);

void praser(char *num1, char *num2, char *op, char *input)
{
    num1[999] = '\0';
    int index_1 = 998;
    int index_2 = 0;
    int found = 0;

    for (int i = 0; input[i] != '\0'; i++)
    {
        if ((input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') && found == 0)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                num1[index_1] = input[j];
                index_1--;
            }
            *op = input[i];
            found = 1;
            continue;
        }

        if (found)
        {
            num2[index_2] = input[i];
            index_2++;
        }
    }
    num2[index_2] = '\0';

    // num1's digits currently sit at num1[index_1+1 .. 998], everything
    // before index_1+1 is garbage. Shift the real digits down to index 0.
    int digit_count = 998 - index_1;
    memmove(num1, num1 + index_1 + 1, digit_count);
    num1[digit_count] = '\0';
}