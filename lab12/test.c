#include <stdio.h>

void RecursionOutput(char num) {
    if (num > 0){
        RecursionOutput(num / 2);
        putchar('0' + num % 2);
    }
}
int main()
{   
    char num = 50;
    RecursionOutput(50);
}