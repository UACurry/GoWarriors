#include <stdio.h>
#include <stdlib.h>

#define UINT unsigned char
//设置八位的char

UINT reverse(UINT a)
{
    int m_4 = 0x0f;
    int m_2 = 0x33;
    int m_1 = 0x55;
    int b = ((a & m_4) << 4) + ((a >> 4) & m_4);
    int c = ((b & m_2) << 2) + ((b >> 2) & m_2);
    int d = ((c & m_1) << 1) + ((c >> 1) & m_1);

    return d;
}

int main()
{
    UINT a = 67;
    UINT b = reverse(a);
    printf("%d\n", b);
    system("pause");
    return 0;
}