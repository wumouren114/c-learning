#include<stdio.h>
int main(void)
{
    char name[] = "吴政闻";
    int age = 18;
    double height = 175.5;
    char initial = 'W';
    printf("===== 我的名片 =====\n");
    printf("姓名：%s\n", name);
    printf("年龄：%d\n",age);
    printf("身高：%.1f\n",height);
    printf("首字母：%c",initial);
    return 0;
}
