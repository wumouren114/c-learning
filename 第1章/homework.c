#include <stdio.h>                    

int factorial(int n);

int main(void)
{
    int n;                            

    printf("请输入一个整数：");          
    scanf("%d", &n);                   
    printf("%d\n", factorial(n));       
    system("pause");                    
    return 0;
}

int factorial(int n)
{
    int i, fact = 1;

    for (i = 1; i <= n; i++) {
        fact = fact * i;
    }

    return fact;
}
