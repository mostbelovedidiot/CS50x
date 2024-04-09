#include <stdio.h>
#include <cs50.h>
#include <cs50.c>
#include <string.h>

// An array within an array

/* Utilizing a library instead of creating the string length formula*/

int main(void)
{
    string name = get_string(NULL, "What's your name?: ");
    int length = strlen(name);

    printf("%i\n", length);

}

/* Abstracting away the formula
int stringLength(inputString);

int main(void)
{
    string name = get_string(NULL, "What's your name?: ");
    int length = stringLength(name);

    printf("%i\n", length);

}

int stringLength(string inputString)
{
    int n = 0;
    while (inputString[n] != '\0')
    {
        n++;
    }
    return n;
}
*/

/* Writing a basic way to find the length of a string
int main(void)
{
    string name = get_string(NULL, "What's your name?: ");

    int n = 0;
    while (name[n] != '\0')
    {
        n++;
    }

    printf("%i\n", n);

}
*/