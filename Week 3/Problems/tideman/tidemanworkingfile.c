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
    pair_count = (candidate_count * (candidate_count-1)) / 2;
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
    //pair_count = (candidate_count * (candidate_count-1)) / 2;
    int p = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (!(i==j) && !(j < i))
            {
                if (preferences[i][j] > preferences[j][i])
                {
                    pairs[p].winner = i;
                    pairs[p].loser = j;
                }
                else if (preferences[j][i] > preferences[i][j])
                {
                    pairs[p].winner = j;
                    pairs[p].loser = i;
                }
                p++;
            }
        }
        //Printing the results, REMOVE WITH BUILD
        printf("Pairs[%i].winner = %i\nPairs[%i].loser= %i\n", i, pairs[i].winner, i, pairs[i].loser);
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    int pairiteration = 1;
    int sortedpairiteration = pair_count + 1;
    int oldmax = 0;
    
    for (int i = 0; i < sortedpairiteration; i++)
    {
        int max = 0;
        for (int j = 0; j < pair_count; j++)
        {
            int current = preferences[pairs[j].winner][pairs[j].loser];
            if ((current > max) && (current != oldmax))
            {
                max = current;
            }
        }
        oldmax = max;
        for (int k = 0; k < pair_count; k++)
        {
            if (preferences[pairs[k].winner][pairs[k].loser] == max)
            {
                sortedpairs[pairiteration-1] = pairs[k];
                pairiteration++;
                sortedpairiteration--;
            }
        }
    }
    //printing the sorted pairs, REMOVE WITH BUILD
    for (int i = 0; i < pair_count; i++)
    {
        printf("sortedpairs[%i].winner = %i\nsortedpairs[%i].loser= %i\n", i, sortedpairs[i].winner, i, sortedpairs[i].loser);
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
    int paircountmodifiable = pair_count;
    if(sortedpairs[0].winner == sortedpairs[pair_count - 1].loser)
        {
            paircountmodifiable--;
        }
    for (int i = 0; i < paircountmodifiable; i++)
    {    
        locked[sortedpairs[i].winner][sortedpairs[i].loser] = true;
        printf("locked[%i][%i] is true\n", sortedpairs[i].winner, sortedpairs[i].loser);
    }
    
    //printing the entire locked truthtable, REMOVE WITH BUILD
    printf("\n\n");
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            printf("locked[%i][%i] is %i\n", i, j, locked[i][j]);
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    //int candidatecount[];
    for (int i = 0; i < pair_count; i++)
    {
        for (int j = 0; j < pair_count; j++)
        {
            if (locked[i][j] == true)
            {
                candidatecount[j] += 1;
            }
        }
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidatecount[i] == 0)
        {
            printf("%s\n", candidates[i]);
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