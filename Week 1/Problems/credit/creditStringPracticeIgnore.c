#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <cs50.c>

/*

american express:   34, 37                  15-digit
mastercard:         51, 52, 53, 54, 55      16-digit
visa:               4                       13 & 16 -digit

*/

int main (void)
{
    //Defined variables and formulas
    string cardNumber;
    //int checkCard(void);
    do 
    {
        cardNumber = get_string(NULL, "Please input your credit card number: \n");
    }
    while (cardNumber - '0' < 1);

    int x = 0;
    int n = strlen(cardNumber);
    int positionInCardNumber = cardNumber[x];

    int totalEvensTimesTwo = 0;
    int totalOdds = 0;

    for (x, n; x < n; x++)
    {
        if (cardNumber[x] % 2 == 0)
        {
            //long individualNumber = atol(cardNumber[x]);
            int individualNumber = cardNumber[x] - '0';
            int modificationComplete = individualNumber * 2;

            printf("%i\n", modificationComplete);

            //printf("%i\n", atoi(cardNumber[x]));
            
            //cardNumber[x] *= 2;
            //printf("%c\n", cardNumber[x]);
            
            
            //individualNumber * 2;
            //cardNumber[x] * 2;
            //totalEvensTimesTwo += cardNumber[x];

            
        }
    }
    //printf("%li\n", totalEvensTimesTwo);

    //int checkcard(cardNumber);
    //{
    //}

}

/*
printf("AMEX\n");
printf("MASTERCARD\n");
printf("VISA\n");
printf("INVALID\n");
*/