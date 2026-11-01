#include <stdio.h>

int main(void)
{
    int i, fact;

    printf("   i        i!\n");
    fact  = 1;

    for (i = 1; i <= 10; i++)
    {
        printf("%4d %8d\n", i, fact);
        fact  = fact * (i + 1);
    }
    return 0;
}