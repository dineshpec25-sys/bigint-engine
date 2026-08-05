#include<stdio.h>
#include<stdlib.h>
#include<string.h>

static int cmp_digits(const char *a, const char *b)
{
    int la = strlen(a), lb = strlen(b);
    int sa = 0, sb = 0;
    while (sa < la - 1 && a[sa] == '0') sa++;
    while (sb < lb - 1 && b[sb] == '0') sb++;
    la -= sa; lb -= sb;

    if (la != lb) return (la < lb) ? -1 : 1;
    int c = strcmp(a + sa, b + sb);
    return (c < 0) ? -1 : (c > 0 ? 1 : 0);
}

static char* mul_by_digit(const char *num, int digit)
{
    int len = strlen(num);
    char *result = malloc(len + 2);
    int carry = 0, pos = len + 1;
    result[pos--] = '\0';

    for (int i = len - 1; i >= 0; i--)
    {
        int prod = (num[i] - '0') * digit + carry;
        result[pos--] = (prod % 10) + '0';
        carry = prod / 10;
    }
    if (carry)
        result[pos--] = carry + '0';

    // shift left to remove unused leading byte if carry wasn't needed
    char *out = strdup(result + pos + 1);
    free(result);
    return out;
}

// subtracts b from a, assuming a >= b (both plain positive digit strings).
static char* sub_digits(const char *a, const char *b)
{
    int la = strlen(a), lb = strlen(b);
    char *result = malloc(la + 1);
    int borrow = 0, ai = la - 1, bi = lb - 1, pos = la;
    result[pos--] = '\0';

    for (int i = 0; i < la; i++)
    {
        int da = a[ai--] - '0';
        int db = (bi >= 0) ? b[bi--] - '0' : 0;
        da -= borrow;
        borrow = 0;
        if (da < db) { da += 10; borrow = 1; }
        result[pos--] = (da - db) + '0';
    }

    int start = 0;
    while (start < (int)strlen(result) - 1 && result[start] == '0') start++;
    char *out = strdup(result + start);
    free(result);
    return out;
}

// ---- public function ----

// divides n1 by n2. Writes the remainder into *remainder_out (caller must free it).
// Returns the quotient (caller must free it). Returns NULL if n2 is zero.
char* bigint_divide(char *n1_arr, char *n2_arr, int s_n1, int s_n2, char **remainder_out)
{
    if (s_n2 == 1 && n2_arr[0] == '0')
    {
        fprintf(stderr, "Error: division by zero\n");
        return NULL;
    }

    char *quotient = malloc(s_n1 + 1);
    int q_len = 0;

    char *current = strdup("0");  // running remainder, grows digit by digit

    for (int i = 0; i < s_n1; i++)
    {
        // bring down the next dividend digit
        char *next = malloc(strlen(current) + 2);
        sprintf(next, "%s%c", current, n1_arr[i]);
        free(current);
        current = next;

        // strip leading zeros (keep at least "0")
        int start = 0;
        int clen = strlen(current);
        while (start < clen - 1 && current[start] == '0') start++;
        if (start > 0)
        {
            char *stripped = strdup(current + start);
            free(current);
            current = stripped;
        }

        // find the largest digit d such that d * divisor <= current
        int d = 0;
        char *chosen_product = strdup("0");
        for (int try_d = 9; try_d >= 1; try_d--)
        {
            char *product = mul_by_digit(n2_arr, try_d);
            if (cmp_digits(product, current) <= 0)
            {
                d = try_d;
                free(chosen_product);
                chosen_product = product;
                break;
            }
            free(product);
        }

        // current -= d * divisor
        char *new_current = sub_digits(current, chosen_product);
        free(chosen_product);
        free(current);
        current = new_current;

        quotient[q_len++] = d + '0';
    }
    quotient[q_len] = '\0';

    int qstart = 0;
    while (qstart < q_len - 1 && quotient[qstart] == '0') qstart++;
    char *final_quotient = strdup(quotient + qstart);
    free(quotient);

    *remainder_out = current;
    return final_quotient;
}