#include <stdio.h>
#include <stdlib.h>

//
// Created by stasc on 02.12.2022.
//

//#include "StaticLib.h"
#include <stdio.h>
#include <stdlib.h>

char* getStr1(char* s1)
{
    char temp;
    int i = 0;
    int size = 256;
    while ((temp = getchar()) != EOF && temp != '\n')
    {
        s1[i] = temp;
        i++;
        if (i > 255)
        {
            size += 2;
            s1 = (char*)realloc(s1, size * sizeof(char));
        }
    }
    s1[i] = '\0';

    return s1;
}

void outStr(char* str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        printf("%c", str[i]);
        i++;
    }
    //printf("\n");
}

int str_len(char* s1)
{
    int i = 0;
    while (s1[i] != '\0')
    {
        i++;
    }
    return i;
}

char* getStr2(char* s2)
{
    char temp;
    int i = 0;
    while ((temp = getchar()) != EOF && temp != '\n')
    {
        s2[i] = temp;
        i++;
    }
    s2[i] = '\0';

    return s2;
}

char* str_cat(char* s1, char* s2, int k, int m)
{
    char* s;
    int i, len1 = str_len(s1), len2 = str_len(s2);

    if (k > len1) k = len1;
    if ((s = (char*)malloc((len1 + len2) * sizeof(char))) == NULL)
        return s1;
    for (i = 0; i < k; i++)
        s[i] = s1[i];
    for (i = 0; i < m; i++)
        s[k + i] = s2[i];
    for (i = 0; s1[k + i] != '\0'; i++)
        s[k + m + i] = s1[k + i];
    s[k + m + i] = '\0';
    s1 = s;
    return s1;
}

int myf(char* str)
{
    int size = str_len(str);
    int sum = 0, n = 0, znak = 1, res = 0;
    for (int i = 0; i < size + 1; i++)
    {
        if (i == 0 || str[i - 1] >= 'a' && str[i] <= 'z' || str[i - 1] >= 'A' && str[i] <= 'Z' || str[i - 1] == ' ')
        {
            znak = ((str[i] == '-')) ? -1 : 1;
        }
        if (str[i] == '+' || str[i] == '-')
            i++;

        if (str[i] >= '0' && str[i] <= '9')
        {
            n = (10 * n + (str[i] - '0'));
        }
        else
        {
            sum += n * znak;
            n = 0;
        }
    }


    return sum;
}

int Correct_input_task(void) {
    int N;
    printf(">");
    while (scanf("%d", &N) != 1 || N > 3 ||  N < 0)
    {
        printf("Incorrect input.Try again!\n");
        printf(">");
        rewind(stdin);
    }
    return N;
}

int contCheck() {
    char temp = 0;
    int CHECK = 0;
    temp = getchar();
    printf("\n<Yes(Y)>\t");
    printf("<No(N)>\n");
    printf(">");
    while ((temp = getchar()) != '\n') {
        CHECK = 0;
        while (temp != 'N' && temp != 'n' && temp != 'Y' && temp != 'y')
        {
            rewind(stdin);
            printf("Incorrect input\n");
            printf(">");
            break;
        }
        if (temp == 'n' || temp == 'N')
        {
            CHECK = 1;
        }
    }
    return CHECK;
}

char* mal()
{
    char* str;
    int length;
    str = (char*)malloc(256 * sizeof(char));
}



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
        scanf("%d", &k);
        printf("\nEnter m::");
        scanf("%d", &m);
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
