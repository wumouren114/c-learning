#include <stdio.h>
#include <stdlib.h>

/* 习题 1 第 3 题：
   改写 1.4 节中"求 1~100 偶数之和"的程序，
   改为求 1~100 中能被 6 整除的所有整数之和，并上机验证。 */

int main(void)
{
    int i;
    int sum = 0;                        /* 累加器，一定要先清零 */

    for (i = 1; i <= 100; i++) {        /* 顺序结构：i 从 1 走到 100 */
        if (i % 6 == 0) {               /* 分支结构：判断能否被 6 整除 */
            sum = sum + i;              /* 循环体：满足条件就累加 */
        }
    }

    printf("1~100 中能被 6 整除的所有整数之和 = %d\n", sum);

    system("pause");
    return 0;
}
