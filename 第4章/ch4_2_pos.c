#include<stdio.h>
int main(void){
    int n;
    do{
        printf("请输入正数：");
        scanf("%d", &n);
    } while(n < 0);
    printf("收到：%d\n", n);
    return 0;
}