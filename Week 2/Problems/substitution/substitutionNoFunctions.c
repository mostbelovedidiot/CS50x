#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <cs50.c>

//void cipherProcess(string inputArray[]);
//string plaintext;

int main (int argc, string argv[])
{
    //working on the command line arguments functioning properly here, need to abstract this into functions
    if (argc != 2)
    {
        printf("Usage: ./substition key\n");
        return 1;
    }
    int characterCheck = 0;
    int uniqueCharacters = 0;
    int length = strlen(argv[1]);
    for (int i = 0; i < length; i++)
    {
        if (isalpha(argv[1][i]) == 0)
        {
            characterCheck = 1;
            break;
        }
    }
    printf("characterCheck = %i\n", characterCheck);

    int sumKeyCharacters = 0;
    for (int i = 0, length = strlen(argv[1]); i < length; i++)
    {
        sumKeyCharacters += (toupper(argv[1][i])) - 65;
        printf("%i\n", (toupper(argv[1][i]) - 65));
    }
    printf("sumKeyCharacters = %i\n", sumKeyCharacters);
    if (sumKeyCharacters != 325)
    {
        uniqueCharacters = 1;
    }
    printf("uniqueCharacters = %i\n", uniqueCharacters);

    if (argc == 2 && (strlen(argv[1]) != 26 || characterCheck == 1 || uniqueCharacters == 1))
    {
        printf("Key must contain 26 characters.");
        return 1;
    }

    //working on the cipher process here
    string plaintext = get_string(NULL, "plaintext: ");
    printf("\n");
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (isupper(plaintext[i]))
        {
            printf("%c", toupper(argv[1][plaintext[i] - 'A']));
            printf("integer is: %i", plaintext[i] - 'A');
        }
        else if (islower(plaintext[i]))
        {
            printf("%c", tolower(argv[1][plaintext[i] - 'a']));
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return 0;
}

/*
void cipherProcess(string inputArray[])
{

}
*/

/*
//must be 26 characters
strlen(argv[1])
//must all be letters
for loop
if toupper(argv[x]) - 65 is not between 0 and 25
or isalpha
//must all be unique letters
if the sum of argv[1] - 65 per character does not equal 1+2+3+4...+25 (representation of all the letters)

//ask for user input
get_string
//set the key to an array
ARRAY[]
//correlate the arrays values with the inputs values
ARRAY[input[i] - 65 or 97 (depending on case)]
we subtract to set the value of the input character to correlate to the respective position inside the key, which is arranged from A-Z (scrambled) by virtue of the input
*/