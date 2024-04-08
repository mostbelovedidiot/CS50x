#include <cs50.h>
#include <stdio.h>
//#include <cs50.c>

int main(void)
{
    //Asking user for input, restricted to numbers
    int h;
    do
    {
        h = get_int("How tall should the pyramid be?\n");
    }
    while (h < 1);
    
    //Variable to allot correct amount of spaces based on user input
    int initialIndent = (h - 1);
    //Variable to allot correct amount of blocks based on user input
    int bigdick = 0;

    //The loop iterates per line, creating spaces, then blocks, then the empty space, then more blocks, adding a line at the end
    for (int i = 0; i < h; i++)
    {
        for (int returnIndent = initialIndent; returnIndent >= 1; returnIndent--)
        {
            printf(" ");
        }
        for (int j = 0; j <= bigdick; j++)
        {
            printf("#");
        }
        //Empty double space between blocks
        printf("  ");
        for (int k = 0; k <= bigdick; k++)
        {
            printf("#");
        }
        //Spaces are reduced per iteration
        initialIndent--;
        //Blocks are increased per iteration
        bigdick++;
        printf("\n");
    }
}