#include "sensor_data.h"
#include <stdio.h>
#include <stdlib.h>

bool is_valid_line(uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, int8_t t)
{
    if (year != YEAR) return false;
    if (month < 1 || month > 12) return false;

    uint8_t days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
        days_in_month[1] = 29;

    if (day < 1 || day > days_in_month[month - 1]) return false;
    if (hour > 23) return false;
    if (minute > 59) return false;
    if (t < -99 || t > 99) return false;

    return true;
}

size_t reader(struct sensor_data **data_array, size_t capacity, const char *file_path)
{
    printf("Считывание файла...\n");

    FILE *f = fopen(file_path, "r");
    if (f == NULL)
    {
        printf("Ошибка открытия файла\n");
        exit(1);
    }

    *data_array = malloc(capacity * sizeof(struct sensor_data));
    if (*data_array == NULL)
    {
        printf("Ошибка выделения памяти\n");
        exit(1);
    }

    size_t index = 0;
    int line_counter = 1;

    while (true)
    {
        int got_elements = fscanf(f, "%hu;%hhu;%hhu;%hhu;%hhu;%hhd", &(*data_array)[index].year,
                                                                &(*data_array)[index].month,
                                                                &(*data_array)[index].day,
                                                                &(*data_array)[index].hour,
                                                                &(*data_array)[index].minute,
                                                                &(*data_array)[index].t);

        if (got_elements == EL_IN_STRUCT)
        {
            if (is_valid_line(  (*data_array)[index].year, (*data_array)[index].month, (*data_array)[index].day,
                                (*data_array)[index].hour, (*data_array)[index].minute, (*data_array)[index].t))
                index++;
            else
                printf("Строка %d имеет невалидную запись\n", line_counter);

            if (index >= capacity)
            {
                capacity *= 2; // увеличиваем ёмкость в два раза
                *data_array = realloc(*data_array, capacity * sizeof(struct sensor_data));
                if (*data_array == NULL)
                {
                    printf("Ошибка выделения памяти при увеличении массива\n");
                    exit(1);
                }
            }
        }
        else if (got_elements == EOF)
        {
            printf("Чтение завершено, достигнут конец файла\n");
            break;
        }
        else
            printf("Ошибка в строке %d, получено элементов: %d из %d\n", line_counter, got_elements, EL_IN_STRUCT);

        line_counter++;
    }

    *data_array = realloc(*data_array, index * sizeof(struct sensor_data));
    if (*data_array == NULL)
    {
        printf("Ошибка выделения памяти при корректировке массива\n");
        exit(1);
    }

    fclose(f);

    return index; // возвращаем количество считанных строк
}

float avg_year_t(struct sensor_data data_array[], size_t len_data_array)
{   
    int sum_t = 0;
    size_t i;

    printf("Рассчитываем среднегодовую температуру\n");

    for (i = 0; i < len_data_array; i++)
        sum_t += data_array[i].t;

    return (float)sum_t / i ;
}

float avg_month_t(struct sensor_data data_array[], size_t len_data_array, uint8_t month)
{
    size_t count = 0;
    int sum_t = 0;

    printf("Рассчитываем среднемесячную температуру\n");

    for (size_t i = 0; i < len_data_array; i++)
        if (data_array[i].month == month)
        {
            sum_t += data_array[i].t;
            count++;
        }

    return (float)sum_t / count;    
}

int8_t min_year_t(struct sensor_data data_array[], size_t len_data_array)
{   
    int8_t min_t = data_array[0].t;

    printf("Рассчитываем минимальную годовую температуру\n");

    for (size_t i = 1; i < len_data_array; i++)
        if (data_array[i].t < min_t)
            min_t = data_array[i].t;
        

    return min_t;
}

int8_t min_month_t(struct sensor_data data_array[], size_t len_data_array, uint8_t month)
{   
    int8_t min_t = MAX_T;

    printf("Рассчитываем минимальную месячную температуру\n");

    for (size_t i = 0; i < len_data_array; i++)
        if (data_array[i].month == month)
        {
            if (data_array[i].t < min_t)
                min_t = data_array[i].t;
        }

    return min_t;
}

int8_t max_year_t(struct sensor_data data_array[], size_t len_data_array)
{   
    int8_t max_t = data_array[0].t;

    printf("Рассчитываем максимальную годовую температуру\n");

    for (size_t i = 1; i < len_data_array; i++)
        if (data_array[i].t > max_t)
            max_t = data_array[i].t;
        

    return max_t;
}

int8_t max_month_t(struct sensor_data data_array[], size_t len_data_array, uint8_t month)
{   
    int8_t max_t = MIN_T;

    printf("Рассчитываем максимальную месячную температуру\n");

    for (size_t i = 0; i < len_data_array; i++)
        if (data_array[i].month == month)
        {
            if (data_array[i].t > max_t)
                max_t = data_array[i].t;
        }

    return max_t;
}