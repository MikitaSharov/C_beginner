// Ввести целое число и «перевернуть» его, так чтобы первая цифра стала
// последней и т.д.
// Данные на входе: Целое неотрицательное число
// Данные на выходе: Целое неотрицательное число наоборот
// Пример №1
// Данные на входе: 1234
// Данные на выходе: 4321
// Пример №2
// Данные на входе: 782
// Данные на выходе: 287

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num = 4321;

    if (num == 0)
        printf("0");    

    if (num < 0)
    {
        printf("-");
        num *= -1;
    }

    while (num > 0)
    {
        printf("%d", num % 10); 
        num /= 10;
    }
    
    return 0;
}
