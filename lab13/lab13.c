// есть ли слова содержащие гласные только 1ого рода (аоуэыи)

#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <wctype.h>


unsigned long long CharToSet(wchar_t c) {
    c = towlower(c);
    if (c < L'а' || c > L'я'){
        return 0;
    } else {
        return 1llu << (c - L'а');
    }
}

int main() {
    setlocale(LC_ALL, "");
    unsigned long long letters_set = 0;
    unsigned long long vowels = (1llu << (L'а' - L'а') | 1llu << (L'о' - L'а') | 1llu << (L'у' - L'а') | 1llu << (L'э' - L'а') | 1llu << (L'ы' - L'а') | 1llu << (L'и' - L'а'));
    wint_t c;

    while (1) {
        c = getwchar();
        letters_set = letters_set | CharToSet(c);
        if (c == '\n') {   
            break;
        }
    }

    letters_set = letters_set & vowels;

    if (letters_set != 0) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}
