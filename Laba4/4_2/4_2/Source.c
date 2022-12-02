#include <stdio.h>
void input(int arr[100][100], int col, int row) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
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
void randinput(int arr[100][100], int col, int row) {
	srand(time(NULL));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			arr[i][j] = rand() % 10;   //Генерация рандомных чисел от 9
			printf("arr[%d][%d] =%d\n", i, j, arr[i][j]);
		}
	}
}
//вывод массива
void output(int arr[100][100], int col, int row) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf(" %d ", arr[i][j]);

		}
		printf("\n");
	}
}
int searchnull(int arr[100][100], int col, int row) {
	int k = 0, remj;
	//цикл, который ищет, равны ли в столбце все элементы нулю 
	for (int j = 0; j < col; j++) {
		for (int i = 0; i < row; i++)
		{
			if (arr[i][j] == 0) {
				k++;
			}
		}
		if (k == row)
		{
			remj = j;
		}
		else
		{
			printf("THERE IS NO COLUMN IN WHICH ALL ELEMENTS ARE NULL\n");
			return 0;
		}
		//цикл, который умножает на (-1) строку с таким же номером, как и столбец (если удовлетворяет условию)
		for (j = 0; j < col; j++) {
			arr[remj][j] *= -1;
		}
		break;
	}
	printf("j = %d\n", remj);
	return remj;
}
void outputres(int arr[100][100], int col, int row) {
	printf("Result:\n");
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
int main() {
	int arr[100][100] = { 0 }, i, col, row, j, k = 0, remj, operation;
	printf("column = ");
	scanf_s("%d", &col);
	printf("row = ");
	scanf_s("%d", &row);
	printf("\nChoose operation:\n");
	printf("1) Input element\n");
	printf("2) Random element\n");
	scanf_s("%d", &operation);
	switch (operation)
	{
	case 1: {
		// ввод массива
		input(arr, col, row);
		//вывод массива
		output(arr, col, row);
		searchnull(arr, col, row);
		outputres(arr, col, row);
		break;
	}
	case 2:
	{
		randinput(arr, col, row);
		//вывод массива
		output(arr, col, row);
		searchnull(arr, col, row);
		//вывод результата 
		outputres(arr, col, row);
	}
	break;
	}
	return 0;
}
