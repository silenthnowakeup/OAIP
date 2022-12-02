#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int MIN_VALUE = -5; // максимальное значение элементов матрицы
const int MAX_VALUE = 5; // минимальное значение
//функция рандомный массив
void randinput(int** arr, int row, int col)
{
	srand(time(NULL));
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = MIN_VALUE + rand() % (MAX_VALUE - MIN_VALUE + 1);
		}
	}
}
//функция ввода массива
void input(int** arr, int col, int row) {
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("arr[%d][%d] = ", i, j);
			while (scanf_s("%d", &arr[i][j]) != 1 || getchar() != '\n')
			{
				printf("\033[31mWrong input!\033[0m\n");
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
int** mal(int col, int row)
{
	int** arr;
	arr = (int**)malloc(row * sizeof(int*));
	for (int i = 0; i < row; i++) {
		arr[i] = (int*)malloc(col * sizeof(int));
	}
	return arr;
}

//malloc для двумерного массива 2
int** malformas(int row)
{
	int** mas;
	mas = (int**)malloc(2 * sizeof(int*));
	for (int i = 0; i < 2; i++) {
		mas[i] = (int*)malloc(row * sizeof(int));
	}
	return mas;
}

void multiplication(int** arr, int** mas, int col, int row)
{
	int mult = 1, min = 1, rem_x = 0, x = -1;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (arr[i][j] < 0)
			{
				mult *= arr[i][j];
				mas[0][i] = mult;
				mas[1][i] = i;
			}
		}
		//printf("Multiplication[%d]::%d\n",x, mult);
		mult = 1;
	}
}

void outputmas(int** mas, int row)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < row; j++)
		{
			printf("%d\t", mas[i][j]);
		}
		printf("\n");
	}
}

void merge_sort(int** mas, int l, int r)
{
	if (l == r) return; // границы сомкнулись
	int mid = (l + r) / 2; // определяем середину последовательности
	// и рекурсивно вызываем функцию сортировки для каждой половины
	merge_sort(mas, l, mid);
	merge_sort(mas, mid + 1, r);
	int i = l;  // начало первого пути
	int j = mid + 1; // начало второго пути
	int** tmp = (int**)malloc(2 * sizeof(int*)); // дополнительный массив
	for (int i = 0; i < 2; i++) {
		tmp[i] = (int*)malloc(r+1 * sizeof(int));
	}
	for (int step = 0; step < r - l + 1; step++) // для всех элементов дополнительного массива
	{
		// записываем в формируемую последовательность меньший из элементов двух путей
		// или остаток первого пути если j > r
		if ((j > r) || ((i <= mid) && (mas[0][i] < mas[0][j])))
		{
			tmp[0][step] = mas[0][i];
			tmp[1][step] = mas[1][i];
			i++;
		}
		else
		{
			tmp[0][step] = mas[0][j];
			tmp[1][step] = mas[1][j];
			j++;
		}
	}
	// переписываем сформированную последовательность в исходный массив
	for (int step = 0; step < r - l + 1; step++)
	{
		mas[0][l + step] = tmp[0][step];
		mas[1][l + step] = tmp[1][step];
	}
}

void sorting(int** arr, int** mas, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d\t ", arr[mas[1][i]][j]);
		}
		printf("\n");
	}
}
int checkRow()
{
	int row;
	printf("row: ");
	while (scanf_s("%d", &row) != 1 || getchar() != '\n' || row <= 0)
	{
		printf("\033[31mWrong input!\033[0m\n");
		rewind(stdin);

	}
	return row;
}
int checkCol()
{
	int col;
	printf("col: ");
	while (scanf_s("%d", &col) != 1 || getchar() != '\n' || col <= 0)
	{
		printf("\033[31mWrong input!\033[0m\n");
		rewind(stdin);

	}
	return col;
}
void free(int **arr, int row)
{
		for (int i = 0; i < row; i++) free(arr[i]);
		free(arr);
	}
void freeMas(int** mas)
{
	for (int i = 0; i < 2; i++) free(mas[i]);
	free(mas);
}