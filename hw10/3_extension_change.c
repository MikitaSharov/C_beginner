// В файле .txt записан полный адрес файла (возможно, без расширения).
// Необходимо изменить его расширение на ".html" и записать результат в файл .txt.
// Данные на входе: Строка состоящая из символов: a-z, A-Z, 0-9, /
// Данные на выходе: Исходная строка с измененным расширением.
// Пример №1
// Данные на входе: /DOC.TXT/qqq
// Данные на выходе: /DOC.TXT/qqq.html
// Пример №2
// Данные на входе: /DOC.TXT/qqq.com
// Данные на выходе: /DOC.TXT/qqq.html

#include <stdio.h>
#include <string.h>

#define INPUT_PATH "./3_input.txt"
#define OUTPUT_PATH "./3_output.txt"
#define LINE_SIZE 1024

void reader(char line[])
{
    FILE *f = fopen(INPUT_PATH, "r");
    fgets(line, LINE_SIZE, f);
    fclose(f);
}

void change_extension(char line[], char extension[])
{
    int line_len = strlen(line);
    int extension_len = strlen(extension);

    for (size_t i = line_len - 1; i >= 0; i--)
    {
        if (line[i] == '.')
        {
            for (size_t j = 1; j < extension_len; j++)
                line[i + j] = extension[j];
            
            line[i + extension_len] = '\0';
            return;
        }

        if (line[i] == '/')
        {
            strcat(line, extension);
            return;
        }        
    }
}

void writer(char line[])
{
    FILE *file = fopen(OUTPUT_PATH, "w");
    fputs(line, file);
    fclose(file);
}

int main(int argc, char const *argv[])
{
    char line[LINE_SIZE];
    char extension[] = ".html";

    reader(line);
    change_extension(line, extension);
    writer(line);       

    return 0;
}

