#include <stdio.h>
#include <cs50.h>
#include <cs50.c>

int add(x, y);

int main(void)
{
    int a = get_int("What's your first number?\n");
    int b = get_int("What's your second number?\n");

    long c = get_long("What's your third number?\n");
    long d = get_long("What's your fourth number?\n");

    printf("Your total is %i\n", add(a, b));
    printf("Your quotient is %li\n", c / d);
}

int add(x, y)
{
    return x + y;
}

/* some level of abstraction
int add(x, y)
{
    int c = x + y;
    return c;
}

int main(void)
{
    int a = get_int("What's your first number?\n");
    int b = get_int("What's your second number?\n");

    int z = add(a, b);

    printf("Your total is int %i\n", z);
}
*/

/* basic example

int main(void)
{
    int x = get_int("What's your first number?\n");
    int y = get_int("What's your second number?\n");

    printf("Your total is %i\n", x + y);
}
*/