#include "pch.h"
#include <iostream>
#include <stdio.h>

// EXE 3
/*
strcat - функция, приписывающая одну строку ко второй
*/

char* strcat(char* dest, const char* src)
{
    int pos_1 = 0, pos_2 = 0;

    while(dest[pos_1] != 0) pos_1++;
    while(src[pos_2] != 0)
    {
        dest[pos_1] = src[pos_2];
        pos_1++;
        pos_2++;
    }
return dest;
}

int main()
{
	char src[] = " the best";
	char dest[] = "My teacher Shariy T.V.";

	char* finaly = strcat(dest, src);
    printf("%s ", finaly);
}
