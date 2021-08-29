// getting the libraries needed
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// prototype of the function
bool check(string str);

// main function (with two arguments, argc (the counter of arguments) and argv (the array of strings that are the arguments))
int main(int argc, string argv[])
{
    // error case
    if (argc != 2 || !check(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // getting the key as the command-line argument
    int key = atoi(argv[1]);

    // getting the plaintext
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    // encipher
    for (int x = 0, len = strlen(plaintext); x < len; x++)
    {
        char a = plaintext[x];

        if (isalpha(a))
        {
            char r = 'A';

            if (islower(a))
            {
                r = 'a';
            }

            printf("%c", (a - r + key) % 26 + r); // printing the alphabetic characters of the ciphertext
        }

        else
        {
            printf("%c", a); // printing the non-alphabetic characters of the ciphertext
        }
    }
    printf("\n");
}



// creating the check valid key function
bool check(string str)
{
    for (int x = 0, len = strlen(str); x < len; x++)
        if (!isdigit(str[x]))
            return false;
    return true;
}
