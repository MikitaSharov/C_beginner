// Ввести номер месяца и вывести название времени года.
// Данные на входе: Целое число от 1 до 12 - номер месяца.
// Данные на выходе: Время года на английском: winter, spring, summer, autumn
// Пример №1
// Данные на входе: 4
// Данные на выходе: spring
// Пример №2
// Данные на входе: 1
// Данные на выходе: winter

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a;

    printf("Введите число от 1 до 12\n");
    scanf("%d", &a);

   a > 0 && a <= 2 || a == 12 ? printf("winter\n") : \
   a > 2 && a <= 5 ? printf("spring\n") : \
   a > 5 && a <= 8 ? printf("summer\n") : \
   a > 8 && a <= 11 ? printf("autumn\n") : \
   printf("Число должно быть от 1 до 12");   

    return 0;
}