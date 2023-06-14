// Practice working with structs
// Practice applying sorting algorithms
#include <stdio.h>

#define NUM_CITIES 10
#define MAX_STR_LENGTH 20
#define ARRAY_SIZE 3

typedef struct
{
    char* city;
    int temp;
}
avg_temp;

avg_temp temps[NUM_CITIES];

void sort_cities(void);

int main(void)
{
    temps[0].city = "Seoul";
    temps[0].temp = 28;

    temps[1].city = "Toronto";
    temps[1].temp = 27;

    temps[2].city = "New York";
    temps[2].temp = 29;

    temps[3].city = "Ghana";
    temps[3].temp = 27;

    temps[4].city = "Lund";
    temps[4].temp = 21;

    temps[5].city = "Stockholm";
    temps[5].temp = 23;

    temps[6].city = "Moscow";
    temps[6].temp = 24;

    temps[7].city = "Vancouver";
    temps[7].temp = 22;

    temps[8].city = "Boston";
    temps[8].temp = 28;

    temps[9].city = "Montreal";
    temps[9].temp = 26;

    sort_cities();

    printf("\nAverage July Temperatures by City\n\n");

    for (int i = 0; i < NUM_CITIES; i++)
    {
        printf("%s: %i\n", temps[i].city, temps[i].temp);
    }
}

// TODO: Sort cities by temperature in descending order
void sort_cities(void)
{
    int swap = 1;
    while (swap != 0)
    {
        swap = 0;
        for (int i = 0; i < NUM_CITIES - 1; i++)
        {
            if (temps[i].temp > temps[i+1].temp)
            {
                // Swap Temperature
                int tmp_ = temps[i].temp;
                temps[i].temp = temps[i+1].temp;
                temps[i+1].temp = j;
                swap ++;
                // // Corresponding Cities
                // char* tmp_city[] = *temps[i].city;
                // *temps[i].city = *temps[i+1].city;
                // *temps[i+1].city = tmp_city;
                // swap ++;
            }
        }
    }
}
