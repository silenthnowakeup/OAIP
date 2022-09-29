#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	long int n = 1, fac = 1, k = 1, z = 0;

	printf("Enter factorial=");
	// Вводим число
	scanf("%d/n", &n);
	//Цикл который находит факториал числа
	for (int i = 1; i < n + 1; i++) {
		fac *= i;
	}
	//Цикл который находит факториал в виде произведения трех последних членов
	for (k = 1; k * k * k - k <= fac; k++) {
		if (k * k * k - k == fac) { z = 1; break; }
	}
	if (z == 1) { printf("%d %d %d", k - 1, k, k + 1); }
	else { printf("No find"); }

	return 0;
}
