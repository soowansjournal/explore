#include <stdio.h>
#include <stdbool.h>

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        printf("Minimum: ");
        scanf("%i", &min);
    }
    while (min < 1);

    int max;
    do
    {
        printf("Maximum: ");
        scanf("%i", &max);
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    // TODO
    // If any number divides into it with no remainder, that number is not prime.
    for (int i = 2; i < number; i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}
