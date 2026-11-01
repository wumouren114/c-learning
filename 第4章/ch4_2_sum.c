#include<stdio.h>
int main(void)
{
    int n;
    int sum = 0;

    scanf("%d", &n);
    int i = 1;
    while (i <= n) {
        sum = sum + i;
        i++;
    }
    printf("sum = %d\n", sum);
    return 0;
}