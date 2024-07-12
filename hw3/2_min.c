// Ввести пять чисел и вывести наименьшее из них
// Нужно напечатать наименьшее число
// Данные на входе: Пять целых чисел разделенных пробелом
// Данные на выходе: Одно целое число
// Данные на входе: 4 15 9 56 4
// Данные на выходе: 4

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int numbers[5], i;

    printf("Введите 5 чисел через пробел\n");
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &numbers[i]);
    }    

    int min = numbers[0];

    for (i = 1; i < 5; i++)
    {
        if (numbers[i] < min)
            min = numbers[i];        
    }    

    printf("%d\n", min);
    return 0;
}
