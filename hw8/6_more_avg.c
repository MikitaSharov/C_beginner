// Определить количество положительных элементов квадратной матрицы,
// превышающих по величине среднее арифметическое всех элементов главной
// диагонали. Реализовать функцию среднее арифметическое главной
// диагонали.
// Данные на входе: 5 строк по 5 целых чисел через пробел
// Данные на выходе: Одно целое число
// Пример
// Данные на входе: 1 1 1 1 1 2 2 2 2 2 3 3 3 3 3 4 4 4 4 4 5 5 5 5 5
// Данные на выходе: 10

#include <stdio.h>

void input_matrix(int size, int matrix[][size])
{
    for (int i = 0; i < size; i++)
    {
        printf("Введите %d элементов %d строки\n", size, i + 1);
        
        for (size_t j = 0; j < size; j++)
            scanf("%d", &matrix[i][j]);        
    }
}

float avg_matrix_diagonal(int size, int matrix[][size])
{
    int sum = 0;
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            if (i == j)
                sum += matrix[i][j];            
        }        
    }
    
    return (float)sum / size;
}

int count_more_avg(int size, int matrix[][size], float avg)
{
    int count = 0;
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            if (matrix[i][j] > avg)
                count++;
        }        
    }
    
    return count;
}

// void print_matrix(int size, int matrix[][size])
// {
//     for (int i = 0; i < size; i++)
//     {
//         for (size_t j = 0; j < size; j++)
//             printf("%d ", matrix[i][j]);        
//     }
// }

int main(int argc, char const *argv[])
{
    int size = 5;
    int matrix[size][size];

    input_matrix(size, matrix);
    printf("%d", count_more_avg(size, matrix, avg_matrix_diagonal(size, matrix)));

    return 0;
}
