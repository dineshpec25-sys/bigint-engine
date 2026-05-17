#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *bigint_sub(char* input_arr1, char* input_arr2, int size_arr1, int size_arr2);

char *bigint_sub(char* input_arr1, char* input_arr2, int size_arr1, int size_arr2)
{
    char local_array1[size_arr1+1];
    char local_array2[size_arr2+1];

    int count_local_array1 = 0;
    for(int i = 0; i < size_arr1; i++)
    {
        local_array1[count_local_array1++] = input_arr1[i];
    }
    local_array1[count_local_array1] = '\0';

    int count_local_array2 = 0;
    for(int i = 0; i < size_arr2; i++)
    {
        local_array2[count_local_array2++] = input_arr2[i];
    }
    local_array2[count_local_array2] = '\0';

    int check_interchange = 0;
    for(int i = 0; i < size_arr1; i++)
    {
        if(local_array1[i] < local_array2[i])
        {
            char intermediate[size_arr1+1];
            for(int i = 0; i < size_arr1; i++)
            {
                intermediate[i] = local_array1[i];
                local_array1[i] = local_array2[i];
                local_array2[i] = intermediate[i];
            }
            check_interchange = 1;
            break;
        }

        else if(local_array1[i] > local_array2[i])
        {
            break;
        }
    }

    char *result = malloc((size_arr1+1) * sizeof(char));
    int count = size_arr1;
    result[count--] = '\0';
    int count_digits = size_arr1-1;
    int borrow = 0;

    for(int i = 0; i < size_arr2; i++)
    {
        int left_digit = local_array1[count_digits] - '0';
        int right_digit = local_array2[count_digits] - '0';

        left_digit -= borrow;
        borrow = 0;

        if(left_digit < right_digit)
        {
            left_digit += 10;
            borrow = 1;
        }

        int int_sub = left_digit - right_digit;
        char char_sub = int_sub + '0';

        result[count--] = char_sub;
        count_digits--;
    }

    if(check_interchange == 1)
    {
        result = realloc(result, (size_arr1+2) * sizeof(char));
        for(int i = size_arr1; i >= 0; i--)
        {
            char temp = result[i];
            result[i+1] = temp;
        }
        result[0] = '-';
    }

    return result;
}