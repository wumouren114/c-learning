#include <stdio.h>

int sum_arr(int arr[], int n)
{
    int i;
    int s = 0;

    for (i = 0; i < n; i++) {
        s = s + i;
    }

    return s;
}

int main(void)
{
    int a[5];
    int i;

    for (i = 0; i < 5; i++) {
        scanf("%d", &a[i]);
    }

    printf("%d\n", sum_arr(a, 5));

    return 0;
}