#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	float a, b, c;
	int n = 0;
	//Вводим число a и проверяем его на условие
	printf("Enter a= ");
	scanf("%f", &a);
	if (a > 0) n++;
	//Вводим число b и проверяем его на условие
	printf("Enter b= ");
	scanf("%f", &b);
	if (b > 0) n++;
	//Вводим число c и проверяем его на условие
	printf("Enter c= ");
	scanf("%f", &c);
	if (c > 0) n++;
	//Вывод в консоль количество положительных чисел
	printf("Quantity of positive numbers=%d", n);
	return 0;

}
