#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start;
    do
    {
        printf("Start size: ");
        scanf("%d", &start);
    }
    while (start < 9);

    // TODO: Prompt for end size
    int end;
    do
    {
        printf("End size: ");
        scanf("%d", &end);
    }
    while (end < start);

    // TODO: Calculate number of years until we reach threshold
    int year = 0;
    while (start < end)
    {
        start = start + (start/3) - (start/4);
        year++;
    }
    printf("Years: %i\n", year);

    // for (int year = 0; year < 1000; year++)
    // {
    //     float born = start / 3;
    //     float dead = start / 4;
    //     start = start + born - dead;

    //     if (start >= end)
    //     {
    //         printf("Years: %i\n", year);
    //         break;
    //     }
    // }

    // TODO: Print number of years
    // printf("Years: %i\n", year);
}
