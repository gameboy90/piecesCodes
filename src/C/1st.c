#include <stdio.h>
#include <string.h>

void leftshiftone(char *s, int n); 
void shiftleft(char *s, int n, int m); 
int main()
{
    char s[] = "abcdefg";
    int strlength = 0;
    strlength = strlen(s);
    int offset = 3;
    shiftleft(s, strlength, offset);
    printf("%s", s); 
    return 0;
}

void leftshiftone(char s[], int n)
{
    char t = s[0];
    int i;
    for (i=1; i<n; i++)
    {   
        s[i-1] = s[i];
    }   
    s[n-1] = t;
}

void shiftleft(char s[], int n, int m)
{
    while (m--)
    {   
        leftshiftone(s, n); 
    }   
}
