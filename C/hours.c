#include <ctype.h>
#include <stdio.h>

float calc_hours(int hours[], int weeks, char output);

int main(void)
{
    int weeks;
    printf("Number of weeks learning to code: ");
    scanf("%d", &weeks);

    // Create and array called hours using weeks as the length
    int hours[weeks];

    for (int i = 0; i < weeks; i++)
    {
        int w = i + 1;
        int est;
        printf("Week %i Estimated Hours: ", w);
        scanf("%d", &est);
        hours[i] = est;
    }

    char output;
    do
    {
        printf("Enter T (total hours) or A (average hours) per week: ");
        output = toupper(getchar());
    }
    while (output != 'T' && output != 'A');

    if (output == 'T')
    {
        printf("Total: %.1f hours in %i weeks\n", calc_hours(hours, weeks, output), weeks);
    }
    else
    {
        printf("Average: %.1f hours/week during %i weeks\n", calc_hours(hours, weeks, output), weeks);
    }
}

float calc_hours(int hours[], int weeks, char output)
{
    // Total up the hours saved in the array into a new variable
    int total = 0;
    for (int i = 0; i < weeks; i++)
    {
        total += hours[i];
    }

    // If total hours --> output total
    if (output == 'T')
    {
        return total;
    }
    // If average hours --> output average
    else
    {
        return total / (float) weeks;
    }

}