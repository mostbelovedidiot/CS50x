#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

#define L 26;

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
        switch (tolower(inputWord[i]))
        {
            case 'a':
                sum += 1;
                break;
            case 'b':
                sum += 3;
                break;
            case 'c':
                sum += 3;
                break;
            case 'd':
                sum += 2;
                break;
            case 'e':
                sum += 1;
                break;
            case 'f':
                sum += 4;
                break;
            case 'g':
                sum += 2;
                break;
            case 'h':
                sum += 4;
                break;
            case 'i':
                sum += 1;
                break;
            case 'j':
                sum += 8;
                break;
            case 'k':
                sum += 5;
                break;
            case 'l':
                sum += 1;
                break;
            case 'm':
                sum += 3;
                break;
            case 'n':
                sum += 1;
                break;
            case 'o':
                sum += 1;
                break;
            case 'p':
                sum += 3;
                break;
            case 'q':
                sum += 10;
                break;
            case 'r':
                sum += 1;
                break;
            case 's':
                sum += 1;
                break;
            case 't':
                sum += 1;
                break;
            case 'u':
                sum += 1;
                break;
            case 'v':
                sum += 4;
                break;
            case 'w':
                sum += 4;
                break;
            case 'x':
                sum += 8;
                break;
            case 'y':
                sum += 4;
                break;
            case 'z':
                sum += 10;
                break;
            default:
                break;
        }
    }
    return sum;
}

/* beginning of complicated if-else statement
        if tolower(inputWord[i]) == 'a'
        {
            sum += 1;
        }
        else if tolower(inputWord[i]) == 'a'
        {
            sum += 1;
        }
        else if tolower(inputWord[i]) == 'a'
        {
            sum += 1;
        }
*/