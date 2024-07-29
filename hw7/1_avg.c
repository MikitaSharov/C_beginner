// Среднее арифметическое чисел
// Ввести с клавиатуры массив из 5 элементов, найти среднее арифметическое
// всех элементов массива.
// Данные на входе: 5 целых ненулевых чисел через пробел
// Данные на выходе: Одно число в формате "%.3f"
// Пример №1
// Данные на входе: 4 15 3 10 14
// Данные на выходе: 9.200
// Пример №2
// Данные на входе: 1 2 3 4 5
// Данные на выходе: 3.000

#include <stdio.h>

void input_array(int array[], unsigned int size)
{
    printf("Введите %u целочисленных элементов массива\n", size);
    
    for (size_t i = 0; i < size; i++)
        scanf("%d", &array[i]);
}

float avg(int array[], unsigned int size)
{
    int sum = 0;

    for (size_t i = 0; i < size; i++)
        sum += array[i];

    float avg = (float)sum / size;
    return avg;    
}

int main(int argc, char const *argv[])
{
    const unsigned int SIZE = 5;
    int array[SIZE];

    input_array(array, SIZE);

    printf("%.3f\n", avg(array, SIZE));

    return 0;
}
