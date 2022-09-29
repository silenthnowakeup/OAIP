#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	float a, V, s;
	printf("ENTER RIB LENGTH = ");
	//Ввод длины ребра
	scanf("%3f", &a);
	//Вычисление объема куба
	V = a * a * a;
	//Вычисление площади боковой поверхности
	s = 4 * a * a;
	//Проверка введёных данных 
	if (a < 0) printf("wrong input");
	else {
		// Вывод Объема и площади боковой поверхности
		printf("the volume of the cube is = %.3f\n", V);
		printf("the lateral surface area of the cube is = %.3f\n", s);
	}
	return 0;
}
