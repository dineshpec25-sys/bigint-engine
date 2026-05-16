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

    char *result = malloc((size_arr1+1) * sizeof(char));
    int count = size_arr1;
    result[count--] = '\0';
    int count_digits = size_arr1-1;

    for(int i = 0; i < size_arr2; i++)
    {
        int int_num1 = local_array1[count_digits] - '0';
        int int_num2 = local_array2[count_digits] - '0';

        int int_sub = int_num1 - int_num2;
        char char_sub = int_sub + '0';

        result[count--] = char_sub;
        count_digits--;
    }

    return result;
}