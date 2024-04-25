#include <cs50.h>
#include <stdio.h>
#include <cs50.c>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];
int candidatecount[MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];
pair sortedpairs[MAX * (MAX - 1) /2];

int pair_count;
int candidate_count;
int lockedcount;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    //check50 doesn't want this here I guess
    //pair_count = (candidate_count * (candidate_count-1)) / 2;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // i is iterating through all the preferences of ONE voter
        // j is iterating through all the ranks to collect these preferences

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string(NULL, "Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO

    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0)
        {
            ranks[rank] = i;
            //printing the results, REMOVE WITH BUILD
            printf("ranks[%i] = %s which is candidates[%i]\n", rank, name, i);
            return true;
        }
    }

    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (!(i == j) && !(j < i))
            {
                preferences[ranks[i]][ranks[j]] += 1;
                printf("preferences[%i][%i] = %i\n", ranks[i], ranks[j], preferences[ranks[i]][ranks[j]]);
            }
        }
    }
    //printing the results, REMOVE WITH BUILD
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            printf("preferences[%i][%i] = %i\n", i, j, preferences[i][j]);
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (!(i==j) && !(j < i))
            {
                if (preferences[i][j] > preferences[j][i])
                {
                    pairs[pair_count].winner = i;
                    pairs[pair_count].loser = j;
                    pair_count++;
                }
                else if (preferences[j][i] > preferences[i][j])
                {
                    pairs[pair_count].winner = j;
                    pairs[pair_count].loser = i;
                    pair_count++;
                }
            }
        }
    }
    printf("PAIR COUNT IS %i\n", pair_count);
    //Printing the unsorted pairs, REMOVE WITH BUILD
    for (int i = 0; i < pair_count; i++)
    {
        printf("Pairs[%i].winner = %i\nPairs[%i].loser= %i\n", i, pairs[i].winner, i, pairs[i].loser);
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    int pairiteration = 0;
    int sortedpairiteration = pair_count;
    int oldmax = 10;
    
    for (int i = 0; i < sortedpairiteration; i++)
    {
        int max = 0;
        for (int j = 0; j < pair_count; j++)
        {
            int current = preferences[pairs[j].winner][pairs[j].loser];
            if ((current > max) && (current < oldmax))
            {
                max = current;
            }
        }
        oldmax = max;
        for (int k = 0; k < pair_count; k++)
        {
            if (preferences[pairs[k].winner][pairs[k].loser] == max)
            {
                sortedpairs[pairiteration] = pairs[k];
                pairiteration++;
            }
        }
    }

    for (int i = 0; i < pair_count; i++)
    {
        pairs[i] = sortedpairs[i];
    }
    //printing the sorted pairs, REMOVE WITH BUILD
    for (int i = 0; i < pair_count; i++)
    {
        printf("sortedpairs[%i].winner = %i\nsortedpairs[%i].loser= %i\n", i, sortedpairs[i].winner, i, sortedpairs[i].loser);
    }
    for (int i = 0; i < pair_count; i++)
    {
        printf("pairs[%i].winner = %i\npairs[%i].loser= %i\n", i, pairs[i].winner, i, pairs[i].loser);
    }
        //iterate through the whole loop and find the max
        //match the max to the respective pair
        //move that pair to sortedpair[0]
        //move to pair[1]
        //repeat
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    locked[pairs[0].winner][pairs[0].loser] = true;
    
    // This solution is not complete as it only checks for a complexity of 4 pairs linked in a cycle 0-1 1-2 2-3 3-0, and it SHOULD fail (having no additional loop) in the situation like 0-1 1-2 2-3 3-4 4-0. These simply require more loops, or a recursive function that I had began to make below, but gave up
    int lockedpairsiteration = 1;
    while (lockedpairsiteration < pair_count)
    {
        bool checkersnecker = true;
        for (int i = 0; i < lockedpairsiteration; i++)
        {
            if (pairs[i].loser == pairs[lockedpairsiteration].winner)
            {
                for (int z = 0; z < lockedpairsiteration; z++)
                {
                    if ((pairs[z].winner == pairs[lockedpairsiteration].loser) && (pairs[z].loser == pairs[i].winner))
                    {
                        checkersnecker = false;
                    }
                    for (int y = 0; y < lockedpairsiteration; y++)
                    {
                        if ((pairs[z].winner == pairs[lockedpairsiteration].loser) && (pairs[z].loser == pairs[y].winner) && (pairs[y].loser == pairs[i].winner))
                        {
                        checkersnecker = false;
                        }
                    }
                }
            }
        }
        if (checkersnecker)
        {
            locked[pairs[lockedpairsiteration].winner][pairs[lockedpairsiteration].loser] = true;
        }
        lockedpairsiteration++;
    }

    return;
/* The beginnings of a "proper" solution, these functions demonstrate the logic needed to recursively check the respective losers to the respective winners. A helper function would be needed, but I gave up
    for (int i = 0; i < lockedpairsiteration; i++)
    {
        if (pairs[i].winner == pairs[lockedpairsiteration].loser)
        {
            if (pairs[i].loser == pairs[lockedpairsiteration].winner)
            {
                checkersnecker = false;
                break;
            }
            else
            {
                for (int a = 0; a < lockedpairsiteration; a++)
                {
                    if (pairs[i].loser == pairs[a].winner)
                    {
                        if (pairs[a].loser == pairs[lockedpairsiteration].winner)
                        checkersnecker = false;
                        break;
                    }
                    else
                }
            }
        }
    }
*/

}

// Print the winner of the election
void print_winner(void)
{
    //printing the entire locked truthtable, REMOVE WITH BUILD
    printf("\n\n");
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            printf("locked[%i][%i] is %i\n", i, j, locked[i][j]);
        }
    }

    int lockedcount = 0;
    for (int i = 0; i <= pair_count; i++)
    {
        for (int j = 0; j <= pair_count; j++)
        {
            if (locked[i][j] == true)
            {
                lockedcount++;
            }
        }
    }

    printf("LOCKED COUNT IS %i\n",lockedcount);
    int winnerarray[lockedcount];
    int loserarray[lockedcount];
    int winnerloserindex = 0;
    for (int i = 0; i <= pair_count; i++)
    {
        for (int j = 0; j <= pair_count; j++)
        {
            if (locked[i][j] == true)
            {
                winnerarray[winnerloserindex] = i;
                loserarray[winnerloserindex] = j;
                winnerloserindex++;
            }
        }
    }

    for (int i = 0; i < lockedcount; i++)
    {
        printf("winnerarray[%i] is %i\n", i, winnerarray[i]);
    }
    for (int i = 0; i < lockedcount; i++)
    {
        printf("loserarray[%i] is %i\n", i, loserarray[i]);
    }


    for (int i = 0; i < lockedcount; i++)
    {
        for (int j = 0; j < lockedcount; j++)
        {
            if (winnerarray[i] == loserarray[j])
            {
                winnerarray[i] += 10;
            }
            if ((i != j) && winnerarray[i] == winnerarray[j])
            {
                winnerarray[j] += 10;
            }
        }
    }

    for (int i = 0; i < lockedcount; i++)
    {
        if (winnerarray[i] < 10)
        {
            printf("%s\n", candidates[winnerarray[i]]);
        }
    }

    return;
}