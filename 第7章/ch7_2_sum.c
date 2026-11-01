#include <stdio.h>

int main(void)
{
    int a[5];
    int i, n = 5, sum = 0;

    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        sum = sum + a[i];
    }
    printf("sum = %d\n", sum);

    return 0;
}