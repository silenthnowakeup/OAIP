#include <stdio.h>
//функция ввода массива
void input(int* mas, int length) {
	for (int i = 0; i < length; i++) {
		printf("arr[%d] = ", i);
		while (scanf_s("%d", &mas[i]) != 1 || getchar() != 'n')
		{
			printf("Wrong input!\n");
			rewind(stdin);
		}
	}
}
//функция случайного ввода массива
void randinput(int* mas, int length) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		mas[i] = rand() / 201 - 100;   //Генерация рандомных чисел от -100 до 100
	printf("\nElements of the array::");
}
//функция вывода массива
void output(int* mas, int length) {
	for (int i = 0; i < length; i++) {
		printf("%d ", mas[i]);
	}
}
//функиция, сдвигающая четные элементы влево 
void left(int* mas, int lenght) {
	int k, temp;
	while (scanf_s("%d", &k) != 1 || k < 0 || getchar() != 'n') {
		printf("Wrong input");
		rewind(stdin);
	}
	for (int i = 0; i < lenght; i++) {
		if (mas[i] % 2 == 0) {
			if (i < k) {
				printf("Error");
				return 0;
			}
			else {
				// цикл, сдвигающий элементы на k влево
				for (int j = 1; j <= k; j++) {
					temp = mas[i - j];
					mas[i - j] = mas[i - j + 1];
					mas[i - j + 1] = temp;
				}
			}
		}

	}
	//цикл вывода массива со сдвинутами элементами 
	for (int i = 0; i < lenght; i++) {
		printf("%d, ", mas[i]);
	}
}
int main() {
	int n, i, x, k, temp, arr[100], operation;
	printf("Enter lenght of array = ");
	while (scanf_s("%d", &x) != 1 || x < 0 || getchar() != '\n' || x>100)
	{
		printf("Wrong input!\n");
		rewind(stdin);
	}
	if (x > 0) {
		printf("\nChoose operation:\n");
		printf("1) Input element\n");
		printf("2) Random element\n");
		while (scanf_s("%d", &operation) != 1 || operation < 0 || getchar() != '\n' || operation>2)
		{
			printf("Wrong input\n");
			rewind(stdin);
		}
		switch (operation)
		{
		case 1: {
			input(arr, x);
			output(arr, x);
			left(arr, x);
			break;
		}

		case 2: {
			randinput(arr, x);
			output(arr, x);
			left(arr, x);
			break;
		}
			  return 0;
		}
	}
}
