// importing the libraries needed
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    // two conditions
    while (1 > n || n > 8);
    // assigning the variable a
    int a = 0;
    int x = n;
    for (int i = 0; i < n; i++)
    {
        // incrementing the variable a
        a++;
        x = x - 1;
        for (int k = 0; k < x; k++)
        {
            printf(" ");
        }
        for (int j = 0; j < a; j++)
        {
            printf("#");
        }
        // making the reverse pyramid
        printf("  ");
        for (int l = 0; l < a; l++)
        {
            printf("#");
        }
        printf("\n");
    }
}
