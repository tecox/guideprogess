#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
    // errors out if there aren't exactly two strings in argv.
    if (argc != 2)
    {
        printf("incorrect command-line input\n");
        return 1;
    }
    // iterates through the key's chars and errors out if any are not letters.
    for (int i = 0, lk = strlen(argv[1]); i < lk; i++)
    {
        if (argv[1][i] < 'A' || (argv[1][i] > 'Z' && argv[1][i] < 'a') || argv[1][i] > 'z')
        {
            printf ("invalid characters in command-line input\n");
            return 1;
        }
    }
    printf("plaintext: ");
    // get plaintext from user
    string pt = get_string();

    printf("ciphertext: ");

    // iterates through pt's chars
    for (int i = 0, j = 0, lpt = strlen(pt), lk = strlen(argv[1]); i < lpt; i++)
    {
        // resets j when it reaches the key length
        if (j == lk)
        {
            j = 0;
        }
        // encipher when pt and key are capital
        if ((pt[i] >= 'A' && pt[i] <= 'Z') && (argv[1][j] >= 'A' && argv[1][j] <= 'Z'))
        {
            printf("%c", (pt[i] + argv[1][j]) % 26 + 65);
            j++;
        }
        // encipher when pt and key are lowercase
        else if ((pt[i] >= 'a' && pt[i] <= 'z') && (argv[1][j] >= 'a' && argv[1][j] <= 'z'))
        {
            printf("%c", (pt[i] + argv[1][j] - 64) % 26 + 97);
            j++;
        }
        // encipher when pt is lowercase and key is capital
        else if ((pt[i] >= 'a' && pt[i] <= 'z') && (argv[1][j] >= 'A' && argv[1][j] <= 'Z'))
        {
            printf("%c", (pt[i] + argv[1][j] - 32) % 26 + 97);
            j++;
        }
        // encipher when pt is capital and key is lowercase
        else if ((pt[i] >= 'A' && pt[i] <= 'Z') && (argv[1][j] >= 'a' && argv[1][j] <= 'z'))
        {
            printf("%c", (pt[i] + argv[1][j] - 32) % 26 + 65);
            j++;
        }
        // if current pt char is not a letter, print as-is
        else
        {
            printf("%c", pt[i]);
        }
    }
    printf("\n");
    return 0;
}