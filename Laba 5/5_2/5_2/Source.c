#include <stdio.h>
#include <stdlib.h>
// ввод массива
void input(int** arr, int n) {
	for (int i = 0; i < n; i++) {
		int j = -1;
		printf("row[%d] ", i);
		do
		{
			j++;
			while (scanf_s("%d", &arr[i][j]) != 1 || arr[i][j] < 0)
			{
				printf("Wrong input!\n");
				rewind(stdin);

			}
		} while (arr[i][j] != 0);
		//printf("%d - j\n", j);
		int Size = j + 1;
		arr[i] = (int*)realloc(arr[i], Size * sizeof(int));
	}
}
//malloc
int** mal(int n)
{
	int** arr;
	arr = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		arr[i] = (int*)malloc(10000 * sizeof(int));
	}
	return arr;
}
//Вывод массива
void output(int** arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		int j = 0;
		while (arr[i][j] != 0)
		{
			printf("%5d", arr[i][j]);
			j++;
		}
		printf("\n");
	}
}
//Функция, которая ищет минимальную сумму элементов в строке 
int summa(int** arr, int n)
{
	int sum = 0, x = -1, min = 10000000;
	int rem_x = 0;
	for (int i = 0; i < n; i++) {
		int j = -1;
		x++;
		for (;;) {
			j++;
			sum += arr[i][j];
			if (arr[i][j] == 0)
			{
				//Перемещение строки, с минимальной суммой элементов, в конец массива
				if (sum < min) {
					min = sum;
					rem_x = x;
				}
				break;
			}

		}
		//printf("Sum[%d]:%d", x, sum);
		sum = 0;
		//printf("\n");
	}
	//printf("min:%d\n", min);
	return rem_x;
}
//функция, удаляющая строку с минимальной суммой элементов 
void deleteMinRow(int** arr, int n, int rem_x)
{
	int* temp;
	for (int i = rem_x; i < n - 1; i++)
	{
		temp = arr[i + 1];
		arr[i + 1] = arr[i];
		arr[i] = temp;
	}
	arr = (int**)realloc(arr, (n - 1) * sizeof(int*));
}
int main()
{
	int** arr;
	int n, sum, rem_x;
	printf("Enter n:");
	while (scanf_s("%d", &n) != 1 || getchar() != '\n' || n <= 0)
	{
		printf("Wrong input!\n");
		rewind(stdin);

	}
	arr = mal(n);
	input(arr, n);
	printf("Array:\n");
	output(arr, n);
	rem_x = summa(arr, n);
	deleteMinRow(arr, n, rem_x);
	printf("Result:\n");
	output(arr, n - 1);
	return 0;
}