#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "..\Project1\Header.h"
int main()
{
	int** arr;
	int** mas;
	int row, col;
	row = checkRow();
	col = checkCol();
	//функции
	arr = mal(col, row);
	mas = malformas(row);
	input(arr, row,col);
	printf("\nElementary array::\n");
	output(arr, col, row);
	multiplication(arr,mas, col, row);
	merge_sort(mas, 0, row-1);
	//outputmas(mas, row);
	printf("\nResult::\n");
	sorting(arr, mas, row, col);
	freeMas(mas);
	free(arr, row);

	return 0;
}