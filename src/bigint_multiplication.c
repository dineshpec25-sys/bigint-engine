#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* bigint_multiplication(char *n1_arr, char *n2_arr, int s_n1, int s_n2);

char* bigint_multiplication(char *n1_arr, char *n2_arr, int s_n1, int s_n2)
{
    int result_len = s_n1 + s_n2;

    int *temp = calloc(result_len, sizeof(int));

    for (int i = s_n1 - 1; i >= 0; i--)
    {
        int digit1 = n1_arr[i] - '0';

        for (int j = s_n2 - 1; j >= 0; j--)
        {
            int digit2 = n2_arr[j] - '0';

            int pos_low  = i + j + 1; 
            int pos_high = i + j;      

            int product = digit1 * digit2 + temp[pos_low];

            temp[pos_low]  = product % 10;
            temp[pos_high] += product / 10;
        }
    }

    int start = 0;
    while (start < result_len - 1 && temp[start] == 0)
        start++;

    char *result = malloc((result_len - start + 1) * sizeof(char));

    for (int k = start; k < result_len; k++)
        result[k - start] = temp[k] + '0';

    result[result_len - start] = '\0';

    free(temp);
    return result;
}