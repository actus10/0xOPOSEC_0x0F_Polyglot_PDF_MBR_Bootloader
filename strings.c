#include "strings.h"
int strcmp(d, s)char *d; char *s;{
    register char *s1 = (char *) d, *s2 = (char *) s, c1, c2;
    while ((c1 = *s1++) == (c2 = *s2++) && c1);
    return c1 - c2;
}


int strlen(str)char *str;{
    register char *p = (char *) str;
    while (*p) p++;
    return p - str;
}


int imod(i, j)int i; int j;{
    return (i - ((i / j) * j));
}

char* itoa(i)int i;{
    static char a[7];
    char *b = a + sizeof(a) - 1;
    int sign = (i < 0);
    if (sign)
        i = -i;
    *b = 0;
    do {
        *--b = '0' + (imod(i, 10));
        i /= 10;
    } while (i);
    if (sign)
        *--b = '-';
    return b;
}


char* strcpy(d, s)char *d; char *s; {
   /* This is probably the quickest on an 8086 but a CPU with a cache will
    * prefer to do this in one pass */
   return memcpy(d, s, strlen(s)+1);
}


typedef int size_t;
void* memcpy(d, s, l) void *d; void *s; size_t l; {
   register char *s1=d, *s2=(char *)s;
   for( ; l>0; l--) *((unsigned char*)s1++) = *((unsigned char*)s2++);
   return d;
}
