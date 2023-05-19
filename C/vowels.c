#include <stdio.h>

// Declare function 
void replace(char *argv[1]);

int main(int argc, char *argv[])
{
    // Check single-line argument from user
    if (argc != 2)
    {
        printf("Type: ./vowels word\n");
        return 1;
    }
    replace(argv);

}

void replace(char *argv[1])
{
    // For each letter in string
    // If letter is following: a e i o u we convert them
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (argv[1][i] == 'a')
        {
            argv[1][i] = '6';
        }
        else if (argv[1][i] == 'e')
        {
            argv[1][i] = '3';
        }
        else if (argv[1][i] == 'i')
        {
            argv[1][i] = '1';
        }
        else if (argv[1][i] == 'o')
        {
            argv[1][i] = '0';
        }
    }
    printf("%s\n", argv[1]);
}