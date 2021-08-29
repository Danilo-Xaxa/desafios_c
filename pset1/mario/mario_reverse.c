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
    for (int i = 0; i < n; i++)
    {
        // incrementing the variable a
        a++;
        for (int j = 0; j < a; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
