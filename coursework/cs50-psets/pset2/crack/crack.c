#include <stdio.h>
#include <cs50.h>
#include <unistd.h>
#include <crypt.h>
#include <string.h>

#define _XOPEN_SOURCE

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("incorrect number of command-line arguments\n");
        return 1;
    }
    // get salt from input for future crypt call
    char salt[3] = {argv[1][0], argv[1][1], '\0'};
    // make null array to turn into keys
    char key[5] = {'\0', '\0', '\0', '\0', '\0'};
    // make alphabet array to avoid additional if statements
    char easyalpha[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '\0'
                       };
    // run each key index through easyalpha, starting with most nested for loop for the first char, and working outward for each consecutive char
    for (int i = 0, a = strlen(easyalpha); i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            for (int k = 0; k < a; k++)
            {
                for (int l = 0; l < a; l++)
                {
                    // if input hash matches the crypt hash of the current key, it's a password match
                    if (! strcmp(argv[1], crypt(key, salt)))
                    {
                        printf("%s\n", key);
                        return 0;
                    }
                    key[0] = easyalpha[l];
                }
                key[1] = easyalpha[k];
            }
            key[2] = easyalpha[j];
        }
        key[3] = easyalpha[i];
    }
}