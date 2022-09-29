#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	int k;
	//Ввод числа месяца 
	printf("Enter month number = ");
	scanf("%d", &k);
	//Проверка условия 
	if (k > 0 && k <= 12) {
		if (k == 12 || k == 1 || k == 2) printf("Winter");
		else if (k == 3 || k == 4 || k == 5) printf("Spring");
		else if (k == 6 || k == 7 || k == 8) printf("Summer");
		else printf("Autumn");
	}
	//Вывод в консоль "Wrong Input"
	else printf("wrong input");
	return 0;
}
