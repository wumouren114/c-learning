#include <stdio.h>

int main(void)
{
    int fahr;

    printf("华氏    摄氏\n");
    for (fahr = 0; fahr <= 300; fahr = fahr + 20)
    {
        printf("%3d     %6.1f\n", fahr, 5.0 * (fahr - 32) / 9);
    }
    return 0;
}