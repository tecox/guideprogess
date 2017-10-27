#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    // get string from user
    string s = get_string();

    // iterate through each char of the string
    for (int i = 0, l = strlen(s); i < l; i++)
    {
        // if statements confirm char is an initial
        if (s[i] >= 'A' && s[i] <= 'Z' && (i == 0 || s[i - 1] == 32))
        {
            printf("%c", s[i]);
        }
        // capitalizes the initial if it's lowercase
        else if ((s[i] >= 'a' && s[i] <= 'z') && (i == 0 || s[i - 1] == 32))
        {
            printf("%c", s[i] - 32);
        }
    }
    printf("\n");
}
