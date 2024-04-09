#include <stdio.h>
#include <cs50.h>
#include <cs50.c>

// Same example of array with abstracted functions for determining average in addition to a magic number specification by const

// magic number
const int N = 3;

// prototype of the average
float average(int length, int array[]);

int main (void)
{
    int scores[N];
    for (int i = 0; i < N; i++)
    {
        scores[i] = get_int("What's your score bro? ");
    }

    printf("Your average is %f\n", average(N, scores));

}

float average(int length, int array[])
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return sum / (float) length;
}

/* Basic example of an array
int main (void)
{
    int scores[3];
    
    for (int i = 0; i < 3; i++)
    {
        scores[i] = get_int("Score: ");
    }

    printf("Average: %f\n", (scores[0] + scores[1] + scores[2]) / 3.0);

}
*/