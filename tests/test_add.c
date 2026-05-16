#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* s_add(char *n1_arr, char *n2_arr, int s_n1, int s_n2);


int main()
{
    char *result;

    result = s_add("999", "1", 3, 1);

    printf("%s\n", result);

    free(result);

    return 0;
}
