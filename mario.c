#include <stdio.h>
#include <cs50.h>
void pattern(void);

int main(void)

{
    pattern();
}


void pattern(void)
{
    int height, row, col, space, blank, col2;

    do
    {
        height = get_int("Enter height here: ");
    }
    while (height < 1 || height > 8);

    for (row = 0; row < height; row++)
    {
        for (space = 0; space < height - row - 1; space++)
        {
            printf(" ");
        }

        for (col = 0; col <= row; col++)
        {
            printf("#");
        }

        blank = 0;
        while (blank < height - (height - 1))
        {
            printf("  ");
            blank++;
        }

        for (col2 = 0; col2 <= row; col2++)
        {
            printf("#");
        }

        printf("\n");
    }
}