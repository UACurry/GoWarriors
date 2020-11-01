#include <stdio.h>
#include <stdlib.h>

#define MAX 100
int arr[MAX] = {0};
int main()
{
    int schoolID;
    int people_count;
    int score;
    scanf("参赛人数:%d", &people_count);
    int i;
    for (i = 0; i < people_count; i++)
    {
        scanf("参赛学校及成绩:%d %d", &schoolID, &score);
        arr[schoolID] += score;
    }
    int max_id = 1;
    int max = -1;
    for (int k = 1; k <= people_count; k++)
    {
        if (arr[k] > max)
        {
            max = arr[k];
            max_id = k;
        }
    }
    printf("%d %d\n", max_id, max);
    system("pause");
    return 0;
}