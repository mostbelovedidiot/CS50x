#include <stdio.h>
#include <cs50.h>
#include <cs50.c>

// example of printfdebugging utilizing separate functions
void columnCreator(int height);

int main(void)
{
    int queryHeight = get_int("What height do you desire?: " );
    columnCreator(queryHeight);
}

void columnCreator(int height)
{
    for (int i = 1; i <= height; i++)
    {
        printf("#\n");
    }
}

/* basic example of printfdebugging
int main (void)
{
    for (int i = 0; i <= 5; i++)
    {
        printf("i is %i\n", i);
        printf("#\n");
    }
}
*/