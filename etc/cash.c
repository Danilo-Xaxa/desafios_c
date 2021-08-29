// importing the libraries needed
#include <stdio.h>
#include <cs50.h>
#include <math.h>

// main function
int main(void)
{
    // getting the input
    float change;
    do
    {
        change = get_float("Change owed: ");
    }
    while (change <= 0);

    //many other things
    change = change * 100;

    int coins_count = 0;

    int cents = round(change);

    int remaining_change = cents;

    //testing and counting the coins needed
    while (remaining_change >= 25)
    {
        remaining_change = remaining_change - 25;
        coins_count++;
    }
    while (remaining_change >= 10)
    {
        remaining_change = remaining_change - 10;
        coins_count++;
    }
    while (remaining_change >= 5)
    {
        remaining_change = remaining_change - 5;
        coins_count++;
    }
    while (remaining_change >= 1)
    {
        remaining_change = remaining_change - 1;
        coins_count++;
    }

    //printing the coints needed
    printf("%i\n", coins_count);
}
