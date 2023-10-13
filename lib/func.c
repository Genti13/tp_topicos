#include "func.h"
#include "secuencia.h"

#define FIN_DE_CADENA(c) ((c) == '\0')
#define IGUALES 1
#define DISTINTOS 0

void myStrCopy(const char * origin, char * destiny)
{
    while(!FIN_DE_CADENA(*origin))
    {
        *destiny=*origin;
        origin++;
        destiny++;
    }
    *destiny='\0';
}

int myStrIquals(const char * str1, const char * str2)
{
    while(!FIN_DE_CADENA(*str1) || !FIN_DE_CADENA(*str2))
    {
        if(*str1 != *str2)
        {
            return DISTINTOS;
        }

        str1++;
        str2++;
    }

    return IGUALES;
}

int is_alpha(const char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c<= 'Z');
}

char myUpper(char c)
{
    return c>='a'&& c<='z' ? c - ('a' - 'A') : c;
}

char myLower(char c)
{
    return c>='A' && c<='Z' ? c+('a'-'A'):c;
}
