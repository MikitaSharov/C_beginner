// Составить логическую функцию, которая определяет, верно ли, что в заданном
// числе сумма цифр равна произведению.
// int is_happy_number(int n)
// Данные на входе: Целое не отрицательное число
// Данные на выходе: YES или NO
// Пример №1
// Данные на входе: 123
// Данные на выходе: YES
// Пример №2
// Данные на входе: 528
// Данные на выходе: NO

#include <stdio.h>

_Bool lucky_nummer(int num) {
    int summary = 0, multiple = 1;

    while (num > 0) {
        summary += num % 10;
        multiple *= num % 10;
        num /= 10;
    }

    if (summary == multiple)
        return 1;
    return 0;
}

int main(int argc, char const *argv[])
{
    int num;
    printf("Введите целое число > 0\n");
    scanf("%d", &num);

    if (num < 0)
        num *= -1;

    if (num > 10)
        lucky_nummer(num) ? printf("YES") : printf("NO");
    else
        printf("Надо больше 10");    

    return 0;
}
