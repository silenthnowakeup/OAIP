#include <stdio.h>
//функция ввода массива
void input(float* mas, int length) {
    for (int i = 0; i < length; i++) {
        printf("arr[%d] = ", i);
        while (scanf_s("%f", &mas[i]) != 1 || getchar() != '\n')
        {
            printf("Wrong input!\n");
            rewind(stdin);

        }
    }
}
//функция ввода случайного массива
void randinput(float* mas, int length) {
    srand(time(NULL));
    for (int i = 0; i < length; i++)
        mas[i] = (float)rand() / 201 - 100;   //Генерация рандомных чисел от -100 до 100
    printf("\nElements of the array::");
}
//функция вывода 
void output(float* mas, int length) {
    for (int i = 0; i < length; i++) {
        printf("%.1f ", mas[i]);
    }
}
//функция, находящая количество членов, которые равны 0
int null(float* mas, int length) {
    float min = *(mas + 0);
    int n = 0;
    for (int i = 0; i < length; i++) {
        if (*(mas + i) == 0) {
            n++;
        }
    }
    return n;
}
//функция, которая находит сумму элементов массива, после минимального элемента
float summa(float* mas, int length) {
    float min = *(mas + 0);
    int k = 0;
    float sum = 0;
    //цикл, который находит минимальный элемент массива
    for (int i = 0; i < length; i++) {
        if (min > *(mas + i)) {
            min = *(mas + i);
            k = i;
        }
    }
    //цикл, который находит сумму элементов
    for (int i = k + 1; i < length; i++) {
        sum += *(mas + i);
    }
    return sum;
}
int main() {
    float arr[100], sum = 0;
    int n = 0, k = 0, x, operation;
    printf("Enter lenght of array:  ");
    while (scanf_s("%d", &x) != 1 || x < 0 || getchar() != '\n' || x>100)
    {
        printf("Wrong input!\n");
        rewind(stdin);
    }
    printf("\nChoose operation:\n");
    printf("1) Input element\n");
    printf("2) Random element\n");
    while (scanf_s("%d", &operation) != 1 || operation < 0 || getchar() != '\n' || operation > 2)
    {
        printf("Wrong input!\n");
        rewind(stdin);
    }
    switch (operation)

    {
    case 1: {
        input(arr, x);
        output(arr, x);
        printf("\n1) n: %d", null(arr, x));                   //вывод 0-вых членов массива
        printf("\n2)summa after min = %.1f ", summa(arr, x));
        break;
    }
    case 2: {
        randinput(arr, x);
        output(arr, x);
        printf("\n1) n: %d", null(arr, x));                   //вывод 0-вых членов массива
        printf("\n2)summa after min = %.1f ", summa(arr, x));
        break;
    }
    }
    return 0;
}