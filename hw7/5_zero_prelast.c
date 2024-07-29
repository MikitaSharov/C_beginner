// Считать массив из 10 элементов и отобрать в другой массив все числа, у
// которых вторая с конца цифра (число десятков) – ноль.
// Данные на входе: 10 целых чисел через пробел.
// Данные на выходе: Целые числа через пробел, у которых вторая с конца
// цифра - ноль
// Пример
// Данные на входе: 40 105 203 1 14 1000 22 33 44 55
// Данные на выходе: 105 203 1 1000

#include <stdio.h>

void zero_prelast(int array[], int size)
{
    int count = 0;
    
    for (int i = 0; i < size; i++)
    {
        if ((array[i] / 10) % 10 == 0)
            count++;
    }
    
    int result[count];
    count = 0;
    
    for (int i = 0; i < size; i++)
    {
        if ((array[i] / 10) % 10 == 0)
            result[count++] = array[i];
    }
    
    for (int i = 0; i < count; i++)
        printf("%d ", result[i]);
}

int main()
{
    const int SIZE = 10;
    int array[] = {40, 105, 203, 1, 14, 1000, 22, 33, 44, 55};
    
    zero_prelast(array, SIZE);
    
    return 0;
}