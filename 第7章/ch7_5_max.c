#include <stdio.h>

int find_max(int arr[], int n)
{
    int i;
    int max = arr[0];
    for(i = 1; i < n; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
int main(void)
{
    int a[5] = {88, 92, 70, 95, 81};
    int result = find_max(a, 5);
    printf("max = %d\n", result);

    return 0;
}