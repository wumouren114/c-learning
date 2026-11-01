#include <stdio.h>
double average(int scores[], int n)
{
    int i;
    int sum = 0;
    double avg;
    for(i = 0; i < n; i++) {
        sum = sum + scores[i];
    }
    avg = sum * 1.0 / n;
    return avg;
}

int main(void)
{
    int a[5];
    int i, n = 5;

    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    double result = average(a, 5);
    printf("avg = %.2f\n", result);

    return 0;
}