#include <iostream>
#include <algorithm>

using namespace std;

int msb(int number)
{
    int count = 0;
    while (number > 0)
    {
        number = (number >> 1);
        count++;
    }
    return count;
}

int set_bit(int result, int i)
{
    return result | (1 << i);
}

int get_bit(int number, int i)
{
    return (number >> i) & 1;
}

int bit_and(int m, int n)
{
    int msb_m = msb(m);
    int msb_n = msb(n);

    int result = 0;

    if (msb_m != msb_n)
    {
        return 0;
    }

    int msb = msb_m;
    while (msb >= 0)
    {
        int x = get_bit(m, msb);
        int y = get_bit(n, msb);
        if (x != y)
        {
            return result;
        }
        else if (x == y && x == 1)
        {
            result = set_bit(result, msb);
        }
        msb--;
    }
    return result;
}

int main()
{

    system("pause");
    return 0;
}