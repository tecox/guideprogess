#include <stdio.h>
#include <cs50.h>

bool checksum(long n);
void company(long n);

int main(void)
{
    printf("Number: ");
    long cc = get_long_long();
    if (checksum(cc))
    {
        company(cc);
    }
    else
    {
        printf("INVALID\n");
    }
}

//checks if the number fulfills Luhn's algorithm
bool checksum(long n)
{
    long sum = 0;
    for (long i = 100; i < n * 10; i *= 100)
    {
        long digit = ((n % i) / (i / 10)) * 2;
        sum += ((digit / 10) + (digit % 10));
    }
    for (long j = 10; j < n * 10; j *= 100)
    {
        sum += ((n % j) / (j / 10));
    }
    if (sum % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//checks company identifiers and length simultaneously
void company(long n)
{
    if (n / 10000000000000 == 34 || n / 10000000000000 == 37)
    {
        printf("AMEX\n");
    }
    else if (n / 100000000000000 >= 51 && n / 100000000000000 <= 55)
    {
        printf("MASTERCARD\n");
    }
    else if (n / 1000000000000 == 4 || n / 1000000000000000 == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}