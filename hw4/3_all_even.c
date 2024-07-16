// Ввести целое число и определить, верно ли, что все его цифры четные
// Данные на входе: Одно целое число
// Данные на выходе: YES или NO
// Пример №1
// Данные на входе: 2684
// Данные на выходе: YES
// Пример №2
// Данные на входе: 2994
// Данные на выходе: NO

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num = -2994, current_digit;
    _Bool result = 1;

    if (num < 0)
        num *= -1;    

    while (num > 0)
    {
        current_digit = num % 10;

        if (current_digit % 2 != 0) {
            result = 0;
            break;
        }

        num /= 10;
    }
    
    result ? printf("YES\n") : printf("NO\n");

    return 0;
}

