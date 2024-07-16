// Ввести три числа и определить, верно ли, что они вводились в порядке
// возрастания.
// Данные на входе: Три целых числа
// Данные на выходе: Одно слово YES или NO
// Пример
// Данные на входе: 4 5 17
// Данные на выходе: YES

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a, b, c;

    printf("Введите 3 числа через пробел\n");
    scanf("%d%d%d", &a, &b, &c);

    _Bool count = a <= b && b <= c;

    count ? printf("YES\n") : printf("NO\n");    

    return 0;
}