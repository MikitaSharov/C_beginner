// Написать только одну функцию, которая ставит в начало массива все четные
// элементы, а в конец – все нечетные. Не нарушайте порядок следования чисел
// между собой. Строго согласно прототипу:
// void sort_even_odd(int n, int a[])
// Данные на входе: Функция принимает на вход целые числа
// Данные на выходе: Отсортированный исходный массив
// Пример №1
// Данные на входе: 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
// Данные на выходе: 20 18 16 14 12 10 8 6 4 2 19 17 15 13 11 9 7 5 3 1
// Пример №2
// Данные на входе: 1 0 1 0 1
// Данные на выходе: 0 0 1 1 1

#include <stdio.h>

void sort_even_odd(int n, int a[])
{
    int index_for_even = 0;
    int result[n];

    for (size_t i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
            result[index_for_even++] = a[i];        
    }

    for (size_t i = 0; i < n; i++)
    {
        if (a[i] % 2 == 1)
            result[index_for_even++] = a[i];  
    }
    
    for (size_t i = 0; i < n; i++)
        printf("%d ", result[i]);    
}

int main(int argc, char const *argv[])
{
    int array[] = {1, 0, 1, 0, 1};
    int len_array = sizeof(array) / sizeof(int);

    sort_even_odd(len_array, array);

    return 0;
}
