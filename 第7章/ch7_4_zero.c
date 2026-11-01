#include <stdio.h>

void zero(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++) {
        arr[i] = 0;        
    }
}

int main(void)
{
    int i;
    int n = 5;
    int a[5] = {1, 2, 3, 4, 5};
    printf("before: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    } 
    zero(a, 5);
    printf("\n");
    printf("after: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    } 

    return 0;
}
    
   
   
