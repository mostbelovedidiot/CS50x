#include <stdio.h>
#include <cs50.h>
#include <cs50.c>

// Doing below in an iterative loop instead of hardcoding the expected argument count

int main(int argc, string argv[])
{
    for (int i = 0; i < argc; i++)
    {
        printf("damn she %s?\n", argv[i]);
    }
}

/* The inputs are abstracted into command line as opposed to get_string by incorporating arguments into your int main (command line)
int main (int argc, string argv[])
{
    if (argc == 2)
    // if the argument count, or how many words we typed is 2, the first word we typed is the program, the second word is the additional modifications
    {
        printf("damn she %s?\n", argv[0]);
        // note that the first argument IS the program itself, as it is the first thing we wrote in the command-line
        printf("damn she %s?\n", argv[1]);
        // now the second argument is what we typed after the program's name in the command-line
    }
    else
    {
        printf("ayo you didn't tell me how thicc yernan was bruv");
    }
}
*/

/* Basic get_string
int main(void)
{
    string howfat = get_string(NULL, "Accurately describe the thiccness of your nan in one word: ");
    printf("damn she %s?\n", howfat);
}
*/
