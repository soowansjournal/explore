#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool valid(char password[]);

char password[] = "";
int main(void)
{
    printf("Create a password: ");
    fgets(password, 100, stdin);
    if (valid(password))
    {
        printf("Password is valid!\n");
    }
    else
    {
        printf("Password missing: one uppercase letter, lowercase letter, number or symbol\n");
    }
}

// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
bool valid(char password[])
{
    // For each letter in password
    // Check for lowercase
    // Check for uppercase
    // Check for number
    // Check for symbol
    bool low = 0;
    bool upp = 0;
    bool num = 0;
    bool sym = 0;
    char alpha[] = "abcdefghijklmnopqrstuvwxyz";
    char numbers[] = "0123456789";
    for (int i = 0; password[i] != '\0'; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (password[i] == alpha[j])
            {
                low = 1;
            }
            else if (password[i] == toupper(alpha[j]))
            {
                upp = 1;
            }
            else
            {
                for (int k = 0; k < 10; k++)
                {
                    if (password[i] == numbers[k])
                    {
                        num = 1;
                    }
                    else
                    {
                        sym = 1;
                    }
                }
            }
        }
    }
    
    // If all conditions are met, valid
    if (low == 1 && upp == 1 && num == 1 && sym ==1)
    {
        return true;
    }

    // If one condition is not met, invalid
    return false;
}
