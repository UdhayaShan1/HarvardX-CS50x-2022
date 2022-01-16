#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    int i2 = 0;
    for (i2 = 0; i2 < candidate_count; i2 ++)
    {
        if (strcmp(name, candidates[i2].name) == 0)
        {
            candidates[i2].votes += 1;
            return true;
        }

    }

    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int max1 = 0;
    int i3 = 0;
    for (i3 = 0; i3 < candidate_count; i3 ++)
    {
        if (candidates[i3].votes > max1)
        {
            max1 = candidates[i3].votes;
        }
    }
    int i4 = 0;
    for (i4 = 0; i4<candidate_count; i4++)
    {
        if (candidates[i4].votes == max1)
        {
            printf("%s\n",candidates[i4].name);
        }
    }
    return;
}
