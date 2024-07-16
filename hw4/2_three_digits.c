// Ввести целое число и определить, верно ли, что в нём ровно 3 цифры.
// Данные на входе: Целое положительное число
// Данные на выходе: Одно слово: YES или NO
// Пример №1
// Данные на входе: 123
// Данные на выходе: YES
// Пример №2
// Данные на входе: 1234
// Данные на выходе: NO

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int number = 1234, count = 0;

    if (number < 0)
        number *= -1;

    while (number > 0)
    {
        number /= 10;
        count++;
    }

    count == 3 ? printf("YES") : printf("NO");

    return 0;
}