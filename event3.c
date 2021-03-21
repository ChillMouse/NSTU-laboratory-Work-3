#include "phoenixLib.h"

void squeeze (char s[], int c);
char* changeChars(char s[], const char* dist, const char* src);
unsigned int whichLength(const char s[]);
// void sumStrings(const char* str1, const char* str2, char* str3);

int main(){
    translateOutput(); // Перевод консоли на кириллицу

    char firstString[100] = {0}; // Объявил переменные, инициилизировал как пустые
    char secondString[100] = {0};

    puts("Введите строку: ");
    gets(firstString); // Ввёл строку в переменную
    puts("\n Введите строку: ");
    gets(secondString);

    printf("\nДлины строк:\n Первая строка: %d\n Вторая строка: %d\n\n", whichLength(firstString), whichLength(secondString));

    char thirdString[200] = {0};

    // sumStrings(*&firstString, *&secondString, *&thirdString);

    int i, j = 0;
    for (i = 0; firstString[i] != '\0'; ++i){ // Вносим первый массив в третий.
        if (firstString[i] != ' '){
            thirdString[j] = firstString[i];
            j++;
        }
    }
    for (i = 0; secondString[i] != '\0'; ++i){ // Вносим второй массив в третий.
        if (secondString[i] != ' ')
        {
            thirdString[j] = secondString[i];
            j++;
        }
    }

    squeeze(thirdString, ' '); // Удалил пробелы

    printf("%s\n", thirdString); // Вывод суммы двух строк

    char alphabet[] = {'X', 'Y'}; // Набор для функции "какие символы менять"
    char targetChanges[] = {'1', '2'}; // набор "на что менять"

    puts(changeChars(thirdString, alphabet, targetChanges));

    return 0;
}

void squeeze (char s[], int c) { // Удаление пробелов
    int i, j;

    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}

char* changeChars(char s[], const char* dist, const char* src){ // Замена XY на 12
    int i = 0;
    int k = 0;

    do{
        if((*&s[*&i] == *&dist[0]) && (*&s[i+1] == *&dist[1])){

        *&s[i] = *&src[0];
        *&s[i+1] = *&src[1];
        *&k += 1;
        }
        *&i += 1;
    }
    while((*&s[*&i] != '\0') && (*&k < 4));

    return s;
}

unsigned int whichLength(const char s[]){ // Подсчёт длины
    int i = 0;
    int j = 0;

    while((s[*&i] != '\0')){
        *&i += 1;
        *&j += 1;
    }
    return *&j;
}