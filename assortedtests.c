#include <stdio.h>
#include <cs50.h>
#include <cs50.c>

int main(void)
{
    int locked[0];
    for (int i = 0; i < 3; i++)
    {
        locked[i] = i;
        printf("locked[%i] is %i\n", i, locked[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        printf("locked[%i] is %i\n", i, locked[i]);
    }
}