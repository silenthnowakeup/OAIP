#include <stdio.h>
#include <stdlib.h>
int maxI = 0, maxL = 0;
//функция ввода массива
void input(int** arr, int col, int row) {
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("arr[%d][%d] = ", i, j);
			while (scanf_s("%d", &arr[i][j]) != 1 || getchar() != '\n')
			{
				printf("Wrong input!\n");
				rewind(stdin);

			}
		}
	}

}

//функция вывода массива
void output(int** arr, int col, int row) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("%d\t", arr[i][j]);

		}
		printf("\n");
	}
}

//malloc для двумерного массива 
int* mal(int col, int row)
{
	int** arr;
	arr = (int**)malloc(row * sizeof(int*));
	for (int i = 0; i < row; i++) {
		arr[i] = (int*)malloc(col * sizeof(int));
	}
	return arr;
}
//malloc для одномерного массива
int* mal1(int length)
{
	int* arr1;
	arr1 = (int*)malloc(length * sizeof(int));
	return arr1;
}
//Функция, переводящая двумерный массив в одномерный 
void conversionArray2Dto1D(int** arr, int col, int row, int* arr1)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr1[i * col + j] = arr[i][j];
		}
	}
}
//Вывод, одномерного массива
//void out1Darray(int* arr1, int col, int row, int** arr)
//{
//	for (int i = 0; i < row * col; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//}
//Функция, которая ищет наибольшую позитивную последовательность элементов 
int findLongestPositive(int col, int row, int* arr1)
{
	int currL = 0, currI = 0;
	for (int i = 0; i < row * col; i++)
	{
		if (arr1[i] > 0)
		{
			currL++;
			if (currL == 1)
				currI = i;
		}
		else {
			if (currL > maxL) {
				maxL = currL;
				maxI = currI;
			}
			currL = 0;
		}
	}
	if (currL > maxL) {
		maxL = currL;
		maxI = currI;
	}
	//printf("\nLength = %d\n", maxL);
	//printf("Index = %d\n", maxI);
}

void outFindLongestPositive(int* arr1)
{
	for (int i = maxI; i < maxI + maxL; i++)
	{
		printf("%d ", arr1[i]);
	}
}

int main()
{
	int** arr;
	int* arr1;
	int row, col;
	printf("row: ");
	scanf_s("%d", &row);
	printf("column: ");
	scanf_s("%d", &col);
	//функции
	arr = mal(col, row);
	input(arr, col, row);
	output(arr, col, row);
	arr1 = mal1(col * row);
	conversionArray2Dto1D(arr, col, row, arr1);
	//out1Darray(arr1, col, row, arr);
	findLongestPositive(col, row, arr1);
	printf("\nResult:\n");
	outFindLongestPositive(arr1);
	return 0;
}