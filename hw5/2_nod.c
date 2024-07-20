// Составить функцию, которая определяет наибольший общий делитель двух
// натуральных и привести пример ее использования
// https://younglinux.info/algorithm/euclidean
// int nod(int a, int b)
// Данные на входе: Два целых положительных числа
// Данные на выходе: Одно целое число - наибольший общий делитель.
// Пример №1
// Данные на входе: 14 21
// Данные на выходе: 7

#include <stdio.h>
#include <math.h>

int nod(int a, int b) {
    while (a != b)
    {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }

    return a;    
}

int main(int argc, char const *argv[])
{
    int a, b;

    printf("Введите 2 числа a, b\n");
    scanf("%d%d", &a, &b);

    printf("%d", nod(a, b));

    return 0;
}

