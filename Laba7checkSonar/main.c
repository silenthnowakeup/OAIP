#include <stdio.h>
#include <stdlib.h>
#include "StaticLib.h"
void Task1()
{
    do
    {
        char* str;
        str = mal();
        printf("Input your string::");
        str = getStr1(str);
        printf("\nsumma = %d \n", myf(str));
    } while (contCheck() != 1);
}

void Task2()
{
    do
    {
        char* s1;
        char* s2;
        int k, m;
        s1 = mal();
        printf("Input first string::");
        s1 = getStr1(s1);
        s2 = mal();
        printf("\nInput second string::");
        s2 = getStr1(s2);
        printf("Enter k::");
        scanf_s("%d", &k);
        printf("\nEnter m::");
        scanf_s("%d", &m);
        s1 = str_cat(s1, s2, k, m);
        outStr(s1);
    } while (contCheck() != 1);
}

void endTask()
{
    printf("Bye-bye :)");
    exit(1);

}

int main() {
    int task;
    void(*Menu_Task[3])() = { endTask, Task1, Task2 };
    do {
        system("cls");
        printf("Input Task number\n");
        task = Correct_input_task();
        rewind(stdin);
        Menu_Task[task]();
        printf("\nWant see another task?\n");
    } while (contCheck() != 1);
    return 0;
}
