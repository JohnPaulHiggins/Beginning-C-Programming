#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float change;
    do
    {
        printf("How much change is owed? ");
        change = GetFloat();
    } while (change < 0);
    int change_integer = roundf(100*change);
    int num_quarters = 0, num_dimes = 0, num_nickels = 0, num_pennies = 0;
    num_quarters = change_integer / 25;
    change_integer -= num_quarters * 25;
    num_dimes = change_integer / 10;
    change_integer -= num_dimes * 10;
    num_nickels = change_integer / 5;
    change_integer -= num_nickels * 5;
    num_pennies = change_integer;
    int sum = num_quarters + num_dimes + num_nickels + num_pennies;
    printf("%d\n", sum);
}