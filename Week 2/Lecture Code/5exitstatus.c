#include <stdio.h>
#include <cs50.h>
#include <cs50.c>

// demonstrating exit status

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Missing command-line argument\n");
        return 1;
        // the reason it exits here instead of needing an else statement is the return value of 1 indicates an exit status of error, which you can determine by running echo $
    }
    printf("hello, %s\n", argv[1]);
    return 0;
    // exit status of no error
}