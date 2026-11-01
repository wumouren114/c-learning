#include <stdio.h>

int main(void)
{
    int scores[5] = {88, 92, 70, 95, 81};
    int i;

    for(i = 0; i <= 4; i++) {
        printf("%d ", scores[i]);
    }

    return 0;
}