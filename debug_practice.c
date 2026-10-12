#include <stdio.h>

/*
 * 调试练习专用文件
 * 用法：在行号左边点一下打红点（断点），然后按 F5。
 * 每次程序停在断点时，左侧 VARIABLES 面板能看到当前所有变量的值。
 */

int add(int a, int b) {
    int sum = a + b;      /* 断点 3：看 a、b、sum 三个值 */
    return sum;
}

int main(void) {
    int n = 0;

    printf("Enter an integer: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    int total = 0;
    for (int i = 1; i <= n; i++) {
        total = add(total, i);   /* 断点 2：看每次循环 total 和 i 怎么变 */
    }

    printf("1 + 2 + ... + %d = %d\n", n, total);
    return 0;
}
