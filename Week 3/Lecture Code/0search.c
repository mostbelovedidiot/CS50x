#include <stdio.h>
#include <cs50.h>
#include <cs50.c>

// two separate sets where each ordered name corresponds to a number, a prelude into the data type structure wherein we can append a .variable to elicit multiple values

int main(void)
{
    string names[] = {"bob villa", "soraka", "anoll"};
    string numbers[] = {"+1-323-132-4269", "+1-617-495-1000", "+1-949-468-2750"};

    string whoyougonnacall = get_string(NULL, "Who are you trying to call? ");

    for (int i = 0; i < 3; i++)
    {
        if (strcmp(names[i], whoyougonnacall) == 0)
        {
            printf("The number of %s is %s.\n", names[i], numbers[i]);
            return 0;
        }
    }
    printf("Your person was not found in the directory.");
    return 1;
}

/* searching strings in a set, utilizing strcmp since C cannot compare string to string natively
int main(void)
{
    string strings[] = {"toads", "butts", "scissors", "soraka", "dragon", "microphone"};

    string want = get_string(NULL, "What word are you looking for? ");

    for (int i = 0; i < 6; i++)
    {
        if (strcmp(strings[i], want) == 0)
        {
            printf("The word exists in the set at the location %i.\n", i + 1);
            return 0;
        }
    }
    printf("Your word was not found.");
    return 1;
}
*/

/* searching integers in a set, very basic loop
int main(void)
{
    int numbers[] = {69, 420, 1337, 13, 0, 8, 9};

    int want = get_int("What number are you looking for? ");

    for (int i = 0; i < 7; i++)
    {
        if (numbers[i] == want)
        {
            printf("The number exists in the set at the location %i.\n", i + 1);
            return 0;
        }
    }
    printf("Your number was not found.");
    return 1;
}
*/