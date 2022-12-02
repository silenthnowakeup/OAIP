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
//вывод массива
void output(int arr[100][100], int x) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x; j++) {
			printf(" %d ", arr[i][j]);

		}
		printf("\n");
	}
}
void thirdfield(int arr[100][100], int x) {
	int min;
	printf("3 field:\n");
	//Условие,которое проверяет, делится ли длина массива на 2 без остатка
	if (x % 2 == 0)
	{
		min = arr[x / 2][0];
		//Цикл, который перебирает элементы 3 участка массива 
		for (int i = x / 2; i < x; i++)
		{
			for (int j = 0; j < x / 2; j++) {
				printf("%d ", arr[i][j]);
				//Условие, проверяющее четность элемента 
				if (arr[i][j] % 2 == 0) {
					if (min > arr[i][j]) {
						min = arr[i][j];
					}

				}

			}
			printf("\n");
		}
		printf("min = %d", min);
	}
	else
	{
		//Цикл, который перебирает элементы 3 участка массива
		min = arr[x / 2 + 1][0];
		for (int i = x / 2 + 1; i < x; i++)
		{
			for (int j = 0; j < x / 2; j++) {
				printf("%d ", arr[i][j]);
				//Цикл, который перебирает элементы 3 участка массива 
				if (arr[i][j] % 2 == 0) {
					if (min > arr[i][j]) {
						min = arr[i][j];
					}
				}
			}
			printf("\n");
		}
		printf("min = %d", min);
	}
}
int main() {
	int arr[100][100] = { 0 }, i, x, j, min;
	float operation;
	printf("X= ");
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
		//вывод массива
		output(arr, x);
		//операция с 3-им участком 
		thirdfield(arr, x);
		break;
	}
	case 2:
	{
		// ввод случайного массива
		randinput(arr, x);
		//вывод массива
		output(arr, x);
		//операция с 3-им участком
		thirdfield(arr, x);
		break;
	}
	}
	return 0;
}