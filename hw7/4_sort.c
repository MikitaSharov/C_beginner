// Считать массив из 10 элементов и отсортировать его по последней цифре.
// Данные на входе: 10 целых чисел через пробел
// Этот же массив отсортированный по последней цифре
// Пример №1
// Данные на входе: 14 25 13 30 76 58 32 11 41 97
// Данные на выходе: 30 11 41 32 13 14 25 76 97 58
// Пример №2
// Данные на входе: 109 118 100 51 62 73 1007 16 4 555
// Данные на выходе: 100 51 62 73 4 555 16 1007 118 109

#include <stdio.h>

int last_digit(int num)
{
    return num % 10;
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort_by_last_digit(int array[], int size)
{
    int i, j;

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - 1 - i; j++)
        {
            if (last_digit(array[j]) > last_digit(array[j + 1]))
                swap(&array[j], &array[j + 1]);
            else if (last_digit(array[j]) == last_digit(array[j + 1]) && array[j] > array[j + 1])
                swap(&array[j], &array[j + 1]);
        }
    }
}

void input_array(int array[], unsigned int size)
{
    printf("Введите %u целочисленных элементов массива\n", size);
    
    for (size_t i = 0; i < size; i++)
        scanf("%d", &array[i]);
}

void print_array(int array[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);    
}


int main(int argc, char const *argv[])
{
    const int SIZE = 10;
    int array[SIZE];
    int i;

    input_array(array, SIZE);
    sort_by_last_digit(array, SIZE);
    print_array(array, SIZE);

    return 0;
}