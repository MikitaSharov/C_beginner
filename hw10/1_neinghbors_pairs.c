// Пары соседних символов
// В файле .txt записаны символы. Необходимо разработать функцию, которая
// меняет местами пары соседних символов не обращая внимание на символы
// пробел. Если количество символов нечетно (пробелы не считаем), то
// последний символ не меняем. Результат записать в файл .txt.
// Данные на входе: Строка из английских букв, пробелов и знаков
// препинания. Не более 1000 символов.
// Данные на выходе: Строка из английских букв, пробелов и знаков
// препинания.
// Пример №1
// Данные на входе: Hello world!
// Данные на выходе: eHllw orodl!
// Пример №2
// Данные на входе: abc def
// Данные на выходе: bad cfe

#include <stdio.h>
#include <ctype.h>

#define INPUT_PATH "./1_input.txt"
#define OUTPUT_PATH "./1_output.txt" 

int main(int argc, char const *argv[])
{
    char ch;
    char first_char = '\0';
    _Bool is_first_char = 0;

    FILE *in_file = fopen(INPUT_PATH, "r");
    FILE *out_file = fopen(OUTPUT_PATH, "w");

    while ((ch = fgetc(in_file)) != EOF)
    {
        if (ch != ' ')
        {
            if (is_first_char)
            {
                fputc(ch, out_file);
                fputc(first_char, out_file);

                is_first_char = 0;          
            }
            else
            {
                first_char = ch;
                is_first_char = 1;
            }            
        }
        else
        {
            fputc(fgetc(in_file), out_file);
            fputc(ch, out_file);
            fputc(first_char, out_file);
            
            is_first_char = 0;
        }
    }

    if (is_first_char)
        fputc(first_char, out_file);

    fclose(out_file);
    fclose(in_file);

    return 0;
}