// Составить функцию, которая меняет в массиве минимальный и максимальный
// элемент местами. Прототип функции
// void change_max_min(int size, int a[])
// Данные на входе: Функция принимает на вход размер массива и
// массив чисел типа int
// Данные на выходе: Функция не возвращает значения, измененный
// массив сохраняется на месте исходного.
// Пример
// Данные на входе: 1 2 3 4 5 6 7 8 9 10
// Данные на выходе: 10 2 3 4 5 6 7 8 9 1

#include <stdio.h>

void change_max_min(int size, int a[])
{   int index_min = 0;
    int index_max = 0;

    for (size_t i = 1; i < size; i++)
    {
        if (a[i] < a[index_min])
            index_min = i;
        
        if (a[i] > a[index_max])
            index_max = i;       
    }

    int temp = a[index_min];
    a[index_min] = a[index_max];
    a[index_max] = temp;

    for (size_t i = 0; i < size; i++)
        printf("%d ", a[i]);    
}

int main(int argc, char const *argv[])
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int len_array = sizeof(array) / sizeof(array[0]);

    change_max_min(len_array, array);

    return 0;
}
