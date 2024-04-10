#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
//#include <cs50.c>

// length of the sentences
// types of punctuation used
// vocabulary?

// index = 0.0588 * L - 0.296 * S - 15.8
// L = average number of letters per 100 words
// S = average number of sentences per 100 words

//function for individual components: characters, spaces, punctuation
float characterCounter(string inputString);
float wordCounter(string inputString);
float sentenceCounter(string inputString);

//function for determining total words/sentences

int main(void)
{
    string input = get_string("Enter your passage: \n");
    //characterCounter(input);
    //wordCounter(input);
    //sentenceCounter(input);
    float averageLettersPerWord = (characterCounter(input) / wordCounter(input)) * 100;
    // printf("Average letters per word: %f\n", averageLettersPerWord);
    float averageSentences = (sentenceCounter(input) / wordCounter(input)) * 100;
    // printf("Average sentences: %f\n", averageSentences);
    int readingScore = round((0.0588 * averageLettersPerWord) - (0.296 * averageSentences) - 15.8);
    if (readingScore >= 16)
    {
        printf("Grade 16+\n", readingScore);
    }
    else if (readingScore < 1)
        {
        printf("Before Grade 1\n", readingScore);
    }
    else
    {
        printf("Grade %i\n", readingScore);
    }
    
}

float characterCounter(string inputString)
{
    int upperSum = 0;
    int lowerSum = 0;
    int totalSum = 0;
    for (int i = 0, length = strlen(inputString); i < length; i++)
    {
        if (isupper(inputString[i]) && inputString[i] - 65 >= 0 && inputString[i] - 65 <= 25)
        {
            upperSum += 1;
        }
        else if (islower(inputString[i]) && inputString[i] - 97 >= 0 && inputString[i] - 97 <= 25)
        {
            lowerSum += 1;
        }
    }
    totalSum = upperSum + lowerSum;
    // printf("Total characters: %i\n", totalSum);
    return totalSum;
}

float wordCounter(string inputString)
{
    //starting the amount of spaces at 1 since there will not be a space after the last word
    int spaceSum = 1;
    for (int i = 0, length = strlen(inputString); i < length; i++)
    {
        if (inputString[i] == ' ')
        {
            spaceSum += 1;
        }
    }
    // printf("Total words: %i\n", spaceSum);
    return spaceSum;
}

float sentenceCounter(string inputString)
{
    int punctuationSum = 0;
    for (int i = 0, length = strlen(inputString); i < length; i++)
    {
        if (inputString[i] == '!' ||  inputString[i] == '?' || inputString[i] == '.')
        {
            punctuationSum += 1;
        }
    }
    // printf("Total sentences: %i\n", punctuationSum);
    return punctuationSum;
}


/*iterate through a word
    count all the letters
        ->letters must not include: -, ',
    count all the spaces
        ->this determines how many words are present

iterate through sentences     
    count all the punctuation
        ->this determines how many sentences are present

iterate per 100 words (likely not needed)
    would have to determine the first 100 spaces, this int must be available in global scope,
    i < inputString[locationof100thspace ]
*/