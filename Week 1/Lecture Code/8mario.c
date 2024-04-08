#include <stdio.h>
#include <cs50.h>
#include <cs50.c>

//final method that prompts over and over if n < 1
int main(void)
{
    //tell this idiot that we need a number
    int n;
    do {
        n = get_int("How big do you want this block to be bro?\n");
    }
    while (n < 1);

    //creates an appropriate block based off the input
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("+");
        }
        printf ("\n");
    }
}

/*asking the user how big the block is
int main(void)
{
    const int n = get_int("How big do you want this block to be bro?\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("+");
        }
        printf ("\n");
    }
}
*/

/*same 3x3 using a constant
int main(void)
{
    const int n = 3;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("+");
        }
        printf ("\n");
    }
}
*/

/* a 3x3 block represented by +s using a loop within a loop
int main(void)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j <3; j++)
        {
            printf("+");
        }
        printf ("\n");
    }
}
*/

/* a 3x3 block represented by +s
int main(void)
{
    for (int i = 0; i < 3; i++)
    {
        printf("+++\n");
    }
}
*/

/* three +'s stacked on each other
int main(void)
{
    for (int i = 0; i < 3; i++)
    {
        printf("+\n");
    }
}
*/

/* four question marks in a row
int main(void)
{
    for (int i = 0; i < 4; i++)
    {
        printf("?");
    }
    printf("\n");
}
*/