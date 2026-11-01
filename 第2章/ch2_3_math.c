#include <stdio.h>
#include <math.h>

int main(void)
{
    double a , b, c;

    printf("请输入两条直角边：");
    scanf("%lf%lf", &a, &b);

    c = sqrt(a * a + b * b);
    printf("c = %.2f\n", c);      

    return 0;
} 