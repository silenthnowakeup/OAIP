#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "..\Project1\Header.h"
int main()
{
	int* arr;
	int* mas;
	int x, indexPositive;
	x = checkX();
	arr = mal(x);
	mas = malMAS(x);
	//input(arr, x);
	randinput(arr, x, mas);
	printf("\n\033[33mElementary Array:\033[0m\n");
	//output(arr, x);
	printf("\n");
	indexPositive = searchPositiveElement(arr, x);
	clock_t start, stop, start1, stop1;

	shell_sort(arr, x, start, stop);
	printf("\n\033[32mShell Result:\033[0m\n");
	//output(arr, x);
	printf("\n\033[32mTime For Shell Sorting %d mseconds\033[0m\n", (stop - start));

	bubble_sort(mas, x, start1, stop1);
	printf("\n\033[35mBubble Result:\033[0m\n");
	//output(arr, x);
	printf("\n\033[35mTime For Bubble Sorting %d mseconds\033[0m\n", (stop1 - start1));

	printf("\n\033[36mReverse Result:\033[0m\n");
	reverse(arr, x);
	//output(arr, x);
	free(arr);
	return 0;
}