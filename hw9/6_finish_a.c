//  Заканчивается на a
// В файле .txt дано предложение. Необходимо определить, сколько слов
// заканчиваются на букву 'а'. Ответ записать в файл .txt.
// Данные на входе: Строка из английских букв и пробелов не более 1000
// символов.
// Данные на выходе: Одно целое число
// Пример
// Данные на входе: Mama mila ramu
// Данные на выходе: 2


#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 1001
#define INPUT_PATH "./6_input.txt"
#define OUTPUT_PATH "./6_output.txt"

int main(int argc, char const *argv[])
{
    char str[SIZE];
    int counter = 0;

    FILE *f = fopen(INPUT_PATH, "r");
    fgets(str, SIZE, f);
    fclose(f);

    for (size_t i = 0; i < strlen(str); i++)
    {
        if (!isalpha(str[i]) && i > 0)
        {
            if (str[i - 1] == 'a')
                counter++;            
        }
    }

    if (str[strlen(str) - 1] == 'a')
            counter++;
    
    FILE *fq = fopen(OUTPUT_PATH, "w");
    fprintf(fq,"%d", counter);
    fclose(fq);
    
    return 0;
}
