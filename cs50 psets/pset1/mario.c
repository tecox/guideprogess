#include <stdio.h>
#include <cs50.h>

void pyramids(void);

int main(void)
{
    pyramids();
}

void pyramids(void)
{
    printf("Height: ");
    int height = get_int();
    if (height < 0 || height > 23)
    {
        pyramids();
    }
    else
    {
        for (int n = 0; n <= height; n++)
        {
            if (n > 0)
            {
                for (int i = n; i < height; i++)
                {
                    printf(" ");
                }
                for (int j = 0; j < n; j++)
                {
                    printf("#");
                }
                printf("  ");
                for (int k = 0; k < n; k++)
                {
                    printf("#");
                }
                printf("\n");
            }
        }
    }
}