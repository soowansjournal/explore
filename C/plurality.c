#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

// Max number of candidates as a 'Macro' constant
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    char name[100];
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(char name[100]);
void print_winner(void);

int main(int argc, char **argv)
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    printf("%i candidates\n", candidate_count);

    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        strcpy(candidates[i].name, argv[i + 1]);
        candidates[i].votes = 0;
    }

    int voter_count; 
    do
    {
        printf("Number of Voters: ");
        scanf("%i", &voter_count);
    }
    while (voter_count < 1);

    // Flush the input buffer to use fgets right off the bat
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        char name[100];
        printf("\nVote #%d: ", i+1);
        fgets(name, sizeof(name), stdin);
        // printf("Received vote: %s", name);

        // Check for invalid vote (function returns false)
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }

    }

    print_winner();

    return 0;
}


// Update vote totals given a new vote
bool vote(char name[100])
{
    // Take single argument (string: name of voted candidate) (Assume no same names)
    // If name == candidate in election
    // Update candidate vote total and return True in vote function
    // If name != candidate in election
    // No change in vote total and return False in vote function
    for (int i = 0; i < candidate_count; i++)
    {
        // printf("candidate %i: %s\n", i, candidates[i].name);
        // printf("Voted Name: %s\n", name);
        // Remove the newline character from the user input
        name[strcspn(name, "\n")] = '\0';
        int result = strcmp(name, candidates[i].name);
        if (result == 0)
        {
            printf("Correct string\n");
            candidates[i].votes += 1;
            printf("%i\n", candidates[i].votes);
            return true;
        }
    }

    return false;
}


// Print the winner (or winners) of the election
void print_winner(void)
{

    // Display winner of election
    // Assume the first element is the maximum
    int max = candidates[0].votes;  
    int arr = 0;
    int max_arr[MAX];
    int j = 0;
    int count = 0;

    // Linear search for the largest number
    for (int i = 0; i < candidate_count; i++) 
    {
        if (candidates[i].votes > max) 
        {
            // Update the maximum if a larger element is found
            max = candidates[i].votes;  
            arr = i;
            // Reset the count if new max is found
            count = 0;
            printf("array index: %i, max votes: %i\n", arr, candidates[i].votes);
        }
        else if (candidates[i].votes == max)
        {
            // Store the index in the array
            max_arr[count] = i;
            // Since first element is compared to first element, count != 0!
            count ++; 
        }
    }

    // Print name of multiple candidates if tie on separate lines
    if (count != 0)
    {
        for (int i = 0; i < count; i++)
        {
            printf("The Winners are:\n");
            printf("%s\n", candidates[max_arr[i]].name);
        }
    }   
    // Print name of most votes and then a new line
    else
    {
        printf("The Winner:\n");
        printf("%s\n", candidates[arr].name);
    }

    return;
}