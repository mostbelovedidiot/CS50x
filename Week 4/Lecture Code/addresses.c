#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //note that this is basically a string without using the cs50 struct of string
    char *s = "HI!";
    //the double quotes "" effectively indicate through the compiler that we are storing the address &H of the first char into the pointer
    //the compiler additionally knows that by utilizing char *s in this fashion it will seek a nul-value to terminate (it is nul-terminated)
    //sets the pointer of s 
    printf("%s\n", s);
    printf("%c\n", s[0]);
    printf("%p\n", s);
    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
}

/*Demonstrates how a string is really an array that retrieves values at certain indices
int main(void)
{
    string s = "HI!";
    printf("%p\n", s);
    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);
    printf("%c\n", s[3]);
    //Note that the string includes the NUL value at the end which indicates the end of the string
}
*/

/*Utilizes %p to print the address of the n-variable which has been stored in pointer p
//Also utilizes %i to print the VALUE of the n-variable called through the pointer and address relation
#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;
    printf("%p\n", p);
    printf("%i\n", *p);
}
*/

/*Utilizes %p to print the address denoted by & of the n-variable
int main(void)
{
    int n = 50;
    printf("%p\n", &n);
}
*/