#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


//takes the command line argument
int main(int argc, string argv[])
{
    int n, i, j, k;

    //checks if there is exactly two arguments
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //check that the second argument is a number or not
    for (i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key \n");
            return 1;
        }
    }

    //changes the argument type from string to int
    int num = atoi(argv[1]);

    //prompts the user for the plain text
    string s = get_string("Plain text: ");

    //prints the cipher text
    printf("ciphertext: ");

    //loops through every char of the given plain text
    for (j = 0, k = strlen(s); j < k; j++)
    {
        //checks if it is a digit
        if (isdigit(s[j]))
        {
            printf("%c", s[j]);
        }

        //checks if it is in lower case and then converts to cipher text
        else if (islower(s[j]))
        {
            int x = (int)s[j];
            x = (x - 97);
            x = (x + num) % 26;
            x = (x + 97);
            char f = (char)x;
            printf("%c", f);
        }


        //checks if it is a punctuation or space or period or exclaimation
        else if (s[j] == ',' || s[j] == ' ' || s[j] == '"' || s[j] == '!')
        {
            printf("%c", s[j]);
        }

        //checks if it is upper case and then ciphers it
        else
        {
            int y = (int)s[j];
            y = (y - 65);
            y = (y + num) % 26;
            y = (y + 65);
            char g = (char)y;
            printf("%c", g);

        }


    }
    //prints a new line after the execution
    printf("\n");

}

