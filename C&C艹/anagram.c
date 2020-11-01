#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//判断两个字符串中字母出现的次数是否一样

bool is_Anagram(char *s, char *t)
{
    int StaS[26] = {0};
    int StaT[26] = {0};
    int lenS = strlen(s);
    int lenT = strlen(t);
    int i;
    for (i = 0; i < lenS; i++)
    {
        int index = s[i] - 'a'; //这样就拿到了下标，用ASCII码减掉的
        StaS[index]++;
    }
    for (i = 0; i < lenT; i++)
    {
        int index = t[i] - 'a'; //这样就拿到了下标，用ASCII码减掉的
        StaT[index]++;
    }
    for (i = 0; i < 26; i++)
    {
        if (StaS[i] != StaT[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    char *n = "ten";
    char *m = "net";
    printf("%d\n", is_Anagram(n, m));
    system("pause");
    return 0;
}