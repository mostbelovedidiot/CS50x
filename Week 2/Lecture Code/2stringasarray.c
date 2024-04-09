#include <stdio.h>
#include <cs50.h>
#include <cs50.c>

// An array within an array
int main(void)
{
    string urnan[2];

    urnan[0] = "fat";
    urnan[1] = "ass";

    printf("%c%c%c%c%c\n", urnan[0][0], urnan[0][1], urnan[0][2], urnan[0][3], urnan[0][4]);
    printf("%c%c%c%c\n", urnan[1][0], urnan[1][1], urnan[1][2], urnan[1][3]);

    // notice there are still sentinel values, and that the first array does bleed into the second array semantically: urnan[0][4] = urnan[1][0], they both return the 'a' in ass
}

/* More elucidated as an array []
int main (void)
{
    string fku = "FKURETARD!";
    printf("%c%c%c%c%c\n", fku[3], fku[0], fku[9], fku[10]);
}
*/

/* String as array indicating the ASCII codes by utilizing %i
int main (void)
{
    char c1 = 'F';
    char c2 = 'K';
    char c3 = 'U';

    printf("%i\n%i\n%i\n%i\n", c1, c2, c3);
}
*/

/* Basic example of a string as array
int main (void)
{
    char c1 = 'F';
    char c2 = 'K';
    char c3 = 'U';

    printf("%c%c%c\n", c1, c2, c3);
}
*/