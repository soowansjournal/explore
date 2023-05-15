#include <ctype.h>
#include <stdio.h>

// Global Variable: points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Required for C to know that compute_score() exists later in the program
int compute_score(char *word);

int main(void)
{
    // Get input words from both players
    char word1[100];
    char word2[100];

    printf("Player 1: ");
    fgets(word1, 100, stdin);
    printf("Player 2: ");
    fgets(word2, 100, stdin);

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    printf("%i %i\n", score1, score2);


    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(char *word)
{
    // Compute and return score for string
    // for each letter in the string
    // if the letter is this
    // sum the corresponding point as score

    int score = 0;
    char alpha[] = {'a','b','c', 'd', 'e',
    'f','g','h','i','j','k','l','m','n',
    'o','p','q','r','s','t','u','v','w','x','y','z'};
    // Create a pointer to the beginning of the string
    char *ptr = word;
    while (*ptr != '\0')
    {
        *ptr = tolower(*ptr);
        for (int i = 0; i < 26; i++)
        {
            if (*ptr == alpha[i])
            {
                score += POINTS[i];
            }
        }
        // Move the pointer to the next character
        ptr++;
    }

    return score;
}
