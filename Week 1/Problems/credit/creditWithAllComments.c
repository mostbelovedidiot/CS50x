#include <cs50.h>
#include <stdio.h>
#include <cs50.c>

int main (void)
{
    //Defined variables and formulas

    long long cardNumber;

    //int checkCard(void);
    
    do 
    {
        cardNumber = get_long_long("Please input your #\n");
    }
    while (cardNumber < 0);

    int totalEvens = 0;
    int totalOdds = 0;

    //Loop that iterates 8 times because each iteration divides the operant cardNumber by 100, and there cannot be more relevant digits beyond 100^8 (10^16) for these credit card numbers
    //This will be the loop that evaluates every two starting from second-to-last

    //Long long so we can modify the original card number for the even loop only
    long long cardNumberForEvenLoop = cardNumber;
    for (int i = 0; i <= 8; i++)
    {
        //printing each digit for reference
        printf("%i\n", ((cardNumberForEvenLoop % 100) / 10));
        //we take the modulo of the second to last digit (aka 100), divide it by 10 to remove the remainder, and multiply it 2 per luhn's algorithm
        int currentDigitIteration = (((cardNumberForEvenLoop % 100) / 10) * 2);
        //an if statement for when the result multiplied by 2 results in a number greater than ten, since by luhn's we are adding the digits of the product together --> aka, if the currentDigitIteration results in 13, we want to separate those digits into 1 and 3
        if (currentDigitIteration >= 10) {
            currentDigitIteration = (currentDigitIteration / 10) + (currentDigitIteration % 10);
        }
        //add the current digit iteration to the total
        totalEvens += currentDigitIteration;
        //divide the total number by 100 to prevent integer overflow (cannot keep modulo-ing a huge number by larger modulos as integer overflow will result in extraneous numbers)
        cardNumberForEvenLoop /= 100;
    }
    
    printf("%li\n", totalEvens);
    printf("%lld\n", cardNumber);

    //This will be the loop that evaluates every two starting from last
    long long cardNumberForOddLoop = cardNumber;
    for (int i = 0; i <= 8; i++)
    {
        printf("%i\n", (cardNumberForOddLoop % 10));
        int currentDigitIteration = (cardNumberForOddLoop % 10);
        totalOdds += currentDigitIteration;
        cardNumberForOddLoop /= 100;
    }
    printf("%li\n", totalOdds);
    printf("\n");
    int completeTotal = totalEvens + totalOdds;
    printf("%li\n", completeTotal);
    
    long long cardNumberShortened = cardNumber / 1000000000000;

    printf("%lld\n", cardNumberShortened);

    //checks for 14
    //checking when 15 digits

    bool lastDigitIsZero = completeTotal % 10 == 0;

    bool fifteenDigits = /*(cardNumberShortened / 10 == 0) &&*/(cardNumberShortened / 100 != 0) && (cardNumberShortened / 1000 == 0);
    bool sixteenDigits = /*(cardNumberShortened / 10 == 0) &&*/(cardNumberShortened / 1000 != 0);
    bool fourteenDigits = (cardNumberShortened / 10 != 0) && !fifteenDigits && !sixteenDigits;

    if (((cardNumberShortened % 10 == 4 && !sixteenDigits) || (cardNumberShortened / 1000) % 10 == 4) && lastDigitIsZero)
    {
        printf("VISA\n");
        return;
    }
    else if ((!sixteenDigits && (cardNumberShortened / 100) % 10 == 3 && lastDigitIsZero) && (((cardNumberShortened / 10) % 10 == 4 || (cardNumberShortened / 10) % 10 == 7)))
    {
        printf("AMEX\n");
        return;
    }
    else if ((sixteenDigits && (cardNumberShortened / 1000) % 10 == 5 && lastDigitIsZero) && (((cardNumberShortened / 100) % 10 == 1 || (cardNumberShortened / 100) % 10 == 2 || (cardNumberShortened / 100) % 10 == 3 || (cardNumberShortened / 100) % 10 == 4 || (cardNumberShortened / 100) % 10 == 5)))
    {
        printf("MASTERCARD\n");
        return;
    }
    else (cardNumberShortened == 0 || fourteenDigits || completeTotal % 10 != 0);
    {
        printf("INVALID\n");
    }
    
    printf("%i\n", (4014 / 1000) % 10);

}

//shortened syntax = 13-digits :: 1-digit; 15-digits :: 3-digits; 16-digits :: 4-digits

/*
american express:   34, 37                  15-digit
mastercard:         51, 52, 53, 54, 55      16-digit
visa:               4                       13 & 16 -digit
*/

/*
printf("AMEX\n");
printf("MASTERCARD\n");
printf("VISA\n");
printf("INVALID\n");
*/