#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//функция случайного ввода массива
void input(int* arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("arr[%d]:", i);
		while (scanf_s("%d", &arr[i]) != 1 || getchar() != '\n')
		{
			printf("\033[31mWrong input!\033[0m\n");
			rewind(stdin);

		}
	}
}

//Ввод случайного массива
void randinput(int* arr, int length,int *mas)
{
	srand(time(NULL));
	for (int i = 0; i < length; i++)
	{
		arr[i] = rand() % 100 - 50;
		mas[i] = arr[i];

	}
}

//функция вывода массива
void output(int* arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d;\t", arr[i]);
	}
}

//malloc
int* mal(int lenght)
{
	int* arr;
	arr = (int*)malloc(lenght * sizeof(int));
	return arr;
}

int* malMAS(int lenght)
{
	int* mas;
	mas = (int*)malloc(lenght * sizeof(int));
	return mas;
}

int searchPositiveElement(int* arr, int length)
{
	int indexPositive = 0;
	for (int i = 0; i < length; i++)
	{
		if (arr[i] > 0)
		{
			indexPositive = i;
			break;
		}
	}
	return indexPositive;
}

//сортировка методом Шелла
void shell_sort(int* arr, int length, clock_t& start, clock_t& stop)
{
	start = clock();
	int indexPositive = searchPositiveElement(arr, length);
	int flag, swap, size;
	size = length - indexPositive;
	for (int gap = size / 2; gap > 0; gap /= 2)
	{
		do
		{
			flag = 0;
			for (int i = indexPositive, j = indexPositive + gap; j < length; i++, j++)
			{
				if (arr[i] > arr[j])
				{
					swap = arr[j];
					arr[j] = arr[i];
					arr[i] = swap;
					flag = 1;
				}
			}
		} while (flag);
	}
	stop = clock();
}

//сортировка пузырьком
void bubble_sort(int* arr, int length, clock_t& start1, clock_t& stop1) 
{
	
	start1 = clock();
	int z, no_swap = 0;
	int indexPositive = searchPositiveElement(arr, length);
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = indexPositive; j < length - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				z = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = z;
				no_swap = 1;
			}
		}
		if (no_swap == 0)
		{
			break;
		}
	}
	stop1 = clock();

}

void reverse(int* arr, int length)
{
	int indexPositive = searchPositiveElement(arr, length);
	int temp = *arr;
	for (int i = indexPositive; i < length / 2; i++)
	{
		temp = arr[i];
		arr[i] = arr[length - i - 1];
		arr[length - i - 1] = temp;
	}
}
int checkX()
{
	int x;
	printf("Enter X::");
	while (scanf_s("%d", &x) != 1 || getchar() != '\n')
	{
		printf("\033[31mWrong input!\033[0m\n");
		rewind(stdin);

	}
	return x;
}
