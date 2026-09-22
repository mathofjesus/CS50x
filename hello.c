#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string answer = get_string("What is your name? ");
    printf ("Hello, %s and welcome to CS50!\n", answer);
    return 0;
}