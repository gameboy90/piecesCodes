#include <stdio.h>
#include <string.h>
#include <math.h>

void moveleftoffset(char *s, int strlength, int offset);
void moveleftstepexchange(char *s, int m, int startoffset);
void moveleftstepbybit(char *s, int offsettotail, int startpoint);

int main()
{
    char s[] = "abcdefghijklm";
    int strlength = strlen(s);
    int moveoffset = 3;
    if (moveoffset <= strlength)
    {
        moveleftoffset(s, strlength, moveoffset);
        printf("%s", s);
    }
}

void moveleftoffset(char *s, int strlength, int offset)
{
    int roundtimes = (int)ceil(ceil(strlength/offset)/2);
    int startpoint = (roundtimes) * offset,
        i;
    for (i=0; i<roundtimes; i++)
    {
        moveleftstepexchange(s, offset, i*offset);
    }
    int offsettotail = strlength - startpoint - offset;
    if (offsettotail > 1)
        moveleftstepbybit(s, offsettotail, startpoint);
}

void moveleftstepexchange(char *s, int m, int startoffset)
{
    char temp;
    int i;
    for (i=0; i<m; i++)
    {
        temp = s[i+startoffset];
        s[i+startoffset] = s[m+i+startoffset];
        s[m+i+startoffset] = temp;
    }
}

void moveleftstepbybit(char *s, int offsettotail, int startpoint)
{
    int strlength = strlen(s);
    while (offsettotail--)
    {
        char temp;
        temp = s[strlength - 1];
        int j;
        for (j=strlength-1; j>startpoint; j--)
        {
            s[j] = s[j-1];
        }
        s[startpoint] = temp;
    }
}
