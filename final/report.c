#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "sensor_data.h"


void print_help()
{
    printf("Приложение для обработки данных о температуре.\n");
    printf("Поддерживаемые ключи:\n");
    printf("  -h                   Описание функционала приложения\n");
    printf("  -f <filename.csv>    Входной файл CSV для обработки\n");
    printf("  -m <номер месяца>    Вывод статистики за указанный месяц\n");
}

int main(int argc, char const *argv[])
{
    const char *file_path;
    uint8_t month = 0;

    if (argc <= 1) {
        print_help();
        return 0;
    }

    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-h") == 0)
        {
            print_help();
            return 0;
        }
        else if (strcmp(argv[i], "-f") == 0)
        {
            if (i + 1 < argc)
                file_path = argv[++i];
            else
            {
                fprintf(stderr, "Ошибка: Не указан файл после -f\n");
                return 1;
            }
        }
        else if (strcmp(argv[i], "-m") == 0)
        {
            if (i + 1 < argc)
            {
                month = atoi(argv[++i]);
                if (month < 1 || month > 12)
                {
                    fprintf(stderr, "Ошибка: Неверный номер месяца\n");
                    return 1;
                }
            }
            else
            {
                fprintf(stderr, "Ошибка: Не указан номер месяца после -m\n");
                return 1;
            }
        }
        else
        {
            fprintf(stderr, "Ошибка: Неизвестный аргумент %s\n", argv[i]);
            return 1;
        }
    }

    struct sensor_data *data_array = NULL;
    size_t capacity = 1000;
    size_t len_data_array = reader(&data_array, capacity, file_path);
    printf("Успешно считано данных: %zu строк\n", len_data_array);

    if (month)
    {
        printf("Cредняя температура за месяц %d: %.2f\n", month, avg_month_t(data_array, len_data_array, month));
        printf("Минимальная месячная %hhd\n", min_month_t(data_array, len_data_array, month));
        printf("Максимальная месячная %hhd\n", max_month_t(data_array, len_data_array, month));
    }
    else
    {
        printf("Cредняя годовая температура: %.2f\n", avg_year_t(data_array, len_data_array));
        printf("Минимальная годовая %hhd\n", min_year_t(data_array, len_data_array));
        printf("Максимальная годовая %hhd\n", max_year_t(data_array, len_data_array));
    }

    free(data_array);

    return 0;
}
