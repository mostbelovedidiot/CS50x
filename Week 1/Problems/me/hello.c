#include <cs50.h>
#include <stdio.h>

// Basic function that asks for a user's name, and greets them
int main(void)
{
    string fuckyou = get_string("What's your name\n");
    printf("hello, %s\n", fuckyou);
}