// Ввести с клавиатуры массив из 5 элементов, найти минимальный из них.
// Данные на входе: 5 целых чисел через пробел
// Данные на выходе: Одно единственное целое число
// Пример №1
// Данные на входе: 4 15 3 10 14
// Данные на выходе: 3
// Пример №2
// Данные на входе: 1 2 3 4 -5
// Данные на выходе: -5

#include <stdio.h>

void input_array(int array[], unsigned int size)
{
    printf("Введите %u целочисленных элементов массива\n", size);
    
    for (size_t i = 0; i < size; i++)
        scanf("%d", &array[i]);
}

int min(int array[], unsigned int size)
{
    int min = array[0];

    for (size_t i = 1; i < size; i++)
    {
        if (array[i] < min)
            min = array[i];
    }

    return min;
}

int main(int argc, char const *argv[])
{
    const unsigned SIZE = 5;
    int array[SIZE];

    input_array(array, SIZE);

    printf("%d\n", min(array, SIZE));
    return 0;
}
