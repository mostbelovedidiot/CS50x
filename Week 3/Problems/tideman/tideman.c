#include <cs50.h>
#include <stdio.h>
//#include <cs50.c>

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

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void checkwinner (int n);
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
            string name = get_string("Rank %i: ", j + 1);

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
            //printf("ranks[%i] = %s which is candidates[%i]\n", rank, name, i);
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
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    locked[pairs[0].winner][pairs[0].loser] = true;
    
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

}

// Print the winner of the election
void print_winner(void)
{
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

    /*
    bob = 0
    billy = 1
    sally = 2


    the three pairs are 
    bob > billy         = 2        => bob over billy 2-1
    billy > bob         = 1 
    
    bob > sally         = 1        => sally over bob 2-1
    sally > bob         = 2
    
    billy > sally       = 1        => sally over billy 2-1
    sally > billy       = 2

    return;
    */