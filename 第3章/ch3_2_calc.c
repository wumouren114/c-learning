#include<stdio.h>

int main(void){
    double a, b;
    char op;
    double r;
    scanf("%lf %c %lf", &a, &op, &b);
    
    switch (op)
    {
    case '+':
        r = a + b;
        break;
    case '-':
        r = a - b;
        break;
    case '*':
        r = a * b;
        break;
    case '/':
        r = a / b;
        break;
    default:
        printf("Unknown operator\n");
        return 0;
    }
    
    printf("%.2f\n", r);

    return 0;

}