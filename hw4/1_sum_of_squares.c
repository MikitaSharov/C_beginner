// Ввести два целых числа a и b (a ≤ b) и вывести сумму квадратов всех чисел от a
// до b.
// Данные на входе: Два целых числа по модулю не больше 100
// Данные на выходе: Сумма квадратов от первого введенного числа до
// второго
// Пример №1
// Данные на входе: 4 10
// Данные на выходе: 371
// Пример №2
// Данные на входе: 1 5
// Данные на выходе: 55

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a, b, summary = 0;

    printf("Введите a и b, где a <= b\n");
    scanf("%d%d", &a, &b);

    if (a <= b) {
        for (int i = a; i <= b; i++)
        {
            summary += i * i;
        }

        printf("%d\n", summary);
        
    } else printf("a > b неверный ввод");

    return 0;
}
