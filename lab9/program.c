/* Лабораторная работа №9. Вариант 26.
Студент группы М8О-110Б-22 */

#include <stdio.h>
#include <locale.h>

// функция поиска модуля числа
int Abs(int num) {
    if (num >= 0)
    {
        return num;
    }
    else
    {
        return -num;
    }
}
// возведение в степень 
int Pow(int num, int p) {
    int res = 1;
    for (int i = 1; i <= p; i++)
    {
        res *= num;
    }
    return res;
}
// поиск максимума
int Max(int a, int b) {
    if (a >= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
// поиск минимума
int Min(int a, int b) {
    if (a <= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
// i на следующем шаге
int iNext(int i, int j, int k, int l) {
    int i_n = 0;
    i_n = Abs(Max(Min(i + j, i + l) % 30, Max(i + l, j + k) % 25));
    return i_n;
}
// j на следующем шаге
int jNext(int i, int j, int k, int l) {
    int j_n = 0;
    j_n = Abs(i + k) % 10 + Abs(j + k) % 10 + Abs(l + k) % 10;
    return j_n;
}
// l на следующем шаге
int lNext(int i, int j, int k, int l) {
    int l_n = 0;
    l_n = (Pow(i, 3) + Pow(j, 3) + Pow(l, 3) - k) % 35;
    return l_n;
}
// проверка попадания
int Check(int i, int j, int l, int k) {
    if (Pow(i - 20, 2) + 4 * Pow(j, 2) <= 100)
    {
        printf("Попал!\n");
        printf("Номер шага: %d\n", k);
        printf("Координата i: %d\n", i);
        printf("Координата j: %d\n", j);
        printf("Динамический параметр движения: %d\n", l);
        return 1;
    }
    else
    {
        return 0;
    }
}
// основное тело 
int main(void) {
    int i_n = 0;
    int j_n = 0;
    int l_n = 0;
    int i = -10;
    int j = -10;
    int l = 6;
    setlocale(LC_ALL, "Rus");
    for (int k = 0; k < 50; k++) {
        i_n = iNext(i, j, k, l);
        j_n = jNext(i, j, k, l);
        l_n = lNext(i, j, k, l);
        if (Check(i, j, k, l) == 1)
        {
            return 0;
        }
        i = i_n;
        j = j_n;
        l = l_n;
    }
    printf("Не попал:(\n");
    printf("Координата i: %d\n", i);
    printf("Координата j: %d\n", j);
    printf("Динамический параметр движения: %d\n", l);
}
