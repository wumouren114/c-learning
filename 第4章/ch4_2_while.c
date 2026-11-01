#include <stdio.h>

int main(void)
{
    int i = 5;
    int sum = 0;
    int k;

    /* 演示1：while 的"先查后干" */
    while (i < 5) {
        printf("不会被打印\n");
    }

    /* 演示2：同样的统计，while 和 for 写法对照 */
    i = 1;
    while (i <= 5) {
        sum = sum + i;
        i++;
    }
    printf("while: sum = %d, 现在的 i = %d\n", sum, i);

    sum = 0;
    for (k = 1; k <= 5; k++) {
        sum = sum + k;
    }
    printf("for  : sum = %d, 循环结束后 k = %d\n", sum, k);

    /* 演示3：do-while 至少执行一次 */
    i = 5;
    do {
        printf("do-while 执行了一次，i = %d\n", i);
        i++;
    } while (i < 5);

    return 0;
}
