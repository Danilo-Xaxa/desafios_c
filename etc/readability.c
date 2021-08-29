// getting the libraries needed
#include <stdio.h>
#include <cs50.h> // for string and get_string()
#include <ctype.h> // for isalpha()
#include <string.h> // for strlen()
#include <math.h> // for round()


// main function
int main(void)
{
    // getting the user input
    string text = get_string("Text: ");

    // calculating the number of sentences (one more sentence every . ! ?)
    int sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    // calculating the number of words (one more every space and then one more at the end)
    int words = 0;
    for (int j = 0; j < strlen(text); j++)
    {
        if (text[j] == ' ')
        {
            words++;
        }
    }
    words++;

    // calculating the number of letters (one more every alphabetical character)
    int letters = 0;
    for (int k = 0; k < strlen(text); k++)
    {
        if (isalpha(text[k]))
        {
            letters++;
        }
    }


    // L (average number of letters per 100 words) and S (average number of sentences per 100 words)
    float L = ((float) letters / words) * 100;
    float S = ((float) sentences / words) * 100;

    // using the given formula
    float grade = 0.0588 * L - 0.296 * S - 15.8;


    // rounding grade
    int rounded_grade = round(grade);

    // before 1 and 16+ exceptions
    if (rounded_grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (rounded_grade > 16)
    {
        printf("Grade 16+\n");
    }

    // normal cases (1 to 16)
    else
    {
        printf("Grade %i\n", rounded_grade);
    }
}
