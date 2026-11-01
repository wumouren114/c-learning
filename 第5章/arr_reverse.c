#include <stdio.h>

int main(void)
{
    int a[5];
    int i;

    /* 读入 5 个数 */
    for (i = 0; i < 5; i++) {
        scanf("%d", &a[i]);
    }

    /* 倒着打印：从最后一个编号 4 开始，到 0 结束 */
    for (i = 4; i >= 0; i--) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}