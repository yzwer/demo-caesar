#include <stdlib.h>
#include <stdio.h>

#include "caesar.h"

void gen_test(char *str, int shift, int len)
{
    char *res1, *res2;

    printf("Encrypt text '%s'\n", str);
    res1 = caesar_encrypt(str, shift,len);
    if (!res1) return;
    printf("Result:       %s\n", res1);

    printf("Decrypt text '%s'\n", res1);
    res2 = caesar_decrypt(res1, shift);
    if (!res2) return;
    printf("Result:       %s\n", res2);

    free(res1);
    free(res2);
}

int main(void)
{
    check_magic_number();

    char orig_str[] = "more than than 33, more than than 33, more than than 33, more than than 33, more than than 33";

    printf("Test 1: Shift with a negative input\n");
    gen_test(orig_str, -3, sizeof(orig_str));
    printf("\nTest 2: Shift with a positive input\n");
    gen_test(orig_str, 7, sizeof(orig_str));

    return 0;
}
