#include <stdio.h> 
int main() {
	int i, A[30], B[30], C[100], ost = 0, C2[100];
	float operation;
	printf("\nChoose operation:\n");
	printf("1) Input element\n");
	printf("2) Random element\n");
	while (scanf_s("%f", &operation) != 1 || operation < 0 || getchar() != '\n' || operation>2 || operation != (int)operation) {
		printf("Wrong input\n");
		rewind(stdin);
	}
	switch ((int)operation)
	{
	case 1: {
		//ввод 1 массива 
		for (i = 0; i < 30; i++) {
			printf("A[%d] = ", i);
			while (scanf_s("%d", &A[i]) != 1 || getchar() != '\n' || A[i] > 9 || A[i] < 0)
			{
				printf("Wrong input!\n");
				rewind(stdin);
			}

		}
		//ввод 2 массива 
		for (i = 0; i < 30; i++) {
			printf("B[%d] = ", i);
			while (scanf_s("%d", &B[i]) != 1 || getchar() != '\n' || B[i] > 9 || B[i] < 0)
			{
				printf("Wrong input!\n");
				rewind(stdin);
			}
		}
		//Счет 3 массива 
		for (i = 29; i >= 0; i--)
		{
			C[i] = A[i] + B[i] + ost;
			if (C[i] >= 10) {
				ost = 1;
				C[i] = C[i] - 10;
			}
			else
				ost = 0;
		}
		printf("A=");
		for (i = 0; i < 30; i++) {  //Вывод первого массива 
			printf("%d ", A[i]);
		}
		printf("\n");
		printf("B=");
		for (i = 0; i < 30; i++) {  //Вывод второго массива 
			printf("%d ", B[i]);
		}
		if (ost == 1) {
			for (i = 31; i >= 0; i--)
			{
				C2[i + 1] = C[i];
				C2[0] = ost;
			}
		}
		if (ost == 1) {
			printf("\n");
			printf("C=");
			for (i = 0; i < 31; i++) {  //Вывод третьего массива 
				printf("%d ", C2[i]);
			}
		}
		else {
			printf("\n");
			printf("C=");
			for (i = 0; i < 30; i++) {  //Вывод третьего массива 
				printf("%d ", C[i]);
			}
		}
		break;
	}
	case 2: {
		//ввод 1 массива 
		srand(time(NULL));
		for (i = 0; i < 30; i++) {
			A[i] = rand() % 10;   //Генерация рандомных чисел от 9
			printf("\nA[%d]= %d", i, A[i]);

		}
		//ввод 2 массива 
		system("pause");
		srand(time(NULL));
		for (i = 0; i < 30; i++) {
			B[i] = rand() % 10;   //Генерация рандомных чисел от 9
			printf("\nA[%d]= %d", i, B[i]);
		}
		for (i = 29; i >= 0; i--)
		{
			C[i] = A[i] + B[i] + ost;
			if (C[i] >= 10) {
				ost = 1;
				C[i] = C[i] - 10;
			}
			else
				ost = 0;
		}
		printf("\n");
		printf("A=");
		for (i = 0; i < 30; i++) {  //Вывод первого массива 
			printf("%d ", A[i]);
		}
		printf("\n");
		printf("B=");
		for (i = 0; i < 30; i++) {  //Вывод второго массива 
			printf("%d ", B[i]);
		}
		if (ost == 1) {
			for (i = 31; i >= 0; i--)
			{
				C2[i + 1] = C[i];
				C2[0] = ost;
			}
		}
		if (ost == 1) {
			printf("\n");
			printf("C=");
			for (i = 0; i < 31; i++) {  //Вывод третьего массива 
				printf("%d ", C2[i]);
			}
		}
		else {
			printf("\n");
			printf("C=");
			for (i = 0; i < 30; i++) {  //Вывод третьего массива 
				printf("%d ", C[i]);
			}
		}
		break;
	}
	}
	return 0;
}

