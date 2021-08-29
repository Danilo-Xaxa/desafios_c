// importing the libraries needed
#include <stdio.h>
#include <cs50.h>

//main function, which says hello to the user
int main(void)
{
    string name = get_string("What's your name?\n");
    printf("hello, %s\n", name);
}