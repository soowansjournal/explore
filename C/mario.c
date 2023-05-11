#include <stdio.h>

// Create mario pyramid, height depends on user
int main(void)
{
    // Prompt user for integer between 1 and 8 inclusive
    int height;
    do
    {
        printf("Pyramid Height: ");
        scanf("%d", &height);
    }
    while (height < 1 || height > 8);

    // Print pyramid
    for (int i = 0; i < height; i++)
    {
        // At each row, print space with pattern: height - row
        int row = i + 1;
        // printf("Row: %i", row);

        for (int j = 0; j < height - row; j++)
        {
            printf(" ");
        }

        for (int k = 0; k < row; k++)
        {
            printf("#");
        }

        printf("  ");

        for (int m = 0; m < row; m++)
        {
            printf("#");
        }

        printf("\n");

    }

}