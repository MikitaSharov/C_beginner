// В файле .txt дана строка слов, разделенных пробелами. Найти самое длинное
// слово и вывести его в файл .txt. Случай, когда самых длинных слов может быть
// несколько, не обрабатывать.
// Данные на входе: Строка из английских букв и пробелов. Не более
// 1000 символов.
// Данные на выходе: Одно слово из английских букв.
// Пример
// Данные на входе: Hello beautiful world
// Данные на выходе: beautiful


#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 1001
#define INPUT_PATH "./5_input.txt"
#define OUTPUT_PATH "./5_output.txt"

void reader(char str[])
{
    FILE *f = fopen(INPUT_PATH, "r");
    fgets(str, SIZE, f);
    
    fclose(f);
}

void find_longest_word(char str[], char longest_word[])
{
    int current_len = 0;
    int max_len = 0;
    int start_index = 0;
    int max_start_index = 0;

    for (size_t i = 0; str[i] != '\0'; i++)
    {
        if (isalpha(str[i]))
        {
            if (current_len == 0)
                start_index = i;

            current_len++;
        }
        else
        {
            if (current_len > max_len)
            {
                max_len = current_len;
                max_start_index = start_index;
            }

            current_len = 0;
        }
    }

    if (current_len > max_len)
    {
        max_len = current_len;
        max_start_index = start_index;
    }

    strncpy(longest_word, &str[max_start_index], max_len);
    longest_word[max_len] = '\0';
}

void writer(char longest_word[])
{
    FILE *f = fopen(OUTPUT_PATH, "w");
    fprintf(f, "%s\n", longest_word);
    fclose(f);
    
}

int main(int argc, char const *argv[])
{
    char str[SIZE] = {0};
    char longest_word[100] = {0};
    reader(str);
    find_longest_word(str, longest_word);
    writer(longest_word);
    
    return 0;
}
