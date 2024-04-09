#include <stdio.h>
#include <cs50.h>
#include <cs50.c>
#include <string.h>
#include <ctype.h>

// Simplifying the code since toupper inherently understands not to convert non-lower chars
int main(void)
{
    string input = get_string(NULL, "What's your string? ");
    printf ("Here it is in uppercase: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        printf("%c", toupper(input[i]));
    }
}

/* Utilizing the library ctype.h
int main(void)
{
    string input = get_string(NULL, "What's your string? ");
    printf ("Here it is in uppercase: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (islower(input[i]))
        {
            printf("%c", toupper(input[i]));
        }
        else
        {
            printf("%c", input[i]);
        }
    }
}
*/

/* Creating the function manually
int main(void)
{
    string input = get_string(NULL, "What's your string? ");
    printf ("Here it is in uppercase: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (input[i] >= 'a' && input [i] <= 'z')
        {
            input[i] -= 32;
            printf("%c", input[i]);
        }
        else
        {
            printf("%c", input[i]);
        }
    }
}
*/

// Note that subtraction from characters functionally subtracts from the ASCII value, thereby converting the character into something else. In this case, removing 32 from exactly a lower case character will result in the upper case since they show up precisely 32 spots from the lower case set