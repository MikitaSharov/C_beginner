// Ввести натуральное число и напечатать все числа от 10 до введенного числа -
// у которых сумма цифр равна произведению цифр
// Данные на входе: Одно натуральное число большее 10
// Данные на выходе: Числа у которых сумма цифр равна произведению
// цифр через пробел в порядке возрастания. Не превосходящие введенное
// число.
// Пример №1
// Данные на входе: 200
// Данные на выходе: 22 123 132
// Пример №2
// Данные на входе: 1000
// Данные на выходе: 22 123 132 213 231 312 321
// Пример №3
// Данные на входе: 22
// Данные на выходе: 22

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num = 2000000, current_number, summary, multiple;

    if (num < 0)
        num *= -1;

    if (num > 10)
    {
        for (size_t i = 10; i <= num; i++)
        {
            summary = 0, multiple = 1;
            current_number = i;
            
            while (current_number > 0)
            {
                summary += current_number % 10;
                multiple *= current_number % 10;
                current_number /= 10;
            }

            if (summary == multiple)
                printf("%d ", i);      
            }
    } else
        printf("Надо больше 10");
   
    return 0;
}
