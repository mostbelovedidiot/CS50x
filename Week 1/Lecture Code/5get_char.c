#include <stdio.h>
#include <cs50.h>
#include <cs50.c>

int main(void)
{
    // Prompt user to agree
    char c = get_char("Do you agree? ");

    // Check whether agreed
    if (c == 'Y' || c == 'y')
    {
        printf("Agreed.\n");
    }
    else if (c == 'N' || c == 'n')
    {
        printf("Not agreed.\n");
    }
    else
    {
        printf("You fucking idiot.\n");
    }
}