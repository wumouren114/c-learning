#include <stdio.h>

int main(void)
{
    int id;
    double price;

    scanf("%d",&id);
    if (id >= 1 && id <= 30)
        price = 3.5;
    else if (id >= 31 && id <= 60)
        price = 2.0;
    else if (id >= 61 && id <= 90)
        price = 3.0;
    else if (id >= 91 && id <= 100)
        price = 5.5;
    else {
        printf("Unknown\n");
        return 0; 
    }
    
    printf("%.1f\n", price);

    return 0;
}