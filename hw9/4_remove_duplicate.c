// В файле .txt строка из маленьких и больших английских букв, знаков
// препинания и пробелов. Требуется удалить из нее повторяющиеся символы и
// все пробелы. Результат записать в файл .txt.
// Данные на входе: Строка из маленьких и больших английских букв,
// знаков препинания и пробелов. Размер строки не более 1000 символов.
// Данные на выходе: Строка из маленьких и больших английских
// букв.
// Пример
// Данные на входе: abc cde def
// Данные на выходе: abcdef

#include <stdio.h>

#define SIZE 1001
#define INPUT_PATH "./4_input.txt"
#define OUTPUT_PATH "./4_output.txt"

int reader(char str[])
{
    int index = 0;
    char ch;

    FILE *f = fopen(INPUT_PATH, "r");

    while ((ch = fgetc(f)) != EOF)
    {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
           str[index++] = ch;        
    }

    str[index] = '\0';
    fclose(f);

    return index;   
}

void remove_duplicate(char str[], char result[], int size)
{
    int is_unique;
    int index = 0;

    for (size_t i = 0; i < size; i++)
    {
        is_unique = 1;

        for (size_t j = 0; j < index; j++)
        {
            if (str[i] == result[j])
            {
                is_unique = 0;
                break;
            }         
        }

        if (is_unique)
            result[index++] = str[i];          
    }

    result[index] ='\0';
}

void writer(char result[])
{
    FILE *file;
    file = fopen(OUTPUT_PATH, "w");

    fprintf(file, "%s", result);
    
    fclose(file);
}

int main(int argc, char const *argv[])
{
    char str[SIZE] = {0};
    int len_result = reader(str);
    char result[len_result];
    remove_duplicate(str, result, len_result);
    writer(result);

    return 0;
}
