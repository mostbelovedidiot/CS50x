#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int ALPHABET[] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};

int characterTransform(string inputWord);

int main(void)
{
    string playerOne = get_string("Player 1's word: \n");
    string playerTwo = get_string("Player 2's word: \n");
    int playerOneScore = characterTransform(playerOne);
    int playerTwoScore = characterTransform(playerTwo);
    if (playerOneScore > playerTwoScore)
    {
        printf("Player 1 wins!\n");
    }
    else if (playerOneScore < playerTwoScore)
    {
        printf("Player 2 wins!\n");
    }
    else if (playerOneScore == playerTwoScore)
    {
        printf("Tie!\n");
    }
    printf("%i\n", playerOneScore);
    printf("%i\n", playerTwoScore);
}

int characterTransform(string inputWord)
{
    int sum = 0;
    for (int i = 0, length = strlen(inputWord); i < length; i++)
    {
        if (isupper(inputWord[i]))
        {
            sum += ALPHABET[inputWord[i] - 'A'];
        }
        else if (islower(inputWord[i]))
        {
            sum += ALPHABET[inputWord[i] - 'a'];
        }
        else
        {
            sum += 0;
        }
    }
    return sum;
}