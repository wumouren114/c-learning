#include <stdio.h>

int main(void)
{
    double sum = 0;
    int d = 1;
    int sign = 1;
    int i;

    for (i = 1; i <= 5; i++) {
        sum = sum + sign * (1.0 / d);
        printf("第 %d 项：分母 = %d, sign = %2d, sum = %.6f\n", i, d, sign, sum);
        d = d + 2;
        sign = -sign;
    }

    printf("π 的近似值 = %.6f\n", 4 * sum);
    return 0;
}
