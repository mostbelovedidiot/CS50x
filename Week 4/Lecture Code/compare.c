#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Get two strings
    char *s = get_string("s: ");
    char *t = get_string("t: ");

    //Indicates that the strings exist at different pointers
    printf("%s\n", s);
    printf("%s\n", t);

    printf("%p\n", s);
    printf("%p\n", t);

    // Compare strings' addresses, not the strings themselves
    if (strcmp(s, t) == 0)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}

/*
int main(void)
{
    // Get two strings
    char *s = get_string("s: ");
    char *t = get_string("t: ");

    // Compare strings' addresses, not the strings themselves
    if (s == t)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}
*/