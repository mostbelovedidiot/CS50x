#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <cs50.c>

// utilizing the same idea of a phonebook in 0search.c, instead now using data types and structs

// defining the structs that will be used later on
// notice that you can use anything as a struct
typedef struct
{
    string name;
    string number;
    int position;
}
person;

int main(void)
{
    // defining our data type of person which will be an array of 3
    person people[3];

    // utilizing our structs
    people[0].name = "bob villa";
    people[0].number = "+1-323-132-4269";
    people[0].position = 0;

    people[1].name = "soraka";
    people[1].number = "+1-617-495-1000";
    people[1].position = 1;

    people[2].name = "anoll";
    people[2].number = "+1-949-468-27500";
    people[3].position = 2;

    string whoyougonnacall = get_string(NULL, "Who are you trying to call? ");

    for (int i = 0; i < 3; i++)
    {
        if (strcmp(people[i].name, whoyougonnacall) == 0)
        {
            printf("The number of %s is %s and it is located at #%i in this directory.\n", people[i].name, people[i].number, people[i].position + 1);
            return 0;
        }
    }
    printf("Your person was not found in the directory.");
    return 1;
}