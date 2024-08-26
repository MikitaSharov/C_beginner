// ; В файле .txt дана символьная строка не более 1000 символов. Необходимо
// ; заменить все буквы "а" на буквы "b" и наоборот, как заглавные, так и
// ; строчные. Результат записать в .txt.
// ; Данные на входе: Строка из маленьких и больших английских букв,
// ; знаков препинания и пробелов.
// ; Данные на выходе: Строка из маленьких и больших английских
// ; букв, знаков препинания и пробелов.
// ; Пример
// ; Данные на входе: aabbccddABCD
// ; Данные на выходе: bbaaccddBACD

#include <stdio.h>
#include <string.h>

#define SIZE 1001
#define INPUT_PATH "./2_input.txt"
#define OUTPUT_PATH "./2_output.txt"

void reader(char str[])
{
    FILE *file;
    file = fopen(INPUT_PATH, "r");
    fscanf(file, "%s", str);
    fclose(file);
}

void replace(char str[])
{
    for (size_t i = 0; i < strlen(str); i++)
    {
        if (str[i] == 'a')
            str[i] = 'b';
        else if (str[i] == 'A')
            str[i] = 'B';
        else if (str[i] == 'b')
            str[i] = 'a';
        else if (str[i] == 'B')
            str[i] = 'A';        
    }    
}

void writer(char str[])
{
    FILE *file;
    file = fopen(OUTPUT_PATH, "w");
    fprintf(file, "%s", str);
    fclose(file);
}

int main(int argc, char const *argv[])
{
    char str[SIZE] = {0};    
    reader(str);
    replace(str);
    writer(str);

    return 0;
}
