#ifndef SENSOR_DATA_H
#define SENSOR_DATA_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h> // для вашего компилятора

#define YEAR 2021
#define EL_IN_STRUCT 6
#define MAX_T 99
#define MIN_T -99

struct sensor_data {
    uint16_t year;
    uint8_t day;
    uint8_t month;
    uint8_t hour;
    uint8_t minute;
    int8_t t;
};

bool is_valid_line(uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, int8_t t);
size_t reader(struct sensor_data **data_array, size_t capacity, const char *file_path);
float avg_year_t(struct sensor_data data_array[], size_t len_data_array);
float avg_month_t(struct sensor_data data_array[], size_t len_data_array, uint8_t month);
int8_t min_year_t(struct sensor_data data_array[], size_t len_data_array);
int8_t min_month_t(struct sensor_data data_array[], size_t len_data_array, uint8_t month);
int8_t max_year_t(struct sensor_data data_array[], size_t len_data_array);
int8_t max_month_t(struct sensor_data data_array[], size_t len_data_array, uint8_t month);

#endif
