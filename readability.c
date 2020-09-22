#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>


int main(void)
{
    string s;
    int letters = 0;
    int words = 0;
    int sentences = 0;
    
    //calculates the string length.
    s = get_string("Text: ");
    
    //checks conditions for counting letters,words and sentences.
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            letters++;
        }
        
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            letters++;
        }

        if (s[i] == ' ')
        {
            words++;
        }

        if (s[i] == '!' || s[i] == '.' || s[i] == '?')
        {
            sentences++;
            words++;
        }
        
        if (s[i] == '.' && s[i + 1] == ' ')
        {
            words--;
        }


    }
    
    //calculates the values of L and S.
    float L = (((float)letters / words) * 100);
    float S = (((float)sentences / words) * 100);

    //calculates the Coleman-Liau index.
    float index = (0.0588 * L) - (0.296 * S) - 15.8;
    printf("index %f\n", index);
    
    //prints different grades according to readining level.
    if (index < 0)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 0 && index <= 16)
    {
        int grade = (int)(round(index));
        printf("Grade %i\n", grade);
    }
    else 
    {
        printf("Grade 16+\n");
    }

}
