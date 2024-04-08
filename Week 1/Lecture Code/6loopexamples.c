#include <stdio.h>
#include <cs50.h>
#include <cs50.c>

void meow(int n)
{
    for (int i = 0; i <= n; i++)
    {
        printf("meow\n");
    }
}

int main(void)
{
    meow(3);
}

/* With a prototype up top example

void meow(int n);

int main(void)
{
    meow(3);
}

void meow(int n)
{
    for (int i = 0; i <= n; i++)
    {
        printf("meow\n");
    }
}

*/