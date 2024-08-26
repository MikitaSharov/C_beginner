// В файле .txt даны два слова не более 100 символов каждое, разделенные
// одним пробелом. Найдите только те символы слов, которые встречаются в
// обоих словах только один раз. Напечатайте их через пробел в файл .txt в
// лексикографическом порядке.
// Данные на входе: Два слова из маленьких английских букв через
// пробел. Длинна каждого слова не больше 100 символов.
// Данные на выходе: Маленькие английские буквы через пробел.
// Пример №1
// Данные на входе: hello world
// Данные на выходе: o
// Данные на входе: aabcd bcef
// Данные на выходе: b c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INPUT_PATH "./1_input.txt"
#define OUTPUT_PATH "./1_output.txt"
#define SIZE 101
#define MAX_LETTERS_IN_ENG_ALPHABET 26


void reader(char first_word[], char second_word[])
{
    FILE *file;
    file = fopen(INPUT_PATH, "r");

    fscanf(file, "%s %s", first_word, second_word);

    fclose(file);
}

void once_time(char first_word[], char second_word[], char result[])
{
    int len_first_word = strlen(first_word);
    int len_second_word = strlen(second_word);
    int count_first;
    int count_second;
    int index_result = 0;

    for (size_t i = 0; i < len_first_word; i++)
    {
        count_first = 0;
        count_second = 0;

        for (size_t j = 0; j < len_first_word; j++)
        {
            if (first_word[i] == first_word[j])
                count_first++;
        }

        if (count_first == 1)
        {
            for (size_t k = 0; k < len_second_word; k++)
            {
                if (first_word[i] == second_word[k])
                    count_second++;
            }
        }

        if (count_second == 1)
            result[index_result++] = first_word[i];

        result[index_result] = '\0';
    }
}

int compare_chars(const void *a, const void *b)
{
    return (*(char *)a - *(char *)b);
}

void writer(char result[])
{
    int len_result = strlen(result);

    qsort(result, len_result, sizeof(char), compare_chars);

    FILE *file;
    file = fopen(OUTPUT_PATH, "w");

    for (size_t i = 0; i < len_result; i++)
        fprintf(file, "%c ", result[i]);

    fclose(file);
}

int main(int argc, char const *argv[])
{
    char first_word[SIZE] = {0};
    char second_word[SIZE] = {0};
    char result[MAX_LETTERS_IN_ENG_ALPHABET + 1] = {0};

    reader(first_word, second_word);
    once_time(first_word, second_word, result);    
    writer(result);

    return 0;
}
