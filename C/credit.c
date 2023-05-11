#include <stdio.h>
#include <string.h>

// Identify which credit card

int main(void)
{

    // Prompt for user to input a credit card number
    long num;
    char str[20];
    int length;
    do
    {
        printf("Number: ");
        scanf("%ld", &num);
        // Convert number to string to get length
        sprintf(str, "%ld", num);
        length = strlen(str);

    }
    while (length < 1);

    // Checksum:
    // Part 1) Start from second last digit, every other digit
    // Part 1) Multiply each of these digits by two
    // Part 1) Add the digits together
    // Part 2) Add this number to digits that were not involved
    // Part 3) Check if resulting number ends with 0 (Valid Number)

    // Part 1)
    int sum_1 = 0;
    int sum_2 = 0;
    long num_1 = num;
    long num_2 = num;

    while (num_1 > 0)
    {
        // Remove last digit from number
        num_1 /= 10;
        // Get last digit of number
        int digit = num_1 % 10;
        // Multiply each digit by 2
        int two = digit * 2;

        // Make sure to sum DIGITS not the actual number
        char str_two[3];
        int length_two;
        sprintf(str_two, "%i", two);
        length_two = strlen(str_two);
        if (length_two > 1)
        {
            // Get last digit of number
            int dig = two % 10;
            sum_1 += dig;
            // Remove last digit from number
            two /= 10;
        }

        sum_1 += two;
        // Remove last digit from number
        num_1 /= 10;
    }

    // Part 2)
    while (num_2 > 0)
    {
        // Get last digit of number
        int digit_2 = num_2 % 10;
        sum_2 += digit_2;
        // Remove last two digits from number
        num_2 /= 10;
        num_2 /= 10;
    }
    sum_2 += sum_1;
    // printf("%i", sum_2);

    // Part 3)
    // Check type of card:
    // INVALID --> Checksum does not end in 0
    // AMEX --> starts with 34 or 37 (15 digits)
    // MASTERCARD --> starts with 51, 52, 53, 54 or 55 (16 digits)
    // VISA --> starts with 4 (13 or 16 digits)

    char check[100];
    // Convert credit number to a string to check first two numbers using indexing
    sprintf(check, "%ld", num);
    printf("%i\n", length);
    printf("%c, %c\n", check[0], check[1]);

    if (sum_2 % 10 != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        if (length == 15 && check[0] == '3' && (check[1] == '4' || check[1] == '7'))
        {
            printf("AMEX\n");
        }
        else if (length == 16 && check[0] == '5' && (check[1] == '1' || check[1] == '2' || check[1] == '3' || check[1] == '4'
        || check[1] == '5'))
        {
            printf("MASTERCARD\n");
        }
        else if ((length == 13 || length == 16) && check[0] == '4')
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }

}