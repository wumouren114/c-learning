#include <stdio.h>

int add(int a, int b) {
    int sum = a + b;      /* 在这里下断点，看 a / b / sum 的值 */
    return sum;
}

int main(void) {
    int i;
    int total = 0;

    for (i = 1; i <= 5; i++) {
        total = add(total, i);   /* 循环 5 次，每轮都能停下来看变量 */
        printf("i = %d, total = %d\n", i, total);
    }

    printf("1+2+3+4+5 = %d\n", total);
    return 0;
}
