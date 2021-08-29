// getting the libraries needed (CHECK)
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// main function (with two arguments, argc (the counter of arguments) and argv (the array of strings that are the arguments))
int main(int argc, string argv[])
{
    // getting the key as a command-line argument (CHECK)
    int key = atoi(argv[1]);

    // creating a verifier
    int verifier = 0;

    // using the verifier to check wether the key (int version of the command-line argument) is a digit or not
    if (isdigit(key) == 0)
    {
        verifier = 1;
    }

    // checking wether there is only one command-line argument or the verifier is not true
    if (argc != 2 || verifier == 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }




























    // getting the plaintext
    string plaintext = get_string("plaintext: ");








    // encipher (fazer diferente!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!)
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isalpha(plaintext[i])) // esse teste lógico tá certo???????????????????????????
        {
            int modified_ascii_value = ((int)plaintext[i] + key);
            // converter o modified_ascii_value pra um caractere alfabético (ascii)
            char novo_caractere = (char)modified_ascii_value;
            // trocar o velho plaintext[i] pelo novo plaintext[i]
            plaintext[i] = novo_caractere;
        }
    }










    // printing the ciphertext
    printf("ciphertext: %s\n", plaintext);

    // returning 0
    return 0;
}