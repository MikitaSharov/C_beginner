// В файле .txt необходимо удалить все лишние пробелы (в начале предложения и сдвоенные пробелы).
// Для решения задачи разработать функцию. Результат записать в .txt.
// Данные на входе: Строка из английских букв, знаков препинания и пробелов. Не более 1000 символов.
// Данные на выходе: Строка из английских букв, знаков препинания и пробелов.
// Пример
// Данные на входе: Hello world!
// Данные на выходе: Hello world!

#include <stdio.h>
#include <ctype.h>

#define INPUT_PATH "./2_input.txt"
#define OUTPUT_PATH "./2_output.txt" 


int main(int argc, char const *argv[])
{
    FILE *in_file = fopen(INPUT_PATH, "r");
    FILE *out_file = fopen(OUTPUT_PATH, "w");

    char ch;
    _Bool is_space = 0;

    while ((ch = fgetc(in_file)) != EOF && isspace(ch))
    {
        
    }

    if (ch != EOF)
        fputc(ch, out_file);

    while ((ch = fgetc(in_file)) != EOF)
    {
        if (isspace(ch))
        {
            if (!is_space)
            {
                fputc(' ', out_file);
                is_space = 1;
            }            
        }
        else
        {
            fputc(ch, out_file);
            is_space = 0;
        }
    }

    fclose(out_file);
    fclose(in_file);

    return 0;
}
