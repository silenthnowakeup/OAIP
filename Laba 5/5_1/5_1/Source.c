#include <stdio.h>
#include <stdlib.h>
//функция случайного ввода массива
void randinput(int* arr, int length) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % 10;   //Генерация рандомных от 1 до 10
	printf("Elements of the array::");
}
//функция вывода массива
void output(int* arr, int length) {
	for (int i = 0; i < length; i++) {
		printf("%d;", arr[i]);
	}
}
//malloc
int* mal(int lenght)
{
	int* arr;
	arr = (int*)malloc(lenght * sizeof(int));
	return arr;
}
int evenNumbers(int* arr, int length) {
	int countEven = 0;
	for (int i = 0; i < length; i++)
	{
		if (arr[i] % 2 == 0)
		{
			countEven++;
		}
	}
	return countEven;
}
//функция, удаляющая четные элементы массива
void deleteEvenElements(int* arr, int* length) {
	int count = 0, temp, countEven;
	countEven = evenNumbers(arr, (*length));
	for (int i = 0; i < (*length); i++)
	{
		if (arr[i] % 2 == 0)
		{
			count++;
			//цикл, переставляющий четные элементы в конец массива
			if (count <= countEven)
			{
				for (int j = i; j < (*length) - 1; j++)
				{
					temp = arr[j + 1];
					arr[j + 1] = arr[j];
					arr[j] = temp;
				}
				i--;
			}
		}
		else
		{
			continue;
		}
	}
	(*length) -= countEven;
	arr = (int*)realloc(arr, (*length) * sizeof(int));
}
//функция, выводящая результат 
void resOutput(int* arr, int length) {
	printf("\nRes=");
	for (int i = 0; i < length; i++) {
		printf("%d;", arr[i]);
	}
}
int main()
{
	int* arr, x;
	printf("x = ");
	while (scanf_s("%d", &x) != 1 || getchar() != '\n' || x <= 0)
	{
		printf("Wrong input!\n");
		rewind(stdin);

	}
	//функции
	arr = mal(x);
	randinput(arr, x);
	output(arr, x);
	evenNumbers(arr, x);
	deleteEvenElements(arr, &x);
	resOutput(arr, x);
	return 0;
}