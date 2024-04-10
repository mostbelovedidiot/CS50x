#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <cs50.c>

// Initializing Check Prototypes
int argumentCheck(int argument);
int checkLength(string inputArray);
int checkUnique(string inputArray);

int main (int argc, string argv[])
{
    string key = argv[1];

    // checks for alphabetical characters only, not abstracted into a function because it was causing a very strange issue with only a one-letter-key breaking the entire program
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isalpha(argv[1][i]) == 0)
        {
            printf("Please only use alphabetical characters in key.\n");
            return 1;
        }
    }
    
    if (argumentCheck(argc) == 1 || checkLength(key) == 1 || checkUnique(key) == 1)
    {
        return 1;
    }
    
    //working on the cipher process here
    string plaintext = get_string(NULL, "plaintext: ");
    //printf("\n");
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (isupper(plaintext[i]))
        {
            printf("%c", toupper(argv[1][plaintext[i] - 'A']));
            //printf("integer is: %i", plaintext[i] - 'A');
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

int argumentCheck(int argument)
{
    if (argument != 2)
    {
        printf("Usage: ./substition key\n");
        return 1;
    }
}

int checkLength(string inputArray)
{
    if (strlen(inputArray) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
}

int checkUnique(string inputArray)
{
    int sumKeyCharacters = 0;
    for (int i = 0, length = strlen(inputArray); i < length; i++)
    {
        sumKeyCharacters += (toupper(inputArray[i])) - 65;
        printf("character value %i\n", (toupper(inputArray[i]) - 65));
    }
    printf("sumKeyCharacters = %i\n", sumKeyCharacters);
    if (sumKeyCharacters != 325)
    {
        printf("Please ensure each character is unique in the key.\n");
        return 1;
    }
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