#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
    float x, y;
    //Ввод числа x
    printf("Enter x=");
    scanf("%f", &x);
    //Ввод числа y
    printf("Enter y=");
    scanf("%f", &y);
    //Проверка условия 
    if (x * x + y * y == 1)
        //Вывод в консоль "Yes"
        printf("Yes\n");
    else
        //Вывод в консоль "No"
        printf("No\n");
    return 0;
}
