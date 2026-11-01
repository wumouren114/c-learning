#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int target, guess;

    srand(time(NULL));
    target = rand() % 100 + 1;

    for (int i = 0; i < 3; i++)
    {

        printf("猜一个 1~100 的数：\n");
        scanf("%d", &guess);

        if (guess > target)
        {
            printf("猜大了\n");
        }
        else if (guess < target)
        {
            printf("猜小了\n");
        }
        else
        {
            printf("猜对了！\n");
            break;
        }
    }
    printf("答案是 %d\n", target);

    return 0;
}
