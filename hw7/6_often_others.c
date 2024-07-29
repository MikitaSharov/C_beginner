// Дан массив из 10 элементов. Определить, какое число в массиве встречается
// чаще всего. Гарантируется, что такое число ровно 1.
// Данные на входе: 10 целых числе через пробел
// Данные на выходе: Одно число, которое встречается чаще других.
// Пример
// Данные на входе: 4 1 2 1 11 2 34 11 0 11
// Данные на выходе: 11

#include <stdio.h>

int often_others(int array[], int size)
{
    int count;
    int max_count_num = 0;
    int max_count_index = 0;

    for (size_t i = 0; i < size; i++)
    {
        count = 0;
        for (size_t j = 0; j < size; j++)
        {
            if (array[i] == array[j])
                count++;
        }

        if (count > max_count_num)
        {
            max_count_num = count;
            max_count_index = i;
        }        
    }

    return array[max_count_index];
}

int main(int argc, char const *argv[])
{
    const int SIZE = 10;
    int array[10] = {4, 1, 2, 1, 11, 2, 34, 11, 0, 11};

    printf("%d\n", often_others(array, SIZE));

    return 0;
}
