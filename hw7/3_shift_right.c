// Считать массив из 12 элементов и выполнить циклический сдвиг ВПРАВО на 4
// элемента.
// Данные на входе: 12 целых чисел через пробел
// Данные на выходе: 12 целых чисел через пробел
// Пример №1
// Данные на входе: 4 -5 3 10 -4 -6 8 -10 1 0 5 7
// Данные на выходе: 1 0 5 7 4 -5 3 10 -4 -6 8 -10
// Пример №2
// Данные на входе: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12
                // 12 11 10 9 8 7 6 5 4 3 2 1
                // 9 10 11 12 
// Данные на выходе: 9 10 11 12 1 2 3 4 5 6 7 8

#include <stdio.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int array[], int i, int j)
{
    while (i < j)
    {
        swap(&array[i], &array[j]);
        i++;
        j--;
    }
    
}

void shift_right(int array[], int size, int shift)
{
    reverse(array, 0, size - 1);
    reverse(array, 0, shift - 1);
    reverse(array, shift, size - 1);
}

void print_array(int array[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);    
}

int main(int argc, char const *argv[])
{
    enum {SIZE = 12, SHIFT = 4};
    int array[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    shift_right(array, SIZE, SHIFT);
    print_array(array, SIZE);

    return 0;
}

