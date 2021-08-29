// getting the libraries needed
#include <stdio.h>
#include <cs50.h> // for string and get_string()
#include <ctype.h> // for isalpha()
#include <string.h> // for strlen()
#include <stdlib.h> // for atoi()


// prototype of the function from line 59
bool checkValidKey(string str);


// main function (with two arguments, argc (the counter of arguments) and argv (an array of strings, which are the arguments))
int main(int argc, string argv[])
{
    // error case (if there is not two arguments or the second one is not numeric)
    if (argc != 2 || !checkValidKey(argv[1]))
    {
        printf("Usage: ./caesar key\n"); // shows how type correctly in the command-line
        return 1; // exits with code error 1
    }


    // getting the key as the command-line argument
    int key = atoi(argv[1]);

    // getting the plaintext and its length
    string plaintext = get_string("plaintext: ");
    int len = strlen(plaintext);

    printf("ciphertext: ");


    // encipher
    for (int x = 0; x < len; x++)
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
bool checkValidKey(string str)
{
    for (int x = 0, len = strlen(str); x < len; x++)
        if (!isdigit(str[x]))
        {
            return false;
        }
    return true;
}
