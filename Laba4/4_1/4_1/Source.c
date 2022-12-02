#include <stdio.h>
// ввод массива
void input(int arr[100][100], int x) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x; j++) {
			printf("arr[%d][%d] = ", i, j);
			while (scanf_s("%d", &arr[i][j]) != 1 || getchar() != '\n')
			{
				printf("Wrong input!\n");
				rewind(stdin);
			}

		}
	}
}
//функция ввода случайных элементов
void randinput(int arr[100][100], int x) {
	srand(time(NULL));
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x; j++) {
			arr[i][j] = rand() % 10;   //Генерация рандомных чисел от 9
			printf("arr[%d][%d] =%d\n", i, j, arr[i][j]);
		}
	}
}
//функция суммы элеметов массива
void summa(int arr[100][100], int x) {
	int sum = 0;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x; j++) {

			if (&arr[j][i] > 0) {
				sum += arr[j][i];
			}
		}
	}
	printf("sum = %d\n", sum);
}
//вывод массива
void output(int arr[100][100], int x) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x; j++) {
			printf(" %d ", arr[i][j]);

		}
		printf("\n");
	}
}
//Функция, которая выводит элементы побочной диагонали
void diagonal(int arr[100][100], int x)
{
	printf("Diagonal:");
	for (int f = 0; f < x; f++)
	{
		printf("%d ", arr[x - 1 - f][f]);
	}
}
//ЭЛЕМЕНТЫ ВЕРХНЕЙ ДИАГОНАЛИ
int topdiagonal(int arr[100][100], int x) {
	int s[100] = { 0 }, sum2;
	//Цикл, который ищет диагонали, параллельные побочной
	for (int r = 2; r <= x; r++)
	{
		for (int f = 0; f <= x - r; f++) {
			if (arr[x - r - f][f] < 0) {
				arr[x - r - f][f] *= -1;
			}
			s[r] += arr[x - r - f][f];
		}
	}
	sum2 = s[2];
	for (int r = 2; r <= x; r++) {
		if (s[r] < sum2) {
			sum2 = s[r];
		}
	}
	return sum2;
}
//ЭЛЕМЕНТЫ НИЖНЕЙ ДИАГОНАЛИ
int underdiagonal(int arr[100][100], int x) {
	int s2[100] = { 0 }, sum3;
	for (int r = x - 2; r >= 0; r--)
	{
		for (int f = x - 1; f > r; f--) {
			if (arr[f][x + r - f] < 0) {
				arr[f][x + r - f] *= -1;
			}
			s2[r] += arr[f][x + r - f];
		}
	}
	sum3 = s2[0];
	for (int r = 0; r <= x - 2; r++) {
		if (s2[r] < sum3) {
			sum3 = s2[r];
		}
	}
	return sum3;
}
int main() {
	int arr[100][100] = { 0 }, i, j, sum = 0, k = 0, sum2 = 0, sum3 = 0, s[100] = { 0 }, s2[100] = { 0 }, x;
	float operation;
	printf("Lenght of array = ");
	while (scanf_s("%d", &x) != 1 || getchar() != '\n' || x > 100 || x < 0)
	{
		printf("Wrong input!\n");
		rewind(stdin);
	}

	printf("\nChoose operation:\n");
	printf("1) Input element\n");
	printf("2) Random element\n");
	while (scanf_s("%f", &operation) != 1 || getchar() != '\n' || operation > 2 || operation < 0 || operation != (int)operation)
	{
		printf("Wrong input!\n");
		rewind(stdin);
	}

	switch ((int)operation)
	{
	case 1: {
		// ввод массива
		input(arr, x);
		//функция суммы элеметов массива
		summa(arr, x);
		//вывод массива
		output(arr, x);
		//Функция, которая выводит элементы побочной диагонали
		diagonal(arr, x);
		//ЭЛЕМЕНТЫ ВЕРХНЕЙ ДИАГОНАЛИ
		sum2 = topdiagonal(arr, x);
		//ЭЛЕМЕНТЫ НИЖНЕЙ ДИАГОНАЛИ
		sum3 = underdiagonal(arr, x);
		if (sum2 < sum3) {
			printf("\nMinimum diagonal = %d", sum2);
		}
		else printf("\nMinimum diagonal = % d", sum3);
		break;
	}
	case 2: {
		//функция ввода случайных элементов
		randinput(arr, x);
		//функция суммы элеметов массива
		summa(arr, x);
		//вывод массива
		output(arr, x);
		//Функция, которая выводит элементы побочной диагонали
		diagonal(arr, x);
		//ЭЛЕМЕНТЫ ВЕРХНЕЙ ДИАГОНАЛИ
		sum2 = topdiagonal(arr, x);
		//ЭЛЕМЕНТЫ НИЖНЕЙ ДИАГОНАЛИ
		sum3 = underdiagonal(arr, x);
		if (sum2 < sum3) {
			printf("\nMinimum element in diagonal = %d", sum2);
		}
		else printf("\nMinimum element in diagonal = % d", sum3);
		break;
	}
	}
	return 0;
}