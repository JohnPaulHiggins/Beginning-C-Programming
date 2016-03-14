#include <cs50.h>
#include <stdio.h>

int is_valid_card(long long number)
{
    // odd_powers will take every other digit, starting from the tens place, double them and sum up the resulting digits
    int odd_powers = 0;
    for (long long i = 100; i <= 10*number; i *= 100)
    {
        int digit_doubled = (2 * ((number % i) / (i/10)));
        if (digit_doubled >= 10)
        {
            odd_powers += (1 + (digit_doubled % 10));
        }
        else
            odd_powers += digit_doubled;
    }
    // even_powers will take the sum of every other digit, starting from the ones place
    int even_powers = 0;
    for (long long j = 10; j <= 10*number; j *= 100)
    {
        even_powers += ((number % j) / (j/10));
    }
    int sum = odd_powers + even_powers;
    if (sum % 10 == 0)
        return 1;
    else
        return 0;
}
int count_digits(long long number)
{
    int count = 0;
    for (long long i = 1; i <= number; i *= 10)
    {
        count++;
    }
    return count;
}
int main(void)
{
    long long number;
    do
    {
        printf("Number: ");
        number = GetLongLong();
    } while (number < 0);
    int num_digits = count_digits(number);
    if (is_valid_card(number) == 1)
    {
        if ((num_digits != 13) && (num_digits != 15) && (num_digits != 16))
            printf("INVALID\n");
        else if (num_digits == 13)
        {
            if ((number / 1000000000000) == 4)
                printf("VISA\n");
            else
                printf("INVALID\n");
        }
        else if (num_digits == 15)
        {
            if (((number / 10000000000000) == 34) || ((number / 10000000000000) == 37))
                printf("AMEX\n");
            else
                printf("INVALID\n");
        }
        else if (num_digits == 16)
        {
            if ((number / 1000000000000000) == 4)
                printf("VISA\n");
            else if (((number / 100000000000000) >= 51) && ((number / 100000000000000) <= 55))
                printf("MASTERCARD\n");
            else
                printf("INVALID\n");
        }
        else
            printf("INVALID\n");
    }
    else
        printf("INVALID\n");
}