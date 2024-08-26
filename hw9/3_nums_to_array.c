// В файле .txt дана строка, не более 1000 символов, содержащая буквы, целые
// числа и иные символы. Требуется все числа, которые встречаются в строке,
// поместить в отдельный целочисленный массив. Например, если дана строка
// "data 48 call 9 read13 blank0a", то в массиве числа 48, 9, 13 и 0. Вывести
// массив по возрастанию в файл .txt.
// Данные на входе: Строка из английских букв, цифр и знаков
// препинания
// Данные на выходе: Последовательность целых чисел
// отсортированная по возрастанию
// Пример
// Данные на входе: data 48 call 9 read13 blank0a
// Данные на выходе: 0 9 13 48


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1001
#define INPUT_PATH "./3_input.txt"
#define OUTPUT_PATH "./3_output.txt"

void reader(char str[]) 
{
    int ch;
    int i = 0;

    FILE *file;
    file = fopen(INPUT_PATH, "r");

    while ((ch = fgetc(file)) != EOF)
        str[i++] = ch;
    
    str[i] = '\0';

    fclose(file);
}

int nums_to_array(char str[], int nums[])
{
    int index = 0;
    int is_num = 0;

    for (size_t i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            if(is_num)
            {
                nums[index] = nums[index] * 10 + (str[i] - '0');
            }
            else
            {
                nums[index] = str[i] - '0';
                is_num = 1;
            }
        }
        else if (is_num)
        {
            index++;
            is_num = 0;
        }
    }

    if (is_num)
        index++;

    nums[index] = -1;
    
    return index;
}

void writer(int nums[])
{
    FILE *file;
    file = fopen(OUTPUT_PATH, "w");

    for (size_t i = 0; nums[i] != -1; i++)
    {
        fprintf(file, "%d ", nums[i]);
    }
    
    fclose(file);
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main(int argc, char const *argv[])
{
    char str[SIZE] = {0};
    int nums[SIZE] = {0};

    reader(str);
    int len_nums = nums_to_array(str, nums);
    qsort(nums, len_nums, sizeof(int), compare);
    writer(nums);   

    return 0;
}
