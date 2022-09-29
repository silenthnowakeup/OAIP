#include <stdio.h>
#include <math.h>
int main() {
	double S = 0, z, x, b;
	int k, n;
	long long int fac = 1;
	//Ввод угла
	printf("Enter x [-90;90]= ");
	scanf_s("%lf", &x);
	// Перевод угла из радиан в градусы
	z = x / 180 * acos(-1);
	//Ввод до какого числа будет суммироваться 
	printf("Enter n= ");
	scanf_s("%d", &n);
	//Цикл который находит синус угла через разложение в ряд Тейлора
	for (k = 0; k <= n; k++) {
		//Цикл который находит факториал числа
		for (int i = 1; i <= 2 * k + 1; i++) {
			fac *= i;
		}

		b = pow(-1, k) * pow(z, 2 * k + 1) / fac;
		S = S + b;
		fac = 1;
	}
	printf("Sin(X)= %lf", S);
	return 0;
}
