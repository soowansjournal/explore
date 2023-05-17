#include <stdio.h>
#include <ctype.h>
#include <string.h>

// 26 Character Key
int main(int argc, char *argv[])
{
    // 1)
    // If user doesn't input key into command line argument or inputs more than one
    // Print error message and return 1 in main() to signify error 
    // If user inputs an invalid key: not 26 characters or not a letter or repeats a letter
    // Print error message and return 1 in main() to signify error 
    // Case Insensitive
    // 2)
    // Get plaintext from user
    // 3) 
    // Output ciphertext, non-letters should be unchanged
    // Case Sensitive


    int key_num = 26;

    // 1)

    if (argc != 2)
    {
        printf("Type: ./cipher key\n");
        return 1;
    }

    if (strlen(argv[1]) != key_num)
    {
        printf("Key needs to be %i characters\n", key_num);
        return 1;
    }

    char alpha[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n',
    'o','p','q','r','s','t','u','v','w','x','y','z'};
    if (strlen(argv[1]) == key_num)
    {
        for (int i = 0; argv[1][i] != '\0'; i++)
        {
            // printf("Character: %c\n", argv[1][i]);
            for (int j = 0; j < sizeof(alpha) + 1; j++)
            {
                if (j == sizeof(alpha))
                {
                    printf("Key contains non-letter or repeats letter\n");
                    return 1;
                }
                // printf("Letter: %c\n", alpha[j]);
                if (argv[1][i] == alpha[j] || argv[1][i] == toupper(alpha[j]))
                {
                    // Shift array elements to overwrite the element at the index
                    alpha[j] = alpha[j + 1];
                    // printf("Key character found in alpha\n");
                    // printf("Length of Alpha: %lu\n", sizeof(alpha));
                    // Go to outer loop to check next key character
                    break; 
                }
            }
        }
        printf("Key is Valid\n");

        // 2)
        
        // Assuming a maximum input length of 100 characters
        char plain[100]; 
        do 
        {
            printf("plaintext: ");
            fgets(plain, sizeof(plain), stdin);
        }
        while (strlen(plain) < 1);

        // 3) 
        // For each letter in plaintext
        // Check which index it corresponds to in alphabet
        // Create ciphertext using letter from same index in cipherkey
        
        char alpha2[] = "abcdefghijklmnopqrstuvwxyz";
        char cipher[100];
        printf("Plaintext Word Count: %lu\n", strlen(plain));
        printf("Ciphertext Word Count: %lu\n", strlen(cipher));

        for (int i = 0; i < strlen(plain); i++)
        {
            // printf("Character: %c\n", plain[i]);

            if (plain[i] == ' ')
            {
                cipher[i] = ' ';
            }

            for (int j = 0; j < strlen(alpha2) + 1; j++)
            {
                // printf("Letter: %c at j: %i\n", alpha2[j], j);
                if (plain[i] == alpha2[j] || plain[i] == toupper(alpha2[j]))
                {
                    // printf("Letter %c is at index %i\n", plain[i], j);
                    // printf("Letter %c cipherkey is %c\n", plain[i], argv[1][j]);
                    if (isupper(plain[i]))
                    {
                        cipher[i] = toupper(argv[1][j]);
                    }
                    else if (islower(plain[i]))
                    {
                        cipher[i] = tolower(argv[1][j]);
                    }
                    // printf("Ciphertext Word Count: %lu\n", strlen(cipher));
                    break;
                }
                else if (j == strlen(alpha2))
                {
                    cipher[i] = plain[i];
                    break;
                }
            }

        }
        
        printf("ciphertext:");
        for (int i = 0; plain[i] != '\0'; i++)
        {
            printf("%c", cipher[i]);
        }
        printf("\n");
        // printf("Plaintext Word Count: %lu\n", strlen(plain));
        // printf("Ciphertext Word Count: %lu\n", strlen(cipher));
    }

    return 0;
}